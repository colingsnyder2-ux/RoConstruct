// from server: 100% by auto
// roc 2011-06 00541450  unit: G3D::MemoryManager  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00541450
//
// 00541450  b801000000           mov eax, 1
// 00541455  8405f8a2cb00         test byte ptr [0xcba2f8], al
// 0054145b  7559                 jne 0x5414b6
// 0054145d  0f57c0               xorps xmm0, xmm0
// 00541460  f30f100d143ba600     movss xmm1, dword ptr [0xa63b14]
// 00541468  0905f8a2cb00         or dword ptr [0xcba2f8], eax
// 0054146e  f30f110dd4a2cb00     movss dword ptr [0xcba2d4], xmm1
// 00541476  f30f1105d8a2cb00     movss dword ptr [0xcba2d8], xmm0
// 0054147e  f30f1105dca2cb00     movss dword ptr [0xcba2dc], xmm0
// 00541486  f30f1105e0a2cb00     movss dword ptr [0xcba2e0], xmm0
// 0054148e  f30f110de4a2cb00     movss dword ptr [0xcba2e4], xmm1
// 00541496  f30f1105e8a2cb00     movss dword ptr [0xcba2e8], xmm0
// 0054149e  f30f1105eca2cb00     movss dword ptr [0xcba2ec], xmm0
// 005414a6  f30f1105f0a2cb00     movss dword ptr [0xcba2f0], xmm0
// 005414ae  f30f110df4a2cb00     movss dword ptr [0xcba2f4], xmm1
// 005414b6  b8d4a2cb00           mov eax, 0xcba2d4
// 005414bb  c3                   ret 
// library rbx2016-g3d/Matrix3.cpp (function ?identity@Matrix3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
