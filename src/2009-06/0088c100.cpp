// from server: 100% by EspClaude
// roc 2009-06 0088c100  unit: seg_00880000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0088c100
//
// 0088c100  33c9                 xor ecx, ecx
// 0088c102  51                   push ecx
// 0088c103  68d0d88b00           push 0x8bd8d0
// 0088c108  68e8718d00           push 0x8d71e8
// 0088c10d  51                   push ecx
// 0088c10e  b8a0a05f00           mov eax, 0x5fa0a0
// 0088c113  50                   push eax
// 0088c114  b938a9a400           mov ecx, 0xa4a938
// 0088c119  e802e1d6ff           call 0x5fa220
// 0088c11e  6870958900           push 0x899570
// 0088c123  e8d3d9e8ff           call 0x719afb
// 0088c128  59                   pop ecx
// 0088c129  c3                   ret 
// copied from an identical function in another client (function ??__Ed@@YAXXZ)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE2 /fp:fast
#pragma pointers_to_members(full_generality, multiple_inheritance)
struct B1{virtual void b();}; struct B2{virtual void c();}; inline void B1::b(){} inline void B2::c(){}
struct P:B1,B2{__declspec(noinline) void method();}; inline void P::method(){}
extern "C" void helper(void(P::*)(),const char*,const char*,int,void*);
struct D{D(void(P::*)(),const char*,const char*,int);~D();};
__declspec(noinline) D::D(void(P::*f)(),const char*n,const char*c,int s){helper(f,n,c,s,this);} D::~D(){}
extern "C" void tail(void*); extern int e;
static D d(&P::method,"service","name",0);
void func_007eedc0(){tail(&e);}