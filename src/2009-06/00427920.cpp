// from server: 100% by EspClaude
// roc 2009-06 00427920  unit: CWrapperView  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00427920
//
// 00427920  56                   push esi
// 00427921  8b742408             mov esi, dword ptr [esp + 8]
// 00427925  56                   push esi
// 00427926  e8611a2f00           call 0x71938c
// 0042792b  85c0                 test eax, eax
// 0042792d  7504                 jne 0x427933
// 0042792f  5e                   pop esi
// 00427930  c20400               ret 4
// 00427933  81662cfffdffff       and dword ptr [esi + 0x2c], 0xfffffdff
// 0042793a  b801000000           mov eax, 1
// 0042793f  5e                   pop esi
// 00427940  c20400               ret 4
// copied from an identical function in another client (function ?update@ns_ROCX0000e6@@YGHPAUObject@1@@Z)

namespace ns_ROCX0000e6 {
struct Object {
    char padding[0x2c];
    unsigned int flags;
};

extern "C" int __stdcall check(Object* object);

int __stdcall update(Object* object)
{
    if (!check(object))
        return 0;

    object->flags &= ~0x200u;
    return 1;
}
}
