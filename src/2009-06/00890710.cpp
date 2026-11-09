// from server: 100% by EspClaude
// roc 2009-06 00890710  unit: seg_00890000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00890710
//
// 00890710  33c9                 xor ecx, ecx
// 00890712  51                   push ecx
// 00890713  681c4b8e00           push 0x8e4b1c
// 00890718  68044b8e00           push 0x8e4b04
// 0089071d  51                   push ecx
// 0089071e  b850ab6700           mov eax, 0x67ab50
// 00890723  50                   push eax
// 00890724  b920e2a400           mov ecx, 0xa4e220
// 00890729  e8229edeff           call 0x67a550
// 0089072e  68c0bb8900           push 0x89bbc0
// 00890733  e8c393e8ff           call 0x719afb
// 00890738  59                   pop ecx
// 00890739  c3                   ret 
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
static D d(&P::method,"SetMinutesAfterMidnight","minutes",0);
void func_007eedc0(){tail(&e);}