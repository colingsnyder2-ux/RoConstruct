// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_claudeM_9176ce383e321941.cpp

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
struct Geometry {virtual ~Geometry();G3D::Vector3 gridSize;};
struct Primitive {
 char unobserved[0x9c];Geometry*geometry;
 const G3D::CoordinateFrame&getCoordinateFrame()const;void setCoordinateFrame(const G3D::CoordinateFrame&);
 const G3D::Vector3&getGridSize()const{return geometry->gridSize;}
 Extents getExtentsLocal()const{G3D::Vector3 half=getGridSize()*.5f;return Extents(-half,half);}
};
struct PartInstance {void setCoordinateFrame(const G3D::CoordinateFrame&);};
struct Workspace;
struct Math {
 static G3D::Matrix3 alignAxesClosest(const G3D::Matrix3&,const G3D::Matrix3&);static bool orthonormalizeIfNecessary(G3D::Matrix3&);
 static NormalId getClosestObjectNormalId(const G3D::Vector3&,const G3D::Matrix3&);static bool intersectRayPlane(const G3D::Ray&,const G3D::Plane&,G3D::Vector3&);
 static G3D::Vector3 getColumn(const G3D::Matrix3&m,int c){return G3D::Vector3(m[0][c],m[1][c],m[2][c]);}
 static G3D::Vector3 getWorldNormal(NormalId id,const G3D::CoordinateFrame&f){const G3D::Matrix3&m=f.rotation;int c=id%3;int s=1-(id/3)*2;return s*G3D::Vector3(m[0][c],m[1][c],m[2][c]);}
};
class RunDragger {
 struct SnapInfo {Primitive*snap;NormalId surface;G3D::Vector3 hitWorld,lastDragSnap;};
 boost::weak_ptr<PartInstance>dragPart,snapPart;Workspace*workspace;Primitive*drag;G3D::Vector3 dragPointLocal;SnapInfo snapInfo;G3D::Ray mouseRay;NormalId dragSurface;G3D::Vector3 dragHitLocal;
 bool snapDragPart();
public:bool moveDragPart();
};
bool RunDragger::moveDragPart(){
 const G3D::CoordinateFrame&snapFrame=snapInfo.snap->getCoordinateFrame();
 G3D::Vector3 normal=Math::getWorldNormal(snapInfo.surface,snapFrame);
 G3D::Matrix3 dragRotation=drag->getCoordinateFrame().rotation;
 G3D::Matrix3 aligned=Math::alignAxesClosest(dragRotation,snapFrame.rotation);
 G3D::Matrix3 relative=dragRotation.transpose()*aligned;
 G3D::Matrix3 rotation=snapFrame.rotation*relative.transpose();
 Math::orthonormalizeIfNecessary(rotation);
 G3D::CoordinateFrame goal(rotation,drag->getCoordinateFrame().translation);
 drag->setCoordinateFrame(goal);
 dragSurface=Math::getClosestObjectNormalId(-normal,rotation);
 G3D::Ray ray=G3D::Ray::fromOriginAndDirection(goal.pointToWorldSpace(dragPointLocal),mouseRay.direction);
 G3D::Ray rayLocal=goal.toObjectSpace(ray);
 Extents extents=drag->getExtentsLocal();
 G3D::Plane plane=extents.getPlane(dragSurface);
 Math::intersectRayPlane(rayLocal,plane,dragHitLocal);
 G3D::Vector3 clamped=dragHitLocal.clamp(extents.min()*100.0f,extents.max()*100.0f);
 goal.translation=(goal.translation-goal.pointToWorldSpace(clamped))+snapInfo.hitWorld;
 dragPart.lock()->setCoordinateFrame(goal);
 return snapDragPart();
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

