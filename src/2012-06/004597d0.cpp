// from server: 100% by auto
// roc 2012-06 004597d0  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004597d0
//
// 004597d0  8b542404             mov edx, dword ptr [esp + 4]
// 004597d4  f30f1001             movss xmm0, dword ptr [ecx]
// 004597d8  0f2e02               ucomiss xmm0, dword ptr [edx]
// 004597db  9f                   lahf 
// 004597dc  f6c444               test ah, 0x44
// 004597df  7a26                 jp 0x459807
// 004597e1  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 004597e6  0f2e4204             ucomiss xmm0, dword ptr [edx + 4]
// 004597ea  9f                   lahf 
// 004597eb  f6c444               test ah, 0x44
// 004597ee  7a17                 jp 0x459807
// 004597f0  f30f104108           movss xmm0, dword ptr [ecx + 8]
// 004597f5  0f2e4208             ucomiss xmm0, dword ptr [edx + 8]
// 004597f9  9f                   lahf 
// 004597fa  f6c444               test ah, 0x44
// 004597fd  7a08                 jp 0x459807
// 004597ff  b801000000           mov eax, 1
// 00459804  c20400               ret 4
// 00459807  33c0                 xor eax, eax
// 00459809  c20400               ret 4
// library rbx2016-g3d/CollisionDetection.cpp (function ??8Vector3@G3D@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CollisionDetection.cpp
