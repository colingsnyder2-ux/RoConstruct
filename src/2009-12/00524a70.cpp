// from server: 100% by auto
// roc 2009-12 00524a70  unit: XVCrashReporter::XV?$mf0::V?$bind_t::?$thread_data  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00524a70
//
// 00524a70  55                   push ebp
// 00524a71  8bec                 mov ebp, esp
// 00524a73  51                   push ecx
// 00524a74  894dfc               mov dword ptr [ebp - 4], ecx
// 00524a77  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00524a7a  e871d6feff           call 0x5120f0
// 00524a7f  8b4508               mov eax, dword ptr [ebp + 8]
// 00524a82  83e001               and eax, 1
// 00524a85  740c                 je 0x524a93
// 00524a87  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00524a8a  51                   push ecx
// 00524a8b  e8caed2c00           call 0x7f385a
// 00524a90  83c404               add esp, 4
// 00524a93  8b45fc               mov eax, dword ptr [ebp - 4]
// 00524a96  8be5                 mov esp, ebp
// 00524a98  5d                   pop ebp
// 00524a99  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
