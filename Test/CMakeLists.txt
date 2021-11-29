include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/a3460d1aeeaa43fdf137a6adefef10ba0b59fe4b.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_reg_map
  test_reg_map.cpp
)
target_link_libraries(test_reg_map PRIVATE
  apex_fsm
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_reg_map)
