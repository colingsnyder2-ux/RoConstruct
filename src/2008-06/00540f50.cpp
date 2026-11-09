// from server: 100% by auto
// roc 2008-06 00540f50  unit: RBX::RenderBase::AggregatingSceneManager::Bucket  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540f50
//
// 00540f50  55                   push ebp
// 00540f51  8bec                 mov ebp, esp
// 00540f53  51                   push ecx
// 00540f54  894dfc               mov dword ptr [ebp - 4], ecx
// 00540f57  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00540f5a  e8b1170000           call 0x542710
// 00540f5f  8b45fc               mov eax, dword ptr [ebp - 4]
// 00540f62  8be5                 mov esp, ebp
// 00540f64  5d                   pop ebp
// 00540f65  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
