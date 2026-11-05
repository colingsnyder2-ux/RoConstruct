// from server: 100% by auto
// roc 2011-06 00542840  unit: G3D::Sphere  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00542840
//
// 00542840  b801000000           mov eax, 1
// 00542845  840538a3cb00         test byte ptr [0xcba338], al
// 0054284b  7529                 jne 0x542876
// 0054284d  0f57c0               xorps xmm0, xmm0
// 00542850  f30f100d143ba600     movss xmm1, dword ptr [0xa63b14]
// 00542858  090538a3cb00         or dword ptr [0xcba338], eax
// 0054285e  f30f11052ca3cb00     movss dword ptr [0xcba32c], xmm0
// 00542866  f30f110d30a3cb00     movss dword ptr [0xcba330], xmm1
// 0054286e  f30f110534a3cb00     movss dword ptr [0xcba334], xmm0
// 00542876  b82ca3cb00           mov eax, 0xcba32c
// 0054287b  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitY@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
