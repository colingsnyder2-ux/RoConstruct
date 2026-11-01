// from server: 100% by auto
// roc 2007-03 0067b9f0  unit: seg_00670000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067b9f0
//
// 0067b9f0  33c0                 xor eax, eax
// 0067b9f2  56                   push esi
// 0067b9f3  8bf1                 mov esi, ecx
// 0067b9f5  c706c8d47c00         mov dword ptr [esi], 0x7cd4c8
// 0067b9fb  894604               mov dword ptr [esi + 4], eax
// 0067b9fe  894608               mov dword ptr [esi + 8], eax
// 0067ba01  89460c               mov dword ptr [esi + 0xc], eax
// 0067ba04  894610               mov dword ptr [esi + 0x10], eax
// 0067ba07  e8c4ffffff           call 0x67b9d0
// 0067ba0c  83c024               add eax, 0x24
// 0067ba0f  56                   push esi
// 0067ba10  8bc8                 mov ecx, eax
// 0067ba12  e84ff80b00           call 0x73b266
// 0067ba17  c7460c14000000       mov dword ptr [esi + 0xc], 0x14
// 0067ba1e  8bc6                 mov eax, esi
// 0067ba20  5e                   pop esi
// 0067ba21  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ??0CXTThemeManagerStyleFactory@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
