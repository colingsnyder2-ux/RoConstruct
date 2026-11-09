// from server: 100% by auto
// roc 2010-06 00559d90  unit: G3D::BinaryInput  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559d90
//
// 00559d90  b801000000           mov eax, 1
// 00559d95  840574a0c000         test byte ptr [0xc0a074], al
// 00559d9b  7521                 jne 0x559dbe
// 00559d9d  0f57c0               xorps xmm0, xmm0
// 00559da0  090574a0c000         or dword ptr [0xc0a074], eax
// 00559da6  f30f110568a0c000     movss dword ptr [0xc0a068], xmm0
// 00559dae  f30f11056ca0c000     movss dword ptr [0xc0a06c], xmm0
// 00559db6  f30f110570a0c000     movss dword ptr [0xc0a070], xmm0
// 00559dbe  b868a0c000           mov eax, 0xc0a068
// 00559dc3  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ?zero@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
