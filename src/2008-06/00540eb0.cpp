// from server: 100% by auto
// roc 2008-06 00540eb0  unit: RBX::RenderBase::AggregatingSceneManager::Bucket  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540eb0
//
// 00540eb0  55                   push ebp
// 00540eb1  8bec                 mov ebp, esp
// 00540eb3  51                   push ecx
// 00540eb4  894dfc               mov dword ptr [ebp - 4], ecx
// 00540eb7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00540eba  e8a1170000           call 0x542660
// 00540ebf  8b45fc               mov eax, dword ptr [ebp - 4]
// 00540ec2  8be5                 mov esp, ebp
// 00540ec4  5d                   pop ebp
// 00540ec5  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
