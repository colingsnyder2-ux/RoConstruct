// from server: 44% by atomic.potato
// roc 2009-12 007d67a0  unit: seg_007d0000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d67a0
//
// 007d67a0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007d67a4  f30f1005c0c39b00     movss xmm0, dword ptr [0x9bc3c0]
// 007d67ac  8b442404             mov eax, dword ptr [esp + 4]
// 007d67b0  f30f1009             movss xmm1, dword ptr [ecx]
// 007d67b4  f30f59c8             mulss xmm1, xmm0
// 007d67b8  f30f1108             movss dword ptr [eax], xmm1
// 007d67bc  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 007d67c1  f30f59c8             mulss xmm1, xmm0
// 007d67c5  f30f114804           movss dword ptr [eax + 4], xmm1
// 007d67ca  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 007d67cf  f30f59c8             mulss xmm1, xmm0
// 007d67d3  f30f114808           movss dword ptr [eax + 8], xmm1
// 007d67d8  c3                   ret

extern float g_scale;

void scale_vec3(float* dst, const float* src)
{
    dst[0] = g_scale * src[0];
    dst[1] = g_scale * src[1];
    dst[2] = g_scale * src[2];
}
