// from server: 100% by auto
// roc 2009-06 005be140  unit: RBX::AggregatingSceneManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005be140
//
// 005be140  55                   push ebp
// 005be141  8bec                 mov ebp, esp
// 005be143  51                   push ecx
// 005be144  894dfc               mov dword ptr [ebp - 4], ecx
// 005be147  8b4508               mov eax, dword ptr [ebp + 8]
// 005be14a  50                   push eax
// 005be14b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005be14e  e8fd81f6ff           call 0x526350
// 005be153  8be5                 mov esp, ebp
// 005be155  5d                   pop ebp
// 005be156  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??8SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
