// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#undef OGRE_NONCLIENT_BUILD
#include "OgreRbxNode/TwoDManager2008.h"
#include <OgreHardwareBufferManager.h>
#include <OgreVertexIndexData.h>
namespace Ogre {
// INFERRED: method name from original target 006829a0 and TwoDManager::render caller.
void TwoDManager::createVertexBuffer(unsigned int count) {
 renderOp.vertexData = new VertexData;
 renderOp.vertexData->vertexStart = 0;
 VertexDeclaration* declaration = renderOp.vertexData->vertexDeclaration;
 size_t offset = 0;
 declaration->addElement(0, offset, VET_FLOAT3, VES_POSITION);
 offset += VertexElement::getTypeSize(VET_FLOAT3);
 declaration->addElement(0, offset, VET_COLOUR, VES_DIFFUSE);
 offset += VertexElement::getTypeSize(VET_COLOUR);
 declaration->addElement(0, offset, VET_FLOAT2, VES_TEXTURE_COORDINATES);
 vertexBuffer = HardwareBufferManager::getSingleton().createVertexBuffer(declaration->getVertexSize(0), count, HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY_DISCARDABLE, false);
 renderOp.vertexData->vertexBufferBinding->setBinding(0, vertexBuffer);
 renderOp.useIndexes = false;
 renderOp.operationType = RenderOperation::OT_TRIANGLE_LIST;
}
}
