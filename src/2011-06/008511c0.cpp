// from server: 100% by auto
// roc 2011-06 008511c0  unit: CXTPToolBar::CControlButtonExpand  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008511c0
//
// 008511c0  56                   push esi
// 008511c1  8bf1                 mov esi, ecx
// 008511c3  8d4e04               lea ecx, [esi + 4]
// 008511c6  c7065882ac00         mov dword ptr [esi], 0xac8258
// 008511cc  ff15b42da400         call dword ptr [0xa42db4]
// 008511d2  33c0                 xor eax, eax
// 008511d4  894608               mov dword ptr [esi + 8], eax
// 008511d7  89460c               mov dword ptr [esi + 0xc], eax
// 008511da  894610               mov dword ptr [esi + 0x10], eax
// 008511dd  894614               mov dword ptr [esi + 0x14], eax
// 008511e0  894618               mov dword ptr [esi + 0x18], eax
// 008511e3  89461c               mov dword ptr [esi + 0x1c], eax
// 008511e6  894620               mov dword ptr [esi + 0x20], eax
// 008511e9  8bc6                 mov eax, esi
// 008511eb  5e                   pop esi
// 008511ec  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPSystemHelpers.cpp (function ??0CXTPModuleHandle@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPSystemHelpers.cpp
