// from server: 100% by auto
// roc 2011-06 0053f9b0  unit: G3D::MemoryManager  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053f9b0
//
// 0053f9b0  b801000000           mov eax, 1
// 0053f9b5  840500a2cb00         test byte ptr [0xcba200], al
// 0053f9bb  7529                 jne 0x53f9e6
// 0053f9bd  f30f1005685ba700     movss xmm0, dword ptr [0xa75b68]
// 0053f9c5  090500a2cb00         or dword ptr [0xcba200], eax
// 0053f9cb  f30f1105f4a1cb00     movss dword ptr [0xcba1f4], xmm0
// 0053f9d3  f30f1105f8a1cb00     movss dword ptr [0xcba1f8], xmm0
// 0053f9db  0f57c0               xorps xmm0, xmm0
// 0053f9de  f30f1105fca1cb00     movss dword ptr [0xcba1fc], xmm0
// 0053f9e6  b8f4a1cb00           mov eax, 0xcba1f4
// 0053f9eb  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?brown@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
