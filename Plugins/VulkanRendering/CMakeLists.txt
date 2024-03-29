# 收集头文件和源文件
###############################################################################
file(GLOB_RECURSE VK_HEAD_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/*.inl
)
file(GLOB_RECURSE VK_SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# 对文件进行分组
###############################################################################
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${VK_HEAD_FILES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${VK_SOURCE_FILES})



if(NLS_USE_SHARED_LIBRARY)
add_library(Vulkan_Rendering SHARED ${VK_HEAD_FILES} ${VK_SOURCE_FILES})

target_compile_definitions(
  Vulkan_Rendering
  PRIVATE
  Vulkan_Rendering_EXPORT
)
else()
add_library(Vulkan_Rendering STATIC ${VK_HEAD_FILES} ${VK_SOURCE_FILES})
endif()

# 指定输出路径
###############################################################################
set_target_properties(Vulkan_Rendering PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${NLS_APP_OUTPUT_PATH}"
)

# 设置包含路径
###############################################################################
target_include_directories(
  Vulkan_Rendering
  PUBLIC # 其他项目使用头文件时所需的目录
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    ${Vulkan_INCLUDE_DIRS}
)
find_package(Vulkan REQUIRED)

target_link_libraries(
  Vulkan_Rendering
    PUBLIC # 使用该库时必须依赖的库
    NLS_Core
    NLS_Platform
    Vulkan::Vulkan
)