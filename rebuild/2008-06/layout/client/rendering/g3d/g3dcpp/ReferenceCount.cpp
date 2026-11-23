// =============================================================================
// ReferenceCount.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/g3dcpp/ReferenceCount.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

// INFERRED: buildFace EndcapTransform spelling at004ff1e0; unique714B body and original references verified.
#include "ViewNew/HeadMesh.h"
#include "ViewNew/QuadVolumeFace.h"
#include <algorithm>
#include <math.h>

namespace RBX
{
	namespace ViewNew
	{
		class CylinderTransform
		{
			const float bevel;
			const int halfVertexCount;
		public:
			// The face slots pass `elements`; the ctor halves it (2007 RenderLibNew/HeadMesh.cpp shape).
			CylinderTransform(float bevel, int vertexCount)
				: bevel(bevel),
				  halfVertexCount((vertexCount + 1) / 2)
			{
			}
			void operator()(
				G3D::Vector3& vertex,
				G3D::Vector3& normal,
				G3D::Vector2& tex,
				const G3D::Vector3& radius,
				const G3D::Vector2int16& ivertex); // 004fdbd0
		};

		class EndcapTransform
		{
			const float bevel;
		public:
			EndcapTransform(float bevel)
				: bevel(bevel)
			{
			}
			void operator()(
				G3D::Vector3& vertex,
				G3D::Vector3& normal,
				G3D::Vector2& tex,
				const G3D::Vector3& radius,
				const G3D::Vector2int16& ivertex); // 004fdcc0
		};

		HeadBuilder::HeadBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes, size_t elements, float bevel)
			: LevelBuilder(level, G3D::Vector3(std::min(size.x, size.z), size.y, std::min(size.x, size.z)), surfaceTypes),
			  bevel(bevel),
			  elements(elements)
		{
		}

		void CylinderTransform::operator()(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2& tex, const G3D::Vector3& radius, const G3D::Vector2int16& ivertex)
		{
			float angleX = vertex.x / radius.x * 0.7853982f;
			float angleY = float(ivertex.y - halfVertexCount + 1) * 1.5707964f / float(halfVertexCount - 1);
			vertex.x = (radius.x - (1.0f - cosf(angleY)) * bevel) * sinf(angleX);
			if (ivertex.y >= halfVertexCount)
				vertex.y = radius.y - (1.0f - sinf(angleY)) * bevel;
			else
				vertex.y = (sinf(angleY) + 1.0f) * bevel - radius.y;
			vertex.z = (radius.z - (1.0f - cosf(angleY)) * bevel) * cosf(angleX);
			normal.x = cosf(angleY) * sinf(angleX);
			normal.y = sinf(angleY);
			normal.z = cosf(angleY) * cosf(angleX);
			float arc = 1.5707964f * bevel;
			float factor = arc / (radius.y + arc - bevel);
			if (ivertex.y >= halfVertexCount)
				tex.y *= factor;
			else
				tex.y = 2.0f * radius.y - (1.0f - (tex.y - radius.y) / radius.y) * radius.y * factor;
		}

		void EndcapTransform::operator()(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2& tex, const G3D::Vector3& radius, const G3D::Vector2int16& ivertex)
		{
			float scale;
			float absY = float(fabs(vertex.y));
			float absX = float(fabs(vertex.x));
			if (absY >= absX)
				scale = vertex.y == 0.0f ? 0.0f : absY / vertex.xy().length() * (1.0f - bevel / radius.y);
			else
				scale = vertex.x == 0.0f ? 0.0f : absX / vertex.xy().length() * (1.0f - bevel / radius.x);
			vertex.x *= scale;
			vertex.y *= scale;
		}

		void HeadBuilder::buildTop(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_Y>(EndcapTransform(bevel), G3D::Vector2int16(e, e), purpose);
		}

		void HeadBuilder::buildBottom(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_Y_NEG>(EndcapTransform(bevel), G3D::Vector2int16(e, e), purpose);
		}

		void HeadBuilder::buildLeft(Purpose purpose)
		{
			buildFace<NORM_X_NEG>(CylinderTransform(bevel, elements), elements, elements, purpose);
		}

		void HeadBuilder::buildRight(Purpose purpose)
		{
			buildFace<NORM_X>(CylinderTransform(bevel, elements), elements, elements, purpose);
		}

		void HeadBuilder::buildFront(Purpose purpose)
		{
			buildFace<NORM_Z_NEG>(CylinderTransform(bevel, elements), elements, elements, purpose);
		}

		void HeadBuilder::buildBack(Purpose purpose)
		{
			buildFace<NORM_Z>(CylinderTransform(bevel, elements), elements, elements, purpose);
		}

		HeadMesh::HeadMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes)
		{
			float bevel = std::min(size.x, size.z) * 0.25f;
			levels.push_back(new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS));

			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = levels.last();
			HeadBuilder builder(level, size, surfaceTypes, 9, bevel);
			builder.build(LevelBuilder::Surface);
		}

		// INFERRED: constructor identity from original HeadMesh factory call and unique exact body.
		HeadMesh::HeadMesh(const G3D::Vector3& size, NormalId decalFace)
		{
			float bevel = std::min(size.x, size.z) * 0.25f;
			RenderBase::Mesh::Level* created = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
			{
				G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> reference(created);
				levels.push_back(reference);
			}
			HeadBuilder builder(created, size, RenderSurfaceTypes(), 9, bevel);
			builder.buildFace(decalFace, LevelBuilder::Decal);
		}

		HeadMesh::HeadMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile)
		{
			float bevel = std::min(size.x, size.z) * 0.25f;
			levels.push_back(new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS));

			HeadBuilder builder(levels.last(), size, RenderSurfaceTypes(), 9, bevel);
			builder.textureScale = mapToUvw_Legacy(size, textureFace).xy() * 2.0f / studsPerTile;
			builder.buildFace(textureFace, LevelBuilder::Decal);
		}
	}
}

#line 1 ".\\glg3dcpp\\GModule.cpp"
/**
 @file GModule.cpp

 @maintainer Morgan McGuire, morgan3d@users.sourceforge.net

 @created 2006-04-22
 @edited  2006-04-22
*/

#include "GLG3D/GModule.h"
#include "GLG3D/RenderDevice.h"

namespace G3D
{

GModuleManagerRef GModuleManager::create() {
	return new GModuleManager();
}

GModuleManager::GModuleManager() : m_locked(false), m_size(0), m_removeAll(false) {
}

int GModuleManager::size() const {
	return m_size;
}

const GModuleRef& GModuleManager::operator[](int i) const {
	debugAssert(i >= 0 && i < m_size);
	for (int p = NUM_PRIORITY - 1; p >= 0; --p) {
		if (i < m_moduleArray[p].size()) {
			return m_moduleArray[p][i];
		} else {
			// Look in the next array.  We are guaranteed
			// not to underflow by the assertion above.
			i -= m_moduleArray[p].size();
		}
	}

	static GModuleRef tmp;
	return tmp;
}

void GModuleManager::beginLock() {
	debugAssert(! m_locked);
	m_locked = true;
}

void GModuleManager::endLock() {
	debugAssert(m_locked);
	m_locked = false;

	// Process add list
	for (int i = 0; i < m_addList.size(); ++i) {
		add(m_addList[i].module, m_addList[i].priority);
	}
	m_addList.clear();

	// Process remove list
	for (int i = 0; i < m_removeList.size(); ++i) {
		remove(m_removeList[i]);
	}
	m_removeList.clear();

	if (m_removeAll) {
		clear();
		m_removeAll = false;
	}
}

void GModuleManager::remove(const GModuleRef& m) {
	if (m_locked) {
		m_removeList.append(m);
	} else {
		for (int p = 0; p < NUM_PRIORITY; ++p) {
			int j = m_moduleArray[p].findIndex(m);
			if (j != -1) {
				m_moduleArray[p].fastRemove(j);
				--m_size;
				return;
			}
		}
		debugAssertM(false, "Removed a GModule that was not in the manager.");
	}
}

void GModuleManager::add(const GModuleRef& m, EventPriority p) {
	debugAssert(p >= LOW_PRIORITY && p <= HIGH_PRIORITY);
	if (m_locked) {
		m_addList.append(Add(m, p));
	} else {
		++m_size;
		m_moduleArray[p].append(m);
	}
}

void GModuleManager::clear() {
	if (m_locked) {
		m_removeAll = true;
	} else {
		for (int p = 0; p < NUM_PRIORITY; ++p) {
			m_moduleArray[p].clear();
		}
	}
}

// Iterate through all modules in priority order.
// This same iteration code is used to implement
// all GModule methods concisely.
#define ITERATOR(body)\
    beginLock();\
    for (int p = NUM_PRIORITY - 1; p >= 0; --p) {\
        Array<GModuleRef>& array = m_moduleArray[p];\
        for (int i = array.size() - 1; i >= 0; --i) {\
            body;\
        }\
    }\
    endLock();

void GModuleManager::getPosedModel(
	Array<PosedModelRef>& posedArray,
	Array<PosedModel2DRef>& posed2DArray) {

	ITERATOR(array[i]->getPosedModel(posedArray, posed2DArray));
}

void GModuleManager::onSimulation(RealTime rdt, SimTime sdt, SimTime idt) {
	ITERATOR(array[i]->onSimulation(rdt, sdt, idt));
}

bool GModuleManager::onEvent(const GEvent& event) {
	// if the event is ever consumed, abort iteration
	ITERATOR(if (array[i]->onEvent(event)) { endLock(); return true; });
	return false;
}

void GModuleManager::onUserInput(UserInput* ui) {
	ITERATOR(array[i]->onUserInput(ui));
}

void GModuleManager::onNetwork() {
	ITERATOR(array[i]->onNetwork());
}

void GModuleManager::onLogic() {
	ITERATOR(array[i]->onLogic());
}

#undef ITERATOR

bool GModuleManager::onEvent(const GEvent& event, GModuleManagerRef& a, GModuleManagerRef& b) {
	a->beginLock();
	b->beginLock();

	for (int p = NUM_PRIORITY - 1; p >= 0; --p) {

		// Process each, interlaced
		for (int k = 0; k < 2; ++k) {
			Array<GModuleRef>& array =
				(k == 0) ?
					a->m_moduleArray[p] :
					b->m_moduleArray[p];

			for (int i = array.size() - 1; i >= 0; --i) {
				if (array[i]->onEvent(event)) {
					b->endLock();
					a->endLock();
					return true;
				}
			}
		}

	}

	b->endLock();
	a->endLock();

	return false;
}

} // G3D

#line 1 ".\\glg3dcpp\\Renderbuffer.cpp"
/**
@file Renderbuffer.cpp

@maintainer Daniel Hilferty, djhilferty@users.sourceforge.net

@cite http://oss.sgi.com/projects/ogl-sample/registry/EXT/framebuffer_object.txt

@created 2006-01-07
@edited  2006-02-14
*/

#include "GLG3D/Renderbuffer.h"
#include "GLG3D/glcalls.h"
#include "GLG3D/TextureFormat.h"

namespace G3D
{

/////////////////////////////////////////////////////////////////////////////

Renderbuffer::Renderbuffer (
	const std::string&			_name,
	const GLuint				_imageID,
	const G3D::TextureFormat*	_format,
	const int					_width,
	const int					_height) :
	mName(_name),
	mImageID(_imageID),
	mFormat(_format),
	mWidth(_width),
	mHeight(_height) {

	// Intentionally empty
}

Renderbuffer::~Renderbuffer () {
	glDeleteRenderbuffersEXT(1, &mImageID);
}

RenderbufferRef Renderbuffer::fromGLRenderbuffer(
	const std::string&			_name,
	const GLuint				_imageID,
	const G3D::TextureFormat	*_format) {

	GLint w, h;

	// Extract the width and height
	glGetRenderbufferParameterivEXT (GL_RENDERBUFFER_EXT, GL_RENDERBUFFER_WIDTH_EXT, &w);
	glGetRenderbufferParameterivEXT (GL_RENDERBUFFER_EXT, GL_RENDERBUFFER_WIDTH_EXT, &h);
	debugAssertGLOk();

	// Create new renderbuffer
	return new Renderbuffer(_name, _imageID, _format, w, h);
}

RenderbufferRef Renderbuffer::createEmpty(
	const std::string&			_name,
	const G3D::TextureFormat*   _format,
	const int					_width,
	const int					_height) {
	// New Renderbuffer ID
	GLuint _imageID;

	// Save old renderbuffer state
	GLint origBuffer;
	glGetIntegerv(GL_RENDERBUFFER_BINDING_EXT, &origBuffer);

	// Generate buffer
	glGenRenderbuffersEXT (1, &_imageID);
	debugAssertGLOk();

	// Bind the buffer
	glBindRenderbufferEXT (GL_RENDERBUFFER_EXT, _imageID);
	debugAssertGLOk();

	// Allocate storage for it
	glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, _format->OpenGLFormat, _width, _height);

	// Check for successful generation (ie, no INVALID_OPERATION)
	debugAssertGLOk();

	// Restore renderbuffer state
	glBindRenderbufferEXT (GL_RENDERBUFFER_EXT, origBuffer);
	debugAssertGLOk();

	// Create new renderbuffer
	return new Renderbuffer(_name, _imageID, _format, _width, _height);
}

} // End Namespace G3D
