// from server: 100% by auto
// roc 2011-06 005427c0  unit: G3D::Sphere  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005427c0
//
// 005427c0  b801000000           mov eax, 1
// 005427c5  840518a3cb00         test byte ptr [0xcba318], al
// 005427cb  7526                 jne 0x5427f3
// 005427cd  f30f1005143ba600     movss xmm0, dword ptr [0xa63b14]
// 005427d5  090518a3cb00         or dword ptr [0xcba318], eax
// 005427db  f30f11050ca3cb00     movss dword ptr [0xcba30c], xmm0
// 005427e3  f30f110510a3cb00     movss dword ptr [0xcba310], xmm0
// 005427eb  f30f110514a3cb00     movss dword ptr [0xcba314], xmm0
// 005427f3  b80ca3cb00           mov eax, 0xcba30c
// 005427f8  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?one@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
