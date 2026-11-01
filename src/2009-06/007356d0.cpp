// from server: 100% by auto
// roc 2009-06 007356d0  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007356d0
//
// 007356d0  83ec0c               sub esp, 0xc
// 007356d3  53                   push ebx
// 007356d4  8bd9                 mov ebx, ecx
// 007356d6  8b432c               mov eax, dword ptr [ebx + 0x2c]
// 007356d9  f7d8                 neg eax
// 007356db  1bc0                 sbb eax, eax
// 007356dd  89442404             mov dword ptr [esp + 4], eax
// 007356e1  7440                 je 0x735723
// 007356e3  56                   push esi
// 007356e4  57                   push edi
// 007356e5  8d7b20               lea edi, [ebx + 0x20]
// 007356e8  eb06                 jmp 0x7356f0
// 007356ea  8d9b00000000         lea ebx, [ebx]
// 007356f0  8d442410             lea eax, [esp + 0x10]
// 007356f4  50                   push eax
// 007356f5  8d4c2418             lea ecx, [esp + 0x18]
// 007356f9  51                   push ecx
// 007356fa  8d542414             lea edx, [esp + 0x14]
// 007356fe  52                   push edx
// 007356ff  8bcf                 mov ecx, edi
// 00735701  e86ad90500           call 0x793070
// 00735706  8b742410             mov esi, dword ptr [esp + 0x10]
// 0073570a  6a01                 push 1
// 0073570c  8bce                 mov ecx, esi
// 0073570e  e8bdfeffff           call 0x7355d0
// 00735713  8bce                 mov ecx, esi
// 00735715  e88e38feff           call 0x718fa8
// 0073571a  837c240c00           cmp dword ptr [esp + 0xc], 0
// 0073571f  75cf                 jne 0x7356f0
// 00735721  5f                   pop edi
// 00735722  5e                   pop esi
// 00735723  8d4b20               lea ecx, [ebx + 0x20]
// 00735726  5b                   pop ebx
// 00735727  83c40c               add esp, 0xc
// 0073572a  e951cfffff           jmp 0x732680
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?RemoveAll@CXTPImageManagerIconSet@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
