// from server: 100% by auto
// roc 2011-06 008f5460  unit: CXTPTabPaintManager::CColorSetDefault  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f5460
//
// 008f5460  56                   push esi
// 008f5461  57                   push edi
// 008f5462  e879fff4ff           call 0x8453e0
// 008f5467  6a10                 push 0x10
// 008f5469  8bc8                 mov ecx, eax
// 008f546b  e840f7f4ff           call 0x844bb0
// 008f5470  8bf0                 mov esi, eax
// 008f5472  e869fff4ff           call 0x8453e0
// 008f5477  6a14                 push 0x14
// 008f5479  8bc8                 mov ecx, eax
// 008f547b  e830f7f4ff           call 0x844bb0
// 008f5480  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f5484  83792000             cmp dword ptr [ecx + 0x20], 0
// 008f5488  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008f548c  7437                 je 0x8f54c5
// 008f548e  83792400             cmp dword ptr [ecx + 0x24], 0
// 008f5492  741b                 je 0x8f54af
// 008f5494  50                   push eax
// 008f5495  56                   push esi
// 008f5496  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 008f549a  56                   push esi
// 008f549b  8bcf                 mov ecx, edi
// 008f549d  e87859f1ff           call 0x80ae1a
// 008f54a2  6a01                 push 1
// 008f54a4  6a01                 push 1
// 008f54a6  56                   push esi
// 008f54a7  ff15601ca400         call dword ptr [0xa41c60]
// 008f54ad  eb16                 jmp 0x8f54c5
// 008f54af  8b510c               mov edx, dword ptr [ecx + 0xc]
// 008f54b2  394a10               cmp dword ptr [edx + 0x10], ecx
// 008f54b5  750e                 jne 0x8f54c5
// 008f54b7  56                   push esi
// 008f54b8  50                   push eax
// 008f54b9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f54bd  50                   push eax
// 008f54be  8bcf                 mov ecx, edi
// 008f54c0  e85559f1ff           call 0x80ae1a
// 008f54c5  e816fff4ff           call 0x8453e0
// 008f54ca  6a12                 push 0x12
// 008f54cc  8bc8                 mov ecx, eax
// 008f54ce  e8ddf6f4ff           call 0x844bb0
// 008f54d3  8b17                 mov edx, dword ptr [edi]
// 008f54d5  50                   push eax
// 008f54d6  8b4238               mov eax, dword ptr [edx + 0x38]
// 008f54d9  8bcf                 mov ecx, edi
// 008f54db  ffd0                 call eax
// 008f54dd  5f                   pop edi
// 008f54de  5e                   pop esi
// 008f54df  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?FillNavigateButton@CColorSetDefault@CXTPTabPaintManager@@UAEXPAVCDC@@PAVCXTPTabManagerNavigateButton@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/TabManager/XTPTabPaintManagerColors.cpp
