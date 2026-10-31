// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004e6b90  unit: RBX::ViewNew::PartChunk  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e6b90
//
// 004e6b90  8b442404             mov eax, dword ptr [esp + 4]
// 004e6b94  3d7cb59700           cmp eax, 0x97b57c
// 004e6b99  7508                 jne 0x4e6ba3
// 004e6b9b  e8a0fbffff           call 0x4e6740
// 004e6ba0  c20400               ret 4
// 004e6ba3  3d145f9700           cmp eax, 0x975f14
// 004e6ba8  740e                 je 0x4e6bb8
// 004e6baa  3df85e9700           cmp eax, 0x975ef8
// 004e6baf  7407                 je 0x4e6bb8
// 004e6bb1  3d305f9700           cmp eax, 0x975f30
// 004e6bb6  7505                 jne 0x4e6bbd
// 004e6bb8  e8f3fcffff           call 0x4e68b0
// 004e6bbd  c20400               ret 4

extern char key1;
extern char key2;
extern char key3;
extern char key4;

struct S {
    void f(const void* key);
    void g();
    void h();
};

void S::f(const void* key)
{
    if (key == &key1)
        g();
    else if (key == &key2 || key == &key3 || key == &key4)
        h();
}
