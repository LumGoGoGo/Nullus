/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#pragma once
#include <string>
#include "CoreDef.h"
namespace NLS
{
namespace Assets
{
const std::string SHADERDIR("../../Assets/Shaders/");
const std::string MESHDIR("../../Assets/Meshes/");
const std::string TEXTUREDIR("../../Assets/Textures/");
const std::string SOUNDSDIR("../../Assets/Sounds/");
const std::string FONTSSDIR("../../Assets/Fonts/");
const std::string DATADIR("../../Assets/Data/");
extern NLS_CORE_API bool ReadTextFile(const std::string& filepath, std::string& result);
extern NLS_CORE_API bool ReadBinaryFile(const std::string& filepath, char** into, size_t& size);
} // namespace Assets
} // namespace NLS