// from server: 100% by auto
// roc 2009-12 004e9a80  unit: seg_004e0000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004e9a80
//
// 004e9a80  55                   push ebp
// 004e9a81  8bec                 mov ebp, esp
// 004e9a83  51                   push ecx
// 004e9a84  894dfc               mov dword ptr [ebp - 4], ecx
// 004e9a87  8b45fc               mov eax, dword ptr [ebp - 4]
// 004e9a8a  83c048               add eax, 0x48
// 004e9a8d  8be5                 mov esp, ebp
// 004e9a8f  5d                   pop ebp
// 004e9a90  c3                   ret 
// library wildmagic-2-core/Geometry\WmlCircle3.cpp (function ?Center@?$Circle3@N@Wml@@QBEABV?$Vector3@N@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlCircle3.cpp
