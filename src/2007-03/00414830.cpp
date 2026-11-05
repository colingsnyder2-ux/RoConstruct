// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B { void ctor(); };
extern int g0,g1,g2,g3,g4,g5,g6,g7,g8,g9;
struct X : B { void* a; void* b; char p0[4]; void* c; char p1[8]; void* d; void* e; char p2[0x14]; void* f; char p3[0x14]; void* g; char p4[0x14]; void* h; char p5[0x14]; void* i; char p6[0x14]; void* j; X(); };
X::X() { ctor(); a=&g0; b=&g1; c=&g2; d=&g3; e=&g4; f=&g5; g=&g6; h=&g7; i=&g8; j=&g9; }
