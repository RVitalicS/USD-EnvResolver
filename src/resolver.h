#pragma once

#include <pxr/usd/ar/defaultResolver.h>



PXR_NAMESPACE_OPEN_SCOPE

class EnvResolver
     : public ArDefaultResolver
{
public:

    std::string
    EnvResolve(const std::string& path);

    std::string
    ResolveWithAssetInfo(
        const std::string& path, 
        ArAssetInfo* assetInfo) override;

private:
    
    struct _Cache;
    using _PerThreadCache = ArThreadLocalScopedCache<_Cache>;
    _PerThreadCache _threadCache;

    using _CachePtr = _PerThreadCache::CachePtr;
    _CachePtr _GetCurrentCache();

    std::string
    _EnvResolve(const std::string& path);
};

PXR_NAMESPACE_CLOSE_SCOPE
