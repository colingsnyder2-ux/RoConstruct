// from server: 100% by EspClaude
// roc 2009-06 0088c130  unit: seg_00880000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0088c130
//
// 0088c130  33c9                 xor ecx, ecx
// 0088c132  51                   push ecx
// 0088c133  68d0d88b00           push 0x8bd8d0
// 0088c138  68f0718d00           push 0x8d71f0
// 0088c13d  51                   push ecx
// 0088c13e  b8a0a05f00           mov eax, 0x5fa0a0
// 0088c143  50                   push eax
// 0088c144  b9f0a8a400           mov ecx, 0xa4a8f0
// 0088c149  e8d2e0d6ff           call 0x5fa220
// 0088c14e  6820958900           push 0x899520
// 0088c153  e8a3d9e8ff           call 0x719afb
// 0088c158  59                   pop ecx
// 0088c159  c3                   ret 
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
static D d(&P::method,"GetService","name",0);
void func_007eedc0(){tail(&e);}