// from server: 100% by auto
// roc 2009-06 0075a540  unit: CXTPControls  size: 272 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075a540
//
// 0075a540  837c240800           cmp dword ptr [esp + 8], 0
// 0075a545  53                   push ebx
// 0075a546  55                   push ebp
// 0075a547  56                   push esi
// 0075a548  57                   push edi
// 0075a549  8bf1                 mov esi, ecx
// 0075a54b  0f84f8000000         je 0x75a649
// 0075a551  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0075a555  6a00                 push 0
// 0075a557  56                   push esi
// 0075a558  68cc758f00           push 0x8f75cc
// 0075a55d  57                   push edi
// 0075a55e  e83db70100           call 0x775ca0
// 0075a563  6a01                 push 1
// 0075a565  8d4604               lea eax, [esi + 4]
// 0075a568  50                   push eax
// 0075a569  68c4ff8b00           push 0x8bffc4
// 0075a56e  57                   push edi
// 0075a56f  e88cb70100           call 0x775d00
// 0075a574  6a00                 push 0
// 0075a576  8d4e08               lea ecx, [esi + 8]
// 0075a579  51                   push ecx
// 0075a57a  68c0758f00           push 0x8f75c0
// 0075a57f  57                   push edi
// 0075a580  e87bb70100           call 0x775d00
// 0075a585  8d5614               lea edx, [esi + 0x14]
// 0075a588  52                   push edx
// 0075a589  68b4758f00           push 0x8f75b4
// 0075a58e  57                   push edi
// 0075a58f  e8dcb60100           call 0x775c70
// 0075a594  6a00                 push 0
// 0075a596  8d4618               lea eax, [esi + 0x18]
// 0075a599  50                   push eax
// 0075a59a  68a4758f00           push 0x8f75a4
// 0075a59f  57                   push edi
// 0075a5a0  e8fbb60100           call 0x775ca0
// 0075a5a5  83c44c               add esp, 0x4c
// 0075a5a8  33c9                 xor ecx, ecx
// 0075a5aa  51                   push ecx
// 0075a5ab  33c0                 xor eax, eax
// 0075a5ad  50                   push eax
// 0075a5ae  8d4e0c               lea ecx, [esi + 0xc]
// 0075a5b1  51                   push ecx
// 0075a5b2  6898758f00           push 0x8f7598
// 0075a5b7  57                   push edi
// 0075a5b8  e833b80100           call 0x775df0
// 0075a5bd  83c404               add esp, 4
// 0075a5c0  8bc4                 mov eax, esp
// 0075a5c2  33c9                 xor ecx, ecx
// 0075a5c4  33d2                 xor edx, edx
// 0075a5c6  8908                 mov dword ptr [eax], ecx
// 0075a5c8  895004               mov dword ptr [eax + 4], edx
// 0075a5cb  8d561c               lea edx, [esi + 0x1c]
// 0075a5ce  52                   push edx
// 0075a5cf  33db                 xor ebx, ebx
// 0075a5d1  688c758f00           push 0x8f758c
// 0075a5d6  33ed                 xor ebp, ebp
// 0075a5d8  895808               mov dword ptr [eax + 8], ebx
// 0075a5db  57                   push edi
// 0075a5dc  89680c               mov dword ptr [eax + 0xc], ebp
// 0075a5df  e83cb80100           call 0x775e20
// 0075a5e4  33c9                 xor ecx, ecx
// 0075a5e6  51                   push ecx
// 0075a5e7  33c0                 xor eax, eax
// 0075a5e9  50                   push eax
// 0075a5ea  8d4630               lea eax, [esi + 0x30]
// 0075a5ed  50                   push eax
// 0075a5ee  6880758f00           push 0x8f7580
// 0075a5f3  57                   push edi
// 0075a5f4  e8f7b70100           call 0x775df0
// 0075a5f9  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0075a5fd  83c430               add esp, 0x30
// 0075a600  833906               cmp dword ptr [ecx], 6
// 0075a603  7644                 jbe 0x75a649
// 0075a605  55                   push ebp
// 0075a606  8d5e3c               lea ebx, [esi + 0x3c]
// 0075a609  53                   push ebx
// 0075a60a  6874758f00           push 0x8f7574
// 0075a60f  57                   push edi
// 0075a610  e8ebb60100           call 0x775d00
// 0075a615  83c410               add esp, 0x10
// 0075a618  392b                 cmp dword ptr [ebx], ebp
// 0075a61a  742d                 je 0x75a649
// 0075a61c  33c9                 xor ecx, ecx
// 0075a61e  51                   push ecx
// 0075a61f  33c0                 xor eax, eax
// 0075a621  50                   push eax
// 0075a622  8d5640               lea edx, [esi + 0x40]
// 0075a625  52                   push edx
// 0075a626  6858758f00           push 0x8f7558
// 0075a62b  57                   push edi
// 0075a62c  e8bfb70100           call 0x775df0
// 0075a631  33c9                 xor ecx, ecx
// 0075a633  51                   push ecx
// 0075a634  33c0                 xor eax, eax
// 0075a636  50                   push eax
// 0075a637  83c648               add esi, 0x48
// 0075a63a  56                   push esi
// 0075a63b  683c758f00           push 0x8f753c
// 0075a640  57                   push edi
// 0075a641  e8aab70100           call 0x775df0
// 0075a646  83c428               add esp, 0x28
// 0075a649  5f                   pop edi
// 0075a64a  5e                   pop esi
// 0075a64b  5d                   pop ebp
// 0075a64c  5b                   pop ebx
// 0075a64d  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPDockState.cpp (function ?DoPropExchange@CToolBarInfo@CXTPToolBar@@QAEXPAVCXTPPropExchange@@PAVCXTPDockState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockState.cpp
