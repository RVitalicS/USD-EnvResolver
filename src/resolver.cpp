
#include "resolver.h"

#include <pxr/base/tf/getenv.h>
#include <pxr/base/tf/fileUtils.h>

#include <pxr/usd/ar/defineResolver.h>
#include <pxr/usd/ar/filesystemAsset.h>

#include "debugCodes.h"
#include <tbb/concurrent_hash_map.h>


PXR_NAMESPACE_OPEN_SCOPE

AR_DEFINE_RESOLVER(EnvResolver, ArResolver);



struct EnvResolver::_Cache
{
    using _PathToResolvedPathMap = 
        tbb::concurrent_hash_map<std::string, std::string>;
    _PathToResolvedPathMap _pathToResolvedPathMap;
};

EnvResolver::_CachePtr 
EnvResolver::_GetCurrentCache() {
    return _threadCache.GetCurrentCache();
}

std::string
EnvResolver::ResolveWithAssetInfo(
    const std::string& path, 
    ArAssetInfo* assetInfo)
{

    if (path.empty()) {
        return path;
    }

    if (_CachePtr currentCache = _GetCurrentCache()) {
        _Cache::_PathToResolvedPathMap::accessor accessor;
        if (currentCache->_pathToResolvedPathMap.insert(
                accessor, std::make_pair(path, std::string()))) {
            accessor->second = _EnvResolve(path);
        }
        return accessor->second;
    }

    return _EnvResolve(path);
}



std::string
EnvResolver::_EnvResolve(const std::string& path)
{
    TF_DEBUG(USD_ENV_RESOLVER)
        .Msg("Resolve : %s\n", path.c_str());

    std::string
    resolvedPath = EnvResolve(path);

    if (!TfPathExists(resolvedPath)) {
        resolvedPath = std::string();
    }

    return resolvedPath;
}


std::string
EnvResolver::EnvResolve(const std::string& path)
{
    if( path.find( "${" ) == std::string::npos ) return path;

    std::string pre  = path.substr( 0, path.find( "${" ) );
    std::string post = path.substr( path.find( "${" ) + 2 );

    if( post.find( '}' ) == std::string::npos ) return path;

    std::string variable = post.substr( 0, post.find( '}' ) );
    post = post.substr( post.find( '}' ) + 1 );

    std::string env = TfGetenv(variable);
    std::string value;
    if (!env.empty()) value = env;

    return EnvResolve( pre + value + post );
}




PXR_NAMESPACE_CLOSE_SCOPE
