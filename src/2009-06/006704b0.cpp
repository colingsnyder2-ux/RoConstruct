// from server: 75% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005e7680  unit: RBX::Ball  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e7680
//
// 005e7680  83ec0c               sub esp, 0xc
// 005e7683  56                   push esi
// 005e7684  8bb19c000000         mov esi, dword ptr [ecx + 0x9c]
// 005e768a  57                   push edi
// 005e768b  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005e768f  57                   push edi
// 005e7690  83c604               add esi, 4
// 005e7693  e8d84e0000           call 0x5ec570
// 005e7698  d900                 fld dword ptr [eax]
// 005e769a  d80e                 fmul dword ptr [esi]
// 005e769c  57                   push edi
// 005e769d  d95c2410             fstp dword ptr [esp + 0x10]
// 005e76a1  d94004               fld dword ptr [eax + 4]
// 005e76a4  d84e04               fmul dword ptr [esi + 4]
// 005e76a7  d95c2414             fstp dword ptr [esp + 0x14]
// 005e76ab  d94008               fld dword ptr [eax + 8]
// 005e76ae  d84e08               fmul dword ptr [esi + 8]
// 005e76b1  d95c2418             fstp dword ptr [esp + 0x18]
// 005e76b5  e846510000           call 0x5ec800
// 005e76ba  8b742420             mov esi, dword ptr [esp + 0x20]
// 005e76be  83c408               add esp, 8
// 005e76c1  50                   push eax
// 005e76c2  8bce                 mov ecx, esi
// 005e76c4  e857bbf2ff           call 0x513220
// 005e76c9  d9442408             fld dword ptr [esp + 8]
// 005e76cd  d95e24               fstp dword ptr [esi + 0x24]
// 005e76d0  5f                   pop edi
// 005e76d1  d9442408             fld dword ptr [esp + 8]
// 005e76d5  8bc6                 mov eax, esi
// 005e76d7  d95e28               fstp dword ptr [esi + 0x28]
// 005e76da  d944240c             fld dword ptr [esp + 0xc]
// 005e76de  d95e2c               fstp dword ptr [esi + 0x2c]
// 005e76e1  5e                   pop esi
// 005e76e2  83c40c               add esp, 0xc
// 005e76e5  c20800               ret 8

struct Vector {
    float x, y, z;
};

struct Matrix {
    float data[9];
};

struct Result {
    Matrix rotation;
    Vector translation;
    Result& __thiscall assign(const Matrix&);
};

extern "C" const Vector* __cdecl getVector(const void*);
extern "C" const Matrix* __cdecl getMatrix(const void*);

struct ScaleData {
    unsigned char padding[4];
    Vector scale;
};

struct S {
    unsigned char padding[156];
    ScaleData* data;

    Result* __thiscall f(Result*, const void*);
};

Result* S::f(Result* result, const void* input)
{
    const Vector* scale = &data->scale;
    const Vector* value = getVector(input);

    Vector product;
    product.x = value->x * scale->x;
    product.y = value->y * scale->y;
    product.z = value->z * scale->z;

    result->assign(*getMatrix(input));
    result->translation.x = product.x;
    result->translation.y = product.y;
    result->translation.z = product.z;
    return result;
}
