// from server: 37% by atomic.potato
// roc 2009-06 00692140  unit: RBX::BodyMover  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00692140
//
// 00692140  0400                 add al, 0
// 00692142  8d5d18               lea ebx, [ebp + 0x18]
// 00692145  eb03                 jmp 0x69214a
// 00692147  83c370               add ebx, 0x70
// 0069214a  53                   push ebx
// 0069214b  8d4c2448             lea ecx, [esp + 0x48]
// 0069214f  e82c7ee0ff           call 0x499f80
// 00692154  8d542444             lea edx, [esp + 0x44]
// 00692158  52                   push edx
// 00692159  8d442430             lea eax, [esp + 0x30]
// 0069215d  50                   push eax
// 0069215e  e88daafdff           call 0x66cbf0
// 00692163  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00692167  d98154010000         fld dword ptr [ecx + 0x154]
// 0069216d  83c408               add esp, 8
// 00692170  d84c2430             fmul dword ptr [esp + 0x30]
// 00692174  8bcf                 mov ecx, edi
// 00692176  d84c243c             fmul dword ptr [esp + 0x3c]
// 0069217a  d86c2418             fsubr dword ptr [esp + 0x18]
// 0069217e  d95c2418             fstp dword ptr [esp + 0x18]
// 00692182  e8a9b2fcff           call 0x65d430
// 00692187  d94608               fld dword ptr [esi + 8]
// 0069218a  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 0069218e  d944241c             fld dword ptr [esp + 0x1c]
// 00692192  5f                   pop edi
// 00692193  dcc9                 fmul st(1), st(0)
// 00692195  5d                   pop ebp
// 00692196  d94604               fld dword ptr [esi + 4]
// 00692199  5b                   pop ebx
// 0069219a  d944240c             fld dword ptr [esp + 0xc]
// 0069219e  dcc9                 fmul st(1), st(0)
// 006921a0  d9cb                 fxch st(3)
// 006921a2  dec1                 faddp st(1)
// 006921a4  d9442408             fld dword ptr [esp + 8]
// 006921a8  d9c0                 fld st(0)
// 006921aa  d80e                 fmul dword ptr [esi]
// 006921ac  dec2                 faddp st(2)
// 006921ae  d94614               fld dword ptr [esi + 0x14]
// 006921b1  d8cb                 fmul st(3)
// 006921b3  d9460c               fld dword ptr [esi + 0xc]
// 006921b6  d8ca                 fmul st(2)
// 006921b8  dec1                 faddp st(1)
// 006921ba  d94610               fld dword ptr [esi + 0x10]
// 006921bd  d8cd                 fmul st(5)
// 006921bf  dec1                 faddp st(1)
// 006921c1  d94620               fld dword ptr [esi + 0x20]
// 006921c4  decc                 fmulp st(4)
// 006921c6  d94618               fld dword ptr [esi + 0x18]
// 006921c9  deca                 fmulp st(2)
// 006921cb  d9cb                 fxch st(3)
// 006921cd  dec1                 faddp st(1)
// 006921cf  d9461c               fld dword ptr [esi + 0x1c]
// 006921d2  5e                   pop esi
// 006921d3  decc                 fmulp st(4)
// 006921d5  dec3                 faddp st(3)
// 006921d7  d8642410             fsub dword ptr [esp + 0x10]
// 006921db  d9c9                 fxch st(1)
// 006921dd  d8642414             fsub dword ptr [esp + 0x14]
// 006921e1  d9ca                 fxch st(2)
// 006921e3  d8642418             fsub dword ptr [esp + 0x18]
// 006921e7  d9c9                 fxch st(1)
// 006921e9  d918                 fstp dword ptr [eax]
// 006921eb  d9c9                 fxch st(1)
// 006921ed  d95804               fstp dword ptr [eax + 4]
// 006921f0  d95808               fstp dword ptr [eax + 8]
// 006921f3  83c458               add esp, 0x58
// 006921f6  c20c00               ret 0xc

struct Vec3 { float x, y, z; };

struct Inner {
    char pad0[0x154];
    float f154;
};

struct Outer {
    char pad0[0x18];
    Inner inner;
};

struct Mat {
    float m[9];
};

struct S {
    char pad0[4];
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    char pad24[0x154 - 0x24];
    float f154;
    void method(Vec3* out, Outer* o, Vec3* a, Vec3* b, Vec3* c);
};

extern "C" void __stdcall copy9(void* dst, const void* src);
extern "C" void __stdcall copy3(Vec3* dst, const Vec3* src);
extern "C" void __stdcall sub65d430();

void S::method(Vec3* out, Outer* o, Vec3* a, Vec3* b, Vec3* c)
{
    Mat m;
    Vec3 v;
    copy9(&m, &o->inner);
    copy3(&v, (Vec3*)&m);
    float t = f154 * v.x * v.z - a->x;
    sub65d430();
    out->x = f8 * t + f4 * v.y + fC * v.z + f10 * v.x + f14 * a->y + f18 * a->z + f1C * b->x + f20 * b->y - c->x;
    out->y = f8 * t + f4 * v.y + fC * v.z + f10 * v.x + f14 * a->y + f18 * a->z + f1C * b->x + f20 * b->y - c->y;
    out->z = f8 * t + f4 * v.y + fC * v.z + f10 * v.x + f14 * a->y + f18 * a->z + f1C * b->x + f20 * b->y - c->z;
}
