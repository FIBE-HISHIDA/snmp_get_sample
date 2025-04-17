
cmake_minimum_required(VERSION 3.10)
project(snmp_agent_sample)

set(CMAKE_CXX_STANDARD 11)
find_package(PkgConfig REQUIRED)
pkg_check_modules(NETSNMP REQUIRED net-snmp-agent net-snmp)

include_directories(${NETSNMP_INCLUDE_DIRS})
link_directories(${NETSNMP_LIBRARY_DIRS})

add_executable(agent agent.cpp)
target_link_libraries(agent ${NETSNMP_LIBRARIES})
