// from server: 100% by Intel
﻿// from server: 87% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 00646460  unit: RBX::RotatePJoint  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00646460
//
// 00646460  83ec20               sub esp, 0x20
// 00646463  53                   push ebx
// 00646464  56                   push esi
// 00646465  8bf1                 mov esi, ecx
// 00646467  8b460c               mov eax, dword ptr [esi + 0xc]
// 0064646a  8b809c000000         mov eax, dword ptr [eax + 0x9c]
// 00646470  d94004               fld dword ptr [eax + 4]
// 00646473  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00646476  d95c2410             fstp dword ptr [esp + 0x10]
// 0064647a  83c004               add eax, 4
// 0064647d  d94004               fld dword ptr [eax + 4]
// 00646480  8d5628               lea edx, [esi + 0x28]
// 00646483  d95c2414             fstp dword ptr [esp + 0x14]
// 00646487  57                   push edi
// 00646488  d94008               fld dword ptr [eax + 8]
// 0064648b  8b819c000000         mov eax, dword ptr [ecx + 0x9c]
// 00646491  d95c241c             fstp dword ptr [esp + 0x1c]
// 00646495  83c004               add eax, 4
// 00646498  d900                 fld dword ptr [eax]
// 0064649a  52                   push edx
// 0064649b  d95c2424             fstp dword ptr [esp + 0x24]
// 0064649f  d94004               fld dword ptr [eax + 4]
// 006464a2  d95c2428             fstp dword ptr [esp + 0x28]
// 006464a6  d94008               fld dword ptr [eax + 8]
// 006464a9  d95c242c             fstp dword ptr [esp + 0x2c]
// 006464ad  e85e5efaff           call 0x5ec310
// 006464b2  83c658               add esi, 0x58
// 006464b5  56                   push esi
// 006464b6  8bf8                 mov edi, eax
// 006464b8  e8535efaff           call 0x5ec310
// 006464bd  50                   push eax
// 006464be  e8bd5cfaff           call 0x5ec180
// 006464c3  8bc8                 mov ecx, eax
// 006464c5  8d4101               lea eax, [ecx + 1]
// 006464c8  99                   cdq 
// 006464c9  be03000000           mov esi, 3
// 006464ce  f7fe                 idiv esi
// 006464d0  8d4102               lea eax, [ecx + 2]
// 006464d3  b903000000           mov ecx, 3
// 006464d8  83c40c               add esp, 0xc
// 006464db  8bf2                 mov esi, edx
// 006464dd  99                   cdq 
// 006464de  f7f9                 idiv ecx
// 006464e0  8d4702               lea eax, [edi + 2]
// 006464e3  8bda                 mov ebx, edx
// 006464e5  99                   cdq 
// 006464e6  f7f9                 idiv ecx
// 006464e8  d9449414             fld dword ptr [esp + edx*4 + 0x14]
// 006464ec  8d4701               lea eax, [edi + 1]
// 006464ef  bf03000000           mov edi, 3
// 006464f4  8d4c9414             lea ecx, [esp + edx*4 + 0x14]
// 006464f8  99                   cdq 
// 006464f9  f7ff                 idiv edi
// 006464fb  d85c9414             fcomp dword ptr [esp + edx*4 + 0x14]
// 006464ff  dfe0                 fnstsw ax
// 00646501  8d549414             lea edx, [esp + edx*4 + 0x14]
// 00646505  f6c441               test ah, 0x41
// 00646508  7402                 je 0x64650c
// 0064650a  8bca                 mov ecx, edx
// 0064650c  d901                 fld dword ptr [ecx]
// 0064650e  8d4c9c20             lea ecx, [esp + ebx*4 + 0x20]
// 00646512  d9542410             fst dword ptr [esp + 0x10]
// 00646516  8d54b420             lea edx, [esp + esi*4 + 0x20]
// 0064651a  d901                 fld dword ptr [ecx]
// 0064651c  5f                   pop edi
// 0064651d  d81a                 fcomp dword ptr [edx]
// 0064651f  5e                   pop esi
// 00646520  5b                   pop ebx
// 00646521  dfe0                 fnstsw ax
// 00646523  f6c441               test ah, 0x41
// 00646526  7402                 je 0x64652a
// 00646528  8bca                 mov ecx, edx
// 0064652a  d901                 fld dword ptr [ecx]
// 0064652c  d91424               fst dword ptr [esp]
// 0064652f  ded9                 fcompp 
// 00646531  dfe0                 fnstsw ax
// 00646533  f6c405               test ah, 5
// 00646536  8d0424               lea eax, [esp]
// 00646539  7b04                 jnp 0x64653f
// 0064653b  8d442404             lea eax, [esp + 4]
// 0064653f  d900                 fld dword ptr [eax]
// 00646541  d80d04e78100         fmul dword ptr [0x81e704]
// 00646547  83c420               add esp, 0x20
// 0064654a  c3                   ret 

#pragma float_control(precise, off)

struct Vector3
{
    float x, y, z;
};

struct Geometry
{
    char padding[4];
    Vector3 size;
};

struct Part
{
    char padding[0x60];
    Geometry* geometry;
};

struct Transform
{
    char data[0x30];
};

extern int __cdecl normalId(const Transform*);
extern int __cdecl normalIdOpposite(int);
extern const float radiusScale;

template<class T>
inline const T& maximum(const T& a, const T& b)
{
    return a < b ? b : a;
}

template<class T>
inline const T& minimum(const T& a, const T& b)
{
    return a < b ? a : b;
}

struct RotatePJoint
{
    char padding0[0x8];
    Part* part0;
    Part* part1;
    char padding1[0x18];
    Transform frame0;
    Transform frame1;

    float radius();
};

float RotatePJoint::radius()
{
    const Vector3& size0 = part0->geometry->size;
    float a[3] = { size0.x, size0.y, size0.z };

    const Vector3& size1 = part1->geometry->size;
    float b[3] = { size1.x, size1.y, size1.z };

    int axis0 = normalId(&frame0);
    int axis1 = normalIdOpposite(normalId(&frame1));

    int b1 = (axis1 + 1) % 3;
    int b2 = (axis1 + 2) % 3;
    int a2 = (axis0 + 2) % 3;
    int a1 = (axis0 + 1) % 3;

    float maximum0 = maximum(a[a1], a[a2]);
    float maximum1 = maximum(b[b1], b[b2]);

    float result = minimum(maximum1, maximum0);
    return result * radiusScale;
}
