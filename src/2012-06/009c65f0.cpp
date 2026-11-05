// roc 2012-06 009c65f0  unit: CXTPControls  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c65f0
//
// 009c65f0  e8dbffffff           call 0x9c65d0
// 009c65f5  85c0                 test eax, eax
// 009c65f7  8b442404             mov eax, dword ptr [esp + 4]
// 009c65fb  7413                 je 0x9c6610
// 009c65fd  85c0                 test eax, eax
// 009c65ff  7508                 jne 0x9c6609
// 009c6601  b801000000           mov eax, 1
// 009c6606  c20400               ret 4
// 009c6609  83f801               cmp eax, 1
// 009c660c  7502                 jne 0x9c6610
// 009c660e  33c0                 xor eax, eax
// 009c6610  c20400               ret 4
// copied from an identical function in another client (function ?sub_0066e1e0@ns_ROCX00000c@@YGHH@Z)

namespace ns_ROCX00000c {
extern int __cdecl sub_0066e1c0();

int __stdcall sub_0066e1e0(int a)
{
    if (sub_0066e1c0())
    {
        if (a == 0)
            return 1;
        if (a == 1)
            return 0;
    }
    return a;
}
}
