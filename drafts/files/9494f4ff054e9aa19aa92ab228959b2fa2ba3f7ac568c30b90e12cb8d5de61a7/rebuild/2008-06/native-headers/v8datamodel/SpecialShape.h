#pragma once
#include "v8tree/Instance.h"
#include <string>
#include "G3D/Vector3.h"
#include "util/MeshId.h"
#include "util/TextureId.h"
namespace RBX {
extern char sSpecialShape[];
class SpecialShape : public DescribedCreatable<SpecialShape, Instance, sSpecialShape> {
public:
 int meshType;
 G3D::Vector3 scale;
 MeshId meshId;
 TextureId textureId;
 G3D::Vector3 vertColor;
 SpecialShape();
};
}
