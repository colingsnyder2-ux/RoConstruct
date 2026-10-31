// from server: 96% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0062e2e0  unit: RBX::VDecal::?$FactoryProduct  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0062e2e0
//
// 0062e2e0  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0062e2e3  8b402c               mov eax, dword ptr [eax + 0x2c]
// 0062e2e6  85c0                 test eax, eax
// 0062e2e8  7406                 je 0x62e2f0
// 0062e2ea  0590000000           add eax, 0x90
// 0062e2ef  c3                   ret 
// 0062e2f0  b801000000           mov eax, 1
// 0062e2f5  840550f09600         test byte ptr [0x96f050], al
// 0062e2fb  751a                 jne 0x62e317
// 0062e2fd  d9ee                 fldz 
// 0062e2ff  090550f09600         or dword ptr [0x96f050], eax
// 0062e305  d91544f09600         fst dword ptr [0x96f044]
// 0062e30b  d91548f09600         fst dword ptr [0x96f048]
// 0062e311  d91d4cf09600         fstp dword ptr [0x96f04c]
// 0062e317  b844f09600           mov eax, 0x96f044
// 0062e31c  c3                   ret 

struct Vector3 {
    float x, y, z;
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
};

struct Object {
    char padding[0x90];
    Vector3 value;
};

struct Holder {
    char padding[0x2c];
    Object* object;
};

struct S {
    char padding[0x10];
    Holder* holder;
    const Vector3& f();
};

const Vector3& S::f()
{
    Object* object = holder->object;
    if (object)
        return object->value;

    static Vector3 zero;
    return zero;
}
