// from server: 100% by EspClaude
// roc 2009-06 00889b30  unit: seg_00880000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00889b30
//
// 00889b30  33c9                 xor ecx, ecx
// 00889b32  51                   push ecx
// 00889b33  685c518d00           push 0x8d515c
// 00889b38  684c518d00           push 0x8d514c
// 00889b3d  51                   push ecx
// 00889b3e  b890dc5c00           mov eax, 0x5cdc90
// 00889b43  50                   push eax
// 00889b44  b9783da400           mov ecx, 0xa43d78
// 00889b49  e8f265d4ff           call 0x5d0140
// 00889b4e  6870738900           push 0x897370
// 00889b53  e8a3ffe8ff           call 0x719afb
// 00889b58  59                   pop ecx
// 00889b59  c3                   ret 
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
static D d(&P::method,"IsAncestorOf","descendant",0);
void func_007eedc0(){tail(&e);}