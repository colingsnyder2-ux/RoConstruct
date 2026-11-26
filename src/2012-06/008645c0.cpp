// from server: 100% by Xemicl
// roc 2012-06 008645c0  unit: VWiniInetRequest_source::?$stream_buffer  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008645c0
//
// 008645c0  8b542408             mov edx, dword ptr [esp + 8]
// 008645c4  85d2                 test edx, edx
// 008645c6  762c                 jbe 0x8645f4
// 008645c8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008645cc  56                   push esi
// 008645cd  8b742410             mov esi, dword ptr [esp + 0x10]
// 008645d1  57                   push edi
// 008645d2  85c9                 test ecx, ecx
// 008645d4  7414                 je 0x8645ea
// 008645d6  8b06                 mov eax, dword ptr [esi]
// 008645d8  8901                 mov dword ptr [ecx], eax
// 008645da  85c0                 test eax, eax
// 008645dc  740c                 je 0x8645ea
// 008645de  83c010               add eax, 0x10
// 008645e1  bf01000000           mov edi, 1
// 008645e6  f00fc138             lock xadd dword ptr [eax], edi
// 008645ea  4a                   dec edx
// 008645eb  83c104               add ecx, 4
// 008645ee  85d2                 test edx, edx
// 008645f0  77e0                 ja 0x8645d2
// 008645f2  5f                   pop edi
// 008645f3  5e                   pop esi
// 008645f4  c3                   ret 
// copied from an identical function in another client (function ?fill_n@@YAXPAUHandle@@IABU1@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <new>
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" long __cdecl _InterlockedExchangeAdd(long volatile*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma intrinsic(_InterlockedIncrement)
struct Data { char pad[0x10]; long count; };
struct Handle {
    Data* p;
    Handle(const Handle& o) : p(o.p) { if (p) _InterlockedIncrement(&p->count); }
};
void fill_n(Handle* first, unsigned int n, const Handle& val)
{
    for (; n > 0; --n, ++first)
        new (first) Handle(val);
}