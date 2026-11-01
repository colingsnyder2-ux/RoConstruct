// from server: 100% by auto
// roc 2009-06 004cf1c0  unit: XVCrashReporter::XV?$mf1::V?$bind_t::?$thread_data  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004cf1c0
//
// 004cf1c0  55                   push ebp
// 004cf1c1  8bec                 mov ebp, esp
// 004cf1c3  51                   push ecx
// 004cf1c4  894dfc               mov dword ptr [ebp - 4], ecx
// 004cf1c7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004cf1ca  e8e14bffff           call 0x4c3db0
// 004cf1cf  8b4508               mov eax, dword ptr [ebp + 8]
// 004cf1d2  83e001               and eax, 1
// 004cf1d5  740c                 je 0x4cf1e3
// 004cf1d7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004cf1da  51                   push ecx
// 004cf1db  e852982400           call 0x718a32
// 004cf1e0  83c404               add esp, 4
// 004cf1e3  8b45fc               mov eax, dword ptr [ebp - 4]
// 004cf1e6  8be5                 mov esp, ebp
// 004cf1e8  5d                   pop ebp
// 004cf1e9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
