// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#include "ViewNew/RenderBaseMesh.h"

namespace RBX {
namespace RenderBase {
Mesh::ShadowSurface::ShadowSurface() {}
Mesh::ShadowSurface::~ShadowSurface() {}
}
}

template G3D::Array<G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh::Level> >::Array();
template G3D::Array<G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh::Level> >::~Array();
template std::vector<unsigned short>::vector();
template std::vector<unsigned short>::~vector();
template std::vector<G3D::Vector3>::vector();
template std::vector<G3D::Vector3>::~vector();
template void G3D::Array<int>::append(const int&);
template void G3D::Array<int>::push(const int&);
template int G3D::Array<int>::pop(bool);
template int& G3D::Array<int>::operator[](int);
template int& G3D::Array<int>::operator[](unsigned int);
template int G3D::Array<int>::length() const;
template void G3D::Array<int>::clear();
template void G3D::Array<G3D::Vector2>::resize(int);
template void G3D::Array<G3D::Vector2>::append(const G3D::Vector2&);
