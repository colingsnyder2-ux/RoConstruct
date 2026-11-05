// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_listener_vertex_buffer_28806614eb3a450c.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <list>

namespace Ogre {

struct Quad {
    Vector3 vertices[4];
};

class Listener : public RenderQueueListener {
public:
    SceneManager* manager;
    bool options[3];
    void* data;
    RenderOperation operation;
    HardwareVertexBufferSharedPtr vertices;
    HardwareIndexBufferSharedPtr indices;
    std::list<Quad> quads;

    void initializeVertexBuffer(size_t vertexCount);
};

void Listener::initializeVertexBuffer(size_t vertexCount)
{
    operation.vertexData = new VertexData;
    operation.vertexData->vertexStart = 0;

    VertexDeclaration* declaration = operation.vertexData->vertexDeclaration;
    size_t offset = 0;
    declaration->addElement(0, offset, VET_FLOAT3, VES_POSITION);
    offset += VertexElement::getTypeSize(VET_FLOAT3);
    declaration->addElement(0, offset, VET_COLOUR, VES_DIFFUSE);
    offset += VertexElement::getTypeSize(VET_COLOUR);
    declaration->addElement(0, offset, VET_FLOAT2, VES_TEXTURE_COORDINATES);

    vertices = HardwareBufferManager::getSingleton().createVertexBuffer(
        declaration->getVertexSize(0), vertexCount,
        HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY_DISCARDABLE, false);
    operation.vertexData->vertexBufferBinding->setBinding(0, vertices);
    operation.useIndexes = false;
    operation.operationType = RenderOperation::OT_TRIANGLE_LIST;
}

}
