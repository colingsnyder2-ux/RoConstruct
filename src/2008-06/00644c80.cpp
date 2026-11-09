// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: g3d-6.09 roc_espclaude_bfbc69262bc77fbf.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/Vector3.h"
#include "G3D/Color3.h"
#include "G3D/Color4.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Ray.h"
#include "G3D/LineSegment.h"
#include <string>
namespace G3D { class Rect2D; class AABox; class Sphere; class Vector2; template<class T> class ReferenceCountedPointer; }
template<class T> inline T roc_val(T v){return v;}
namespace RBX {
class TextureProxyBase;
class __declspec(novtable) Adorn {
public:
 enum Spacing {PROPORTIONAL_SPACING,FIXED_SPACING};enum XAlign{XALIGN_RIGHT,XALIGN_LEFT,XALIGN_CENTER};enum YAlign{YALIGN_TOP,YALIGN_BASELINE,YALIGN_CENTER,YALIGN_BOTTOM};
 virtual ~Adorn();
 virtual void createTextureProxy()=0;
 virtual void prepareRenderPass()=0;virtual void finishRenderPass()=0;virtual void getViewport()const=0;virtual int getWidth()const=0;virtual int getHeight()const=0;
 virtual void setTexture()=0;virtual void getTextureSize()const=0;
 virtual void line2d()const=0;virtual void outlineRect2d()const=0;virtual void rect2d()const=0;
 virtual void get2DStringBounds()const=0;virtual void drawFont2D()const=0;
 virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame&)=0;virtual void setColor(const G3D::Color4&)=0;
 virtual void box()=0;virtual void sphere()=0;virtual void explosion()=0;
 virtual void cylinderAlongX(float,float,const G3D::Color4&,const G3D::Color4&)=0;virtual void ray(const G3D::Ray&,const G3D::Color4&,float)=0;virtual void lineSegment(const G3D::LineSegment&,const G3D::Color4&,float)=0;
};
class Instance {public: virtual ~Instance();char opaque[0x104-4];Instance*parent; Instance* getParent() const { return parent; }};
class Body {public: char opaque[0x94];G3D::CoordinateFrame frame;void updatePV()const;const G3D::CoordinateFrame&getCoordinateFrame()const{updatePV();return frame;}};
class Humanoid:public Instance {public: Body*getTorsoBody();};
class RayQuery {public: G3D::Vector3 raycast(Instance*,G3D::Ray);};
RayQuery* __cdecl findRayQuery(Instance*);
G3D::LineSegment __cdecl segmentFrom(const G3D::Vector3&,const G3D::Vector3&);
class DrawAdorn {public: static void cylinder(Adorn*,const G3D::CoordinateFrame&,int,float,float,const G3D::Color3&);};
class Name;class Primitive;
class INamed {public: virtual const Name&getName()const=0;};
class HitTestFilter {public: enum Result{STOP_TEST,IGNORE_PRIM,INCLUDE_PRIM};virtual Result filterResult(const Primitive*)const=0;};
namespace HUMAN {
class HumanoidState:public INamed,public HitTestFilter {public: Humanoid*humanoid;bool checkNearObstruction(Adorn*);bool detectClimb(Adorn*);};
bool HumanoidState::detectClimb(Adorn*adorn){
 Body*torso=humanoid->getTorsoBody();if(!torso)return false;
 if(!checkNearObstruction(adorn))return false;
 const G3D::CoordinateFrame&frame=torso->getCoordinateFrame();
 G3D::Vector3 look=frame.lookVector();
 RayQuery*query=findRayQuery(humanoid);
 float firstHeight=0,span=0;bool first=true,inContact=false;
 G3D::Color3 color=G3D::Color3::orange();
 G3D::Vector3 direction=look*2.0f;
 for(int i=1;i<18;++i){
  float height=(float)i*0.1428571492433548f;
  G3D::Vector3 verticalOffset(0,height-2.7f,0);
  G3D::Ray ray;
  G3D::Vector3 origin=frame.translation+verticalOffset;
  ray.origin=origin;ray.direction=direction;
  G3D::Vector3 hit=query->raycast(roc_val(humanoid->parent),ray);
  if((hit-origin).magnitude()<0.7f){if(first){first=false;firstHeight=height;inContact=true;color=G3D::Color3::green();}}
  else{if(inContact){inContact=false;span=height-firstHeight;color=G3D::Color3::red();}}
  if(adorn){
   adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(frame.translation));
   G3D::LineSegment segment=segmentFrom(origin-frame.translation,hit-origin);
   adorn->lineSegment(segment,G3D::Color4(color),1);
  }
 }
 if(firstHeight<2.45f&&span>0&&span<2.45f){
  if(adorn)DrawAdorn::cylinder(adorn,G3D::CoordinateFrame(frame.translation+G3D::Vector3(0,5,0)),1,.2f,1,G3D::Color3::purple());
  return true;
 }
 return false;
}
}
}
