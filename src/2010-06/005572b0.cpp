// from server: 100% by auto
// roc 2010-06 005572b0  unit: seg_00550000  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005572b0
//
// 005572b0  b801000000           mov eax, 1
// 005572b5  8405709fc000         test byte ptr [0xc09f70], al
// 005572bb  7551                 jne 0x55730e
// 005572bd  0f57c0               xorps xmm0, xmm0
// 005572c0  0905709fc000         or dword ptr [0xc09f70], eax
// 005572c6  f30f11054c9fc000     movss dword ptr [0xc09f4c], xmm0
// 005572ce  f30f1105509fc000     movss dword ptr [0xc09f50], xmm0
// 005572d6  f30f1105549fc000     movss dword ptr [0xc09f54], xmm0
// 005572de  f30f1105589fc000     movss dword ptr [0xc09f58], xmm0
// 005572e6  f30f11055c9fc000     movss dword ptr [0xc09f5c], xmm0
// 005572ee  f30f1105609fc000     movss dword ptr [0xc09f60], xmm0
// 005572f6  f30f1105649fc000     movss dword ptr [0xc09f64], xmm0
// 005572fe  f30f1105689fc000     movss dword ptr [0xc09f68], xmm0
// 00557306  f30f11056c9fc000     movss dword ptr [0xc09f6c], xmm0
// 0055730e  b84c9fc000           mov eax, 0xc09f4c
// 00557313  c3                   ret 
// library rbx2016-g3d/Matrix3.cpp (function ?zero@Matrix3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
