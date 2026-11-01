// from server: 100% by auto
// roc 2009-12 0085a730  unit: CXTThemeManager  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a730
//
// 0085a730  33c0                 xor eax, eax
// 0085a732  56                   push esi
// 0085a733  8bf1                 mov esi, ecx
// 0085a735  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0085a739  c706b8d19f00         mov dword ptr [esi], 0x9fd1b8
// 0085a73f  894604               mov dword ptr [esi + 4], eax
// 0085a742  894610               mov dword ptr [esi + 0x10], eax
// 0085a745  89460c               mov dword ptr [esi + 0xc], eax
// 0085a748  894614               mov dword ptr [esi + 0x14], eax
// 0085a74b  894608               mov dword ptr [esi + 8], eax
// 0085a74e  3bc8                 cmp ecx, eax
// 0085a750  7408                 je 0x85a75a
// 0085a752  51                   push ecx
// 0085a753  8bce                 mov ecx, esi
// 0085a755  e806ffffff           call 0x85a660
// 0085a75a  8bc6                 mov eax, esi
// 0085a75c  5e                   pop esi
// 0085a75d  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ??0CXTThemeManagerStyleHost@@IAE@PAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
