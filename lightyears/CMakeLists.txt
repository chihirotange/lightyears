add_executable(${LIGHT_YEAR_TARGET} 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/application.cpp
)

target_include_directories(${LIGHT_YEAR_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${LIGHT_YEAR_TARGET} PUBLIC sfml-graphics)
target_link_libraries(${LIGHT_YEAR_TARGET} PUBLIC sfml-window)
target_link_libraries(${LIGHT_YEAR_TARGET} PUBLIC sfml-system)
target_link_libraries(${LIGHT_YEAR_TARGET} PUBLIC sfml-audio)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
    add_custom_command(TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:${LIB_NAME}>
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibToTarget(sfml-graphics ${LIGHT_YEAR_TARGET})
CopyLibToTarget(sfml-window ${LIGHT_YEAR_TARGET})
CopyLibToTarget(sfml-system ${LIGHT_YEAR_TARGET})
CopyLibToTarget(sfml-audio ${LIGHT_YEAR_TARGET})