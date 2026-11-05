// from server: 100% by auto
// roc 2012-06 004252e0  unit: RBX::FunctionMarshaller  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004252e0
//
// 004252e0  57                   push edi
// 004252e1  8b7c2408             mov edi, dword ptr [esp + 8]
// 004252e5  85ff                 test edi, edi
// 004252e7  742a                 je 0x425313
// 004252e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004252ed  85c0                 test eax, eax
// 004252ef  7422                 je 0x425313
// 004252f1  56                   push esi
// 004252f2  50                   push eax
// 004252f3  ff15b03ab200         call dword ptr [0xb23ab0]
// 004252f9  0fb7f0               movzx esi, ax
// 004252fc  8d44240c             lea eax, [esp + 0xc]
// 00425300  50                   push eax
// 00425301  8d4f20               lea ecx, [edi + 0x20]
// 00425304  89742410             mov dword ptr [esp + 0x10], esi
// 00425308  e873fbffff           call 0x424e80
// 0042530d  0fb7c6               movzx eax, si
// 00425310  5e                   pop esi
// 00425311  5f                   pop edi
// 00425312  c3                   ret 
// 00425313  33c0                 xor eax, eax
// 00425315  5f                   pop edi
// 00425316  c3                   ret 
// library atl-8.0/atl.cpp (function ?RegisterClassExA@AtlModuleRegisterWndClassInfoParamA@ATL@@SAGPAU_ATL_WIN_MODULE70@2@PBUtagWNDCLASSEXA@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
