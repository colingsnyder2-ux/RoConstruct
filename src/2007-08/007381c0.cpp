// from server: 100% by colin
// roc 2007-08 007381c0  unit: G3D::GFont  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007381c0
//
// 007381c0  8b442404             mov eax, dword ptr [esp + 4]
// 007381c4  c1e004               shl eax, 4
// 007381c7  8b90288e7e00         mov edx, dword ptr [eax + 0x7e8e28]
// 007381cd  8d1452               lea edx, [edx + edx*2]
// 007381d0  d9449104             fld dword ptr [ecx + edx*4 + 4]
// 007381d4  8d549104             lea edx, [ecx + edx*4 + 4]
// 007381d8  56                   push esi
// 007381d9  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007381dd  d91e                 fstp dword ptr [esi]
// 007381df  d94204               fld dword ptr [edx + 4]
// 007381e2  d95e04               fstp dword ptr [esi + 4]
// 007381e5  d94208               fld dword ptr [edx + 8]
// 007381e8  d95e08               fstp dword ptr [esi + 8]
// 007381eb  8b902c8e7e00         mov edx, dword ptr [eax + 0x7e8e2c]
// 007381f1  8b742410             mov esi, dword ptr [esp + 0x10]
// 007381f5  8d1452               lea edx, [edx + edx*2]
// 007381f8  d9449104             fld dword ptr [ecx + edx*4 + 4]
// 007381fc  8d549104             lea edx, [ecx + edx*4 + 4]
// 00738200  d91e                 fstp dword ptr [esi]
// 00738202  d94204               fld dword ptr [edx + 4]
// 00738205  d95e04               fstp dword ptr [esi + 4]
// 00738208  d94208               fld dword ptr [edx + 8]
// 0073820b  d95e08               fstp dword ptr [esi + 8]
// 0073820e  8b90308e7e00         mov edx, dword ptr [eax + 0x7e8e30]
// 00738214  8b742414             mov esi, dword ptr [esp + 0x14]
// 00738218  8d1452               lea edx, [edx + edx*2]
// 0073821b  d9449104             fld dword ptr [ecx + edx*4 + 4]
// 0073821f  8d549104             lea edx, [ecx + edx*4 + 4]
// 00738223  d91e                 fstp dword ptr [esi]
// 00738225  d94204               fld dword ptr [edx + 4]
// 00738228  d95e04               fstp dword ptr [esi + 4]
// 0073822b  d94208               fld dword ptr [edx + 8]
// 0073822e  d95e08               fstp dword ptr [esi + 8]
// 00738231  8b80348e7e00         mov eax, dword ptr [eax + 0x7e8e34]
// 00738237  8d0440               lea eax, [eax + eax*2]
// 0073823a  d9448104             fld dword ptr [ecx + eax*4 + 4]
// 0073823e  8d448104             lea eax, [ecx + eax*4 + 4]
// 00738242  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00738246  d919                 fstp dword ptr [ecx]
// 00738248  5e                   pop esi
// 00738249  d94004               fld dword ptr [eax + 4]
// 0073824c  d95904               fstp dword ptr [ecx + 4]
// 0073824f  d94008               fld dword ptr [eax + 8]
// 00738252  d95908               fstp dword ptr [ecx + 8]
// 00738255  c21400               ret 0x14
// copied from an identical function in another client (function ?f@S@@QAEXHAAUVec3@@000@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Vec3 {
    float x, y, z;
};

extern int indices[][4];

struct S {
    char padding[4];
    Vec3 vertices[8];

    void f(int index, Vec3& a, Vec3& b, Vec3& c, Vec3& d);
};

void S::f(int index, Vec3& a, Vec3& b, Vec3& c, Vec3& d)
{
    const Vec3& v0 = vertices[indices[index][0]];
    a.x = v0.x;
    a.y = v0.y;
    a.z = v0.z;

    const Vec3& v1 = vertices[indices[index][1]];
    b.x = v1.x;
    b.y = v1.y;
    b.z = v1.z;

    const Vec3& v2 = vertices[indices[index][2]];
    c.x = v2.x;
    c.y = v2.y;
    c.z = v2.z;

    const Vec3& v3 = vertices[indices[index][3]];
    d.x = v3.x;
    d.y = v3.y;
    d.z = v3.z;
}