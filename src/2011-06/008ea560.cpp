// from server: 100% by auto
// roc 2011-06 008ea560  unit: CXTColorBase  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ea560
//
// 008ea560  56                   push esi
// 008ea561  8bf1                 mov esi, ecx
// 008ea563  e8c600f2ff           call 0x80a62e
// 008ea568  8b4620               mov eax, dword ptr [esi + 0x20]
// 008ea56b  50                   push eax
// 008ea56c  ff15341ba400         call dword ptr [0xa41b34]
// 008ea572  50                   push eax
// 008ea573  e8b0fdf1ff           call 0x80a328
// 008ea578  8b442410             mov eax, dword ptr [esp + 0x10]
// 008ea57c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008ea580  8b16                 mov edx, dword ptr [esi]
// 008ea582  8b924c010000         mov edx, dword ptr [edx + 0x14c]
// 008ea588  50                   push eax
// 008ea589  51                   push ecx
// 008ea58a  8bce                 mov ecx, esi
// 008ea58c  ffd2                 call edx
// 008ea58e  ff15f819a400         call dword ptr [0xa419f8]
// 008ea594  50                   push eax
// 008ea595  e88efdf1ff           call 0x80a328
// 008ea59a  3bc6                 cmp eax, esi
// 008ea59c  7407                 je 0x8ea5a5
// 008ea59e  8bce                 mov ecx, esi
// 008ea5a0  e85bfef1ff           call 0x80a400
// 008ea5a5  5e                   pop esi
// 008ea5a6  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnLButtonDown@CXTPColorBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Dialog/XTPColorPageCustom.cpp
