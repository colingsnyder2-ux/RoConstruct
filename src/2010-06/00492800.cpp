// from server: 100% by auto
// roc 2010-06 00492800  unit: std::D::DU?$char_traits::V?$basic_string::?$Set  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00492800
//
// 00492800  b801000000           mov eax, 1
// 00492805  8405d03cc000         test byte ptr [0xc03cd0], al
// 0049280b  7521                 jne 0x49282e
// 0049280d  0f57c0               xorps xmm0, xmm0
// 00492810  0905d03cc000         or dword ptr [0xc03cd0], eax
// 00492816  f30f1105c43cc000     movss dword ptr [0xc03cc4], xmm0
// 0049281e  f30f1105c83cc000     movss dword ptr [0xc03cc8], xmm0
// 00492826  f30f1105cc3cc000     movss dword ptr [0xc03ccc], xmm0
// 0049282e  b8c43cc000           mov eax, 0xc03cc4
// 00492833  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ?zero@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
