// from server: 100% by auto
// roc 2010-06 00437c50  unit: HVCXTPPropertyGridItem::?$XItem  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00437c50
//
// 00437c50  8b542404             mov edx, dword ptr [esp + 4]
// 00437c54  f30f1001             movss xmm0, dword ptr [ecx]
// 00437c58  0f2e02               ucomiss xmm0, dword ptr [edx]
// 00437c5b  9f                   lahf 
// 00437c5c  f6c444               test ah, 0x44
// 00437c5f  7a26                 jp 0x437c87
// 00437c61  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 00437c66  0f2e4204             ucomiss xmm0, dword ptr [edx + 4]
// 00437c6a  9f                   lahf 
// 00437c6b  f6c444               test ah, 0x44
// 00437c6e  7a17                 jp 0x437c87
// 00437c70  f30f104108           movss xmm0, dword ptr [ecx + 8]
// 00437c75  0f2e4208             ucomiss xmm0, dword ptr [edx + 8]
// 00437c79  9f                   lahf 
// 00437c7a  f6c444               test ah, 0x44
// 00437c7d  7a08                 jp 0x437c87
// 00437c7f  b801000000           mov eax, 1
// 00437c84  c20400               ret 4
// 00437c87  33c0                 xor eax, eax
// 00437c89  c20400               ret 4
// library rbx2016-g3d/CollisionDetection.cpp (function ??8Vector3@G3D@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CollisionDetection.cpp
