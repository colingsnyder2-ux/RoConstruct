// from server: 100% by auto
// roc 2009-06 00748460  unit: CXTPReportControl  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748460
//
// 00748460  83ec0c               sub esp, 0xc
// 00748463  53                   push ebx
// 00748464  8b1de0ed8900         mov ebx, dword ptr [0x89ede0]
// 0074846a  57                   push edi
// 0074846b  8bf9                 mov edi, ecx
// 0074846d  8b4720               mov eax, dword ptr [edi + 0x20]
// 00748470  50                   push eax
// 00748471  ffd3                 call ebx
// 00748473  85c0                 test eax, eax
// 00748475  7508                 jne 0x74847f
// 00748477  5f                   pop edi
// 00748478  5b                   pop ebx
// 00748479  83c40c               add esp, 0xc
// 0074847c  c20800               ret 8
// 0074847f  56                   push esi
// 00748480  8b742420             mov esi, dword ptr [esp + 0x20]
// 00748484  85f6                 test esi, esi
// 00748486  7504                 jne 0x74848c
// 00748488  8d74240c             lea esi, [esp + 0xc]
// 0074848c  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 0074848f  890e                 mov dword ptr [esi], ecx
// 00748491  8bcf                 mov ecx, edi
// 00748493  e8c63c1000           call 0x84c15e
// 00748498  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0074849c  894604               mov dword ptr [esi + 4], eax
// 0074849f  895608               mov dword ptr [esi + 8], edx
// 007484a2  8b4738               mov eax, dword ptr [edi + 0x38]
// 007484a5  85c0                 test eax, eax
// 007484a7  750a                 jne 0x7484b3
// 007484a9  8b4720               mov eax, dword ptr [edi + 0x20]
// 007484ac  50                   push eax
// 007484ad  ff1598ee8900         call dword ptr [0x89ee98]
// 007484b3  50                   push eax
// 007484b4  e84908fdff           call 0x718d02
// 007484b9  8bf8                 mov edi, eax
// 007484bb  85ff                 test edi, edi
// 007484bd  7424                 je 0x7484e3
// 007484bf  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 007484c2  51                   push ecx
// 007484c3  ffd3                 call ebx
// 007484c5  85c0                 test eax, eax
// 007484c7  741a                 je 0x7484e3
// 007484c9  8b4604               mov eax, dword ptr [esi + 4]
// 007484cc  8b5720               mov edx, dword ptr [edi + 0x20]
// 007484cf  56                   push esi
// 007484d0  50                   push eax
// 007484d1  6a4e                 push 0x4e
// 007484d3  52                   push edx
// 007484d4  ff1590ee8900         call dword ptr [0x89ee90]
// 007484da  5e                   pop esi
// 007484db  5f                   pop edi
// 007484dc  5b                   pop ebx
// 007484dd  83c40c               add esp, 0xc
// 007484e0  c20800               ret 8
// 007484e3  5e                   pop esi
// 007484e4  5f                   pop edi
// 007484e5  33c0                 xor eax, eax
// 007484e7  5b                   pop ebx
// 007484e8  83c40c               add esp, 0xc
// 007484eb  c20800               ret 8
// library xtp-15.2.1/Source\FlowGraph\XTPFlowGraphControl.cpp (function ?SendNotifyMessageA@CXTPFlowGraphControl@@UBEJIPAUtagNMHDR@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/FlowGraph/XTPFlowGraphControl.cpp
