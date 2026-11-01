// from server: 100% by auto
// roc 2007-03 006dd1c0  unit: seg_006d0000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006dd1c0
//
// 006dd1c0  83ec10               sub esp, 0x10
// 006dd1c3  56                   push esi
// 006dd1c4  8bf1                 mov esi, ecx
// 006dd1c6  56                   push esi
// 006dd1c7  8d4c2408             lea ecx, [esp + 8]
// 006dd1cb  e890e6f8ff           call 0x66b860
// 006dd1d0  8b442420             mov eax, dword ptr [esp + 0x20]
// 006dd1d4  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006dd1d8  50                   push eax
// 006dd1d9  51                   push ecx
// 006dd1da  8d54240c             lea edx, [esp + 0xc]
// 006dd1de  52                   push edx
// 006dd1df  ff1598ed7700         call dword ptr [0x77ed98]
// 006dd1e5  85c0                 test eax, eax
// 006dd1e7  8b06                 mov eax, dword ptr [esi]
// 006dd1e9  8bce                 mov ecx, esi
// 006dd1eb  740f                 je 0x6dd1fc
// 006dd1ed  8b9064010000         mov edx, dword ptr [eax + 0x164]
// 006dd1f3  ffd2                 call edx
// 006dd1f5  5e                   pop esi
// 006dd1f6  83c410               add esp, 0x10
// 006dd1f9  c20c00               ret 0xc
// 006dd1fc  8b9060010000         mov edx, dword ptr [eax + 0x160]
// 006dd202  ffd2                 call edx
// 006dd204  5e                   pop esi
// 006dd205  83c410               add esp, 0x10
// 006dd208  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnLButtonUp@CXTPPropertyGridInplaceList@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
