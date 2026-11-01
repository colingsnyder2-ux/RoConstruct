// from server: 100% by auto
// roc 2009-12 00823270  unit: CXTPReportControl  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823270
//
// 00823270  83ec0c               sub esp, 0xc
// 00823273  53                   push ebx
// 00823274  8b1d84cc9800         mov ebx, dword ptr [0x98cc84]
// 0082327a  57                   push edi
// 0082327b  8bf9                 mov edi, ecx
// 0082327d  8b4720               mov eax, dword ptr [edi + 0x20]
// 00823280  50                   push eax
// 00823281  ffd3                 call ebx
// 00823283  85c0                 test eax, eax
// 00823285  7508                 jne 0x82328f
// 00823287  5f                   pop edi
// 00823288  5b                   pop ebx
// 00823289  83c40c               add esp, 0xc
// 0082328c  c20800               ret 8
// 0082328f  56                   push esi
// 00823290  8b742420             mov esi, dword ptr [esp + 0x20]
// 00823294  85f6                 test esi, esi
// 00823296  7504                 jne 0x82329c
// 00823298  8d74240c             lea esi, [esp + 0xc]
// 0082329c  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 0082329f  890e                 mov dword ptr [esi], ecx
// 008232a1  8bcf                 mov ecx, edi
// 008232a3  e822341000           call 0x9266ca
// 008232a8  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008232ac  894604               mov dword ptr [esi + 4], eax
// 008232af  895608               mov dword ptr [esi + 8], edx
// 008232b2  8b4738               mov eax, dword ptr [edi + 0x38]
// 008232b5  85c0                 test eax, eax
// 008232b7  750a                 jne 0x8232c3
// 008232b9  8b4720               mov eax, dword ptr [edi + 0x20]
// 008232bc  50                   push eax
// 008232bd  ff15bccb9800         call dword ptr [0x98cbbc]
// 008232c3  50                   push eax
// 008232c4  e86108fdff           call 0x7f3b2a
// 008232c9  8bf8                 mov edi, eax
// 008232cb  85ff                 test edi, edi
// 008232cd  7424                 je 0x8232f3
// 008232cf  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 008232d2  51                   push ecx
// 008232d3  ffd3                 call ebx
// 008232d5  85c0                 test eax, eax
// 008232d7  741a                 je 0x8232f3
// 008232d9  8b4604               mov eax, dword ptr [esi + 4]
// 008232dc  8b5720               mov edx, dword ptr [edi + 0x20]
// 008232df  56                   push esi
// 008232e0  50                   push eax
// 008232e1  6a4e                 push 0x4e
// 008232e3  52                   push edx
// 008232e4  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008232ea  5e                   pop esi
// 008232eb  5f                   pop edi
// 008232ec  5b                   pop ebx
// 008232ed  83c40c               add esp, 0xc
// 008232f0  c20800               ret 8
// 008232f3  5e                   pop esi
// 008232f4  5f                   pop edi
// 008232f5  33c0                 xor eax, eax
// 008232f7  5b                   pop ebx
// 008232f8  83c40c               add esp, 0xc
// 008232fb  c20800               ret 8
// library xtp-15.2.1/Source\FlowGraph\XTPFlowGraphControl.cpp (function ?SendNotifyMessageA@CXTPFlowGraphControl@@UBEJIPAUtagNMHDR@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/FlowGraph/XTPFlowGraphControl.cpp
