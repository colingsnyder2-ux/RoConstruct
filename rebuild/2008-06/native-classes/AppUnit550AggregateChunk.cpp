// 2008-06 native RBX::RenderBase AggregateChunk.cpp template members (inactive), the application range 00550000..00554000.
// Built by tests/record_native_app_unit550.py with the RenderBase library profile of tests/record_native_render_scene.py
// and tests/record_native_app_unit540_2008.py (/Od /Ob0 /GS plus the Ogre 1.4.5 client headers) against the read-only
// RenderLib/AggregateChunk2008.h (render-scene owner) and ViewNew/RenderBaseMesh.h (ViewNew owner).
// No class is declared here and no header is created.
//
// Main build (counted when the recorder proves them): explicit instantiations of the COMDAT template members the
// AggregateChunk.cpp unit (AggregateChunk ctor 00551f30 / dtor 00552160 / renderShadows 00552300) and the Mesh.cpp
// statics reference, each bound by its original call site in the recorder (the std::set / std::map allocator and
// _Tree rows the recorder also counts are implicit instantiations of the read-only app-unit540 sources):
//   G3D::Array<Vector3>::clear              005527b0 (renderShadows 005523f9 on the function-local static shadowVertex
//                                                     009739bc, Array<Vector3> ctor 00481520 under guard 009739c8)
//   G3D::Array<unsigned int>::clear         005527d0 (renderShadows 0055236e / 00552533 on shadowIndexArray +0xd8)
//   G3D::Array<unsigned short>::clear       00552810 (renderShadows 0055237f on shadowIndexArray16 +0xe4)
//   RenderDevice::sendIndices<unsigned short>(Primitive, const Array<unsigned short>&)
//                                           00552830 (renderShadows 00552665: push +0xe4, push 2) and its
//                                           (Primitive, int, const unsigned short*) overload 00552860
//   G3D::Array<Vector2>::Array()            00551600 (dynamic initializer 007f26e0 on Mesh texCoordArray 00973934)
//   G3D::Array<Vector2>::init(int, int)     00551620 (00551600: push 0, push 0; resize 0054bda0)
//   G3D::Array<MeshAlg::Edge / Face>::~Array 005516d0 (ShadowSurface dtor 0054aad1 / 0054aaef, one folded body)
//   G3D::VAR::VAR(const Array<Vector2>&, VARAreaRef) 00551400 (Mesh.cpp VAR static 00548df7 on texCoordArray
//                                           00973934, element size 8) and _GLFormat<Vector2>::x 005514a0
// Under NATIVE_APPUNIT550_PENDING (pending-build-only, never counted): AggregateChunk::renderShadows 00552300 and
// makeMesh 00552270, which need declarations the read-only headers lack (Mesh::computeDirectionalShadowVolume 00549050
// and Mesh::aggregate 00547610 in ViewNew/RenderBaseMesh.h, AggregateChunk::makeMesh in RenderLib/AggregateChunk2008.h;
// proposals in the receipt). Each `xor r, r; jne` pair in the target is an empty release-build debugAssert
// (do {} while (0)); the asserted expressions are not visible in the bytes, only their positions are significant.
#include "RenderLib/AggregateChunk2008.h"
#include "RenderLib/Material2008.h"   // completes RenderBase::MaterialBase (needs the Ogre 1.4.5 client headers)
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

#ifdef NATIVE_APPUNIT550_PENDING
namespace RBX
{
	namespace RenderBase
	{
		// 00552270 (called by the Bucket member 0053fe10 after new AggregateChunk): Mesh::aggregate 00547610 (cdecl,
		// hidden RCP<Mesh> return, components +0xf0, _cframe +0x30, radius +0x1c), assigned to mesh +0x2c (004d7560).
		void AggregateChunk::makeMesh()
		{
			mesh = Mesh::aggregate(components, _cframe, radius);
		}

		// 00552300 (vtable 0082d258 slot 2, ret 0x10).
		void AggregateChunk::renderShadows(G3D::RenderDevice* rd, const G3D::GLight& light, bool caps, float shadowVertexDistance)
		{
			debugAssert(rd);

			if (light != shadowSource)
			{
				shadowSource = light;
				shadowIndexArray.clear();
				shadowIndexArray16.clear();

				if (material->veryTransparent())
					return;

				static G3D::Array<G3D::Vector3> shadowVertex;

				shadowVertex.clear();
				shadowVertex.append(-light.position.xyz().direction() * shadowVertexDistance);
				debugAssert(shadowVertex.size() == 1);

				G3D::Vector3 worldLight = light.position.xyz().direction();
				mesh->computeDirectionalShadowVolume(cframe(), worldLight, shadowIndexArray, shadowVertex, caps);

				if (shadowVertex.size() < 65536)
				{
					int size = shadowIndexArray.size();

					shadowIndexArray16.resize(size);
					for (int i = 0; i < size; i++)
						shadowIndexArray16[i] = shadowIndexArray[i];

					shadowIndexArray.clear();
				}

				G3D::ReferenceCountedPointer<G3D::VARArea> area = G3D::VARArea::create(shadowVertex.size() * 12, G3D::VARArea::WRITE_EVERY_FEW_FRAMES);
				shadowVAR = G3D::VAR(shadowVertex, area);
			}

			if (shadowIndexArray.size() > 0)
			{
				rd->beginIndexedPrimitives();
				rd->setVertexArray(shadowVAR);
				rd->sendIndices(G3D::RenderDevice::TRIANGLES, shadowIndexArray);
				rd->endIndexedPrimitives();
			}
			else if (shadowIndexArray16.size() > 0)
			{
				rd->beginIndexedPrimitives();
				rd->setVertexArray(shadowVAR);
				rd->sendIndices(G3D::RenderDevice::TRIANGLES, shadowIndexArray16);
				rd->endIndexedPrimitives();
			}
		}
	}
}
#endif
