// from server: 100% by auto
// roc 2010-06 0055afe0  unit: G3D::Plane  size: 282 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0055afe0
//
// 0055afe0  b801000000           mov eax, 1
// 0055afe5  8405bc88c000         test byte ptr [0xc088bc], al
// 0055afeb  7531                 jne 0x55b01e
// 0055afed  f30f100578b7a000     movss xmm0, dword ptr [0xa0b778]
// 0055aff5  0905bc88c000         or dword ptr [0xc088bc], eax
// 0055affb  0f28f0               movaps xmm6, xmm0
// 0055affe  0f28e0               movaps xmm4, xmm0
// 0055b001  0f28d8               movaps xmm3, xmm0
// 0055b004  f30f1135b088c000     movss dword ptr [0xc088b0], xmm6
// 0055b00c  f30f1125b488c000     movss dword ptr [0xc088b4], xmm4
// 0055b014  f30f111db888c000     movss dword ptr [0xc088b8], xmm3
// 0055b01c  eb18                 jmp 0x55b036
// 0055b01e  f30f101db888c000     movss xmm3, dword ptr [0xc088b8]
// 0055b026  f30f1025b488c000     movss xmm4, dword ptr [0xc088b4]
// 0055b02e  f30f1035b088c000     movss xmm6, dword ptr [0xc088b0]
// 0055b036  840520a1c000         test byte ptr [0xc0a120], al
// 0055b03c  752e                 jne 0x55b06c
// 0055b03e  f30f100598fba100     movss xmm0, dword ptr [0xa1fb98]
// 0055b046  090520a1c000         or dword ptr [0xc0a120], eax
// 0055b04c  0f28e8               movaps xmm5, xmm0
// 0055b04f  0f28d0               movaps xmm2, xmm0
// 0055b052  f30f112d14a1c000     movss dword ptr [0xc0a114], xmm5
// 0055b05a  f30f111518a1c000     movss dword ptr [0xc0a118], xmm2
// 0055b062  f30f11051ca1c000     movss dword ptr [0xc0a11c], xmm0
// 0055b06a  eb18                 jmp 0x55b084
// 0055b06c  f30f10051ca1c000     movss xmm0, dword ptr [0xc0a11c]
// 0055b074  f30f101518a1c000     movss xmm2, dword ptr [0xc0a118]
// 0055b07c  f30f102d14a1c000     movss xmm5, dword ptr [0xc0a114]
// 0055b084  f30f104c240c         movss xmm1, dword ptr [esp + 0xc]
// 0055b08a  0f2fc1               comiss xmm0, xmm1
// 0055b08d  7205                 jb 0x55b094
// 0055b08f  0f28c8               movaps xmm1, xmm0
// 0055b092  eb08                 jmp 0x55b09c
// 0055b094  0f2fcb               comiss xmm1, xmm3
// 0055b097  7203                 jb 0x55b09c
// 0055b099  0f28cb               movaps xmm1, xmm3
// 0055b09c  f30f10442408         movss xmm0, dword ptr [esp + 8]
// 0055b0a2  0f2fd0               comiss xmm2, xmm0
// 0055b0a5  730d                 jae 0x55b0b4
// 0055b0a7  0f2fc4               comiss xmm0, xmm4
// 0055b0aa  7205                 jb 0x55b0b1
// 0055b0ac  0f28d4               movaps xmm2, xmm4
// 0055b0af  eb03                 jmp 0x55b0b4
// 0055b0b1  0f28d0               movaps xmm2, xmm0
// 0055b0b4  f30f10442404         movss xmm0, dword ptr [esp + 4]
// 0055b0ba  0f2fe8               comiss xmm5, xmm0
// 0055b0bd  7205                 jb 0x55b0c4
// 0055b0bf  0f28c5               movaps xmm0, xmm5
// 0055b0c2  eb08                 jmp 0x55b0cc
// 0055b0c4  0f2fc6               comiss xmm0, xmm6
// 0055b0c7  7203                 jb 0x55b0cc
// 0055b0c9  0f28c6               movaps xmm0, xmm6
// 0055b0cc  f30f105908           movss xmm3, dword ptr [ecx + 8]
// 0055b0d1  f30f59da             mulss xmm3, xmm2
// 0055b0d5  f30f10510c           movss xmm2, dword ptr [ecx + 0xc]
// 0055b0da  f30f59d1             mulss xmm2, xmm1
// 0055b0de  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 0055b0e3  f30f58da             addss xmm3, xmm2
// 0055b0e7  f30f59c8             mulss xmm1, xmm0
// 0055b0eb  f30f58d9             addss xmm3, xmm1
// 0055b0ef  0f2f5910             comiss xmm3, dword ptr [ecx + 0x10]
// 0055b0f3  7302                 jae 0x55b0f7
// 0055b0f5  33c0                 xor eax, eax
// 0055b0f7  c20c00               ret 0xc
// library rbx2016-g3d/AABox.cpp (function ?halfSpaceContains@Plane@G3D@@QBE_NVVector3@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
