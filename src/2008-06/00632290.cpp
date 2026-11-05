// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_bodyvelocitylayout6e361dae92280215.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/Vector3.h>
struct B0{virtual ~B0();char pad[12];};
struct B1{virtual ~B1();};
struct B2{virtual ~B2();char pad[8];};
struct B3{virtual ~B3();};
struct B4{virtual ~B4();char pad[28];};
struct B5{virtual ~B5();char pad[28];};
struct B6{virtual ~B6();char pad[28];};
struct B7{virtual ~B7();char pad[28];};
struct B8{virtual ~B8();char pad[28];};
struct B9{virtual ~B9();char pad[104];};
struct B10{virtual ~B10();char pad[4];};
struct B11{virtual ~B11();char pad[12];};
struct Base:B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11{Base(const char*);virtual~Base();};
struct BodyVelocity:Base{float kP;G3D::Vector3 maxForce,velocity,lastForce;BodyVelocity();virtual~BodyVelocity();};
BodyVelocity::BodyVelocity():Base("BodyVelocity"),kP(1250.0f),maxForce(4000.0f,4000.0f,4000.0f),velocity(0.0f,2.0f,0.0f),lastForce(){}
