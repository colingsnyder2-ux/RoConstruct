// from server: 100% by EspClaude
// from server: 64% by colin
// roc 2007-08 0042c070  unit: VCLuaFunction::?$CComObjectNoLock  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042c070
//
// 0042c070  53                   push ebx
// 0042c071  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0042c075  55                   push ebp
// 0042c076  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0042c07a  56                   push esi
// 0042c07b  8b742418             mov esi, dword ptr [esp + 0x18]
// 0042c07f  57                   push edi
// 0042c080  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0042c084  3bf5                 cmp esi, ebp
// 0042c086  740a                 je 0x42c092
// 0042c088  8b4e08               mov ecx, dword ptr [esi + 8]
// 0042c08b  57                   push edi
// 0042c08c  ffd3                 call ebx
// 0042c08e  8b36                 mov esi, dword ptr [esi]
// 0042c090  ebf2                 jmp 0x42c084
// 0042c092  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042c096  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0042c09a  8918                 mov dword ptr [eax], ebx
// 0042c09c  894804               mov dword ptr [eax + 4], ecx
// 0042c09f  897808               mov dword ptr [eax + 8], edi
// 0042c0a2  5f                   pop edi
// 0042c0a3  5e                   pop esi
// 0042c0a4  5d                   pop ebp
// 0042c0a5  5b                   pop ebx
// 0042c0a6  c3                   ret 

#include <list>
#include <algorithm>

class Target { public: void m(struct Arg*); };
struct Arg;

struct placeholder1 {};

struct BoundCall {
    void (Target::*f)(Arg*);
    placeholder1 a1;
    Arg* a2;
    void operator()(Target* p) const { (p->*f)(a2); }
};


template BoundCall std::for_each<std::list<Target*>::iterator, BoundCall>(std::list<Target*>::iterator, std::list<Target*>::iterator, BoundCall);
