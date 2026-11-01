// from server: 100% by auto
// roc 2010-06 00821840  unit: CSelectionCaption  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00821840
//
// 00821840  56                   push esi
// 00821841  8bf1                 mov esi, ecx
// 00821843  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 00821849  57                   push edi
// 0082184a  8b3d28bc9e00         mov edi, dword ptr [0x9ebc28]
// 00821850  50                   push eax
// 00821851  ffd7                 call edi
// 00821853  85c0                 test eax, eax
// 00821855  7423                 je 0x82187a
// 00821857  6a00                 push 0
// 00821859  8d8edc000000         lea ecx, [esi + 0xdc]
// 0082185f  e82464f8ff           call 0x7a7c88
// 00821864  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 0082186a  6a00                 push 0
// 0082186c  6a00                 push 0
// 0082186e  68f3000000           push 0xf3
// 00821873  51                   push ecx
// 00821874  ff1554ba9e00         call dword ptr [0x9eba54]
// 0082187a  8b868c010000         mov eax, dword ptr [esi + 0x18c]
// 00821880  85c0                 test eax, eax
// 00821882  7403                 je 0x821887
// 00821884  8b4020               mov eax, dword ptr [eax + 0x20]
// 00821887  50                   push eax
// 00821888  ffd7                 call edi
// 0082188a  85c0                 test eax, eax
// 0082188c  740d                 je 0x82189b
// 0082188e  8b8e8c010000         mov ecx, dword ptr [esi + 0x18c]
// 00821894  8b11                 mov edx, dword ptr [ecx]
// 00821896  8b4268               mov eax, dword ptr [edx + 0x68]
// 00821899  ffd0                 call eax
// 0082189b  8b8e8c010000         mov ecx, dword ptr [esi + 0x18c]
// 008218a1  85c9                 test ecx, ecx
// 008218a3  7413                 je 0x8218b8
// 008218a5  8b11                 mov edx, dword ptr [ecx]
// 008218a7  8b4204               mov eax, dword ptr [edx + 4]
// 008218aa  6a01                 push 1
// 008218ac  ffd0                 call eax
// 008218ae  c7868c01000000000000 mov dword ptr [esi + 0x18c], 0
// 008218b8  5f                   pop edi
// 008218b9  5e                   pop esi
// 008218ba  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaption.cpp (function ?KillChildWindow@CXTCaption@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaption.cpp
