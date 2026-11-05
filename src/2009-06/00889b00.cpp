// from server: 100% by EspClaude
// roc 2009-06 00889b00  unit: seg_00880000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00889b00
//
// 00889b00  33c9                 xor ecx, ecx
// 00889b02  51                   push ecx
// 00889b03  6840518d00           push 0x8d5140
// 00889b08  6830518d00           push 0x8d5130
// 00889b0d  51                   push ecx
// 00889b0e  b820dd5c00           mov eax, 0x5cdd20
// 00889b13  50                   push eax
// 00889b14  b9503ea400           mov ecx, 0xa43e50
// 00889b19  e82266d4ff           call 0x5d0140
// 00889b1e  6850748900           push 0x897450
// 00889b23  e8d3ffe8ff           call 0x719afb
// 00889b28  59                   pop ecx
// 00889b29  c3                   ret 
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
static D d(&P::method,"IsDescendantOf","ancestor",0);
void func_007eedc0(){tail(&e);}