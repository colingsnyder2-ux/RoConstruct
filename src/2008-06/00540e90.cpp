// from server: 100% by auto
// roc 2008-06 00540e90  unit: RBX::RenderBase::AggregatingSceneManager::Bucket  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540e90
//
// 00540e90  55                   push ebp
// 00540e91  8bec                 mov ebp, esp
// 00540e93  51                   push ecx
// 00540e94  894dfc               mov dword ptr [ebp - 4], ecx
// 00540e97  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00540e9a  e8a1170000           call 0x542640
// 00540e9f  8be5                 mov esp, ebp
// 00540ea1  5d                   pop ebp
// 00540ea2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
