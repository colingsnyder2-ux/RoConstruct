// from server: 100% by EspClaude
// from server: 55% by EspClaude
// from server: 44% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_espclaude_610f7f834b7be5f0.cpp

// Candidate translation unit (score above; library headers required).
// Native 006832b0. Names are behavioral analogues; owner layout is opaque.
#undef OGRE_NONCLIENT_BUILD

#include <Ogre.h>
#include <list>
using namespace Ogre;
struct Command { float x1,y1,x2,y2,u1,v1,u2,v2; unsigned colour; ResourceHandle texture; RenderOperation::OperationType points; int mode; };
struct Batch {ResourceHandle texture; RenderOperation::OperationType points; int mode; unsigned count;};

// Genuine SDK postfix iterator method; native 00682ad0 is a separate call.
template<> template<> __declspec(noinline)
std::list<Batch>::_Iterator<true> std::list<Batch>::_Iterator<true>::operator++(int) {
    _Myt_iter result = *this;
    ++*this;
    return result;
}

struct CmdIt : std::list<Command>::iterator { __declspec(noinline) Command& get() const { return **this; } };
struct BatchIt : std::list<Batch>::iterator { __declspec(noinline) Batch& get() const { return **this; } };
#define O(i) static_cast<const CmdIt&>(i).get()
#define VERTEXO(X,Y,U,V) *out++=O(i).X; *out++=O(i).Y; *out++=-1.0f; col=static_cast<RGBA*>(static_cast<void*>(out)); *col++=O(i).colour; out=static_cast<float*>(static_cast<void*>(col)); *out++=O(i).U; *out++=O(i).V;
class TwoDManager {public: void draw(); void allocate(unsigned); void setup();};
#define OP (*reinterpret_cast<RenderOperation*>(reinterpret_cast<char*>(this)+0x10))
#define BUFFER (*reinterpret_cast<HardwareVertexBufferSharedPtr*>(reinterpret_cast<char*>(this)+0x24))
#define COMMANDS (*reinterpret_cast<std::list<Command>*>(reinterpret_cast<char*>(this)+0x3c))
#define VERTEX(X,Y,U,V) *out++=i->X; *out++=i->Y; *out++=-1.0f; col=static_cast<RGBA*>(static_cast<void*>(out)); *col++=i->colour; out=static_cast<float*>(static_cast<void*>(col)); *out++=i->U; *out++=i->V;
#define VERTEXL(X,Y,U,V) *out++=i->X; *out++=i->Y; *out++=-1.0f; col=static_cast<RGBA*>(static_cast<void*>(out)); *col++=i->colour; out=static_cast<float*>(static_cast<void*>(col)); *out++=i->U; *out=i->V;
#define VERTEXF(X,Y,U,V) out[1]=i->X; out+=2; *out++=i->Y; *out++=-1.0f; col=static_cast<RGBA*>(static_cast<void*>(out)); *col++=i->colour; out=static_cast<float*>(static_cast<void*>(col)); *out++=i->U; *out++=i->V;
#define VERTEXOF(X,Y,U,V) out[1]=O(i).X; out+=2; *out++=O(i).Y; *out++=-1.0f; col=static_cast<RGBA*>(static_cast<void*>(out)); *col++=O(i).colour; out=static_cast<float*>(static_cast<void*>(col)); *out++=O(i).U; *out++=O(i).V;
void TwoDManager::draw() {
 RenderSystem* rs=Root::getSingleton().getRenderSystem();
 std::list<Command>::iterator i,end;
 std::list<Batch> batches;
 if(COMMANDS.empty()) return;
 end=COMMANDS.end();
 i=COMMANDS.begin();
 unsigned need=0;
 for(;i!=end;i++) {if(i->points==4) need+=6; else if(i->mode==0) need+=8; else need+=2;}
 unsigned capacity=need;
 if(capacity<120)capacity=120;
 if(BUFFER.isNull() || BUFFER->getNumVertices()<capacity) {
  if(!BUFFER.isNull()){delete OP.vertexData; OP.vertexData=0; BUFFER.setNull();}
  allocate(capacity);
  if(BUFFER.isNull()) {LogManager::getSingleton().logMessage("TwoDManager: failed to create hardware buffer\n",LML_NORMAL,false);return;}
 }
 float* buffer=static_cast<float*>(BUFFER->lock(HardwareBuffer::HBL_DISCARD));
 RGBA* col;
 i=COMMANDS.begin();
 Batch batch;
 batch.texture=i->texture; batch.points=i->points; batch.mode=i->mode; batch.count=0;
 while(i!=end) {
   unsigned n;
   float* out=buffer;
   if(batch.points==4) {
    VERTEX(x1,y2,u1,v2) VERTEX(x2,y1,u2,v1) VERTEX(x1,y1,u1,v1)
    VERTEX(x1,y2,u1,v2) VERTEX(x2,y1,u2,v1) VERTEX(x2,y2,u2,v2)
    n=6;
   } else {
    VERTEXL(x1,y1,u1,v1)
    if(batch.mode==0) {
     VERTEXF(x2,y1,u1,v1) VERTEX(x2,y1,u1,v1) VERTEX(x2,y2,u1,v1)
     VERTEX(x2,y2,u1,v1) VERTEX(x1,y2,u1,v1) VERTEX(x1,y2,u1,v1) VERTEXO(x1,y1,u1,v1)
     n=8;
    } else {VERTEXOF(x2,y2,u1,v1) n=2;}
   }
   batch.count+=n;
   buffer=out;
   i++;
   if(i==end || batch.texture!=i->texture || batch.points!=O(i).points) {
    batches.push_back(batch);
    if(i!=end) {batch.texture=i->texture; batch.points=i->points; batch.mode=i->mode; batch.count=0;}
   }
 }
 BUFFER->unlock(); setup();
 TexturePtr current;
 std::list<Batch>::iterator last=batches.end();
 OP.vertexData->vertexStart=0;
 TexturePtr previous;
 std::list<Batch>::iterator b;
 for(b=batches.begin();b!=last;b++) {
  if(b->texture) {
   current=TextureManager::getSingleton().getByHandle(static_cast<const BatchIt&>(b).get().texture);
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
  OP.vertexData->vertexCount=b->count;OP.operationType=b->points;
  rs->_render(OP);OP.vertexData->vertexStart+=b->count;
 }
 COMMANDS.clear();
}
// Force actual SDK list helpers into this object for bounded family checks.
void append(std::list<Batch>* p,const Batch& v){p->push_back(v);}
std::list<Batch>::iterator advance(std::list<Batch>::iterator* p){return (*p)++;}
void destroy(std::list<Batch>* p){p->~list();}

#define TARGET (*reinterpret_cast<RenderTarget**>(reinterpret_cast<char*>(this)+0xc))
#define NORMALIZED (*reinterpret_cast<bool*>(reinterpret_cast<char*>(this)+0xa))
void TwoDManager::setup() {
 LayerBlendModeEx colour,alpha;
 RenderSystem* rs=Root::getSingleton().getRenderSystem();
 colour.blendType=LBT_COLOUR;colour.operation=LBX_SOURCE1;colour.source1=LBS_TEXTURE;
 alpha.blendType=LBT_ALPHA;alpha.operation=LBX_SOURCE1;alpha.source1=LBS_TEXTURE;
 TextureUnitState::UVWAddressingMode address={TextureUnitState::TAM_CLAMP,TextureUnitState::TAM_CLAMP,TextureUnitState::TAM_CLAMP};
 rs->_setWorldMatrix(Matrix4::IDENTITY);
 Matrix4 view,projection;
 if(NORMALIZED) {
  view=Matrix4::IDENTITY;
  view[0][3]=-0.5f;view[1][3]=-0.5f;view[2][3]=0;
  view[0][0]=0.5f;view[1][1]=0.5f;view[2][2]=0;
  rs->_setViewMatrix(view);
  rs->_makeOrthoMatrix(Radian(Math::PI*0.5f),static_cast<float>(TARGET->getWidth())/TARGET->getHeight(),1,0,projection);
 }else {
  float nearPlane=TARGET->getHeight()*0.5f;
  TARGET->getHeight();
  view=Matrix4::IDENTITY;
  view[0][3]=TARGET->getWidth()*-0.5f;view[1][3]=TARGET->getHeight()*-0.5f;view[2][3]=0;
  rs->_setViewMatrix(view);
  rs->_makeOrthoMatrix(Radian(Math::PI*0.5f),static_cast<float>(TARGET->getWidth())/TARGET->getHeight(),nearPlane,0,projection);
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


