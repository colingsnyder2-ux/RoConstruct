// from server: 100% by Yeetserama
// roc 2007-08 004034b0  unit: ATL::CRegObject  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004034b0
//
// 004034b0  8b442408             mov eax, dword ptr [esp + 8]
// 004034b4  85c0                 test eax, eax
// 004034b6  56                   push esi
// 004034b7  7429                 je 0x4034e2
// 004034b9  8b30                 mov esi, dword ptr [eax]
// 004034bb  85f6                 test esi, esi
// 004034bd  7423                 je 0x4034e2
// 004034bf  8b542408             mov edx, dword ptr [esp + 8]
// 004034c3  8b0a                 mov ecx, dword ptr [edx]
// 004034c5  8b5204               mov edx, dword ptr [edx + 4]
// 004034c8  8d1491               lea edx, [ecx + edx*4]
// 004034cb  3bca                 cmp ecx, edx
// 004034cd  b801000000           mov eax, 1
// 004034d2  730e                 jae 0x4034e2
// 004034d4  3931                 cmp dword ptr [ecx], esi
// 004034d6  740c                 je 0x4034e4
// 004034d8  83c104               add ecx, 4
// 004034db  83c001               add eax, 1
// 004034de  3bca                 cmp ecx, edx
// 004034e0  72f2                 jb 0x4034d4
// 004034e2  33c0                 xor eax, eax
// 004034e4  5e                   pop esi
// 004034e5  c20800               ret 8
// copied from an identical function in another client (function ?f@ns_ROCX00000d@@YGKPAUS@1@PBK@Z)

namespace ns_ROCX00000d {
// from server: 100% by king_originala
struct S {
    unsigned long* data;
    unsigned long count;
};

unsigned long __stdcall f(S* container, const unsigned long* value)
{
    if (value && *value) {
        unsigned long target = *value;
        unsigned long index = 1;
        unsigned long* current = container->data;
        unsigned long* end = current + container->count;
        while (current < end) {
            if (*current == target)
                return index;
            ++current;
            ++index;
        }
    }
    return 0;
}
}
