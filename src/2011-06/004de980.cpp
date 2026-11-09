// from server: 100% by auto
// roc 2011-06 004de980  unit: XVCrashReporter::XV?$mf0::V?$bind_t::?$thread_data  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004de980
//
// 004de980  55                   push ebp
// 004de981  8bec                 mov ebp, esp
// 004de983  51                   push ecx
// 004de984  894dfc               mov dword ptr [ebp - 4], ecx
// 004de987  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004de98a  e8d139f6ff           call 0x442360
// 004de98f  8b4508               mov eax, dword ptr [ebp + 8]
// 004de992  83e001               and eax, 1
// 004de995  740c                 je 0x4de9a3
// 004de997  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004de99a  51                   push ecx
// 004de99b  e8b8b63200           call 0x80a058
// 004de9a0  83c404               add esp, 4
// 004de9a3  8b45fc               mov eax, dword ptr [ebp - 4]
// 004de9a6  8be5                 mov esp, ebp
// 004de9a8  5d                   pop ebp
// 004de9a9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
