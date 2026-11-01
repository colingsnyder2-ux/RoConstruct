// from server: 100% by auto
// roc 2011-06 008e5b30  unit: CXTPPropertyGridInplaceList  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e5b30
//
// 008e5b30  83ec10               sub esp, 0x10
// 008e5b33  56                   push esi
// 008e5b34  8bf1                 mov esi, ecx
// 008e5b36  56                   push esi
// 008e5b37  8d4c2408             lea ecx, [esp + 8]
// 008e5b3b  e85072f7ff           call 0x85cd90
// 008e5b40  8b442420             mov eax, dword ptr [esp + 0x20]
// 008e5b44  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008e5b48  50                   push eax
// 008e5b49  51                   push ecx
// 008e5b4a  8d54240c             lea edx, [esp + 0xc]
// 008e5b4e  52                   push edx
// 008e5b4f  ff15101ca400         call dword ptr [0xa41c10]
// 008e5b55  85c0                 test eax, eax
// 008e5b57  8b06                 mov eax, dword ptr [esi]
// 008e5b59  8bce                 mov ecx, esi
// 008e5b5b  740f                 je 0x8e5b6c
// 008e5b5d  8b906c010000         mov edx, dword ptr [eax + 0x16c]
// 008e5b63  ffd2                 call edx
// 008e5b65  5e                   pop esi
// 008e5b66  83c410               add esp, 0x10
// 008e5b69  c20c00               ret 0xc
// 008e5b6c  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 008e5b72  ffd2                 call edx
// 008e5b74  5e                   pop esi
// 008e5b75  83c410               add esp, 0x10
// 008e5b78  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnLButtonUp@CXTPPropertyGridInplaceList@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
