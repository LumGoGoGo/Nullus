# 收集头文件和源文件
###############################################################################
file(GLOB_RECURSE GL_HEAD_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/*.inl
)
file(GLOB_RECURSE GL_SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

# 对文件进行分组
###############################################################################
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${GL_HEAD_FILES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${GL_SOURCE_FILES})

if(NLS_USE_SHARED_LIBRARY)
add_library(OpenGL_Rendering SHARED ${GL_HEAD_FILES} ${GL_SOURCE_FILES})

target_compile_definitions(
  OpenGL_Rendering
  PUBLIC
  GLAD_GLAPI_EXPORT
  PRIVATE
  GLAD_GLAPI_EXPORT_BUILD
  OGL_EXPORT
)
else()
add_library(OpenGL_Rendering STATIC ${GL_HEAD_FILES} ${GL_SOURCE_FILES})
endif()

# 指定输出路径
###############################################################################
set_target_properties(OpenGL_Rendering PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${NLS_APP_OUTPUT_PATH}"
)


# 设置包含路径
###############################################################################
target_include_directories(
  OpenGL_Rendering
  PUBLIC # 其他项目使用头文件时所需的目录
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>

    )
find_package(OpenGL REQUIRED)

target_link_libraries(
  OpenGL_Rendering
    PUBLIC # 使用该库时必须依赖的库
    NLS_Core
    NLS_Platform
    ${OPENGL_LIBRARIES}
)