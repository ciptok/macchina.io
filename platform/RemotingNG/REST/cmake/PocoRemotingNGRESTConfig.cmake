include(CMakeFindDependencyMacro)
set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR})
find_dependency(RemotingNG)
include("${CMAKE_CURRENT_LIST_DIR}/PocoRemotingNGRESTTargets.cmake")