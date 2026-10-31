// from server: 81% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005735e0  unit: RBX::UnifiedWidget  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005735e0
//
// 005735e0  d90568f88200         fld dword ptr [0x82f868]
// 005735e6  56                   push esi
// 005735e7  8bf1                 mov esi, ecx
// 005735e9  d99e3c010000         fstp dword ptr [esi + 0x13c]
// 005735ef  d905884d8700         fld dword ptr [0x874d88]
// 005735f5  d99e40010000         fstp dword ptr [esi + 0x140]
// 005735fb  c7866001000012000000 mov dword ptr [esi + 0x160], 0x12
// 00573605  e83613faff           call 0x514940
// 0057360a  d900                 fld dword ptr [eax]
// 0057360c  d94004               fld dword ptr [eax + 4]
// 0057360f  d94008               fld dword ptr [eax + 8]
// 00573612  d9ca                 fxch st(2)
// 00573614  d99e64010000         fstp dword ptr [esi + 0x164]
// 0057361a  d99e68010000         fstp dword ptr [esi + 0x168]
// 00573620  d99e6c010000         fstp dword ptr [esi + 0x16c]
// 00573626  d9e8                 fld1 
// 00573628  d99e70010000         fstp dword ptr [esi + 0x170]
// 0057362e  e8dd782400           call 0x7baf10
// 00573633  d900                 fld dword ptr [eax]
// 00573635  d99e74010000         fstp dword ptr [esi + 0x174]
// 0057363b  d94004               fld dword ptr [eax + 4]
// 0057363e  d99e78010000         fstp dword ptr [esi + 0x178]
// 00573644  d94008               fld dword ptr [eax + 8]
// 00573647  d99e7c010000         fstp dword ptr [esi + 0x17c]
// 0057364d  d9400c               fld dword ptr [eax + 0xc]
// 00573650  d99e80010000         fstp dword ptr [esi + 0x180]
// 00573656  c7868401000001000000 mov dword ptr [esi + 0x184], 1
// 00573660  5e                   pop esi
// 00573661  c3                   ret 

struct Vector3 {
    float x, y, z;
};

struct Vector4 {
    float x, y, z, w;
};

extern float value_82f868;
extern float value_874d88;

extern const Vector3& __cdecl getVector3();
extern const Vector4& __cdecl getVector4();

struct S {
    char padding0[0x13c];
    float value13c;
    volatile float value140;
    char padding1[0x1c];
    volatile int value160;
    Vector4 value164;
    Vector4 value174;
    int value184;

    void initialize();
};

void S::initialize()
{
    value13c = value_82f868;
    value140 = value_874d88;
    value160 = 18;

    const volatile Vector3& v = getVector3();
    double x = v.x;
    double y = v.y;
    double z = v.z;
    value164.x = (float)x;
    value164.y = (float)y;
    value164.z = (float)z;
    value164.w = 1.0f;

    const Vector4& q = getVector4();
    value174.x = q.x;
    value174.y = q.y;
    value174.z = q.z;
    value174.w = q.w;

    value184 = 1;
}
