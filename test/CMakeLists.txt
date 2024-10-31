cmake_minimum_required(VERSION 3.15...3.30)

# -----------------------------------------------------------------------------
#   T E S T S
# -----------------------------------------------------------------------------


add_executable(test-jread test-jread.c)
target_link_libraries(test-jread PRIVATE jReadWrite)
add_test(NAME test-jread COMMAND $<TARGET_FILE:test-jread>)

add_executable(test-jwrite test-jwrite.c)
target_link_libraries(test-jwrite PRIVATE jReadWrite)
add_test(NAME test-jwrite COMMAND $<TARGET_FILE:test-jwrite>)
