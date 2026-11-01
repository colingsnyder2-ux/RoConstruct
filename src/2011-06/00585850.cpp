// from server: 100% by auto
// roc 2011-06 00585850  unit: RBX::CRenderSettings  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00585850
//
// 00585850  55                   push ebp
// 00585851  8bec                 mov ebp, esp
// 00585853  51                   push ecx
// 00585854  894dfc               mov dword ptr [ebp - 4], ecx
// 00585857  8b45fc               mov eax, dword ptr [ebp - 4]
// 0058585a  83c030               add eax, 0x30
// 0058585d  8be5                 mov esp, ebp
// 0058585f  5d                   pop ebp
// 00585860  c3                   ret 
// library wildmagic-2-core/Geometry\WmlBox2.cpp (function ?Extents@?$Box2@N@Wml@@QBEPBNXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlBox2.cpp
