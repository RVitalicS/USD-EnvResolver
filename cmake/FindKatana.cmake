
find_path(KATANA_INSTALL_DIR
    NAMES
        bin/katanaBin
    PATHS
        ${KATANA_HOME}
        $ENV{KATANA_HOME}
)


set(KATANA_LIBRARY_DIR ${KATANA_INSTALL_DIR}/bin)


set(USD_INCLUDE_DIR
    ${KATANA_INSTALL_DIR}/external/FnUSD/include)

set(BOOST_INCLUDE_DIR
    ${KATANA_INSTALL_DIR}/external/FnBoost/include)

set(TBB_INCLUDE_DIR
    ${KATANA_INSTALL_DIR}/external/FnTBB/include)

set(PYTHON_INCLUDE_DIR
    ${KATANA_INSTALL_DIR}/bin/python2.7/include/python2.7)
