// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005b0b70  unit: RBX::VAccoutrement::?$FactoryProduct  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b0b70
//
// 005b0b70  83ec34               sub esp, 0x34
// 005b0b73  56                   push esi
// 005b0b74  57                   push edi
// 005b0b75  81c138feffff         add ecx, 0xfffffe38
// 005b0b7b  c744240800000000     mov dword ptr [esp + 8], 0
// 005b0b83  e818fdffff           call 0x5b08a0
// 005b0b88  85c0                 test eax, eax
// 005b0b8a  7409                 je 0x5b0b95
// 005b0b8c  8bc8                 mov ecx, eax
// 005b0b8e  e81d81feff           call 0x598cb0
// 005b0b93  eb09                 jmp 0x5b0b9e
// 005b0b95  8d4c240c             lea ecx, [esp + 0xc]
// 005b0b99  e83277ecff           call 0x4782d0
// 005b0b9e  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 005b0ba2  8bf0                 mov esi, eax
// 005b0ba4  56                   push esi
// 005b0ba5  8bcf                 mov ecx, edi
// 005b0ba7  e87426f6ff           call 0x513220
// 005b0bac  d94624               fld dword ptr [esi + 0x24]
// 005b0baf  d95f24               fstp dword ptr [edi + 0x24]
// 005b0bb2  8bc7                 mov eax, edi
// 005b0bb4  d94628               fld dword ptr [esi + 0x28]
// 005b0bb7  d95f28               fstp dword ptr [edi + 0x28]
// 005b0bba  d9462c               fld dword ptr [esi + 0x2c]
// 005b0bbd  d95f2c               fstp dword ptr [edi + 0x2c]
// 005b0bc0  5f                   pop edi
// 005b0bc1  5e                   pop esi
// 005b0bc2  83c434               add esp, 0x34
// 005b0bc5  c20400               ret 4

struct Matrix
{
    float data[9];
    Matrix(const Matrix&);
};

struct Frame
{
    Matrix rotation;
    float x, y, z;
    Frame();
};

struct Part
{
    const Frame& getFrame() const;
};

struct Owner
{
    Part* getPart();
};

struct S
{
    Frame getFrame();
};

Frame S::getFrame()
{
    volatile int state = 0;
    Part* part = reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 456)->getPart();
    return part ? part->getFrame() : Frame();
}
