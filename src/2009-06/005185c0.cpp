// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 004e6bc0  unit: RBX::ViewNew::PartChunk  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e6bc0
//
// 004e6bc0  8b442404             mov eax, dword ptr [esp + 4]
// 004e6bc4  3d7cb59700           cmp eax, 0x97b57c
// 004e6bc9  742b                 je 0x4e6bf6
// 004e6bcb  3d145f9700           cmp eax, 0x975f14
// 004e6bd0  740e                 je 0x4e6be0
// 004e6bd2  3df85e9700           cmp eax, 0x975ef8
// 004e6bd7  7407                 je 0x4e6be0
// 004e6bd9  3d305f9700           cmp eax, 0x975f30
// 004e6bde  7508                 jne 0x4e6be8
// 004e6be0  e8cbfcffff           call 0x4e68b0
// 004e6be5  c20400               ret 4
// 004e6be8  3d685f9700           cmp eax, 0x975f68
// 004e6bed  7407                 je 0x4e6bf6
// 004e6bef  3d4c5f9700           cmp eax, 0x975f4c
// 004e6bf4  7505                 jne 0x4e6bfb
// 004e6bf6  e845fbffff           call 0x4e6740
// 004e6bfb  c20400               ret 4

extern "C" void __cdecl sub_4E68B0();
extern "C" void __cdecl sub_4E6740();

struct S {
    void f(void* type);
};

void S::f(void* type)
{
    unsigned int t = (unsigned int)type;
    if (t == 0x97b57c)
        goto call_6740;
    if (t == 0x975f14)
        goto call_68b0;
    if (t == 0x975ef8)
        goto call_68b0;
    if (t == 0x975f30)
        goto call_68b0;
    if (t == 0x975f68)
        goto call_6740;
    if (t == 0x975f4c)
        goto call_6740;
    return;

call_68b0:
    sub_4E68B0();
    return;

call_6740:
    sub_4E6740();
    return;
}
