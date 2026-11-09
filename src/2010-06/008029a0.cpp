// from server: 100% by auto
// roc 2010-06 008029a0  unit: CXTPPropertyGrid  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008029a0
//
// 008029a0  83ec20               sub esp, 0x20
// 008029a3  56                   push esi
// 008029a4  8bf1                 mov esi, ecx
// 008029a6  837e2000             cmp dword ptr [esi + 0x20], 0
// 008029aa  7459                 je 0x802a05
// 008029ac  56                   push esi
// 008029ad  8d4c2418             lea ecx, [esp + 0x18]
// 008029b1  e85ac9ffff           call 0x7ff310
// 008029b6  8b442414             mov eax, dword ptr [esp + 0x14]
// 008029ba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008029be  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008029c2  89442404             mov dword ptr [esp + 4], eax
// 008029c6  8b442420             mov eax, dword ptr [esp + 0x20]
// 008029ca  89442410             mov dword ptr [esp + 0x10], eax
// 008029ce  2b4654               sub eax, dword ptr [esi + 0x54]
// 008029d1  894c2408             mov dword ptr [esp + 8], ecx
// 008029d5  89442408             mov dword ptr [esp + 8], eax
// 008029d9  8b442428             mov eax, dword ptr [esp + 0x28]
// 008029dd  8954240c             mov dword ptr [esp + 0xc], edx
// 008029e1  85c0                 test eax, eax
// 008029e3  740f                 je 0x8029f4
// 008029e5  8b16                 mov edx, dword ptr [esi]
// 008029e7  50                   push eax
// 008029e8  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 008029ee  6a02                 push 2
// 008029f0  8bce                 mov ecx, esi
// 008029f2  ffd0                 call eax
// 008029f4  8b5620               mov edx, dword ptr [esi + 0x20]
// 008029f7  6a00                 push 0
// 008029f9  8d4c2408             lea ecx, [esp + 8]
// 008029fd  51                   push ecx
// 008029fe  52                   push edx
// 008029ff  ff1578ba9e00         call dword ptr [0x9eba78]
// 00802a05  5e                   pop esi
// 00802a06  83c420               add esp, 0x20
// 00802a09  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSelectionChanged@CXTPPropertyGrid@@MAEXPAVCXTPPropertyGridItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGrid.cpp
