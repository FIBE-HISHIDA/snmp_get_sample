cmake_minimum_required(VERSION 3.10)
project(agent)

find_package(Threads REQUIRED)

add_executable(agent agent.cpp)

target_include_directories(agent PRIVATE /usr/include/net-snmp)
target_link_libraries(agent PRIVATE netsnmp netsnmpagent pthread)
