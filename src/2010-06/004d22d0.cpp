// from server: 100% by auto
// roc 2010-06 004d22d0  unit: XVCrashReporter::XV?$mf0::V?$bind_t::?$thread_data  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004d22d0
//
// 004d22d0  55                   push ebp
// 004d22d1  8bec                 mov ebp, esp
// 004d22d3  51                   push ecx
// 004d22d4  894dfc               mov dword ptr [ebp - 4], ecx
// 004d22d7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004d22da  e88104f6ff           call 0x432760
// 004d22df  8b4508               mov eax, dword ptr [ebp + 8]
// 004d22e2  83e001               and eax, 1
// 004d22e5  740c                 je 0x4d22f3
// 004d22e7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004d22ea  51                   push ecx
// 004d22eb  e8aa562d00           call 0x7a799a
// 004d22f0  83c404               add esp, 4
// 004d22f3  8b45fc               mov eax, dword ptr [ebp - 4]
// 004d22f6  8be5                 mov esp, ebp
// 004d22f8  5d                   pop ebp
// 004d22f9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
