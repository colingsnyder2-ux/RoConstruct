// from server: 100% by auto
// roc 2010-06 00881ea0  unit: CXTPPropertyGridInplaceList  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00881ea0
//
// 00881ea0  83ec10               sub esp, 0x10
// 00881ea3  56                   push esi
// 00881ea4  8bf1                 mov esi, ecx
// 00881ea6  56                   push esi
// 00881ea7  8d4c2408             lea ecx, [esp + 8]
// 00881eab  e860d4f7ff           call 0x7ff310
// 00881eb0  8b442420             mov eax, dword ptr [esp + 0x20]
// 00881eb4  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00881eb8  50                   push eax
// 00881eb9  51                   push ecx
// 00881eba  8d54240c             lea edx, [esp + 0xc]
// 00881ebe  52                   push edx
// 00881ebf  ff15e0bb9e00         call dword ptr [0x9ebbe0]
// 00881ec5  85c0                 test eax, eax
// 00881ec7  8b06                 mov eax, dword ptr [esi]
// 00881ec9  8bce                 mov ecx, esi
// 00881ecb  740f                 je 0x881edc
// 00881ecd  8b906c010000         mov edx, dword ptr [eax + 0x16c]
// 00881ed3  ffd2                 call edx
// 00881ed5  5e                   pop esi
// 00881ed6  83c410               add esp, 0x10
// 00881ed9  c20c00               ret 0xc
// 00881edc  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 00881ee2  ffd2                 call edx
// 00881ee4  5e                   pop esi
// 00881ee5  83c410               add esp, 0x10
// 00881ee8  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnLButtonUp@CXTPPropertyGridInplaceList@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
