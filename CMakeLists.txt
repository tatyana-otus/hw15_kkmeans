cmake_minimum_required(VERSION 3.2)

project(kkmeans VERSION 1.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(kkmeans main.cpp)

set_target_properties(kkmeans PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wall -Wextra -Wpedantic 
)

target_link_libraries(kkmeans openblas)

install(TARGETS kkmeans RUNTIME DESTINATION bin)

install(
    FILES draw.py run.sh
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    DESTINATION  "/opt/kkmeans"
)

install(
    FILES kkmeans_ex.txt sky.txt
    DESTINATION  "/opt/kkmeans"
)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT lisstic.tt@gmail.com)

include (CPack)