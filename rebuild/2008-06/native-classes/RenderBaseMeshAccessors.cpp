// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native RBX::RenderBase::Mesh vertex / normal accessors (inactive). Declarations: ViewNew/RenderBaseMesh.h.
// Identity evidence: 007a9c90 and 007a9ce0 are the two out-of-line optimized copies placed at the head of the
// RenderNew::RenderScene image block (007a9c40 .. 007ab0a0, RenderSceneNew2008.cpp flags); their only caller is
// RenderScene::render 007ab0a0 (call sites 007ab911 / 007ab8f7), which loads the mesh pointer into ecx before each
// call (thiscall, ret 4: one int argument, `this` unused). Each bounds-checks the index against the size of one of
// the Mesh::visibleGeometry arrays (vertexArray data/num 009738f0 / 009738f4, normalArray 009738fc / 00973900) and
// returns &array[index] (12-byte elements), else throws std::exception (ctor import 008028a4, throw info 008d997c)
// with the strings 00874928 "RBX Mesh::getVertex() index out of range" / 00874954 "RBX Mesh::getNormal() index
// out of range". The names come from those strings.
// INFERRED: the original most likely had these as header-inline members, emitted out of line where render calls
// them. render 007ab0a0 is parked (RenderSceneNew2008.cpp), so nothing here calls them; this unit defines them out
// of line instead (same code, same decorated names).
#include "ViewNew/RenderBaseMesh.h"
#include <exception>

namespace RBX
{
	namespace RenderBase
	{
		// 007a9c90
		const G3D::Vector3& Mesh::getVertex(int index) const
		{
			if (index < 0 || index >= visibleGeometry.vertexArray.size())
				throw std::exception("RBX Mesh::getVertex() index out of range");
			return visibleGeometry.vertexArray[index];
		}

		// 007a9ce0
		const G3D::Vector3& Mesh::getNormal(int index) const
		{
			if (index < 0 || index >= visibleGeometry.normalArray.size())
				throw std::exception("RBX Mesh::getNormal() index out of range");
			return visibleGeometry.normalArray[index];
		}
	}
}
