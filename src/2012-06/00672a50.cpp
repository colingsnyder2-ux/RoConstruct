// roc 2012-06 00672a50  unit: RBX::CRenderSettings  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00672a50
//
// 00672a50  55                   push ebp
// 00672a51  8bec                 mov ebp, esp
// 00672a53  51                   push ecx
// 00672a54  894dfc               mov dword ptr [ebp - 4], ecx
// 00672a57  8b45fc               mov eax, dword ptr [ebp - 4]
// 00672a5a  8be5                 mov esp, ebp
// 00672a5c  5d                   pop ebp
// 00672a5d  c3                   ret 
// library wildmagic-2-core/Geometry\WmlAxisAlignedBox2.cpp (function ?XMin@?$AxisAlignedBox2@M@Wml@@QAEAAMXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlAxisAlignedBox2.cpp
