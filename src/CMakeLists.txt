
add_library(
    ${PLUGIN_NAME}
    SHARED
    resolver.cpp
    debugCodes.cpp
)



set_target_properties(${PLUGIN_NAME} PROPERTIES PREFIX "")
set(libraryName ${PLUGIN_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX})

configure_file(
    plugInfo.json.in
    ${CMAKE_BINARY_DIR}/plugInfo.json
    @ONLY
)
configure_file(
    plugInfo.json.rsc
    ${CMAKE_BINARY_DIR}/resources/plugInfo.json
    @ONLY
)



target_include_directories(
    ${PLUGIN_NAME}
    SYSTEM PRIVATE
    ${USD_INCLUDE_DIR}
    ${BOOST_INCLUDE_DIR}
    ${TBB_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIR}
)


link_directories(
    ${KATANA_LIBRARY_DIR}
)

target_link_libraries(
    ${PLUGIN_NAME}
    PRIVATE Fntf Fnar
)
