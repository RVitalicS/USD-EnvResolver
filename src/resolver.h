#pragma once

#include <pxr/usd/ar/defaultResolver.h>
#include <pxr/usd/ar/resolvedPath.h>

#include <string>


PXR_NAMESPACE_OPEN_SCOPE

class EnvResolver
     : public ArDefaultResolver
{
public:
    ArResolvedPath _Resolve(
        const std::string& path) const override;
};

PXR_NAMESPACE_CLOSE_SCOPE
