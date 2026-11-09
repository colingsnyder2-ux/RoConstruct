// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 007b8fb0  unit: RBX::Render::TextureProxy  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007b8fb0
//
// 007b8fb0  8b442408             mov eax, dword ptr [esp + 8]
// 007b8fb4  56                   push esi
// 007b8fb5  6a00                 push 0
// 007b8fb7  8bf1                 mov esi, ecx
// 007b8fb9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007b8fbd  50                   push eax
// 007b8fbe  51                   push ecx
// 007b8fbf  8bce                 mov ecx, esi
// 007b8fc1  e86a8bd9ff           call 0x551b30
// 007b8fc6  d9ee                 fldz 
// 007b8fc8  d95e54               fstp dword ptr [esi + 0x54]
// 007b8fcb  c706ec5c8700         mov dword ptr [esi], 0x875cec
// 007b8fd1  8bc6                 mov eax, esi
// 007b8fd3  5e                   pop esi
// 007b8fd4  c20800               ret 8

struct Base {
    virtual void f();
    unsigned char padding[80];
    Base(int, int, int);
};

struct S : Base {
    float value;
    virtual void f();
    S(int, int);
};

S::S(int a, int b) : Base(a, b, 0), value(0.0f)
{
}
