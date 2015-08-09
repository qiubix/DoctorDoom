project(PlaceDescriptionService)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include $ENV{JSONCPP_HOME}/include $ENV{CURL_HOME}/include)
link_directories($ENV{GMOCK_HOME}/build $ENV{GMOCK_HOME}/gtest/build $ENV{JSONCPP_HOME}/build $ENV{CURL_HOME}/lib)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall -pthread")
enable_testing()

set(sources
   main.cpp
   CurlHttpTest.cpp CurlHttp.cpp
   AddressExtractorTest.cpp AddressExtractor.cpp
   PlaceDescriptionServiceTest.cpp PlaceDescriptionService.cpp)
add_executable(PlaceDescriptionServiceTest ${sources})
target_link_libraries(PlaceDescriptionServiceTest pthread)
target_link_libraries(PlaceDescriptionServiceTest gmock)
target_link_libraries(PlaceDescriptionServiceTest gtest)
#target_link_libraries(PlaceDescriptionServiceTest json_linux-gcc)
target_link_libraries(PlaceDescriptionServiceTest libjsoncpp.a)
target_link_libraries(PlaceDescriptionServiceTest curl)
add_dependencies(PlaceDescriptionServiceTest gmock)
add_test(PlaceDescriptionServiceTest PlaceDescriptionServiceTest)
