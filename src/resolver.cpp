
#include "resolver.h"

#include "pxr/base/tf/pathUtils.h"
#include "pxr/base/tf/fileUtils.h"
#include <pxr/usd/ar/defineResolver.h>

#include "debugCodes.h"


PXR_NAMESPACE_OPEN_SCOPE

AR_DEFINE_RESOLVER(EnvResolver, ArResolver);



static std::string 
_EnvResolve(const std::string& path)
{
    if( path.find( "${" ) == std::string::npos ) return path;

    std::string pre  = path.substr( 0, path.find( "${" ) );
    std::string post = path.substr( path.find( "${" ) + 2 );

    if( post.find( '}' ) == std::string::npos ) return path;

    std::string variable = post.substr( 0, post.find( '}' ) );
    std::string value    = "";

    post = post.substr( post.find( '}' ) + 1 );

    const char *var = std::getenv( variable.c_str() );
    if( var != nullptr ) value = std::string( var );

    return _EnvResolve( pre + value + post );
}



ArResolvedPath
EnvResolver::_Resolve(const std::string& path) const
{
    TF_DEBUG(USD_ENV_RESOLVER)
        .Msg("EnvResolver input: %s\n", path.c_str());

    std::string resolvedPath = _EnvResolve(path);

    return TfPathExists(resolvedPath)
        ? ArResolvedPath(TfAbsPath(resolvedPath))
        : ArResolvedPath();
}



PXR_NAMESPACE_CLOSE_SCOPE
