// from server: 100% by auto
// roc 2011-06 0086a050  unit: CXTPPropertyGrid  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086a050
//
// 0086a050  83ec20               sub esp, 0x20
// 0086a053  56                   push esi
// 0086a054  8bf1                 mov esi, ecx
// 0086a056  837e2000             cmp dword ptr [esi + 0x20], 0
// 0086a05a  7459                 je 0x86a0b5
// 0086a05c  56                   push esi
// 0086a05d  8d4c2418             lea ecx, [esp + 0x18]
// 0086a061  e82a2dffff           call 0x85cd90
// 0086a066  8b442414             mov eax, dword ptr [esp + 0x14]
// 0086a06a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0086a06e  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0086a072  89442404             mov dword ptr [esp + 4], eax
// 0086a076  8b442420             mov eax, dword ptr [esp + 0x20]
// 0086a07a  89442410             mov dword ptr [esp + 0x10], eax
// 0086a07e  2b4654               sub eax, dword ptr [esi + 0x54]
// 0086a081  894c2408             mov dword ptr [esp + 8], ecx
// 0086a085  89442408             mov dword ptr [esp + 8], eax
// 0086a089  8b442428             mov eax, dword ptr [esp + 0x28]
// 0086a08d  8954240c             mov dword ptr [esp + 0xc], edx
// 0086a091  85c0                 test eax, eax
// 0086a093  740f                 je 0x86a0a4
// 0086a095  8b16                 mov edx, dword ptr [esi]
// 0086a097  50                   push eax
// 0086a098  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 0086a09e  6a02                 push 2
// 0086a0a0  8bce                 mov ecx, esi
// 0086a0a2  ffd0                 call eax
// 0086a0a4  8b5620               mov edx, dword ptr [esi + 0x20]
// 0086a0a7  6a00                 push 0
// 0086a0a9  8d4c2408             lea ecx, [esp + 8]
// 0086a0ad  51                   push ecx
// 0086a0ae  52                   push edx
// 0086a0af  ff15ec19a400         call dword ptr [0xa419ec]
// 0086a0b5  5e                   pop esi
// 0086a0b6  83c420               add esp, 0x20
// 0086a0b9  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSelectionChanged@CXTPPropertyGrid@@MAEXPAVCXTPPropertyGridItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGrid.cpp
