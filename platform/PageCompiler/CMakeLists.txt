set(POCO_EXENAME "PageCompiler")

# Sources
file(GLOB SRCS_G "src/*.cpp")
POCO_SOURCES_AUTO( SRCS ${SRCS_G})

add_executable( "${POCO_EXENAME}" ${SRCS} )
set_target_properties( "${POCO_EXENAME}"
    PROPERTIES
    OUTPUT_NAME cpspc
    )

target_link_libraries( "${POCO_EXENAME}" Net Util XML JSON Foundation)

install(
    TARGETS "${POCO_EXENAME}" EXPORT "${POCO_EXENAME}Targets"
    LIBRARY DESTINATION macchina/lib${LIB_SUFFIX}
    ARCHIVE DESTINATION macchina/lib${LIB_SUFFIX}
    RUNTIME DESTINATION macchina/bin
    INCLUDES DESTINATION macchina/include
    )

#POCO_GENERATE_PACKAGE("${LIBNAME}" "${LIBNAME}Targets" "lib/cmake/${PROJECT_NAME}")
