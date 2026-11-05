// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_bodyenergydotorder186f0dd43e5c319f.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/Matrix3.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector3.h>
G3D::Matrix3 momentToWorldSpace(const G3D::Matrix3&,const G3D::Matrix3&);
struct Body {char prefix[0x68];G3D::Matrix3 inertia;float mass;int state;G3D::CoordinateFrame position;G3D::Vector3 linear,rotational;
void updatePV()const;
G3D::Matrix3 getIBody()const{return inertia;}
const G3D::CoordinateFrame&getPosition()const{updatePV();return position;}
G3D::Matrix3 getIWorld()const{return momentToWorldSpace(getIBody(),getPosition().rotation);}
float kineticEnergy()const;};
inline G3D::Vector3 multiply(const G3D::Matrix3&m,const G3D::Vector3&v){G3D::Vector3 out;for(int r=0;r<3;++r)out[r]=m[r][1]*v[1]+m[r][0]*v[0]+m[r][2]*v[2];return out;}
float Body::kineticEnergy()const{return (rotational.dot(multiply(getIWorld(),rotational))+linear.dot(linear)*mass)*0.5f;}
