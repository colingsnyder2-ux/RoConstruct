// Ogre::TwoDManager method bodies (inactive native recovery, June 2008 client); see OgreRbxNode/TwoDManager2008.h.
// Bodies 00682560..006843e6 except render 006832b0. Built with the Ogre 1.4.5 client headers (/fp:fast);
// record_native_ogre_rbx_node.py verifies them.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// OgreRbxNodeTwoDManager | 2008-06 | draft (no current byte proof)
// 0/8 mapped addresses byte-exact | 8 unproved | no mapped strings | by colin (+2) (mixed 3)
// <<< native-status | src d4045eb0 | roc native-status --write
#include "OgreRbxNode/TwoDManager2008.h"
#include <OgreRoot.h>
#include <OgreRenderSystem.h>
#include <OgreSceneManager.h>
#include <OgreTextureManager.h>
#include <OgreLogManager.h>
#include <OgreHardwareBufferManager.h>
#include <OgreTextureUnitState.h>
#include <OgreMatrix4.h>

namespace Ogre
{
	// 006831d0
	TwoDManager::TwoDManager()
	{
	}

	// 00683240
	TwoDManager::~TwoDManager()
	{
	}

	// 00682560
	void TwoDManager::setup(SceneManager* sceneManager, RenderTarget* target, uint8 queueId, bool afterQueue, bool flag)
	{
		this->afterQueue = afterQueue;
		this->queueId = queueId;
		this->sceneManager = sceneManager;
		this->target = target;
		this->flag = flag;
		vertexBuffer.setNull();
		sceneManager->addRenderQueueListener(this);
	}

	// 00682d60
	void TwoDManager::addQuad(String textureName, const G3D::Color4& color, Real left, Real top, Real right,
	                          Real bottom, Real u0, Real v0, Real u1, Real v1)
	{
		TexturePtr texture;

		Quad quad;
		quad.left = left;
		quad.top = top;
		quad.right = right;
		quad.bottom = bottom;
		quad.u0 = u0;
		quad.v0 = v0;
		quad.u1 = u1;
		quad.v1 = v1;

		RenderSystem* renderSystem = Root::getSingleton().getRenderSystem();
		renderSystem->convertColourValue(ColourValue(color.r, color.g, color.b, color.a), &quad.colour);
		quad.operationType = RenderOperation::OT_TRIANGLE_LIST;
		quad.mode = 0;

		if (textureName != "")
		{
			texture = TextureManager::getSingleton().getByName(textureName);
			if (texture.isNull())
				texture = TextureManager::getSingleton().load(textureName, "General");

			if (!texture.isNull())
			{
				quad.texture = texture.getPointer()->getHandle();
				if ((left == right) && (top == bottom))
				{
					texture.getPointer()->getWidth();
					texture.getPointer()->getHeight();
				}
			}
			else
				quad.texture = 0;
		}
		else
			quad.texture = 0;

		quads.push_back(quad);
	}

	// 00683000
	void TwoDManager::primitive(RenderOperation::OperationType operationType, Real left, Real top, Real right,
	                            Real bottom, const G3D::Color4& color)
	{
		Quad quad;
		quad.left = left;
		quad.top = top;
		quad.right = right;
		quad.bottom = bottom;
		RenderSystem* renderSystem = Root::getSingleton().getRenderSystem();
		renderSystem->convertColourValue(ColourValue(color.r, color.g, color.b, color.a), &quad.colour);
		quad.texture = 0;
		quad.operationType = operationType;
		quad.mode = 0;
		quads.push_back(quad);
	}

	// 006830b0
	void TwoDManager::outlineRectangle(Real left, Real top, Real right, Real bottom, const G3D::Color4& color)
	{
		Quad quad;
		quad.left = left;
		quad.top = top;
		quad.right = right;
		quad.bottom = bottom;
		RenderSystem* renderSystem = Root::getSingleton().getRenderSystem();
		renderSystem->convertColourValue(ColourValue(color.r, color.g, color.b, color.a), &quad.colour);
		quad.texture = 0;
		quad.operationType = RenderOperation::OT_LINE_LIST;
		quad.mode = 1;
		quads.push_back(quad);
	}

	// 006843b0
	void TwoDManager::renderQueueStarted(uint8 queueGroupId, const String& invocation, bool& skipThisInvocation)
	{
		if (!afterQueue && queueGroupId == queueId)
			render();
	}

	// 006843d0
	void TwoDManager::renderQueueEnded(uint8 queueGroupId, const String& invocation, bool& repeatThisInvocation)
	{
		if (afterQueue && queueGroupId == queueId)
			render();
	}
	// INFERRED (owner rule 2026-11-11): Batch, createVertexBuffer 006829a0 and prepareRenderState 006825b0 names;
	// bodies follow the server-exact fork analog roc_espclaude_610f7f834b7be5f0.cpp.
	// PARKED drafts: render 4554/4309 B (original calls out-of-line list iterator operator*/++ 0042a8f0/00682ad0; the fork
	// forces them with noinline wrappers, not plausible source). prepareRenderState: body from its own 100% app analog 006825b0 (the fork variant is 999 B)
	// under the native runner (rbxgs prelude) but 1007 B under the ogre-1.4.5-dll recipe build -> runner prelude difference.
	struct Batch {ResourceHandle texture; RenderOperation::OperationType points; int mode; unsigned count;};
#define VERTEXO(X,Y,U,V) *out++=(*i).X; *out++=(*i).Y; *out++=-1.0f; col=static_cast<RGBA*>(static_cast<void*>(out)); *col++=(*i).colour; out=static_cast<float*>(static_cast<void*>(col)); *out++=(*i).U; *out++=(*i).V;
#define VERTEX(X,Y,U,V) *out++=i->X; *out++=i->Y; *out++=-1.0f; col=static_cast<RGBA*>(static_cast<void*>(out)); *col++=i->colour; out=static_cast<float*>(static_cast<void*>(col)); *out++=i->U; *out++=i->V;
#define VERTEXL(X,Y,U,V) *out++=i->X; *out++=i->Y; *out++=-1.0f; col=static_cast<RGBA*>(static_cast<void*>(out)); *col++=i->colour; out=static_cast<float*>(static_cast<void*>(col)); *out++=i->U; *out=i->V;
#define VERTEXF(X,Y,U,V) out[1]=i->X; out+=2; *out++=i->Y; *out++=-1.0f; col=static_cast<RGBA*>(static_cast<void*>(out)); *col++=i->colour; out=static_cast<float*>(static_cast<void*>(col)); *out++=i->U; *out++=i->V;
#define VERTEXOF(X,Y,U,V) out[1]=(*i).X; out+=2; *out++=(*i).Y; *out++=-1.0f; col=static_cast<RGBA*>(static_cast<void*>(out)); *col++=(*i).colour; out=static_cast<float*>(static_cast<void*>(col)); *out++=(*i).U; *out++=(*i).V;
void TwoDManager::render() {
 RenderSystem* rs=Root::getSingleton().getRenderSystem();
 std::list<Quad>::iterator i,end;
 std::list<Batch> batches;
 if(quads.empty()) return;
 end=quads.end();
 i=quads.begin();
 unsigned need=0;
 for(;i!=end;i++) {if(i->operationType==4) need+=6; else if(i->mode==0) need+=8; else need+=2;}
 unsigned capacity=need;
 if(capacity<120)capacity=120;
 if(vertexBuffer.isNull() || vertexBuffer->getNumVertices()<capacity) {
  if(!vertexBuffer.isNull()){delete renderOp.vertexData; renderOp.vertexData=0; vertexBuffer.setNull();}
  createVertexBuffer(capacity);
  if(vertexBuffer.isNull()) {LogManager::getSingleton().logMessage("TwoDManager: failed to create hardware buffer\n",LML_NORMAL,false);return;}
 }
 float* buffer=static_cast<float*>(vertexBuffer->lock(HardwareBuffer::HBL_DISCARD));
 RGBA* col;
 i=quads.begin();
 Batch batch;
 batch.texture=i->texture; batch.points=i->operationType; batch.mode=i->mode; batch.count=0;
 while(i!=end) {
   unsigned n;
   float* out=buffer;
   if(batch.points==4) {
    VERTEX(left,bottom,u0,v1) VERTEX(right,top,u1,v0) VERTEX(left,top,u0,v0)
    VERTEX(left,bottom,u0,v1) VERTEX(right,top,u1,v0) VERTEX(right,bottom,u1,v1)
    n=6;
   } else {
    VERTEXL(left,top,u0,v0)
    if(batch.mode==0) {
     VERTEXF(right,top,u0,v0) VERTEX(right,top,u0,v0) VERTEX(right,bottom,u0,v0)
     VERTEX(right,bottom,u0,v0) VERTEX(left,bottom,u0,v0) VERTEX(left,bottom,u0,v0) VERTEXO(left,top,u0,v0)
     n=8;
    } else {VERTEXOF(right,bottom,u0,v0) n=2;}
   }
   batch.count+=n;
   buffer=out;
   i++;
   if(i==end || batch.texture!=i->texture || batch.points!=(*i).operationType) {
    batches.push_back(batch);
    if(i!=end) {batch.texture=i->texture; batch.points=i->operationType; batch.mode=i->mode; batch.count=0;}
   }
 }
 vertexBuffer->unlock(); prepareRenderState();
 TexturePtr current;
 std::list<Batch>::iterator last=batches.end();
 renderOp.vertexData->vertexStart=0;
 TexturePtr previous;
 std::list<Batch>::iterator b;
 for(b=batches.begin();b!=last;b++) {
  if(b->texture) {
   current=TextureManager::getSingleton().getByHandle((*b).texture);
   if(current.get()!=previous.get()) {
    rs->_setTexture(0,true,current); rs->_setTextureMatrix(0,Matrix4::IDENTITY);
    LayerBlendModeEx colour,alpha;
    colour.blendType=LBT_COLOUR;
    if(current->getName()=="ft0" || current->getFormat()==PF_A8) {
     colour.source2=LBS_DIFFUSE;colour.operation=LBX_SOURCE2;
    }else {colour.source2=LBS_CURRENT;colour.operation=LBX_SOURCE1;}
    colour.source1=LBS_TEXTURE;
    previous=current;
    alpha.blendType=LBT_ALPHA;alpha.source1=LBS_TEXTURE;alpha.source2=LBS_DIFFUSE;alpha.operation=LBX_SOURCE1;
    rs->_setTextureBlendMode(0,colour);rs->_setTextureBlendMode(0,alpha);
    rs->_setTextureUnitFiltering(0,FO_LINEAR,FO_LINEAR,FO_LINEAR);
   }
  }else {rs->_disableTextureUnit(0);previous.setNull();}
  renderOp.vertexData->vertexCount=b->count;renderOp.operationType=b->points;
  rs->_render(renderOp);renderOp.vertexData->vertexStart+=b->count;
 }
 quads.clear();
}

void TwoDManager::prepareRenderState() {
 LayerBlendModeEx colour,alpha;
 RenderSystem* rs=Root::getSingleton().getRenderSystem();
 colour.blendType=LBT_COLOUR;colour.operation=LBX_SOURCE1;colour.source1=LBS_TEXTURE;
 alpha.blendType=LBT_ALPHA;alpha.operation=LBX_SOURCE1;alpha.source1=LBS_TEXTURE;
 TextureUnitState::UVWAddressingMode address={TextureUnitState::TAM_CLAMP,TextureUnitState::TAM_CLAMP,TextureUnitState::TAM_CLAMP};
 rs->_setWorldMatrix(Matrix4::IDENTITY);
 Matrix4 projection;
 if(flag) {
  Matrix4 view=Matrix4::IDENTITY;
  view[0][3]=-0.5f;view[1][3]=-0.5f;view[2][3]=0;
  view[0][0]=0.5f;view[1][1]=0.5f;view[2][2]=0;
  rs->_setViewMatrix(view);
  rs->_makeOrthoMatrix(Radian(Math::PI*0.5f),static_cast<float>(target->getWidth())/target->getHeight(),1,0,projection);
 }else {
  float nearPlane=target->getHeight()*0.5f;
  target->getHeight();
  Matrix4 view=Matrix4::IDENTITY;
  view.setTrans(Vector3(target->getWidth()*-0.5f,target->getHeight()*-0.5f,0));
  rs->_setViewMatrix(view);
  rs->_makeOrthoMatrix(Radian(Math::PI*0.5f),static_cast<float>(target->getWidth())/target->getHeight(),nearPlane,0,projection);
 }
 rs->_setProjectionMatrix(projection);
 rs->_setTextureMatrix(0,Matrix4::IDENTITY);
 rs->_setTextureCoordSet(0,0);
 rs->_setTextureCoordCalculation(0,TEXCALC_NONE);
 rs->_setTextureUnitFiltering(0,FO_LINEAR,FO_LINEAR,FO_LINEAR);
 rs->_setTextureBlendMode(0,colour);rs->_setTextureBlendMode(0,alpha);
 rs->_setTextureAddressingMode(0,address);
 rs->_disableTextureUnitsFrom(1);
 rs->setLightingEnabled(false);
 rs->_setFog(FOG_NONE,ColourValue::White,1,0,1);
 rs->_setCullingMode(CULL_NONE);
 rs->_setDepthBufferParams(false,false,CMPF_LESS_EQUAL);
 rs->_setColourBufferWriteEnabled(true,true,true,false);
 rs->setShadingType(SO_GOURAUD);
 rs->_setPolygonMode(PM_SOLID);
 rs->unbindGpuProgram(GPT_FRAGMENT_PROGRAM);rs->unbindGpuProgram(GPT_VERTEX_PROGRAM);
 rs->_setSceneBlending(SBF_SOURCE_ALPHA,SBF_ONE_MINUS_SOURCE_ALPHA);
 rs->_setAlphaRejectSettings(CMPF_ALWAYS_PASS,0);
}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<Ogre::TwoDManager::Quad> >;
template class std::allocator<Ogre::TwoDManager::Quad>;
template class std::allocator<std::_List_nod<Ogre::TwoDManager::Quad,std::allocator<Ogre::TwoDManager::Quad> >::_Node *>;
