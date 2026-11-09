// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
#include <new>

struct VDelete { virtual ~VDelete() {} };
struct Own { VDelete* p; ~Own() { delete p; } };
template<int N> struct Dual { void* a; int an, ac; void* b; int bn, bc; ~Dual() { if (b) ::operator delete(b); b=0; bn=0; bc=0; delete[] (char*)a; } };
struct NodeSet { char data[0x20]; ~NodeSet(); };
extern void free_unknown(void*);
struct Vec { void* p; int n, cap; ~Vec() { free_unknown(p); p=0; n=0; cap=0; } };
struct Node40 { char data[0x28]; ~Node40(); };
struct SleepStage {
    virtual ~SleepStage();
    int pad; Own child; int pad2;
    Dual<0> d0; Dual<1> d1; Dual<2> d2; Dual<3> d3; Dual<4> d4; Dual<5> d5; Dual<6> d6; Dual<7> d7;
    char gap[0x10];
    NodeSet s0,s1,s2,s3,s4,s5;
    Vec v0,v1;
    Node40 last;
    Own r0,r1,r2;
};
SleepStage::~SleepStage() {}


