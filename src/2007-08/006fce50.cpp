// from server: 100% by auto
// roc 2007-08 006fce50  unit: CXTPPropertyGridInplaceList  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006fce50
//
// 006fce50  83ec10               sub esp, 0x10
// 006fce53  56                   push esi
// 006fce54  8bf1                 mov esi, ecx
// 006fce56  56                   push esi
// 006fce57  8d4c2408             lea ecx, [esp + 8]
// 006fce5b  e8a031f8ff           call 0x680000
// 006fce60  8b442420             mov eax, dword ptr [esp + 0x20]
// 006fce64  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006fce68  50                   push eax
// 006fce69  51                   push ecx
// 006fce6a  8d54240c             lea edx, [esp + 0xc]
// 006fce6e  52                   push edx
// 006fce6f  ff1594ed7700         call dword ptr [0x77ed94]
// 006fce75  85c0                 test eax, eax
// 006fce77  8b06                 mov eax, dword ptr [esi]
// 006fce79  8bce                 mov ecx, esi
// 006fce7b  740f                 je 0x6fce8c
// 006fce7d  8b9064010000         mov edx, dword ptr [eax + 0x164]
// 006fce83  ffd2                 call edx
// 006fce85  5e                   pop esi
// 006fce86  83c410               add esp, 0x10
// 006fce89  c20c00               ret 0xc
// 006fce8c  8b9060010000         mov edx, dword ptr [eax + 0x160]
// 006fce92  ffd2                 call edx
// 006fce94  5e                   pop esi
// 006fce95  83c410               add esp, 0x10
// 006fce98  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnLButtonUp@CXTPPropertyGridInplaceList@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
