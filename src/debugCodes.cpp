
#include "debugCodes.h"

#include <pxr/base/tf/registryManager.h>


PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfDebug) {
    TF_DEBUG_ENVIRONMENT_SYMBOL(
        USD_ENV_RESOLVER, "Handling Usd Environment Asset Resolver.");
}

PXR_NAMESPACE_CLOSE_SCOPE
