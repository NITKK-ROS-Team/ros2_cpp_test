cmake_minimum_required(VERSION 3.5)
project(pub_sub_int32)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)

set(RCL_PKGS rclcpp rclcpp_components std_msgs)
set(LIBS)
set(EXECS)

# pub --------------------------------------------------
set(TARGET pub)
add_library(${TARGET} SHARED src/${TARGET}.cpp)
rclcpp_components_register_nodes(${TARGET} "pub_sub_int32::pub_int")
ament_target_dependencies(${TARGET} ${RCL_PKGS})
target_include_directories(${TARGET} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_compile_options(${TARGET} PUBLIC -Wall)
set(LIBS ${LIBS} ${TARGET})

add_executable(${TARGET}_exec src/${TARGET}.cpp)
ament_target_dependencies(${TARGET}_exec ${RCL_PKGS})
target_include_directories(${TARGET}_exec PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_compile_options(${TARGET}_exec PUBLIC -Wall)
set(EXECS ${EXECS} ${TARGET}_exec)


# sub --------------------------------------------------
set(TARGET sub)
add_library(${TARGET} SHARED src/${TARGET}.cpp)
rclcpp_components_register_nodes(${TARGET} "pub_sub_int32::sub_int")
ament_target_dependencies(${TARGET} ${RCL_PKGS})
target_include_directories(${TARGET} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_compile_options(${TARGET} PUBLIC -Wall)
set(LIBS ${LIBS} ${TARGET})

add_executable(${TARGET}_exec src/${TARGET}.cpp)
ament_target_dependencies(${TARGET}_exec ${RCL_PKGS})
target_include_directories(${TARGET}_exec PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_compile_options(${TARGET}_exec PUBLIC -Wall)
set(EXECS ${EXECS} ${TARGET}_exec)

install(
  TARGETS ${LIBS}
  EXPORT export_${PROJECT_NAME}
  DESTINATION lib
)

install(
  TARGETS ${EXECS}
  EXPORT export_${PROJECT_NAME}
  DESTINATION bin
)

install(DIRECTORY
    launch
    DESTINATION share/${PROJECT_NAME}
)


ament_package()
