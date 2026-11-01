// from server: 100% by auto
// roc 2007-03 00648cb0  unit: seg_00640000  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00648cb0
//
// 00648cb0  83ec0c               sub esp, 0xc
// 00648cb3  53                   push ebx
// 00648cb4  8b1d74ed7700         mov ebx, dword ptr [0x77ed74]
// 00648cba  57                   push edi
// 00648cbb  8bf9                 mov edi, ecx
// 00648cbd  8b4720               mov eax, dword ptr [edi + 0x20]
// 00648cc0  50                   push eax
// 00648cc1  ffd3                 call ebx
// 00648cc3  85c0                 test eax, eax
// 00648cc5  7508                 jne 0x648ccf
// 00648cc7  5f                   pop edi
// 00648cc8  5b                   pop ebx
// 00648cc9  83c40c               add esp, 0xc
// 00648ccc  c20800               ret 8
// 00648ccf  56                   push esi
// 00648cd0  8b742420             mov esi, dword ptr [esp + 0x20]
// 00648cd4  85f6                 test esi, esi
// 00648cd6  7504                 jne 0x648cdc
// 00648cd8  8d74240c             lea esi, [esp + 0xc]
// 00648cdc  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00648cdf  890e                 mov dword ptr [esi], ecx
// 00648ce1  8bcf                 mov ecx, edi
// 00648ce3  e81a200f00           call 0x73ad02
// 00648ce8  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00648cec  894604               mov dword ptr [esi + 4], eax
// 00648cef  895608               mov dword ptr [esi + 8], edx
// 00648cf2  8b4738               mov eax, dword ptr [edi + 0x38]
// 00648cf5  85c0                 test eax, eax
// 00648cf7  750a                 jne 0x648d03
// 00648cf9  8b4720               mov eax, dword ptr [edi + 0x20]
// 00648cfc  50                   push eax
// 00648cfd  ff15c8ec7700         call dword ptr [0x77ecc8]
// 00648d03  50                   push eax
// 00648d04  e84559fdff           call 0x61e64e
// 00648d09  8bf8                 mov edi, eax
// 00648d0b  85ff                 test edi, edi
// 00648d0d  7424                 je 0x648d33
// 00648d0f  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00648d12  51                   push ecx
// 00648d13  ffd3                 call ebx
// 00648d15  85c0                 test eax, eax
// 00648d17  741a                 je 0x648d33
// 00648d19  8b4604               mov eax, dword ptr [esi + 4]
// 00648d1c  8b5720               mov edx, dword ptr [edi + 0x20]
// 00648d1f  56                   push esi
// 00648d20  50                   push eax
// 00648d21  6a4e                 push 0x4e
// 00648d23  52                   push edx
// 00648d24  ff1550ee7700         call dword ptr [0x77ee50]
// 00648d2a  5e                   pop esi
// 00648d2b  5f                   pop edi
// 00648d2c  5b                   pop ebx
// 00648d2d  83c40c               add esp, 0xc
// 00648d30  c20800               ret 8
// 00648d33  5e                   pop esi
// 00648d34  5f                   pop edi
// 00648d35  33c0                 xor eax, eax
// 00648d37  5b                   pop ebx
// 00648d38  83c40c               add esp, 0xc
// 00648d3b  c20800               ret 8
// library xtp-15.2.1/Source\FlowGraph\XTPFlowGraphControl.cpp (function ?SendNotifyMessageA@CXTPFlowGraphControl@@UBEJIPAUtagNMHDR@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/FlowGraph/XTPFlowGraphControl.cpp
