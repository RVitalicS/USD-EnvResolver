
find_file(USD_CONFIG_FILE
    NAME
        pxrConfig.cmake
    PATHS
        ${PXR_USD_LOCATION}
        $ENV{PXR_USD_LOCATION}
)

include(${USD_CONFIG_FILE})



find_path(USD_INCLUDE_DIR pxr/pxr.h
    PATHS
        ${PXR_USD_LOCATION}/include
        $ENV{PXR_USD_LOCATION}/include
)


find_path(USD_LIBRARY_DIR
    NAMES
        ${CMAKE_SHARED_LIBRARY_PREFIX}usd${CMAKE_SHARED_LIBRARY_SUFFIX}
    PATHS
        ${PXR_USD_LOCATION}/lib
        $ENV{PXR_USD_LOCATION}/lib
)
