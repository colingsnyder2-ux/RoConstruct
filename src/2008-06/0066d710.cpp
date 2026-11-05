// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_ad6e4c73030fd9ac.cpp

// Candidate translation unit (score above; library headers required).
// from server: 73% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// Complete 1027-byte RunDragger::moveDragPart; native RunDragger.h supplies identity/layout.
// G3D 6.09 and native Math/Extents contracts; only observed Primitive/Geometry fields.
// Named relative rotation and clamped hit reproduce the measured temporary lifetimes.
#include <stddef.h>
#include <intrin.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Ray.h>
#include <G3D/Plane.h>
namespace boost {namespace detail {
struct sp_counted_base {
 long use_count_,weak_count_;virtual ~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {sp_counted_base*pi_;~shared_count(){if(pi_)pi_->release();}};
}
template<class T>struct shared_ptr {T*px;detail::shared_count pn;T*operator->()const{return px;}};
template<class T>struct weak_ptr {T*px;void*count;shared_ptr<T>lock()const;};
}
namespace RBX {
enum NormalId{NORM_X,NORM_Y,NORM_Z,NORM_X_NEG,NORM_Y_NEG,NORM_Z_NEG,NORM_UNDEFINED};
struct Extents {G3D::Vector3 low,high;Extents(const G3D::Vector3&a,const G3D::Vector3&b):low(a),high(b){}const G3D::Vector3&min()const{return low;}const G3D::Vector3&max()const{return high;}G3D::Plane getPlane(NormalId)const;};
class Face {G3D::Vector3 c0,c1,c2,c3;public:Face():c0(),c1(),c2(),c3(){}const G3D::Vector3&operator[](int i)const;G3D::Vector3&operator[](int i);};
struct Geometry {virtual ~Geometry();G3D::Vector3 gridSize;};
struct Primitive {
 char unobserved[0x9c];Geometry*geometry;
 const G3D::CoordinateFrame&getCoordinateFrame()const;Face getFaceInWorld(NormalId);void setCoordinateFrame(const G3D::CoordinateFrame&);
 const G3D::Vector3&getGridSize()const{return geometry->gridSize;}
 Extents getExtentsLocal()const{G3D::Vector3 half=getGridSize()*.5f;return Extents(-half,half);}
};
struct PartInstance {void setCoordinateFrame(const G3D::CoordinateFrame&);};
struct Workspace;
struct Math {
 static G3D::Vector3 iRoundVector3(const G3D::Vector3&);
 static G3D::Matrix3 alignAxesClosest(const G3D::Matrix3&,const G3D::Matrix3&);static bool orthonormalizeIfNecessary(G3D::Matrix3&);
 static NormalId getClosestObjectNormalId(const G3D::Vector3&,const G3D::Matrix3&);static bool intersectRayPlane(const G3D::Ray&,const G3D::Plane&,G3D::Vector3&);
 static G3D::Vector3 getColumn(const G3D::Matrix3&m,int c){return G3D::Vector3(m[0][c],m[1][c],m[2][c]);}
 static G3D::Vector3 getWorldNormal(NormalId id,const G3D::CoordinateFrame&f){G3D::Vector3 c=getColumn(f.rotation,id%3);return c*(float)(1-(id/3)*2);}
};
class RunDragger {
 struct SnapInfo {Primitive*snap;NormalId surface;G3D::Vector3 hitWorld,lastDragSnap;};
 boost::weak_ptr<PartInstance>dragPart,snapPart;Workspace*workspace;Primitive*drag;G3D::Vector3 dragPointLocal;SnapInfo snapInfo;G3D::Ray mouseRay;NormalId dragSurface;G3D::Vector3 dragHitLocal;
public:bool snapDragPart();
 bool moveDragPart();
};
bool RunDragger::snapDragPart(){
 Face snapFace=snapInfo.snap->getFaceInWorld(snapInfo.surface);
 Face dragFace=drag->getFaceInWorld(dragSurface);
 G3D::Vector3 snapCorner=snapFace[0];
 G3D::Vector3 dragCorner=dragFace[0];
 G3D::CoordinateFrame snapGrid(snapInfo.snap->getCoordinateFrame().rotation,snapCorner);
 G3D::Vector3 dragInGrid=snapGrid.pointToObjectSpace(dragCorner);
 G3D::Vector3 snapped=Math::iRoundVector3(dragInGrid);
 G3D::Vector3 delta=snapGrid.pointToWorldSpace(snapped)-dragCorner;
 G3D::CoordinateFrame goal=drag->getCoordinateFrame();
 goal.translation+=delta;
 dragPart.lock()->setCoordinateFrame(goal);
 if(snapped!=snapInfo.lastDragSnap){snapInfo.lastDragSnap=snapped;return true;}
 return false;
}
}
typedef char frame_size[sizeof(G3D::CoordinateFrame)==48?1:-1];
typedef char ray_size[sizeof(G3D::Ray)==28?1:-1];
typedef char plane_size[sizeof(G3D::Plane)==20?1:-1];
typedef char dragger_size[sizeof(RBX::RunDragger)==0x70?1:-1];

typedef char primitive_geometry_offset[offsetof(RBX::Primitive,geometry)==0x9c?1:-1];
typedef char geometry_size_offset[offsetof(RBX::Geometry,gridSize)==4?1:-1];
typedef char shared_size[sizeof(boost::shared_ptr<RBX::PartInstance>)==8?1:-1];
typedef char weak_size[sizeof(boost::weak_ptr<RBX::PartInstance>)==8?1:-1];


