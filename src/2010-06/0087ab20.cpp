// from server: 100% by tester
// roc 2012-06 00a56af0  unit: CXTPPropertyGridInplaceButtons  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a56af0
//
// 00a56af0  56                   push esi
// 00a56af1  8bf1                 mov esi, ecx
// 00a56af3  8d8e84000000         lea ecx, [esi + 0x84]
// 00a56af9  ff15d047b200         call dword ptr [0xb247d0]
// 00a56aff  8d8e80000000         lea ecx, [esi + 0x80]
// 00a56b05  ff15d047b200         call dword ptr [0xb247d0]
// 00a56b0b  8d4e7c               lea ecx, [esi + 0x7c]
// 00a56b0e  ff15d047b200         call dword ptr [0xb247d0]
// 00a56b14  8d4e78               lea ecx, [esi + 0x78]
// 00a56b17  ff15d047b200         call dword ptr [0xb247d0]
// 00a56b1d  8d4e74               lea ecx, [esi + 0x74]
// 00a56b20  ff15d047b200         call dword ptr [0xb247d0]
// 00a56b26  8d4e70               lea ecx, [esi + 0x70]
// 00a56b29  ff15d047b200         call dword ptr [0xb247d0]
// 00a56b2f  8bce                 mov ecx, esi
// 00a56b31  5e                   pop esi
// 00a56b32  e97d2a0400           jmp 0xa995b4
// library xtp-15.2.1-shared-mfc/Source\Controls\Edit\XTPEdit.cpp (function ??1?$CXTPMaskEditT@VCEdit@@@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Edit/XTPEdit.cpp
