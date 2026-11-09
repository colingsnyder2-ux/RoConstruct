// from server: 100% by auto
// roc 2010-06 00888690  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00888690
//
// 00888690  56                   push esi
// 00888691  6a00                 push 0
// 00888693  6a00                 push 0
// 00888695  8bf1                 mov esi, ecx
// 00888697  6a00                 push 0
// 00888699  6a00                 push 0
// 0088869b  8d4604               lea eax, [esi + 4]
// 0088869e  50                   push eax
// 0088869f  c706c4eea600         mov dword ptr [esi], 0xa6eec4
// 008886a5  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 008886ac  ff15c0bb9e00         call dword ptr [0x9ebbc0]
// 008886b2  c74614feffffff       mov dword ptr [esi + 0x14], 0xfffffffe
// 008886b9  c7462000000000       mov dword ptr [esi + 0x20], 0
// 008886c0  8bc6                 mov eax, esi
// 008886c2  5e                   pop esi
// 008886c3  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ??0CAppearanceSet@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
