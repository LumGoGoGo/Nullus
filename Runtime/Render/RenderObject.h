﻿#pragma once

#include "Matrix4.h"
#include "RHI/TextureBase.h"
#include "RHI/ShaderBase.h"
#include "Vector4.h"
#include "RenderDef.h"

namespace NLS
{
using namespace NLS::Rendering;

class MeshGeometry;
namespace Engine
{
class Transform;
using namespace Maths;

class NLS_RENDER_API RenderObject
{
public:
    RenderObject(Transform* parentTransform, MeshGeometry* mesh, TextureBase* tex, ShaderBase* shader);
    ~RenderObject();

    void SetDefaultTexture(TextureBase* t)
    {
        texture = t;
    }

    TextureBase* GetDefaultTexture() const
    {
        return texture;
    }

    MeshGeometry* GetMesh() const
    {
        return mesh;
    }

    Transform* GetTransform() const
    {
        return transform;
    }

    ShaderBase* GetShader() const
    {
        return shader;
    }

    void SetColour(const Vector4& c)
    {
        colour = c;
    }

    Vector4 GetColour() const
    {
        return colour;
    }

protected:
    MeshGeometry* mesh;
    TextureBase* texture;
    ShaderBase* shader;
    Transform* transform;
    Vector4 colour;
};
} // namespace Engine
} // namespace NLS
