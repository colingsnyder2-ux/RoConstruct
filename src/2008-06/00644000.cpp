// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// Minimal target-backed ABI views; unused native APIs are omitted.
// updateFloor is a descriptive name for the complete measured member routine.
// G3D 6.09 supplies Ray/Vector3/CoordinateFrame; Boost 1.34.1 supplies nested counts.
#include <stddef.h>
#include <intrin.h>
namespace G3D {
struct Vector3 {
 float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}
 Vector3 operator-()const{return Vector3(-x,-y,-z);}Vector3 operator*(float f)const{return Vector3(x*f,y*f,z*f);}
 static const Vector3&unitY(){static Vector3 v(0,1,0);return v;}
};
struct Matrix3 {float elt[3][3];};
struct CoordinateFrame {Matrix3 rotation;Vector3 translation;
 Vector3 pointToWorldSpace(const Vector3&v)const{return Vector3(rotation.elt[0][0]*v.x+rotation.elt[0][1]*v.y+rotation.elt[0][2]*v.z+translation.x,rotation.elt[1][0]*v.x+rotation.elt[1][1]*v.y+rotation.elt[1][2]*v.z+translation.y,rotation.elt[2][0]*v.x+rotation.elt[2][1]*v.y+rotation.elt[2][2]*v.z+translation.z);}
};
struct Ray {
 private:Ray(const Vector3&p,const Vector3&d){origin=p;direction=d;}
 public:Vector3 origin,direction;Ray():origin(Vector3(0,0,0)),direction(Vector3(0,0,0)){}virtual ~Ray(){}
 static __declspec(noinline) Ray fromOriginAndDirection(const Vector3&p,const Vector3&d){return Ray(p,d);}
};
}
namespace boost {namespace detail {
struct sp_counted_base {
 long use_count_,weak_count_;virtual ~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}
 void add_ref_copy(){_InterlockedIncrement(&use_count_);}void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {
 sp_counted_base*pi_;shared_count():pi_(0){}shared_count(const shared_count&r):pi_(r.pi_){if(pi_)pi_->add_ref_copy();}~shared_count(){if(pi_)pi_->release();}
 shared_count&operator=(const shared_count&r){sp_counted_base*tmp=r.pi_;if(tmp!=pi_){if(tmp)tmp->add_ref_copy();if(pi_)pi_->release();pi_=tmp;}return *this;}
};
}
template<class T>struct shared_ptr {
 T*px;detail::shared_count pn;shared_ptr():px(0),pn(){}shared_ptr&operator=(const shared_ptr&r){px=r.px;pn=r.pn;return *this;}T*get()const{return px;}bool operator!()const{return px==0;}
};
}
namespace RBX {
struct Name;struct Primitive;
struct INamed {virtual const Name&getName()const=0;};
struct HitTestFilter {enum Result{STOP_TEST,IGNORE_PRIM,INCLUDE_PRIM};virtual Result filterResult(const Primitive*)const=0;};
struct Geometry {virtual ~Geometry();G3D::Vector3 gridSize;const G3D::Vector3&getGridSize()const{return gridSize;}};
struct Primitive {char opaque[0x9c];Geometry*geometry;const G3D::CoordinateFrame&getCoordinateFrame()const;const G3D::Vector3&getGridSize()const{return geometry->getGridSize();}};
struct Body;struct PartInstance;
struct Humanoid {Body*getTorsoBody();Primitive*getTorsoPrimitive()const;Primitive*getLeftLegPrimitive();Primitive*getRightLegPrimitive();};
namespace HUMAN {
struct HumanoidState:INamed,HitTestFilter {
 Humanoid*humanoid;char opaque0c[0x24-0xc];boost::shared_ptr<PartInstance>floorPart;G3D::Vector3 floorTouchInWorld;
 boost::shared_ptr<PartInstance>tryFloor(const G3D::Ray&,float);void updateFloor();
};
void HumanoidState::updateFloor(){
 if(!humanoid->getTorsoBody())return;
 const G3D::CoordinateFrame&frame=humanoid->getTorsoPrimitive()->getCoordinateFrame();
 G3D::Vector3 halfSize=humanoid->getTorsoPrimitive()->getGridSize()*.5f;
 float maxDistance=1.0f;float factor=!!floorPart?1.5f:1.1f;
 if(humanoid->getLeftLegPrimitive())maxDistance=humanoid->getLeftLegPrimitive()->getGridSize().y*factor+1.0f;
 else if(humanoid->getRightLegPrimitive())maxDistance=humanoid->getRightLegPrimitive()->getGridSize().y*factor+1.0f;
 G3D::Vector3 origin=frame.pointToWorldSpace(G3D::Vector3(0,-halfSize.y,0));
 G3D::Ray ray=G3D::Ray::fromOriginAndDirection(origin,-G3D::Vector3::unitY());
 if((floorPart=tryFloor(ray,maxDistance)).get()!=0)return;
 for(int x=-1;x<=1;x+=2)for(int z=-1;z<=1;z+=2){
  origin=frame.pointToWorldSpace(G3D::Vector3(x*halfSize.x,-halfSize.y,z*halfSize.z));
  ray=G3D::Ray::fromOriginAndDirection(origin,-G3D::Vector3::unitY());
  if((floorPart=tryFloor(ray,maxDistance)).get()!=0)return;
 }
}
}
}
typedef char ray_size[sizeof(G3D::Ray)==28?1:-1];
typedef char frame_size[sizeof(G3D::CoordinateFrame)==48?1:-1];
typedef char shared_size[sizeof(boost::shared_ptr<RBX::PartInstance>)==8?1:-1];
typedef char primitive_geometry[offsetof(RBX::Primitive,geometry)==0x9c?1:-1];
typedef char geometry_size[offsetof(RBX::Geometry,gridSize)==4?1:-1];
typedef char state_humanoid[offsetof(RBX::HUMAN::HumanoidState,humanoid)==8?1:-1];
typedef char state_floor[offsetof(RBX::HUMAN::HumanoidState,floorPart)==0x24?1:-1];
typedef char state_touch[offsetof(RBX::HUMAN::HumanoidState,floorTouchInWorld)==0x2c?1:-1];


