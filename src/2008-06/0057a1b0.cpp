// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_b7e4c02ad8531df9.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Rect.h"
#include <G3D/Color4.h>
#include <G3D/Rect2D.h>
#define _CPPUNWIND 1
#include <string>
#include <vector>
#include <stddef.h>
#include <intrin.h>
namespace boost {namespace detail {
struct sp_counted_base {virtual ~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}long use_count_,weak_count_;void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}};
struct shared_count {sp_counted_base*pi_;shared_count():pi_(0){}shared_count(const shared_count&r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}~shared_count(){if(pi_)pi_->release();}};
}
template<class T>struct shared_ptr {T*px;detail::shared_count pn;shared_ptr():px(0),pn(){}shared_ptr(const shared_ptr&r):px(r.px),pn(r.pn){}T*get()const{return px;}T&operator*()const{return *px;}T*operator->()const{return px;}};
}
namespace G3D {
struct Vector3 {float x,y,z;};
struct CoordinateFrame;struct AABox;struct Sphere;struct Ray;struct LineSegment;
template<class T>struct ReferenceCountedPointer {T*pointer;};
}
namespace RBX {
struct TextureProxyBase;struct Adorn;struct Name;struct XmlElement;struct IReferenceBinder;struct ServiceProvider;struct AncestorChanged;struct PropertyChanged;struct GuiEvent;
template<class T>struct CopyOnWrite {boost::shared_ptr<T>object;const T*operator->()const{return object.get();}};
class Instance {public:
 virtual ~Instance();virtual void setName(const std::string&);
 virtual bool askAddChild(const Instance*)const;virtual bool askSetParent(const Instance*)const;
 virtual void onAncestorChanged(const AncestorChanged&);virtual void onDescendentAdded(Instance*);virtual void onDescendentRemoving(const boost::shared_ptr<Instance>&);
 virtual void onChildAdded(Instance*);virtual void onChildRemoving(Instance*);virtual void onChildRemoved(Instance*);virtual void onLastChildRemoved();
 virtual void readProperty(const XmlElement*,IReferenceBinder&);virtual void onServiceProvider(const ServiceProvider*,const ServiceProvider*);virtual boost::shared_ptr<Instance>createChild(const Name&);virtual XmlElement*write();virtual void onChildChanged(Instance*,const PropertyChanged&);
 char opaque[0x108-4];CopyOnWrite<std::vector<boost::shared_ptr<Instance> > >children;std::string name;bool archivable;
 unsigned numChildren()const;
};
struct Adorn {
 enum Spacing{PROPORTIONAL_SPACING,FIXED_SPACING};enum XAlign{XALIGN_RIGHT,XALIGN_LEFT,XALIGN_CENTER};enum YAlign{YALIGN_TOP,YALIGN_BASELINE,YALIGN_CENTER,YALIGN_BOTTOM};
 virtual ~Adorn();
 virtual G3D::ReferenceCountedPointer<TextureProxyBase>createTextureProxy(const std::string&)=0;
 virtual void prepareRenderPass()=0;virtual void finishRenderPass()=0;virtual G3D::Rect2D getViewport()const=0;virtual int getWidth()const=0;virtual int getHeight()const=0;
 virtual void setTexture(int,G3D::ReferenceCountedPointer<TextureProxyBase>)=0;virtual G3D::Rect2D getTextureSize(G3D::ReferenceCountedPointer<TextureProxyBase>)const=0;
 virtual void line2d(const G3D::Vector2&,const G3D::Vector2&,const G3D::Color4&)const=0;
 virtual void outlineRect2d(const G3D::Rect2D&,float,const G3D::Color4&)const=0;virtual void rect2d(const G3D::Rect2D&,const G3D::Color4&)const=0;
 virtual G3D::Vector2 get2DStringBounds(const std::string&,double,Spacing)const=0;
 virtual G3D::Vector2 drawFont2D(const std::string&,const G3D::Vector2&,double,const G3D::Color4&,const G3D::Color4&,XAlign,YAlign,Spacing)const=0;
 virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame&)=0;virtual void setColor(const G3D::Color4&)=0;
 virtual void box(const G3D::AABox&,const G3D::Color4&,const G3D::Color4&)=0;virtual void sphere(const G3D::Sphere&,const G3D::Color4&,const G3D::Color4&)=0;virtual void explosion(const G3D::Sphere&,const G3D::Color4&,const G3D::Color4&)=0;
 virtual void cylinderAlongX(float,float,const G3D::Color4&,const G3D::Color4&)=0;virtual void ray(const G3D::Ray&,const G3D::Color4&,float)=0;virtual void lineSegment(const G3D::LineSegment&,const G3D::Color4&,float)=0;virtual void axes(const G3D::Color4&,const G3D::Color4&,const G3D::Color4&,float)=0;virtual void quad(const G3D::Vector3&,const G3D::Vector3&,const G3D::Vector3&,const G3D::Vector3&,const G3D::Color4&)=0;
};
enum SelectState{SELECT_NONE};
class IRenderable {public:int index2d,index3d;void*bucket;virtual bool shouldRender2d()const=0;virtual bool shouldRender3dAdorn()const=0;virtual void render2d(Adorn*)=0;virtual void render3dAdorn(Adorn*)=0;virtual void render3dSelect(Adorn*,SelectState)=0;};
struct GuiTarget;struct GuiResponse {int response;GuiTarget*target;};
struct GuiTarget {virtual GuiResponse process(const GuiEvent&)=0;};
struct GuiItem:Instance,GuiTarget {
 virtual void onLoseFocus();virtual bool canLoseFocus();virtual G3D::Vector2 getPosition()const;virtual G3D::Vector2 getChildPosition(const GuiItem*)const;virtual int getFontSize()const;virtual bool isVisible()const;virtual std::string getTitle();virtual G3D::Vector2 getSize()const;virtual void render2d(Adorn*);
};
struct GuiRoot:GuiItem {virtual void render2d(Adorn*);static void render2dItem(Adorn*,GuiItem*);};
struct Evaluator {virtual std::string evaluate(const std::string&)const=0;};
struct IMetric {virtual ~IMetric();virtual std::string getMetric(const std::string&)const=0;};
struct RunService;struct RunTransition {int oldState,newState;};
template<class C,class E>struct Listener {virtual void onEvent(const C*,E)=0;virtual ~Listener();};
struct ContentId {std::string id;const Name*mimeTypePtr;static ContentId fromAssets(const char*);};
struct TextureId:ContentId {TextureId(const ContentId&c):ContentId(c){}};
struct UserInputBase {
 enum WrapMode{WRAP_AUTO,WRAP_CENTER};
 virtual G3D::Vector2 getCursorPosition()=0;virtual G3D::ReferenceCountedPointer<TextureProxyBase>getGameCursor(Adorn*);
 virtual void setWrapMode(WrapMode)=0;virtual WrapMode getWrapMode()const=0;virtual void centerCursor()=0;virtual bool keyDown(int)const=0;virtual void setKeyState(int,bool)=0;virtual void setCursorId(Adorn*,const TextureId&);
 void renderGameCursor(Adorn*);
};
struct ControllerService {char opaque[0x130];UserInputBase*hardwareDevice;};
struct WorkspacePrefix:Instance {char opaqueWorkspace[0x1a0-sizeof(Instance)];};
struct Workspace:WorkspacePrefix,IRenderable {void setCursor(Adorn*);};
namespace Network {
struct Player:Instance {};
struct Players {char opaque[0x1a0];boost::shared_ptr<Player>localPlayer;static Player*findLocalPlayer(const Instance*);};
}
struct DataModelPrefix:Instance {char opaqueDataModel[0x1f4-sizeof(Instance)];};
struct DataModel:DataModelPrefix,Evaluator,Listener<RunService,RunTransition> {
 boost::shared_ptr<Instance>localBackpack;boost::shared_ptr<Workspace>workspace;boost::shared_ptr<RunService>runService;boost::shared_ptr<Instance>starterPack;boost::shared_ptr<GuiRoot>guiRoot,guiHooks;
 GuiTarget*guiTarget;bool forceArrowCursor;std::string uiMessage;int drawId;IMetric*tempMetric;bool dirty;bool renderEnabled;
 Network::Players*getPlayers();ControllerService*getControllerService();
 void renderPass2d(Adorn*,IMetric*);
 static const G3D::Color4&messageBackground();
};
void DataModel::renderPass2d(Adorn*adorn,IMetric*metric){
 if(!renderEnabled)return;
 if(!adorn)return;
 if(!metric)return;
 tempMetric=metric;
 workspace->render2d(adorn);
 if(Network::Players::findLocalPlayer(this))GuiRoot::render2dItem(adorn,static_cast<GuiItem*>(localBackpack.get()));
 else GuiRoot::render2dItem(adorn,static_cast<GuiItem*>(starterPack.get()));
 guiRoot->render2d(adorn);
 Network::Players*players=getPlayers();
 Network::Player*player=players->localPlayer.get();
 if(player){
  for(unsigned i=0;i<player->numChildren();++i){
   Instance*child=player->children->operator[](i).get();
   IRenderable*renderable=dynamic_cast<IRenderable*>(child);
   if(renderable)renderable->render2d(adorn);
  }
 }
 std::string message;
 if(uiMessage=="[[[progress]]]"){
  std::string joints("numJoints");
  std::string primitives("numPrimitives");
  message="Bricks: "+evaluate(primitives)+"   Connectors: "+evaluate(joints);
 }else message=uiMessage;
 if(message.size()>0){
  G3D::Rect2D viewport=adorn->getViewport();
  int width=(int)viewport.width();
  G3D::Vector2 center=viewport.center();
  int fontSize=(int)(width*.02f);
  float halfWidth=viewport.width()*.3f;
  G3D::Vector2 halfSize(halfWidth,halfWidth*.3f);
  Rect rectangle(center-halfSize,center+halfSize);
  adorn->rect2d(rectangle.toRect2D(),messageBackground());
  adorn->outlineRect2d(rectangle.toRect2D(),2.0f,G3D::Color4(G3D::Color3::white()));
  adorn->drawFont2D(message,center,(double)fontSize,G3D::Color4(G3D::Color3::black()),G3D::Color4::zero(),Adorn::XALIGN_CENTER,Adorn::YALIGN_CENTER,Adorn::PROPORTIONAL_SPACING);
 }
 UserInputBase*input=getControllerService()->hardwareDevice;
 if(input){
  if(forceArrowCursor)input->setCursorId(adorn,ContentId::fromAssets("Textures\\ArrowCursor.png"));
  else workspace->setCursor(adorn);
  input->renderGameCursor(adorn);
 }
 tempMetric=0;
}
}
typedef char instance_size[sizeof(RBX::Instance)==0x130?1:-1];
typedef char children_offset[offsetof(RBX::Instance,children)==0x108?1:-1];
typedef char model_workspace_offset[offsetof(RBX::DataModel,workspace)==0x204?1:-1];
typedef char model_message_offset[offsetof(RBX::DataModel,uiMessage)==0x234?1:-1];
typedef char model_metric_offset[offsetof(RBX::DataModel,tempMetric)==0x254?1:-1];
typedef char model_enabled_offset[offsetof(RBX::DataModel,renderEnabled)==0x259?1:-1];
typedef char texture_size[sizeof(RBX::TextureId)==32?1:-1];

typedef char input_offset[offsetof(RBX::ControllerService,hardwareDevice)==0x130?1:-1];
typedef char local_player_offset[offsetof(RBX::Network::Players,localPlayer)==0x1a0?1:-1];
typedef char root_offset[offsetof(RBX::DataModel,guiRoot)==0x21c?1:-1];
typedef char cursor_offset[offsetof(RBX::DataModel,forceArrowCursor)==0x230?1:-1];
typedef char renderable_offset[offsetof(RBX::Workspace,index2d)==0x1a4?1:-1];
typedef char vector_extent[sizeof(G3D::Vector2)==8?1:-1];
typedef char rectangle_extent[sizeof(G3D::Rect2D)==16?1:-1];
typedef char color_extent[sizeof(G3D::Color4)==16?1:-1];
