// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc 2008-06 005cc740  unit: RBX::VCamera::?$FactoryProduct  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005cc740
//
// 005cc740  d9ee                 fldz 
// 005cc742  83ec0c               sub esp, 0xc
// 005cc745  d85c2410             fcomp dword ptr [esp + 0x10]
// 005cc749  56                   push esi
// 005cc74a  8bf1                 mov esi, ecx
// 005cc74c  dfe0                 fnstsw ax
// 005cc74e  f6c444               test ah, 0x44
// 005cc751  0f8ba9000000         jnp 0x5cc800
// 005cc757  8d442408             lea eax, [esp + 8]
// 005cc75b  50                   push eax
// 005cc75c  8d4c2408             lea ecx, [esp + 8]
// 005cc760  51                   push ecx
// 005cc761  8d542414             lea edx, [esp + 0x14]
// 005cc765  52                   push edx
// 005cc766  8bce                 mov ecx, esi
// 005cc768  e853f9ffff           call 0x5cc0c0
// 005cc76d  f605ac98970001       test byte ptr [0x9798ac], 1
// 005cc774  7515                 jne 0x5cc78b
// 005cc776  d905e8a38300         fld dword ptr [0x83a3e8]
// 005cc77c  830dac98970001       or dword ptr [0x9798ac], 1
// 005cc783  d915a8989700         fst dword ptr [0x9798a8]
// 005cc789  eb06                 jmp 0x5cc791
// 005cc78b  d905a8989700         fld dword ptr [0x9798a8]
// 005cc791  d9442404             fld dword ptr [esp + 4]
// 005cc795  d9442414             fld dword ptr [esp + 0x14]
// 005cc799  d8c1                 fadd st(1)
// 005cc79b  d9c2                 fld st(2)
// 005cc79d  d9e0                 fchs 
// 005cc79f  d8d1                 fcom st(1)
// 005cc7a1  dfe0                 fnstsw ax
// 005cc7a3  f6c401               test ah, 1
// 005cc7a6  7547                 jne 0x5cc7ef
// 005cc7a8  ddd9                 fstp st(1)
// 005cc7aa  ddda                 fstp st(2)
// 005cc7ac  dde9                 fucomp st(1)
// 005cc7ae  dfe0                 fnstsw ax
// 005cc7b0  f6c444               test ah, 0x44
// 005cc7b3  7b49                 jnp 0x5cc7fe
// 005cc7b5  d9442408             fld dword ptr [esp + 8]
// 005cc7b9  83ec0c               sub esp, 0xc
// 005cc7bc  d95c2408             fstp dword ptr [esp + 8]
// 005cc7c0  8bce                 mov ecx, esi
// 005cc7c2  d95c2404             fstp dword ptr [esp + 4]
// 005cc7c6  d9442418             fld dword ptr [esp + 0x18]
// 005cc7ca  d91c24               fstp dword ptr [esp]
// 005cc7cd  e8befeffff           call 0x5cc690
// 005cc7d2  8bce                 mov ecx, esi
// 005cc7d4  e877f7ffff           call 0x5cbf50
// 005cc7d9  85c0                 test eax, eax
// 005cc7db  7409                 je 0x5cc7e6
// 005cc7dd  8b10                 mov edx, dword ptr [eax]
// 005cc7df  8bc8                 mov ecx, eax
// 005cc7e1  8b420c               mov eax, dword ptr [edx + 0xc]
// 005cc7e4  ffd0                 call eax
// 005cc7e6  b001                 mov al, 1
// 005cc7e8  5e                   pop esi
// 005cc7e9  83c40c               add esp, 0xc
// 005cc7ec  c20400               ret 4
// 005cc7ef  ddd8                 fstp st(0)
// 005cc7f1  d8d2                 fcom st(2)
// 005cc7f3  dfe0                 fnstsw ax
// 005cc7f5  f6c401               test ah, 1
// 005cc7f8  75b0                 jne 0x5cc7aa
// 005cc7fa  ddd8                 fstp st(0)
// 005cc7fc  ebae                 jmp 0x5cc7ac
// 005cc7fe  ddd8                 fstp st(0)
// 005cc800  32c0                 xor al, al
// 005cc802  5e                   pop esi
// 005cc803  83c40c               add esp, 0xc
// 005cc806  c20400               ret 4

// from server: 82% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern float g83a3e8;

namespace RBX {
struct ICameraOwner {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void f();
};

struct Camera {
    ICameraOwner* getCameraOwner();
    void getAngles(float&, float&, float&);
    void setAngles(float, float, float);
    bool adjust(float);
};
}

bool RBX::Camera::adjust(float delta) {
    if (delta == 0.0f)
        return false;

    float x, y, z;
    getAngles(x, y, z);

    static float limit = g83a3e8;
    double value = (double)delta + y;
    value = -(double)limit >= value ? -(double)limit :
        (value >= (double)limit ? (double)limit : value);

    if (value != y) {
        setAngles(x, (float)value, z);
        return true;
    }
    return false;
}
