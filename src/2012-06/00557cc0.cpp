// roc 2012-06 00557cc0  unit: XVCrashReporter::XV?$mf0::V?$bind_t::?$thread_data  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00557cc0
//
// 00557cc0  55                   push ebp
// 00557cc1  8bec                 mov ebp, esp
// 00557cc3  51                   push ecx
// 00557cc4  894dfc               mov dword ptr [ebp - 4], ecx
// 00557cc7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00557cca  e891cfedff           call 0x434c60
// 00557ccf  8b4508               mov eax, dword ptr [ebp + 8]
// 00557cd2  83e001               and eax, 1
// 00557cd5  740c                 je 0x557ce3
// 00557cd7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00557cda  51                   push ecx
// 00557cdb  e834a44200           call 0x982114
// 00557ce0  83c404               add esp, 4
// 00557ce3  8b45fc               mov eax, dword ptr [ebp - 4]
// 00557ce6  8be5                 mov esp, ebp
// 00557ce8  5d                   pop ebp
// 00557ce9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
