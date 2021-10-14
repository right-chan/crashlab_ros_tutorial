# Create Package
```bash
catkin_create_pkg tutorial_package roscpp std_msgs
```

# package.xml
##### 의존하는 빌드 시스템
```xml
<buildtool_depend>catkin</buildtool_depend>
```
##### 빌드할 때의 의존 패키지
```xml
<build_depend>roscpp</build_depend>
```
##### build_depend가 포함된 소스를 내보낼 때 의존하는 패키지
```xml
<build_export_depend>roscpp</build_export_depend>
```
##### 패키지 실행할 때의 의존 패키지
```xml
<exec_depend>roscpp</exec_depend>
```

# CMakeLists.txt
##### 소스코드가 빌드될 때 요구되는 cmake패키지
##### package.xml의 <build_depend>을 참조
```cmake
find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
)
```
##### build_depend가 포함된 소스를 내보낼 때 의존하는 패키지
##### package.xml의 <build_export_depend>을 참조
```cmake
catkin_package(
#   INCLUDE_DIRS include
#   LIBRARIES tutorial_package
#   CATKIN_DEPENDS roscpp std_msgs
#   DEPENDS system_lib
)
```
##### 소스코드가 빌드될 때 요구되는 헤더파일 경로
```cmake
include_directories(
#  include
    ${catkin_INCLUDE_DIRS}
)
```

---
##### 소스코드를 빌드하여 실행파일 생성
```cmake
add_executable(pub_node src/pub_node.cpp)
```

##### 빌드할 파일 타겟에 의존성 추가
```cmake
add_dependencies(pub_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
```

##### 실행할 파일 타겟에 라이브러리 추가
```cmake
target_link_libraries(pub_node ${catkin_LIBRARIES})
```
---