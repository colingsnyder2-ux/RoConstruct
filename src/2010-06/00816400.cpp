// from server: 100% by auto
// roc 2010-06 00816400  unit: CXTPToolTipContextToolTip::PAUTOOLITEM::?$CArray  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00816400
//
// 00816400  8b442404             mov eax, dword ptr [esp + 4]
// 00816404  57                   push edi
// 00816405  8bf9                 mov edi, ecx
// 00816407  3b8718010000         cmp eax, dword ptr [edi + 0x118]
// 0081640d  0f8586000000         jne 0x816499
// 00816413  53                   push ebx
// 00816414  33db                 xor ebx, ebx
// 00816416  56                   push esi
// 00816417  399f00010000         cmp dword ptr [edi + 0x100], ebx
// 0081641d  7431                 je 0x816450
// 0081641f  e89cfdffff           call 0x8161c0
// 00816424  3bc3                 cmp eax, ebx
// 00816426  7418                 je 0x816440
// 00816428  8b8f00010000         mov ecx, dword ptr [edi + 0x100]
// 0081642e  3b4820               cmp ecx, dword ptr [eax + 0x20]
// 00816431  751d                 jne 0x816450
// 00816433  8b9704010000         mov edx, dword ptr [edi + 0x104]
// 00816439  3b5024               cmp edx, dword ptr [eax + 0x24]
// 0081643c  740a                 je 0x816448
// 0081643e  eb10                 jmp 0x816450
// 00816440  399f00010000         cmp dword ptr [edi + 0x100], ebx
// 00816446  7508                 jne 0x816450
// 00816448  50                   push eax
// 00816449  8bcf                 mov ecx, edi
// 0081644b  e820e3ffff           call 0x814770
// 00816450  8b8718010000         mov eax, dword ptr [edi + 0x118]
// 00816456  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00816459  50                   push eax
// 0081645a  51                   push ecx
// 0081645b  ff1560ba9e00         call dword ptr [0x9eba60]
// 00816461  8db7e0000000         lea esi, [edi + 0xe0]
// 00816467  8bce                 mov ecx, esi
// 00816469  899f18010000         mov dword ptr [edi + 0x118], ebx
// 0081646f  ff1588c69e00         call dword ptr [0x9ec688]
// 00816475  8d560c               lea edx, [esi + 0xc]
// 00816478  895e08               mov dword ptr [esi + 8], ebx
// 0081647b  895e20               mov dword ptr [esi + 0x20], ebx
// 0081647e  895e1c               mov dword ptr [esi + 0x1c], ebx
// 00816481  8b1de4ba9e00         mov ebx, dword ptr [0x9ebae4]
// 00816487  52                   push edx
// 00816488  c74624ffffffff       mov dword ptr [esi + 0x24], 0xffffffff
// 0081648f  ffd3                 call ebx
// 00816491  83c628               add esi, 0x28
// 00816494  56                   push esi
// 00816495  ffd3                 call ebx
// 00816497  5e                   pop esi
// 00816498  5b                   pop ebx
// 00816499  8bcf                 mov ecx, edi
// 0081649b  e8d01af9ff           call 0x7a7f70
// 008164a0  5f                   pop edi
// 008164a1  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Common\XTPToolTipContext.cpp (function ?OnTimer@CXTPToolTipContextToolTip@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPToolTipContext.cpp
