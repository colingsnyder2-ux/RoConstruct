// from server: 100% by auto
// roc 2011-06 0053fa40  unit: G3D::MemoryManager  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053fa40
//
// 0053fa40  b801000000           mov eax, 1
// 0053fa45  840520a2cb00         test byte ptr [0xcba220], al
// 0053fa4b  7521                 jne 0x53fa6e
// 0053fa4d  0f57c0               xorps xmm0, xmm0
// 0053fa50  090520a2cb00         or dword ptr [0xcba220], eax
// 0053fa56  f30f110514a2cb00     movss dword ptr [0xcba214], xmm0
// 0053fa5e  f30f110518a2cb00     movss dword ptr [0xcba218], xmm0
// 0053fa66  f30f11051ca2cb00     movss dword ptr [0xcba21c], xmm0
// 0053fa6e  b814a2cb00           mov eax, 0xcba214
// 0053fa73  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ?zero@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
