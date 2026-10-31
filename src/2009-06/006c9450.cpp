// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00658ae0  unit: RBX::ArrowButton  size: 366 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00658ae0
//
// 00658ae0  8b442404             mov eax, dword ptr [esp + 4]
// 00658ae4  d9ee                 fldz 
// 00658ae6  53                   push ebx
// 00658ae7  56                   push esi
// 00658ae8  8bf1                 mov esi, ecx
// 00658aea  57                   push edi
// 00658aeb  d95e04               fstp dword ptr [esi + 4]
// 00658aee  8d7e0c               lea edi, [esi + 0xc]
// 00658af1  bb01000000           mov ebx, 1
// 00658af6  8bcf                 mov ecx, edi
// 00658af8  8906                 mov dword ptr [esi], eax
// 00658afa  885e08               mov byte ptr [esi + 8], bl
// 00658afd  e8cef7e1ff           call 0x4782d0
// 00658b02  8d4f30               lea ecx, [edi + 0x30]
// 00658b05  e866b6fbff           call 0x614170
// 00658b0a  d9ee                 fldz 
// 00658b0c  d95654               fst dword ptr [esi + 0x54]
// 00658b0f  d95658               fst dword ptr [esi + 0x58]
// 00658b12  d9565c               fst dword ptr [esi + 0x5c]
// 00658b15  d9e8                 fld1 
// 00658b17  d95e60               fstp dword ptr [esi + 0x60]
// 00658b1a  d95664               fst dword ptr [esi + 0x64]
// 00658b1d  d95668               fst dword ptr [esi + 0x68]
// 00658b20  d9566c               fst dword ptr [esi + 0x6c]
// 00658b23  d95670               fst dword ptr [esi + 0x70]
// 00658b26  d95674               fst dword ptr [esi + 0x74]
// 00658b29  d95678               fst dword ptr [esi + 0x78]
// 00658b2c  d99680000000         fst dword ptr [esi + 0x80]
// 00658b32  841d50f09600         test byte ptr [0x96f050], bl
// 00658b38  7518                 jne 0x658b52
// 00658b3a  091d50f09600         or dword ptr [0x96f050], ebx
// 00658b40  d91544f09600         fst dword ptr [0x96f044]
// 00658b46  d91548f09600         fst dword ptr [0x96f048]
// 00658b4c  d9154cf09600         fst dword ptr [0x96f04c]
// 00658b52  d90544f09600         fld dword ptr [0x96f044]
// 00658b58  d99e84000000         fstp dword ptr [esi + 0x84]
// 00658b5e  d90548f09600         fld dword ptr [0x96f048]
// 00658b64  d99e88000000         fstp dword ptr [esi + 0x88]
// 00658b6a  d9054cf09600         fld dword ptr [0x96f04c]
// 00658b70  d99e8c000000         fstp dword ptr [esi + 0x8c]
// 00658b76  841d50f09600         test byte ptr [0x96f050], bl
// 00658b7c  7518                 jne 0x658b96
// 00658b7e  091d50f09600         or dword ptr [0x96f050], ebx
// 00658b84  d91544f09600         fst dword ptr [0x96f044]
// 00658b8a  d91548f09600         fst dword ptr [0x96f048]
// 00658b90  d9154cf09600         fst dword ptr [0x96f04c]
// 00658b96  d90544f09600         fld dword ptr [0x96f044]
// 00658b9c  d99e90000000         fstp dword ptr [esi + 0x90]
// 00658ba2  d90548f09600         fld dword ptr [0x96f048]
// 00658ba8  d99e94000000         fstp dword ptr [esi + 0x94]
// 00658bae  d9054cf09600         fld dword ptr [0x96f04c]
// 00658bb4  d99e98000000         fstp dword ptr [esi + 0x98]
// 00658bba  841d50f09600         test byte ptr [0x96f050], bl
// 00658bc0  7518                 jne 0x658bda
// 00658bc2  091d50f09600         or dword ptr [0x96f050], ebx
// 00658bc8  d91544f09600         fst dword ptr [0x96f044]
// 00658bce  d91548f09600         fst dword ptr [0x96f048]
// 00658bd4  d9154cf09600         fst dword ptr [0x96f04c]
// 00658bda  d90544f09600         fld dword ptr [0x96f044]
// 00658be0  d99e9c000000         fstp dword ptr [esi + 0x9c]
// 00658be6  d90548f09600         fld dword ptr [0x96f048]
// 00658bec  d99ea0000000         fstp dword ptr [esi + 0xa0]
// 00658bf2  d9054cf09600         fld dword ptr [0x96f04c]
// 00658bf8  d99ea4000000         fstp dword ptr [esi + 0xa4]
// 00658bfe  841d50f09600         test byte ptr [0x96f050], bl
// 00658c04  751a                 jne 0x658c20
// 00658c06  091d50f09600         or dword ptr [0x96f050], ebx
// 00658c0c  d91544f09600         fst dword ptr [0x96f044]
// 00658c12  d91548f09600         fst dword ptr [0x96f048]
// 00658c18  d91d4cf09600         fstp dword ptr [0x96f04c]
// 00658c1e  eb02                 jmp 0x658c22
// 00658c20  ddd8                 fstp st(0)
// 00658c22  d90544f09600         fld dword ptr [0x96f044]
// 00658c28  5f                   pop edi
// 00658c29  d99ea8000000         fstp dword ptr [esi + 0xa8]
// 00658c2f  8bc6                 mov eax, esi
// 00658c31  d90548f09600         fld dword ptr [0x96f048]
// 00658c37  d99eac000000         fstp dword ptr [esi + 0xac]
// 00658c3d  d9054cf09600         fld dword ptr [0x96f04c]
// 00658c43  d99eb0000000         fstp dword ptr [esi + 0xb0]
// 00658c49  5e                   pop esi
// 00658c4a  5b                   pop ebx
// 00658c4b  c20400               ret 4

struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c);
    Vec3(const Vec3& other);
    static const Vec3& zero();
};

inline Vec3::Vec3(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

inline Vec3::Vec3(const Vec3& other)
    : x(other.x), y(other.y), z(other.z)
{
}

inline const Vec3& Vec3::zero()
{
    static Vec3 value(0.0f, 0.0f, 0.0f);
    return value;
}

struct __declspec(align(4)) A {
    unsigned char data[48];
    A();
};

struct B {
    unsigned char data[24];
    B();
};

struct C {
    A a;
    B b;
};

struct S {
    int value;
    float elapsed;
    bool enabled;
    C state;
    float f54, f58, f5c, f60;
    float f64, f68, f6c, f70, f74, f78;
    int unused;
    float f80;
    Vec3 v84, v90, v9c, va8;

    S(int);
};

S::S(int argument)
    : value(argument),
      elapsed(0.0f),
      enabled(true),
      f54(0.0f),
      f58(0.0f),
      f5c(0.0f),
      f60(1.0f),
      f64(0.0f),
      f68(0.0f),
      f6c(0.0f),
      f70(0.0f),
      f74(0.0f),
      f78(0.0f),
      f80(0.0f),
      v84(Vec3::zero()),
      v90(Vec3::zero()),
      v9c(Vec3::zero()),
      va8(Vec3::zero())
{
}
