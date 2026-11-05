// from server: 100% by auto
// roc 2012-06 00758b40  unit: RBX::PartInstance  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00758b40
//
// 00758b40  b801000000           mov eax, 1
// 00758b45  84050865e300         test byte ptr [0xe36508], al
// 00758b4b  7526                 jne 0x758b73
// 00758b4d  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 00758b55  09050865e300         or dword ptr [0xe36508], eax
// 00758b5b  f30f1105fc64e300     movss dword ptr [0xe364fc], xmm0
// 00758b63  f30f11050065e300     movss dword ptr [0xe36500], xmm0
// 00758b6b  f30f11050465e300     movss dword ptr [0xe36504], xmm0
// 00758b73  b8fc64e300           mov eax, 0xe364fc
// 00758b78  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?one@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
