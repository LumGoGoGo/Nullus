# OpenGL
add_subdirectory(OpenGLRendering)
set_target_properties(OpenGL_Rendering PROPERTIES FOLDER "Plugins")

# Vulkan
find_package(Vulkan QUIET)
if(Vulkan_FOUND)
    add_subdirectory(VulkanRendering)
    set_target_properties(Vulkan_Rendering PROPERTIES FOLDER "Plugins")
endif()
