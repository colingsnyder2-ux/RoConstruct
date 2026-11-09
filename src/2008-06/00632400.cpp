// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_bodyangularbases_6f32e8cc600840ea.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector3.h>
struct A{virtual ~A();char data[12];};
struct B{virtual ~B();};
struct C{virtual ~C();char data[8];};
struct D{virtual ~D();};
struct E{virtual ~E();char data[28];};
struct F{virtual ~F();char data[28];};
struct G{virtual ~G();char data[28];};
struct H{virtual ~H();char data[28];};
struct I{virtual ~I();char data[28];};
struct J{virtual ~J();char data[104];};
struct K{virtual ~K();char data[4];};
struct L{virtual ~L();char data[12];};
struct Base:A,B,C,D,E,F,G,H,I,J,K,L {Base(const char*);};
struct S:Base{float p;G3D::Vector3 force,velocity,last;S();virtual ~S();};
S::S():Base("BodyAngularVelocity"),p(1250.0f),force(4000.0f,4000.0f,4000.0f),velocity(0.0f,2.0f,0.0f),last(){}
