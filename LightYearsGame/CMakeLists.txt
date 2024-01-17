add_executable(${LIGHTYEARS_GAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gameFramework/GameApplication.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gameFramework/GameApplication.cpp
)

target_include_directories(${LIGHTYEARS_GAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${LIGHTYEARS_GAME} PUBLIC ${AI_ENGINE})
function(CopyDirToTarget LIB_NAME TARGET_NAME)
    add_custom_command(TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        $<TARGET_FILE_DIR:${LIB_NAME}>
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyDirToTarget(${AI_ENGINE} ${LIGHTYEARS_GAME})