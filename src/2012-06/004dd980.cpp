// from server: 100% by Xemicl
// roc 2012-06 004dd980  unit: Ogre::VertexStreamer  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004dd980
//
// 004dd980  56                   push esi
// 004dd981  8bf1                 mov esi, ecx
// 004dd983  807e1400             cmp byte ptr [esi + 0x14], 0
// 004dd987  7418                 je 0x4dd9a1
// 004dd989  807e0900             cmp byte ptr [esi + 9], 0
// 004dd98d  7512                 jne 0x4dd9a1
// 004dd98f  8a442408             mov al, byte ptr [esp + 8]
// 004dd993  3a4608               cmp al, byte ptr [esi + 8]
// 004dd996  7509                 jne 0x4dd9a1
// 004dd998  e8d3e7ffff           call 0x4dc170
// 004dd99d  c6461400             mov byte ptr [esi + 0x14], 0
// 004dd9a1  5e                   pop esi
// 004dd9a2  c20c00               ret 0xc
// copied from an identical function in another client (function ?func@TwoDManager@ns_ROCX00000d@@QAEXDHH@Z)

namespace ns_ROCX00000d {
struct TwoDManager {
    char pad0[8];
    char field8;
    char field9;
    char pad10[10];
    char field14;
    void unknownCall();
    void func(char a, int b, int c);
};

void TwoDManager::func(char a, int b, int c) {
    if (field14 == 0)
        return;
    if (field9 != 0)
        return;
    if (a != field8)
        return;
    unknownCall();
    field14 = 0;
}
}
