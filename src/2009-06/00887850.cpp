// from server: 100% by EspClaude
// roc 2009-06 00887850  unit: seg_00880000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00887850
//
// 00887850  33c9                 xor ecx, ecx
// 00887852  51                   push ecx
// 00887853  68e84e8c00           push 0x8c4ee8
// 00887858  688c548c00           push 0x8c548c
// 0088785d  51                   push ecx
// 0088785e  b870664c00           mov eax, 0x4c6670
// 00887863  50                   push eax
// 00887864  b938dea300           mov ecx, 0xa3de38
// 00887869  e8f242c4ff           call 0x4cbb60
// 0088786e  6870568900           push 0x895670
// 00887873  e88322e9ff           call 0x719afb
// 00887878  59                   pop ecx
// 00887879  c3                   ret 
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
static D d(&P::method,"GetPlayerFromCharacter","character",0);
void func_007eedc0(){tail(&e);}