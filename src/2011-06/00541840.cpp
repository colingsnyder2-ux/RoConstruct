// from server: 100% by auto
// roc 2011-06 00541840  unit: G3D::Sphere  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00541840
//
// 00541840  83ec0c               sub esp, 0xc
// 00541843  6a02                 push 2
// 00541845  8d442404             lea eax, [esp + 4]
// 00541849  50                   push eax
// 0054184a  e891e8ffff           call 0x5400e0
// 0054184f  f30f1005dc5ca700     movss xmm0, dword ptr [0xa75cdc]
// 00541857  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0054185b  0f28c8               movaps xmm1, xmm0
// 0054185e  f30f5c08             subss xmm1, dword ptr [eax]
// 00541862  f30f1109             movss dword ptr [ecx], xmm1
// 00541866  0f28c8               movaps xmm1, xmm0
// 00541869  f30f5c4804           subss xmm1, dword ptr [eax + 4]
// 0054186e  f30f5c4008           subss xmm0, dword ptr [eax + 8]
// 00541873  f30f114904           movss dword ptr [ecx + 4], xmm1
// 00541878  f30f114108           movss dword ptr [ecx + 8], xmm0
// 0054187d  8bc1                 mov eax, ecx
// 0054187f  83c40c               add esp, 0xc
// 00541882  c20400               ret 4
// library rbx2016-g3d/CoordinateFrame.cpp (function ?lookVector@CoordinateFrame@G3D@@QBE?AVVector3@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CoordinateFrame.cpp
