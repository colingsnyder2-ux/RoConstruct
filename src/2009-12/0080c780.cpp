// from server: 100% by auto
// roc 2009-12 0080c780  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080c780
//
// 0080c780  83ec0c               sub esp, 0xc
// 0080c783  53                   push ebx
// 0080c784  8bd9                 mov ebx, ecx
// 0080c786  8b432c               mov eax, dword ptr [ebx + 0x2c]
// 0080c789  f7d8                 neg eax
// 0080c78b  1bc0                 sbb eax, eax
// 0080c78d  89442404             mov dword ptr [esp + 4], eax
// 0080c791  7440                 je 0x80c7d3
// 0080c793  56                   push esi
// 0080c794  57                   push edi
// 0080c795  8d7b20               lea edi, [ebx + 0x20]
// 0080c798  eb06                 jmp 0x80c7a0
// 0080c79a  8d9b00000000         lea ebx, [ebx]
// 0080c7a0  8d442410             lea eax, [esp + 0x10]
// 0080c7a4  50                   push eax
// 0080c7a5  8d4c2418             lea ecx, [esp + 0x18]
// 0080c7a9  51                   push ecx
// 0080c7aa  8d542414             lea edx, [esp + 0x14]
// 0080c7ae  52                   push edx
// 0080c7af  8bcf                 mov ecx, edi
// 0080c7b1  e86ad0ffff           call 0x809820
// 0080c7b6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0080c7ba  6a01                 push 1
// 0080c7bc  8bce                 mov ecx, esi
// 0080c7be  e8bdfeffff           call 0x80c680
// 0080c7c3  8bce                 mov ecx, esi
// 0080c7c5  e81276feff           call 0x7f3ddc
// 0080c7ca  837c240c00           cmp dword ptr [esp + 0xc], 0
// 0080c7cf  75cf                 jne 0x80c7a0
// 0080c7d1  5f                   pop edi
// 0080c7d2  5e                   pop esi
// 0080c7d3  8d4b20               lea ecx, [ebx + 0x20]
// 0080c7d6  5b                   pop ebx
// 0080c7d7  83c40c               add esp, 0xc
// 0080c7da  e9419dfeff           jmp 0x7f6520
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?RemoveAll@CXTPImageManagerIconSet@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
