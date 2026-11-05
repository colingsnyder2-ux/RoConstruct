// from server: 100% by auto
// roc 2010-06 007c81c0  unit: CXTPCommandBars  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c81c0
//
// 007c81c0  83ec24               sub esp, 0x24
// 007c81c3  53                   push ebx
// 007c81c4  55                   push ebp
// 007c81c5  8be9                 mov ebp, ecx
// 007c81c7  8b85a0000000         mov eax, dword ptr [ebp + 0xa0]
// 007c81cd  56                   push esi
// 007c81ce  57                   push edi
// 007c81cf  c74424141be80000     mov dword ptr [esp + 0x14], 0xe81b
// 007c81d7  c744241800280000     mov dword ptr [esp + 0x18], 0x2800
// 007c81df  c744241c1ee80000     mov dword ptr [esp + 0x1c], 0xe81e
// 007c81e7  c744242000820000     mov dword ptr [esp + 0x20], 0x8200
// 007c81ef  c74424241ce80000     mov dword ptr [esp + 0x24], 0xe81c
// 007c81f7  c744242800140000     mov dword ptr [esp + 0x28], 0x1400
// 007c81ff  c744242c1de80000     mov dword ptr [esp + 0x2c], 0xe81d
// 007c8207  c744243000410000     mov dword ptr [esp + 0x30], 0x4100
// 007c820f  89442410             mov dword ptr [esp + 0x10], eax
// 007c8213  33f6                 xor esi, esi
// 007c8215  8d9d90000000         lea ebx, [ebp + 0x90]
// 007c821b  eb03                 jmp 0x7c8220
// 007c821d  8d4900               lea ecx, [ecx]
// 007c8220  8b0d7c55c200         mov ecx, dword ptr [0xc2557c]
// 007c8226  e87701feff           call 0x7a83a2
// 007c822b  8b4cf414             mov ecx, dword ptr [esp + esi*8 + 0x14]
// 007c822f  8b54f418             mov edx, dword ptr [esp + esi*8 + 0x18]
// 007c8233  51                   push ecx
// 007c8234  8bf8                 mov edi, eax
// 007c8236  8b442414             mov eax, dword ptr [esp + 0x14]
// 007c823a  81ca00000056         or edx, 0x56000000
// 007c8240  52                   push edx
// 007c8241  50                   push eax
// 007c8242  8bcf                 mov ecx, edi
// 007c8244  896f6c               mov dword ptr [edi + 0x6c], ebp
// 007c8247  e824cf0700           call 0x845170
// 007c824c  85c0                 test eax, eax
// 007c824e  7505                 jne 0x7c8255
// 007c8250  e8b54c1b00           call 0x97cf0a
// 007c8255  893b                 mov dword ptr [ebx], edi
// 007c8257  46                   inc esi
// 007c8258  83c304               add ebx, 4
// 007c825b  83fe04               cmp esi, 4
// 007c825e  7cc0                 jl 0x7c8220
// 007c8260  5f                   pop edi
// 007c8261  5e                   pop esi
// 007c8262  5d                   pop ebp
// 007c8263  5b                   pop ebx
// 007c8264  83c424               add esp, 0x24
// 007c8267  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?EnableDocking@CXTPCommandBars@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
