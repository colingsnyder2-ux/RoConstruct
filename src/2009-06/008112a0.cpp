// from server: 100% by auto
// roc 2009-06 008112a0  unit: CXTPRibbonGroup  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008112a0
//
// 008112a0  83ec10               sub esp, 0x10
// 008112a3  53                   push ebx
// 008112a4  55                   push ebp
// 008112a5  8bd9                 mov ebx, ecx
// 008112a7  8b4328               mov eax, dword ptr [ebx + 0x28]
// 008112aa  56                   push esi
// 008112ab  33f6                 xor esi, esi
// 008112ad  57                   push edi
// 008112ae  85c0                 test eax, eax
// 008112b0  7e61                 jle 0x811313
// 008112b2  8b2dc0ed8900         mov ebp, dword ptr [0x89edc0]
// 008112b8  85f6                 test esi, esi
// 008112ba  7c11                 jl 0x8112cd
// 008112bc  3bf0                 cmp esi, eax
// 008112be  7d0d                 jge 0x8112cd
// 008112c0  3b7328               cmp esi, dword ptr [ebx + 0x28]
// 008112c3  7d5a                 jge 0x81131f
// 008112c5  8b4324               mov eax, dword ptr [ebx + 0x24]
// 008112c8  8b3cb0               mov edi, dword ptr [eax + esi*4]
// 008112cb  eb02                 jmp 0x8112cf
// 008112cd  33ff                 xor edi, edi
// 008112cf  8bcf                 mov ecx, edi
// 008112d1  e89ad7ffff           call 0x80ea70
// 008112d6  85c0                 test eax, eax
// 008112d8  7431                 je 0x81130b
// 008112da  8b5738               mov edx, dword ptr [edi + 0x38]
// 008112dd  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 008112e0  8b473c               mov eax, dword ptr [edi + 0x3c]
// 008112e3  894c2410             mov dword ptr [esp + 0x10], ecx
// 008112e7  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 008112ea  89542414             mov dword ptr [esp + 0x14], edx
// 008112ee  8b542428             mov edx, dword ptr [esp + 0x28]
// 008112f2  89442418             mov dword ptr [esp + 0x18], eax
// 008112f6  8b442424             mov eax, dword ptr [esp + 0x24]
// 008112fa  52                   push edx
// 008112fb  894c2420             mov dword ptr [esp + 0x20], ecx
// 008112ff  50                   push eax
// 00811300  8d4c2418             lea ecx, [esp + 0x18]
// 00811304  51                   push ecx
// 00811305  ffd5                 call ebp
// 00811307  85c0                 test eax, eax
// 00811309  7519                 jne 0x811324
// 0081130b  8b4328               mov eax, dword ptr [ebx + 0x28]
// 0081130e  46                   inc esi
// 0081130f  3bf0                 cmp esi, eax
// 00811311  7ca5                 jl 0x8112b8
// 00811313  5f                   pop edi
// 00811314  5e                   pop esi
// 00811315  5d                   pop ebp
// 00811316  33c0                 xor eax, eax
// 00811318  5b                   pop ebx
// 00811319  83c410               add esp, 0x10
// 0081131c  c20800               ret 8
// 0081131f  e8c079f0ff           call 0x718ce4
// 00811324  8bc7                 mov eax, edi
// 00811326  5f                   pop edi
// 00811327  5e                   pop esi
// 00811328  5d                   pop ebp
// 00811329  5b                   pop ebx
// 0081132a  83c410               add esp, 0x10
// 0081132d  c20800               ret 8
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroups.cpp (function ?HitTest@CXTPRibbonGroups@@QBEPAVCXTPRibbonGroup@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroups.cpp
