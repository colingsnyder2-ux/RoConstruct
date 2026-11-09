// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_menuctororderedfloats398eef2262ba1c93.cpp

// Candidate translation unit (score above; library headers required).

#include <G3D/Vector2.h>
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
struct B10{virtual ~B10();char pad[8];};
struct Base:B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10 {char remaining[32];Base();virtual ~Base();};
struct Menu:Base{int a,b;volatile float c,d;Menu(int,int,float,float);virtual~Menu();};
Menu::Menu(int av,int bv,float cv,float dv):Base(),a(av){b=bv;c=cv;d=dv;}
