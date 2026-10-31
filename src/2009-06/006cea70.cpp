// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00613cc0  unit: RBX::RevoluteLink  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00613cc0
//
// 00613cc0  83ec54               sub esp, 0x54
// 00613cc3  56                   push esi
// 00613cc4  8bf1                 mov esi, ecx
// 00613cc6  d986cc000000         fld dword ptr [esi + 0xcc]
// 00613ccc  51                   push ecx
// 00613ccd  8d4608               lea eax, [esi + 8]
// 00613cd0  d91c24               fstp dword ptr [esp]
// 00613cd3  50                   push eax
// 00613cd4  8d4c240c             lea ecx, [esp + 0xc]
// 00613cd8  51                   push ecx
// 00613cd9  e8e2a0fcff           call 0x5dddc0
// 00613cde  83c40c               add esp, 0xc
// 00613ce1  50                   push eax
// 00613ce2  8d4c242c             lea ecx, [esp + 0x2c]
// 00613ce6  e835f5efff           call 0x513220
// 00613ceb  d9462c               fld dword ptr [esi + 0x2c]
// 00613cee  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 00613cf2  d95c244c             fstp dword ptr [esp + 0x4c]
// 00613cf6  d94630               fld dword ptr [esi + 0x30]
// 00613cf9  52                   push edx
// 00613cfa  d95c2454             fstp dword ptr [esp + 0x54]
// 00613cfe  83c668               add esi, 0x68
// 00613d01  d946cc               fld dword ptr [esi - 0x34]
// 00613d04  8d44242c             lea eax, [esp + 0x2c]
// 00613d08  56                   push esi
// 00613d09  d95c245c             fstp dword ptr [esp + 0x5c]
// 00613d0d  50                   push eax
// 00613d0e  e8bd4cf8ff           call 0x5989d0
// 00613d13  83c40c               add esp, 0xc
// 00613d16  5e                   pop esi
// 00613d17  83c454               add esp, 0x54
// 00613d1a  c20400               ret 4

struct Matrix {
    float value[9];
    Matrix(const Matrix&);
};

struct Vector {
    float x, y, z;
};

struct Frame {
    Matrix rotation;
    Vector position;
};

extern const Matrix* __cdecl rotate(void*, const Matrix*, float);
extern void __cdecl apply(const Frame*, void*, void*);

struct S {
    char padding0[8];
    Matrix basis;
    Vector position;
    char padding1[0x30];
    char destination[0x64];
    float angle;

    void update(void*);
};

void S::update(void* argument)
{
    float storage[9];
    Frame frame = {
        *rotate(storage, &basis, angle),
        { position.x, position.y, position.z }
    };
    apply(&frame, destination, argument);
}
