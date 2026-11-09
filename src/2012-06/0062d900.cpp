// from server: 100% by auto
// roc 2012-06 0062d900  unit: G3D::Line  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062d900
//
// 0062d900  83ec0c               sub esp, 0xc
// 0062d903  6a02                 push 2
// 0062d905  8d442404             lea eax, [esp + 4]
// 0062d909  50                   push eax
// 0062d90a  e8d1e9ffff           call 0x62c2e0
// 0062d90f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0062d913  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 0062d91b  f30f1008             movss xmm1, dword ptr [eax]
// 0062d91f  0f57c8               xorps xmm1, xmm0
// 0062d922  f30f1109             movss dword ptr [ecx], xmm1
// 0062d926  f30f104804           movss xmm1, dword ptr [eax + 4]
// 0062d92b  0f57c8               xorps xmm1, xmm0
// 0062d92e  f30f114904           movss dword ptr [ecx + 4], xmm1
// 0062d933  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0062d938  0f57c8               xorps xmm1, xmm0
// 0062d93b  f30f114908           movss dword ptr [ecx + 8], xmm1
// 0062d940  8bc1                 mov eax, ecx
// 0062d942  83c40c               add esp, 0xc
// 0062d945  c20400               ret 4
// library rbx2016-g3d/CoordinateFrame.cpp (function ?lookVector@CoordinateFrame@G3D@@QBE?AVVector3@2@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CoordinateFrame.cpp
