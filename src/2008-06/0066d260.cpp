// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_snapfindnativeed282d76aa28c688.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include "G3D/Vector3.h"
#include "G3D/Array.h"
struct Primitive;
struct Contact {bool adjacent(float);bool colliding(float);};
struct SnapInfo {Primitive*object;int kind;G3D::Vector3 hit,last;SnapInfo():object(0),kind(6),hit(G3D::Vector3::inf()),last(G3D::Vector3::inf()){} };
struct Dragger {SnapInfo query(const G3D::Array<Primitive*>&,bool);SnapInfo filtered(const G3D::Array<Primitive*>&,bool(Contact::*)(float));SnapInfo find(const G3D::Array<Primitive*>&);};
SnapInfo Dragger::find(const G3D::Array<Primitive*>&tried){
 SnapInfo value;
 value=query(tried,true);if(value.object)return value;
 value=filtered(tried,&Contact::adjacent);if(value.object)return value;
 value=filtered(tried,&Contact::colliding);if(value.object)return value;
 value=query(tried,false);if(value.object)return value;
 return SnapInfo();
}
