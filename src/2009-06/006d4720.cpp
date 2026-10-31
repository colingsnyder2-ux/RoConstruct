// from server: 70% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00614480  unit: RBX::RevoluteLink  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00614480
//
// 00614480  83ec0c               sub esp, 0xc
// 00614483  56                   push esi
// 00614484  8bf1                 mov esi, ecx
// 00614486  837e2800             cmp dword ptr [esi + 0x28], 0
// 0061448a  7420                 je 0x6144ac
// 0061448c  e8cf4ef8ff           call 0x599360
// 00614491  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 00614494  e8c7bc0400           call 0x660160
// 00614499  50                   push eax
// 0061449a  8d442408             lea eax, [esp + 8]
// 0061449e  50                   push eax
// 0061449f  8d8e94000000         lea ecx, [esi + 0x94]
// 006144a5  e8f621e6ff           call 0x4766a0
// 006144aa  eb0b                 jmp 0x6144b7
// 006144ac  e8af4ef8ff           call 0x599360
// 006144b1  8d86b8000000         lea eax, [esi + 0xb8]
// 006144b7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006144bb  d900                 fld dword ptr [eax]
// 006144bd  d919                 fstp dword ptr [ecx]
// 006144bf  5e                   pop esi
// 006144c0  d94004               fld dword ptr [eax + 4]
// 006144c3  d95904               fstp dword ptr [ecx + 4]
// 006144c6  d94008               fld dword ptr [eax + 8]
// 006144c9  8bc1                 mov eax, ecx
// 006144cb  d95908               fstp dword ptr [ecx + 8]
// 006144ce  83c40c               add esp, 0xc
// 006144d1  c20400               ret 4

struct Vector3 {
    float x, y, z;

    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Cofm {
    const Vector3& getCofmInBody() const;
};

struct Frame {
    char data[0x24];
    Vector3 transform(const Vector3&) const;
};

struct S {
    char reserved0[0x28];
    Cofm* cofm;
    char reserved1[0x68];
    Frame frame;
    Vector3 fallback;

    const void* get();
    Vector3 f();
};

Vector3 S::f()
{
    return cofm
        ? (get(), frame.transform(cofm->getCofmInBody()))
        : (get(), fallback);
}
