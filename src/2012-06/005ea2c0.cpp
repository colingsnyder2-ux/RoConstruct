// roc 2012-06 005ea2c0  unit: G3D::Random  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ea2c0
//
// 005ea2c0  8bc1                 mov eax, ecx
// 005ea2c2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005ea2c6  d901                 fld dword ptr [ecx]
// 005ea2c8  d918                 fstp dword ptr [eax]
// 005ea2ca  d94104               fld dword ptr [ecx + 4]
// 005ea2cd  d95804               fstp dword ptr [eax + 4]
// 005ea2d0  d94108               fld dword ptr [ecx + 8]
// 005ea2d3  d95808               fstp dword ptr [eax + 8]
// 005ea2d6  d9410c               fld dword ptr [ecx + 0xc]
// 005ea2d9  d9580c               fstp dword ptr [eax + 0xc]
// 005ea2dc  d94110               fld dword ptr [ecx + 0x10]
// 005ea2df  d95810               fstp dword ptr [eax + 0x10]
// 005ea2e2  d94114               fld dword ptr [ecx + 0x14]
// 005ea2e5  d95814               fstp dword ptr [eax + 0x14]
// 005ea2e8  d94118               fld dword ptr [ecx + 0x18]
// 005ea2eb  d95818               fstp dword ptr [eax + 0x18]
// 005ea2ee  d9411c               fld dword ptr [ecx + 0x1c]
// 005ea2f1  d9581c               fstp dword ptr [eax + 0x1c]
// 005ea2f4  d94120               fld dword ptr [ecx + 0x20]
// 005ea2f7  d95820               fstp dword ptr [eax + 0x20]
// 005ea2fa  d94124               fld dword ptr [ecx + 0x24]
// 005ea2fd  d95824               fstp dword ptr [eax + 0x24]
// 005ea300  d94128               fld dword ptr [ecx + 0x28]
// 005ea303  d95828               fstp dword ptr [eax + 0x28]
// 005ea306  d9412c               fld dword ptr [ecx + 0x2c]
// 005ea309  d9582c               fstp dword ptr [eax + 0x2c]
// 005ea30c  d94130               fld dword ptr [ecx + 0x30]
// 005ea30f  d95830               fstp dword ptr [eax + 0x30]
// 005ea312  d94134               fld dword ptr [ecx + 0x34]
// 005ea315  d95834               fstp dword ptr [eax + 0x34]
// 005ea318  d94138               fld dword ptr [ecx + 0x38]
// 005ea31b  d95838               fstp dword ptr [eax + 0x38]
// 005ea31e  d9413c               fld dword ptr [ecx + 0x3c]
// 005ea321  d9583c               fstp dword ptr [eax + 0x3c]
// 005ea324  d94140               fld dword ptr [ecx + 0x40]
// 005ea327  d95840               fstp dword ptr [eax + 0x40]
// 005ea32a  c20400               ret 4
// copied from an identical function in another client (function ?copy@RbxMeshPartAdapter@ns_ROCX000008@@QAEAAU12@PBM@Z)

namespace ns_ROCX000008 {
// from server: 100% by atomic.potato
struct RbxMeshPartAdapter
{
    float data[17];
    RbxMeshPartAdapter& copy(const float* src);
};

RbxMeshPartAdapter& RbxMeshPartAdapter::copy(const float* src)
{
    data[0] = src[0];
    data[1] = src[1];
    data[2] = src[2];
    data[3] = src[3];
    data[4] = src[4];
    data[5] = src[5];
    data[6] = src[6];
    data[7] = src[7];
    data[8] = src[8];
    data[9] = src[9];
    data[10] = src[10];
    data[11] = src[11];
    data[12] = src[12];
    data[13] = src[13];
    data[14] = src[14];
    data[15] = src[15];
    data[16] = src[16];
    return *this;
}
}