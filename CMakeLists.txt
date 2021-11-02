
project(USD-Environment-Resolver)
set(PLUGIN_NAME EnvResolver)

cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)



list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
find_package(Katana REQUIRED)



add_subdirectory(src)



install(
    TARGETS
        ${PLUGIN_NAME}
    LIBRARY DESTINATION
        plugin/usd
)

install(
    FILES
        ${CMAKE_BINARY_DIR}/plugInfo.json
    DESTINATION
        plugin/usd
)

install(
    FILES
        ${CMAKE_BINARY_DIR}/resources/plugInfo.json
    DESTINATION
        plugin/usd/${PLUGIN_NAME}/resources
)
