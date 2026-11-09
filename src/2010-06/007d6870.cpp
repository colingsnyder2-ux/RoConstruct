// from server: 100% by auto
// roc 2010-06 007d6870  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 213 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d6870
//
// 007d6870  56                   push esi
// 007d6871  8b35cc55c200         mov esi, dword ptr [0xc255cc]
// 007d6877  85f6                 test esi, esi
// 007d6879  0f84c4000000         je 0x7d6943
// 007d687f  90                   nop 
// 007d6880  8b4608               mov eax, dword ptr [esi + 8]
// 007d6883  85c0                 test eax, eax
// 007d6885  7408                 je 0x7d688f
// 007d6887  8bf0                 mov esi, eax
// 007d6889  85f6                 test esi, esi
// 007d688b  75f3                 jne 0x7d6880
// 007d688d  5e                   pop esi
// 007d688e  c3                   ret 
// 007d688f  53                   push ebx
// 007d6890  55                   push ebp
// 007d6891  8b2d0ca39e00         mov ebp, dword ptr [0x9ea30c]
// 007d6897  57                   push edi
// 007d6898  eb06                 jmp 0x7d68a0
// 007d689a  8d9b00000000         lea ebx, [ebx]
// 007d68a0  833e00               cmp dword ptr [esi], 0
// 007d68a3  0f858c000000         jne 0x7d6935
// 007d68a9  8b4608               mov eax, dword ptr [esi + 8]
// 007d68ac  8bde                 mov ebx, esi
// 007d68ae  85c0                 test eax, eax
// 007d68b0  7406                 je 0x7d68b8
// 007d68b2  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007d68b5  89480c               mov dword ptr [eax + 0xc], ecx
// 007d68b8  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d68bb  85c0                 test eax, eax
// 007d68bd  7406                 je 0x7d68c5
// 007d68bf  8b5608               mov edx, dword ptr [esi + 8]
// 007d68c2  895008               mov dword ptr [eax + 8], edx
// 007d68c5  3935cc55c200         cmp dword ptr [0xc255cc], esi
// 007d68cb  750f                 jne 0x7d68dc
// 007d68cd  8b4608               mov eax, dword ptr [esi + 8]
// 007d68d0  85c0                 test eax, eax
// 007d68d2  7503                 jne 0x7d68d7
// 007d68d4  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d68d7  a3cc55c200           mov dword ptr [0xc255cc], eax
// 007d68dc  8b760c               mov esi, dword ptr [esi + 0xc]
// 007d68df  33ff                 xor edi, edi
// 007d68e1  393da055c200         cmp dword ptr [0xc255a0], edi
// 007d68e7  740d                 je 0x7d68f6
// 007d68e9  68a055c200           push 0xc255a0
// 007d68ee  ff157ca39e00         call dword ptr [0x9ea37c]
// 007d68f4  8bf8                 mov edi, eax
// 007d68f6  833da855c20000       cmp dword ptr [0xc255a8], 0
// 007d68fd  53                   push ebx
// 007d68fe  742b                 je 0x7d692b
// 007d6900  8b0d9c55c200         mov ecx, dword ptr [0xc2559c]
// 007d6906  6a00                 push 0
// 007d6908  51                   push ecx
// 007d6909  ffd5                 call ebp
// 007d690b  85ff                 test edi, edi
// 007d690d  7529                 jne 0x7d6938
// 007d690f  a19c55c200           mov eax, dword ptr [0xc2559c]
// 007d6914  85c0                 test eax, eax
// 007d6916  7407                 je 0x7d691f
// 007d6918  50                   push eax
// 007d6919  ff1514a39e00         call dword ptr [0x9ea314]
// 007d691f  c7059c55c20000000000 mov dword ptr [0xc2559c], 0
// 007d6929  eb0d                 jmp 0x7d6938
// 007d692b  e86a10fdff           call 0x7a799a
// 007d6930  83c404               add esp, 4
// 007d6933  eb03                 jmp 0x7d6938
// 007d6935  8b760c               mov esi, dword ptr [esi + 0xc]
// 007d6938  85f6                 test esi, esi
// 007d693a  0f8560ffffff         jne 0x7d68a0
// 007d6940  5f                   pop edi
// 007d6941  5d                   pop ebp
// 007d6942  5b                   pop ebx
// 007d6943  5e                   pop esi
// 007d6944  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?FreeExtraData@?$CXTPBatchAllocManagerT@VCXTPReportRowAllocator@@UCXTPReportRow_BatchData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
