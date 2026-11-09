// from server: 100% by auto
// roc 2012-06 00a96d30  unit: seg_00a90000  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a96d30
//
// 00a96d30  0f57c0               xorps xmm0, xmm0
// 00a96d33  56                   push esi
// 00a96d34  8bf1                 mov esi, ecx
// 00a96d36  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 00a96d3b  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 00a96d40  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 00a96d45  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 00a96d4a  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 00a96d4f  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 00a96d54  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 00a96d59  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 00a96d5e  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 00a96d63  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 00a96d68  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 00a96d6d  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 00a96d72  8d8e88000000         lea ecx, [esi + 0x88]
// 00a96d78  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 00a96d7d  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 00a96d82  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 00a96d87  e8c46bb9ff           call 0x62d950
// 00a96d8c  8d8eb8000000         lea ecx, [esi + 0xb8]
// 00a96d92  e8b96bb9ff           call 0x62d950
// 00a96d97  d9ee                 fldz 
// 00a96d99  0f57c0               xorps xmm0, xmm0
// 00a96d9c  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 00a96da4  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 00a96dac  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 00a96db4  f30f100508fcc300     movss xmm0, dword ptr [0xc3fc08]
// 00a96dbc  83ec08               sub esp, 8
// 00a96dbf  8bce                 mov ecx, esi
// 00a96dc1  dd1c24               fstp qword ptr [esp]
// 00a96dc4  c6464c01             mov byte ptr [esi + 0x4c], 1
// 00a96dc8  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 00a96dd0  e84befffff           call 0xa95d20
// 00a96dd5  8bc6                 mov eax, esi
// 00a96dd7  5e                   pop esi
// 00a96dd8  c3                   ret 
// library rbx2016-g3d/LightingParameters.cpp (function ??0LightingParameters@G3D@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d LightingParameters.cpp
