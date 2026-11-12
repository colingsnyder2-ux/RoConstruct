// from server: 100% by EspClaude
// roc-flags: /O2 /GS /EHsc /MD /fp:fast
// from server: 56% by colin
// roc 2007-08 00626690  unit: RBX::Balancing  size: 207 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00626690
//
// 00626690  83ec30               sub esp, 0x30
// 00626693  56                   push esi
// 00626694  57                   push edi
// 00626695  8bf9                 mov edi, ecx
// 00626697  8b4f04               mov ecx, dword ptr [edi + 4]
// 0062669a  e8d1fbf7ff           call 0x5a6270
// 0062669f  8bf0                 mov esi, eax
// 006266a1  85f6                 test esi, esi
// 006266a3  0f84ae000000         je 0x626757
// 006266a9  b801000000           mov eax, 1
// 006266ae  8405f4fb8b00         test byte ptr [0x8bfbf4], al
// 006266b4  751c                 jne 0x6266d2
// 006266b6  d9ee                 fldz 
// 006266b8  0905f4fb8b00         or dword ptr [0x8bfbf4], eax
// 006266be  d915e8fb8b00         fst dword ptr [0x8bfbe8]
// 006266c4  d9e8                 fld1 
// 006266c6  d91decfb8b00         fstp dword ptr [0x8bfbec]
// 006266cc  d91df0fb8b00         fstp dword ptr [0x8bfbf0]
// 006266d2  8bce                 mov ecx, esi
// 006266d4  e8279af0ff           call 0x530100
// 006266d9  8d442414             lea eax, [esp + 0x14]
// 006266dd  50                   push eax
// 006266de  8d8e84000000         lea ecx, [esi + 0x84]
// 006266e4  e8b732eeff           call 0x5099a0
// 006266e9  d94008               fld dword ptr [eax + 8]
// 006266ec  d905f0fb8b00         fld dword ptr [0x8bfbf0]
// 006266f2  8d4c2408             lea ecx, [esp + 8]
// 006266f6  dcc9                 fmul st(1), st(0)
// 006266f8  51                   push ecx
// 006266f9  d94004               fld dword ptr [eax + 4]
// 006266fc  51                   push ecx
// 006266fd  d905ecfb8b00         fld dword ptr [0x8bfbec]
// 00626703  8bcf                 mov ecx, edi
// 00626705  dcc9                 fmul st(1), st(0)
// 00626707  d9cb                 fxch st(3)
// 00626709  dec1                 faddp st(1)
// 0062670b  d900                 fld dword ptr [eax]
// 0062670d  d905e8fb8b00         fld dword ptr [0x8bfbe8]
// 00626713  dcc9                 fmul st(1), st(0)
// 00626715  d9ca                 fxch st(2)
// 00626717  dec1                 faddp st(1)
// 00626719  d95c2410             fstp dword ptr [esp + 0x10]
// 0062671d  d94014               fld dword ptr [eax + 0x14]
// 00626720  d8ca                 fmul st(2)
// 00626722  d94010               fld dword ptr [eax + 0x10]
// 00626725  d8cc                 fmul st(4)
// 00626727  dec1                 faddp st(1)
// 00626729  d9400c               fld dword ptr [eax + 0xc]
// 0062672c  d8ca                 fmul st(2)
// 0062672e  dec1                 faddp st(1)
// 00626730  d95c2414             fstp dword ptr [esp + 0x14]
// 00626734  d94020               fld dword ptr [eax + 0x20]
// 00626737  deca                 fmulp st(2)
// 00626739  d9401c               fld dword ptr [eax + 0x1c]
// 0062673c  decb                 fmulp st(3)
// 0062673e  d9c9                 fxch st(1)
// 00626740  dec2                 faddp st(2)
// 00626742  d84818               fmul dword ptr [eax + 0x18]
// 00626745  dec1                 faddp st(1)
// 00626747  d95c2418             fstp dword ptr [esp + 0x18]
// 0062674b  d9442444             fld dword ptr [esp + 0x44]
// 0062674f  d91c24               fstp dword ptr [esp]
// 00626752  e8e9f7ffff           call 0x625f40
// 00626757  5f                   pop edi
// 00626758  5e                   pop esi
// 00626759  83c430               add esp, 0x30
// 0062675c  c20400               ret 4

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct Matrix3 {
    float elt[3][3];
    Vector3 operator*(const Vector3& v) const {
        Vector3 r;
        r.x = elt[0][2] * v.z + elt[0][1] * v.y + elt[0][0] * v.x;
        r.y = elt[1][2] * v.z + elt[1][1] * v.y + elt[1][0] * v.x;
        r.z = elt[2][2] * v.z + elt[2][1] * v.y + elt[2][0] * v.x;
        return r;
    }
};

struct Coord {
    Matrix3 rotationOf() const;
};

struct Body {
    char pad[0x84];
    Coord coord;
    void update();
};

struct Humanoid {
    Body* getTorso();
};

struct Balancing {
    void* vtable;
    Humanoid* humanoid;

    void applyTorque(float dt, const Vector3& v);
    void onComputeForceImpl(float dt);
};

void Balancing::onComputeForceImpl(float dt)
{
    Body* b = humanoid->getTorso();
    if (b) {
        static Vector3 up(0.0f, 1.0f, 0.0f);
        b->update();
        Vector3 v = b->coord.rotationOf() * up;
        applyTorque(dt, v);
    }
}
