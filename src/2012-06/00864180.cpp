// from server: 100% by Xemicl
// roc 2012-06 00864180  unit: VWiniInetRequest_source::?$stream_buffer  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00864180
//
// 00864180  8b542404             mov edx, dword ptr [esp + 4]
// 00864184  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00864188  56                   push esi
// 00864189  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0086418d  3bd6                 cmp edx, esi
// 0086418f  7424                 je 0x8641b5
// 00864191  57                   push edi
// 00864192  85c0                 test eax, eax
// 00864194  7414                 je 0x8641aa
// 00864196  8b0a                 mov ecx, dword ptr [edx]
// 00864198  8908                 mov dword ptr [eax], ecx
// 0086419a  85c9                 test ecx, ecx
// 0086419c  740c                 je 0x8641aa
// 0086419e  83c110               add ecx, 0x10
// 008641a1  bf01000000           mov edi, 1
// 008641a6  f00fc139             lock xadd dword ptr [ecx], edi
// 008641aa  83c204               add edx, 4
// 008641ad  83c004               add eax, 4
// 008641b0  3bd6                 cmp edx, esi
// 008641b2  75de                 jne 0x864192
// 008641b4  5f                   pop edi
// 008641b5  5e                   pop esi
// 008641b6  c3                   ret 
// copied from an identical function in another client (function ?uninit_copy@@YAPAUP@@PAU1@00@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
struct T { char pad[0x10]; long count; };
inline void add_ref(T* p) { _InterlockedIncrement(&p->count); }
struct P {
    T* p;
    P(const P& o) : p(o.p) { if (p) add_ref(p); }
};
P* uninit_copy(P* first, P* last, P* dest)
{
    for (; first != last; ++dest, ++first)
        new (dest) P(*first);
    return dest;
}