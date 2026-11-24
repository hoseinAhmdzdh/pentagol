# White's last move rotates the upper-right quadrant into a winning hook.
# Rotating twice, or checking only Black after the rotation, loses this win.
set(moves [=[
5 1 + 4
1 1 + 4
5 2 + 4
1 2 + 4
5 3 + 4
1 3 + 4
6 1 + 4
2 1 + 4
6 2 + 4
3 5 + 4
7 3 + 4
2 5 + 1
]=])
set(input "${CMAKE_CURRENT_BINARY_DIR}/rotation-win.input")
file(WRITE "${input}" "${moves}")
execute_process(COMMAND "${GAME}" INPUT_FILE "${input}" OUTPUT_VARIABLE transcript
                RESULT_VARIABLE status TIMEOUT 5)
if(NOT "${status}" STREQUAL "0" OR NOT transcript MATCHES "PLAYER W HAS WON")
    message(FATAL_ERROR "Expected White to win on the final rotation.\n${transcript}")
endif()
