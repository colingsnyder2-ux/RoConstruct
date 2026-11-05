// from server: 100% by auto
// roc 2011-06 009c64e0  unit: seg_009c0000  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009c64e0
//
// 009c64e0  0f57c0               xorps xmm0, xmm0
// 009c64e3  56                   push esi
// 009c64e4  8bf1                 mov esi, ecx
// 009c64e6  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 009c64eb  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 009c64f0  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 009c64f5  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 009c64fa  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 009c64ff  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 009c6504  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 009c6509  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 009c650e  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 009c6513  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 009c6518  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 009c651d  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 009c6522  8d8e88000000         lea ecx, [esi + 0x88]
// 009c6528  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 009c652d  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 009c6532  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 009c6537  e854b3b7ff           call 0x541890
// 009c653c  8d8eb8000000         lea ecx, [esi + 0xb8]
// 009c6542  e849b3b7ff           call 0x541890
// 009c6547  d9ee                 fldz 
// 009c6549  0f57c0               xorps xmm0, xmm0
// 009c654c  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 009c6554  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 009c655c  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 009c6564  f30f1005488eaf00     movss xmm0, dword ptr [0xaf8e48]
// 009c656c  83ec08               sub esp, 8
// 009c656f  8bce                 mov ecx, esi
// 009c6571  dd1c24               fstp qword ptr [esp]
// 009c6574  c6464c01             mov byte ptr [esi + 0x4c], 1
// 009c6578  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 009c6580  e84befffff           call 0x9c54d0
// 009c6585  8bc6                 mov eax, esi
// 009c6587  5e                   pop esi
// 009c6588  c3                   ret 
// library rbx2016-g3d/LightingParameters.cpp (function ??0LightingParameters@G3D@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d LightingParameters.cpp
