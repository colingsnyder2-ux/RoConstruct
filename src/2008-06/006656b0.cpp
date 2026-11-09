// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_effectspherehitnative9e1eb2582adc1485.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include "util/Extents.h"
#include <G3D/Ray.h>
#include <G3D/Sphere.h>
#include <G3D/CollisionDetection.h>
float handleRadius(const G3D::Vector3&,const G3D::Vector3&);
bool testEffect(const RBX::Extents& box,const G3D::CoordinateFrame& frame,const G3D::Ray& ray,G3D::Vector3& result,int& face){for(int i=0;i<6;++i){G3D::Vector3 center=box.faceCenter((RBX::NormalId)i);center+=RBX::normalIdToVector3((RBX::NormalId)i)*3.f;G3D::Vector3 point=frame.pointToWorldSpace(center);float radius=handleRadius(ray.origin,point);G3D::Vector3 hit;bool found=G3D::CollisionDetection::collisionTimeForMovingPointFixedSphere(ray.origin,ray.direction,G3D::Sphere(point,radius),hit)!=G3D::inf();if(found){face=i;result=point;return true;}}return false;}
