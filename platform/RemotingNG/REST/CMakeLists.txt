set(LIBNAME "RemotingNGREST")
set(POCO_LIBNAME "Poco${LIBNAME}")

# Sources
file(GLOB SRCS_G "src/*.cpp")
POCO_SOURCES_AUTO( SRCS ${SRCS_G})

# Headers
file(GLOB_RECURSE HDRS_G "include/*.h" )
POCO_HEADERS_AUTO( SRCS ${HDRS_G})

if (NOT POCO_STATIC)
    add_definitions(-DTHREADSAFE)
endif (NOT POCO_STATIC)

if(MSVC AND NOT(MSVC_VERSION LESS 1400))
    set_source_files_properties(src/StatementImpl.cpp
        PROPERTIES COMPILE_FLAGS "/bigobj")
endif()

add_library( "${LIBNAME}" ${LIB_MODE} ${SRCS} )
add_library( "${POCO_LIBNAME}" ALIAS "${LIBNAME}")
set_target_properties( "${LIBNAME}"
    PROPERTIES
    VERSION ${SHARED_LIBRARY_VERSION} SOVERSION ${SHARED_LIBRARY_VERSION}
    OUTPUT_NAME ${POCO_LIBNAME}
    DEFINE_SYMBOL RemotingNGREST_EXPORTS
    )

target_link_libraries( "${LIBNAME}" RemotingNG Net XML)
target_include_directories( "${LIBNAME}"
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
install(
    DIRECTORY include/Poco
    DESTINATION macchina/include
    COMPONENT Devel
    PATTERN ".svn" EXCLUDE
    )

install(
    TARGETS "${LIBNAME}" EXPORT "${LIBNAME}Targets"
    LIBRARY DESTINATION macchina/lib${LIB_SUFFIX}
    ARCHIVE DESTINATION macchina/lib${LIB_SUFFIX}
    RUNTIME DESTINATION macchina/bin
    INCLUDES DESTINATION macchina/include
    )

POCO_GENERATE_PACKAGE("${LIBNAME}" "${LIBNAME}Targets" "lib/cmake/${PROJECT_NAME}")

if (ENABLE_TESTS)
#     add_subdirectory(testsuite)
endif ()
