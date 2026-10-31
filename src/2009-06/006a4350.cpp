// from server: 96% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00608aa0  unit: RBX::VModelInstance::?$FactoryProduct  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00608aa0
//
// 00608aa0  83ec60               sub esp, 0x60
// 00608aa3  8b8134010000         mov eax, dword ptr [ecx + 0x134]
// 00608aa9  8b5008               mov edx, dword ptr [eax + 8]
// 00608aac  8b840a34010000       mov eax, dword ptr [edx + ecx + 0x134]
// 00608ab3  8b00                 mov eax, dword ptr [eax]
// 00608ab5  56                   push esi
// 00608ab6  8b742468             mov esi, dword ptr [esp + 0x68]
// 00608aba  8d8c0a34010000       lea ecx, [edx + ecx + 0x134]
// 00608ac1  57                   push edi
// 00608ac2  8b3e                 mov edi, dword ptr [esi]
// 00608ac4  8d542438             lea edx, [esp + 0x38]
// 00608ac8  52                   push edx
// 00608ac9  ffd0                 call eax
// 00608acb  8b5738               mov edx, dword ptr [edi + 0x38]
// 00608ace  50                   push eax
// 00608acf  8bce                 mov ecx, esi
// 00608ad1  ffd2                 call edx
// 00608ad3  e838bef0ff           call 0x514910
// 00608ad8  d900                 fld dword ptr [eax]
// 00608ada  d95c2408             fstp dword ptr [esp + 8]
// 00608ade  d94004               fld dword ptr [eax + 4]
// 00608ae1  d95c240c             fstp dword ptr [esp + 0xc]
// 00608ae5  d94008               fld dword ptr [eax + 8]
// 00608ae8  d95c2410             fstp dword ptr [esp + 0x10]
// 00608aec  d9e8                 fld1 
// 00608aee  d95c2414             fstp dword ptr [esp + 0x14]
// 00608af2  e8e9bdf0ff           call 0x5148e0
// 00608af7  d900                 fld dword ptr [eax]
// 00608af9  d95c2418             fstp dword ptr [esp + 0x18]
// 00608afd  d94004               fld dword ptr [eax + 4]
// 00608b00  d95c241c             fstp dword ptr [esp + 0x1c]
// 00608b04  d94008               fld dword ptr [eax + 8]
// 00608b07  d95c2420             fstp dword ptr [esp + 0x20]
// 00608b0b  d9e8                 fld1 
// 00608b0d  d95c2424             fstp dword ptr [esp + 0x24]
// 00608b11  e89abdf0ff           call 0x5148b0
// 00608b16  d900                 fld dword ptr [eax]
// 00608b18  d95c2428             fstp dword ptr [esp + 0x28]
// 00608b1c  51                   push ecx
// 00608b1d  d94004               fld dword ptr [eax + 4]
// 00608b20  8d4c240c             lea ecx, [esp + 0xc]
// 00608b24  d95c2430             fstp dword ptr [esp + 0x30]
// 00608b28  8d54241c             lea edx, [esp + 0x1c]
// 00608b2c  d94008               fld dword ptr [eax + 8]
// 00608b2f  8b06                 mov eax, dword ptr [esi]
// 00608b31  d95c2434             fstp dword ptr [esp + 0x34]
// 00608b35  d9e8                 fld1 
// 00608b37  d95c2438             fstp dword ptr [esp + 0x38]
// 00608b3b  d90590748200         fld dword ptr [0x827490]
// 00608b41  d91c24               fstp dword ptr [esp]
// 00608b44  51                   push ecx
// 00608b45  52                   push edx
// 00608b46  8b505c               mov edx, dword ptr [eax + 0x5c]
// 00608b49  8d4c2434             lea ecx, [esp + 0x34]
// 00608b4d  51                   push ecx
// 00608b4e  8bce                 mov ecx, esi
// 00608b50  ffd2                 call edx
// 00608b52  5f                   pop edi
// 00608b53  5e                   pop esi
// 00608b54  83c460               add esp, 0x60
// 00608b57  c20400               ret 4

struct Vec3 {
    float x, y, z;
};

struct Vec4 {
    float x, y, z, w;
};

struct Matrix {
    float data[12];
};

extern const Vec3& __cdecl axisZ();
extern const Vec3& __cdecl axisY();
extern const Vec3& __cdecl axisX();
extern const float scalar;

struct Base {
    virtual Matrix getMatrix();
};

struct Receiver {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void setMatrix(const Matrix&);
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void setVectors(const Vec4&, const Vec4&, const Vec4&, float);
};

struct S {
    char padding[0x134];
    int* vbtable;
    void apply(Receiver*);
};

void S::apply(Receiver* receiver)
{
    Base* base = reinterpret_cast<Base*>(
        reinterpret_cast<char*>(this) + 0x134 + vbtable[2]);

    receiver->setMatrix(base->getMatrix());

    const Vec3& z = axisZ();
    Vec4 a = { z.x, z.y, z.z, 1.0f };

    const Vec3& y = axisY();
    Vec4 b = { y.x, y.y, y.z, 1.0f };

    const Vec3& x = axisX();
    Vec4 c = { x.x, x.y, x.z, 1.0f };

    receiver->setVectors(c, b, a, scalar);
}
