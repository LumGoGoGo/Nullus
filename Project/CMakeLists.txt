# 收集头文件和源文件
###############################################################################
file(GLOB_RECURSE GAME_HEAD_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/*.inl
)
file(GLOB_RECURSE GAME_SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

# 对文件进行分组
###############################################################################
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${GAME_HEAD_FILES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${GAME_SOURCE_FILES})

add_executable(Game ${GAME_SOURCE_FILES} ${GAME_HEAD_FILES})

# 指定输出路径
###############################################################################
set_target_properties(Game PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${NLS_APP_OUTPUT_PATH}"
)

# 设置包含路径
###############################################################################
target_include_directories(
  Game
  PUBLIC # 其他项目使用头文件时所需的目录
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(
  Game
    PUBLIC # 使用该库时必须依赖的库
    NLS_Engine
)
