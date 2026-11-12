// from server: 94% by EspClaude
// roc-flags: /O2 /GS /EHsc /MD /fp:fast
// roc 2007-08 00608fb0  unit: RBX::SimJobStage  size: 304 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00608fb0
//
// 00608fb0  83ec14               sub esp, 0x14
// 00608fb3  55                   push ebp
// 00608fb4  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00608fb8  56                   push esi
// 00608fb9  57                   push edi
// 00608fba  8bcd                 mov ecx, ebp
// 00608fbc  e8cfbcfaff           call 0x5b4c90
// 00608fc1  8b742428             mov esi, dword ptr [esp + 0x28]
// 00608fc5  8bce                 mov ecx, esi
// 00608fc7  8bf8                 mov edi, eax
// 00608fc9  e8c2bcfaff           call 0x5b4c90
// 00608fce  d905005c7900         fld dword ptr [0x795c00]
// 00608fd4  51                   push ecx
// 00608fd5  d91c24               fstp dword ptr [esp]
// 00608fd8  50                   push eax
// 00608fd9  8bcf                 mov ecx, edi
// 00608fdb  e83038fbff           call 0x5bc810
// 00608fe0  84c0                 test al, al
// 00608fe2  7409                 je 0x608fed
// 00608fe4  5f                   pop edi
// 00608fe5  5e                   pop esi
// 00608fe6  33c0                 xor eax, eax
// 00608fe8  5d                   pop ebp
// 00608fe9  83c414               add esp, 0x14
// 00608fec  c3                   ret 
// 00608fed  53                   push ebx
// 00608fee  8b5d64               mov ebx, dword ptr [ebp + 0x64]
// 00608ff1  8bcb                 mov ecx, ebx
// 00608ff3  e80871f2ff           call 0x530100
// 00608ff8  8b7664               mov esi, dword ptr [esi + 0x64]
// 00608ffb  8bce                 mov ecx, esi
// 00608ffd  e8fe70f2ff           call 0x530100
// 00609002  81c684000000         add esi, 0x84
// 00609008  89742414             mov dword ptr [esp + 0x14], esi
// 0060900c  33f6                 xor esi, esi
// 0060900e  8bff                 mov edi, edi
// 00609010  b856555555           mov eax, 0x55555556
// 00609015  f7ee                 imul esi
// 00609017  8bc2                 mov eax, edx
// 00609019  c1e81f               shr eax, 0x1f
// 0060901c  03c2                 add eax, edx
// 0060901e  8d0c40               lea ecx, [eax + eax*2]
// 00609021  8bd1                 mov edx, ecx
// 00609023  8bce                 mov ecx, esi
// 00609025  2bca                 sub ecx, edx
// 00609027  03c0                 add eax, eax
// 00609029  8b542414             mov edx, dword ptr [esp + 0x14]
// 0060902d  d9848b84000000       fld dword ptr [ebx + ecx*4 + 0x84]
// 00609034  52                   push edx
// 00609035  d9848b90000000       fld dword ptr [ebx + ecx*4 + 0x90]
// 0060903c  d9848b9c000000       fld dword ptr [ebx + ecx*4 + 0x9c]
// 00609043  b901000000           mov ecx, 1
// 00609048  2bc8                 sub ecx, eax
// 0060904a  894c2414             mov dword ptr [esp + 0x14], ecx
// 0060904e  8d44241c             lea eax, [esp + 0x1c]
// 00609052  db442414             fild dword ptr [esp + 0x14]
// 00609056  50                   push eax
// 00609057  d9c0                 fld st(0)
// 00609059  decc                 fmulp st(4)
// 0060905b  d9c0                 fld st(0)
// 0060905d  decb                 fmulp st(3)
// 0060905f  dec9                 fmulp st(1)
// 00609061  d9ca                 fxch st(2)
// 00609063  d9e0                 fchs 
// 00609065  d95c2420             fstp dword ptr [esp + 0x20]
// 00609069  d9e0                 fchs 
// 0060906b  d95c2424             fstp dword ptr [esp + 0x24]
// 0060906f  d9e0                 fchs 
// 00609071  d95c2428             fstp dword ptr [esp + 0x28]
// 00609075  e83626faff           call 0x5ab6b0
// 0060907a  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0060907e  8bf8                 mov edi, eax
// 00609080  57                   push edi
// 00609081  56                   push esi
// 00609082  51                   push ecx
// 00609083  55                   push ebp
// 00609084  e867050000           call 0x6095f0
// 00609089  83c418               add esp, 0x18
// 0060908c  85c0                 test eax, eax
// 0060908e  7548                 jne 0x6090d8
// 00609090  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00609094  57                   push edi
// 00609095  56                   push esi
// 00609096  52                   push edx
// 00609097  55                   push ebp
// 00609098  e803f20100           call 0x6282a0
// 0060909d  83c410               add esp, 0x10
// 006090a0  85c0                 test eax, eax
// 006090a2  7534                 jne 0x6090d8
// 006090a4  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006090a8  57                   push edi
// 006090a9  56                   push esi
// 006090aa  50                   push eax
// 006090ab  55                   push ebp
// 006090ac  e8fff00100           call 0x6281b0
// 006090b1  83c410               add esp, 0x10
// 006090b4  85c0                 test eax, eax
// 006090b6  7520                 jne 0x6090d8
// 006090b8  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006090bc  57                   push edi
// 006090bd  56                   push esi
// 006090be  51                   push ecx
// 006090bf  55                   push ebp
// 006090c0  e84b1c0000           call 0x60ad10
// 006090c5  83c410               add esp, 0x10
// 006090c8  85c0                 test eax, eax
// 006090ca  750c                 jne 0x6090d8
// 006090cc  83c601               add esi, 1
// 006090cf  83fe06               cmp esi, 6
// 006090d2  0f8c38ffffff         jl 0x609010
// 006090d8  5b                   pop ebx
// 006090d9  5f                   pop edi
// 006090da  5e                   pop esi
// 006090db  5d                   pop ebp
// 006090dc  83c414               add esp, 0x14
// 006090df  c3                   ret 

// Shape (from the bytes): cdecl free function (a, b); a/b->getX() thiscall,
// X::test(X*, float) thiscall returning bool; body pointer at +0x64 updated by a
// thiscall with no args; 3x3 float matrix at body+0x84 (row stride 0xc); loop
// i=0..5 over +/- columns, cdecl helper (const Vector3&, const Matrix3&) -> int,
// then four cdecl tests (a, b, i, face) whose first nonzero result is returned.

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    Vector3 operator-() const { return Vector3(-x, -y, -z); }
};

struct Matrix3 {
    float elt[3][3];
    Vector3 getColumn(int c) const { return Vector3(elt[0][c], elt[1][c], elt[2][c]); }
};

struct Body {
    char pad[0x84];
    Matrix3 R;
    void update();
};

struct Geom {
    bool overlaps(Geom* other, float tol);
};

struct Primitive {
    Geom* getGeom();
    char pad[0x64];
    Body* body;
};

extern float g_tolerance;
int closestFace(const Vector3& n, const Matrix3& m);
int testA(Primitive* a, Primitive* b, int i, int face);
int testB(Primitive* a, Primitive* b, int i, int face);
int testC(Primitive* a, Primitive* b, int i, int face);
int testD(Primitive* a, Primitive* b, int i, int face);

int stageCollide(Primitive* a, Primitive* b)
{
    Geom* ga = a->getGeom();
    Geom* gb = b->getGeom();
    if (ga->overlaps(gb, g_tolerance))
        return 0;

    Body* ba = a->body;
    ba->update();
    Body* bb = b->body;
    bb->update();
    const Matrix3& rb = bb->R;

    for (int i = 0; i < 6; ++i) {
        Vector3 n = -(ba->R.getColumn(i % 3) * (float)(1 - 2 * (i / 3)));
        int face = closestFace(n, rb);
        int r;
        if ((r = testA(a, b, i, face)) != 0) return r;
        if ((r = testB(a, b, i, face)) != 0) return r;
        if ((r = testC(a, b, i, face)) != 0) return r;
        if ((r = testD(a, b, i, face)) != 0) return r;
    }
    return 0;
}
