// from server: 100% by EspClaude
// roc 2009-06 00887820  unit: seg_00880000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00887820
//
// 00887820  33c9                 xor ecx, ecx
// 00887822  51                   push ecx
// 00887823  68e84e8c00           push 0x8c4ee8
// 00887828  6878548c00           push 0x8c5478
// 0088782d  51                   push ecx
// 0088782e  b870664c00           mov eax, 0x4c6670
// 00887833  50                   push eax
// 00887834  b9c8dfa300           mov ecx, 0xa3dfc8
// 00887839  e82243c4ff           call 0x4cbb60
// 0088783e  68f0568900           push 0x8956f0
// 00887843  e8b322e9ff           call 0x719afb
// 00887848  59                   pop ecx
// 00887849  c3                   ret 
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
static D d(&P::method,"playerFromCharacter","character",0);
void func_007eedc0(){tail(&e);}