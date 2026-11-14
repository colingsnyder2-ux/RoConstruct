// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#include "RenderLib/AggregateChunk2008.h"
#include "RenderLib/Material2008.h"
#include <GLG3D/RenderDevice.h>
#include <GLG3D/VARArea.h>

template void G3D::Array<G3D::Vector3>::clear();
template void G3D::Array<unsigned int>::clear();
template void G3D::Array<unsigned short>::clear();
template void G3D::RenderDevice::sendIndices<unsigned short>(G3D::RenderDevice::Primitive,
	const G3D::Array<unsigned short>&);
template G3D::Array<G3D::Vector2>::Array();
template G3D::Array<G3D::MeshAlg::Edge>::~Array();
template G3D::Array<G3D::MeshAlg::Face>::~Array();
template G3D::VAR::VAR(const G3D::Array<G3D::Vector2>&, G3D::VARAreaRef);
