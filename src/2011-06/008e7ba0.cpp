// from server: 100% by auto
// roc 2011-06 008e7ba0  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e7ba0
//
// 008e7ba0  53                   push ebx
// 008e7ba1  56                   push esi
// 008e7ba2  57                   push edi
// 008e7ba3  8bf1                 mov esi, ecx
// 008e7ba5  e8842af2ff           call 0x80a62e
// 008e7baa  ff15f819a400         call dword ptr [0xa419f8]
// 008e7bb0  50                   push eax
// 008e7bb1  e87227f2ff           call 0x80a328
// 008e7bb6  3bc6                 cmp eax, esi
// 008e7bb8  7407                 je 0x8e7bc1
// 008e7bba  8bce                 mov ecx, esi
// 008e7bbc  e83f28f2ff           call 0x80a400
// 008e7bc1  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 008e7bc5  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 008e7bc9  57                   push edi
// 008e7bca  53                   push ebx
// 008e7bcb  8bce                 mov ecx, esi
// 008e7bcd  e8befaffff           call 0x8e7690
// 008e7bd2  83f8ff               cmp eax, -1
// 008e7bd5  7437                 je 0x8e7c0e
// 008e7bd7  57                   push edi
// 008e7bd8  53                   push ebx
// 008e7bd9  8bce                 mov ecx, esi
// 008e7bdb  e860feffff           call 0x8e7a40
// 008e7be0  8b4620               mov eax, dword ptr [esi + 0x20]
// 008e7be3  c7466001000000       mov dword ptr [esi + 0x60], 1
// 008e7bea  8b35b819a400         mov esi, dword ptr [0xa419b8]
// 008e7bf0  50                   push eax
// 008e7bf1  ffd6                 call esi
// 008e7bf3  50                   push eax
// 008e7bf4  e82f27f2ff           call 0x80a328
// 008e7bf9  8b4820               mov ecx, dword ptr [eax + 0x20]
// 008e7bfc  51                   push ecx
// 008e7bfd  ffd6                 call esi
// 008e7bff  50                   push eax
// 008e7c00  e82327f2ff           call 0x80a328
// 008e7c05  6a01                 push 1
// 008e7c07  8bc8                 mov ecx, eax
// 008e7c09  e896510e00           call 0x9ccda4
// 008e7c0e  5f                   pop edi
// 008e7c0f  5e                   pop esi
// 008e7c10  5b                   pop ebx
// 008e7c11  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnLButtonDblClk@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
