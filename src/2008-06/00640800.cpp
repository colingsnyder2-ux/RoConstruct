// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// Complete 821-byte measured mouse-drag update; AxisDragUpdate is a descriptive label.
// UIEvent/ServiceClient/MegaDragger and G3D operations follow native project headers.
// SelectionView and createSelectionService name the observed transport ABI only.
// Native ServiceClient body proves its stack object does not escape to the service.
#include <memory>
#include <vector>
#include <intrin.h>
#include <math.h>
#include <stddef.h>
namespace G3D {
struct Vector2int16 {short x,y;};
struct Vector2 {float x,y;Vector2(float a,float b):x(a),y(b){}Vector2(const Vector2int16&v):x(v.x),y(v.y){}Vector2 operator-(const Vector2&v)const{return Vector2(x-v.x,y-v.y);}float length()const{return (float)sqrt(x*x+y*y);}};
struct Vector3 {float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}
 Vector3 operator-(const Vector3&v)const{return Vector3(x-v.x,y-v.y,z-v.z);}Vector3 operator+(const Vector3&v)const{return Vector3(x+v.x,y+v.y,z+v.z);}
 bool operator!=(const Vector3&v)const{return x!=v.x||y!=v.y||z!=v.z;}
 static const Vector3&zero(){static Vector3 v(0,0,0);return v;}
};
struct Ray {Vector3 origin,direction;virtual ~Ray(){}};
}
namespace boost {namespace detail {
struct sp_counted_base {virtual ~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}long use_count_,weak_count_;void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}};
struct shared_count {sp_counted_base*pi_;shared_count():pi_(0){}shared_count(const shared_count&r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
 shared_count&operator=(const shared_count&r){sp_counted_base*tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
 ~shared_count(){if(pi_)pi_->release();}};
}
template<class T>struct shared_ptr {T*px;detail::shared_count pn;shared_ptr():px(0){}shared_ptr&operator=(const shared_ptr&r){px=r.px;pn=r.pn;return *this;}T*get()const{return px;}};
}
namespace RBX {
struct UIEvent {int eventType;void*userInput;G3D::Vector2int16 mousePosition,mouseDelta,windowSize;};
struct PartInstance;struct PVInstance;struct RootInstance;
// Descriptive selection transport: items offset is observed at this call site.
struct SelectionView {char unobserved[0x13c];std::vector<PVInstance*>items;};
template<class T>T*createSelectionService(RootInstance*);
template<class T>boost::shared_ptr<T>shared_from(T*);
template<class T>struct ServiceClient {RootInstance*context;mutable boost::shared_ptr<T>service;ServiceClient(RootInstance*c):context(c){}T*createService(bool)const{if(service.get()==0)service=shared_from<T>(createSelectionService<T>(context));return service.get();}T*operator->()const{return createService(true);}};
struct MegaDragger {
 char unobserved[44];
 MegaDragger(PartInstance*,const std::vector<PVInstance*>&,RootInstance*);~MegaDragger();void startDragging();void alignAndCleanParts();bool anyDragPartAlive();void continueDragging();G3D::Vector3 safeMoveAlongLine(const G3D::Vector3&);
};
struct Math {static G3D::Vector3 closestPointOnRay(const G3D::Ray&,const G3D::Ray&);static G3D::Vector3 toGrid(const G3D::Vector3&,const G3D::Vector3&);};
// Descriptive member name; all accessed offsets come from the complete target.
struct AxisDragUpdate {
 char unobserved[0x18];RootInstance*workspace;char unobserved1c[4];std::auto_ptr<MegaDragger>megaDragger;char unobserved24[0x40-0x24];bool dragging;G3D::Vector2int16 downPoint;char unobserved46[2];G3D::Ray axisRay;char unobserved64[4];G3D::Vector3 lastHit;
 G3D::Ray getSearchRay(const UIEvent&)const;
 static const G3D::Vector3&grid(){static G3D::Vector3 v(1.0f,0.4f,1.0f);return v;}
 void onMouseMove(const UIEvent&);
};
void AxisDragUpdate::onMouseMove(const UIEvent&event){
 if(!dragging&&(G3D::Vector2(event.mousePosition)-G3D::Vector2(downPoint)).length()>4.0f){
  ServiceClient<SelectionView>selection(workspace);
  megaDragger.reset(new MegaDragger(0,selection->items,workspace));
  megaDragger->startDragging();megaDragger->alignAndCleanParts();dragging=true;
 }
 if(dragging&&megaDragger->anyDragPartAlive()){
  G3D::Vector3 hit=Math::closestPointOnRay(axisRay,getSearchRay(event));
  hit=Math::toGrid(hit,grid());
  G3D::Vector3 delta=Math::toGrid(hit-lastHit,grid());
  if(delta!=G3D::Vector3::zero()){
   megaDragger->continueDragging();
   G3D::Vector3 moved=megaDragger->safeMoveAlongLine(delta);
   if(moved!=G3D::Vector3::zero())lastHit=Math::toGrid(lastHit+moved,grid());
  }
 }
}
}
typedef char ray_extent[sizeof(G3D::Ray)==28?1:-1];
typedef char dragger_extent[sizeof(RBX::MegaDragger)==44?1:-1];
typedef char selection_extent[sizeof(RBX::ServiceClient<RBX::SelectionView>)==12?1:-1];
typedef char event_position[offsetof(RBX::UIEvent,mousePosition)==8?1:-1];
typedef char dragger_offset[offsetof(RBX::AxisDragUpdate,megaDragger)==0x20?1:-1];
typedef char dragging_offset[offsetof(RBX::AxisDragUpdate,dragging)==0x40?1:-1];
typedef char ray_offset[offsetof(RBX::AxisDragUpdate,axisRay)==0x48?1:-1];
typedef char hit_offset[offsetof(RBX::AxisDragUpdate,lastHit)==0x68?1:-1];

typedef char down_point_offset[offsetof(RBX::AxisDragUpdate,downPoint)==0x42?1:-1];
typedef char selection_items_offset[offsetof(RBX::SelectionView,items)==0x13c?1:-1];
