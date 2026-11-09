// from server: 100% by auto
// roc 2010-06 008a1090  unit: CXTPRibbonGroup  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a1090
//
// 008a1090  83ec10               sub esp, 0x10
// 008a1093  53                   push ebx
// 008a1094  55                   push ebp
// 008a1095  8bd9                 mov ebx, ecx
// 008a1097  8b4328               mov eax, dword ptr [ebx + 0x28]
// 008a109a  56                   push esi
// 008a109b  33f6                 xor esi, esi
// 008a109d  57                   push edi
// 008a109e  85c0                 test eax, eax
// 008a10a0  7e61                 jle 0x8a1103
// 008a10a2  8b2de0bb9e00         mov ebp, dword ptr [0x9ebbe0]
// 008a10a8  85f6                 test esi, esi
// 008a10aa  7c11                 jl 0x8a10bd
// 008a10ac  3bf0                 cmp esi, eax
// 008a10ae  7d0d                 jge 0x8a10bd
// 008a10b0  3b7328               cmp esi, dword ptr [ebx + 0x28]
// 008a10b3  7d5a                 jge 0x8a110f
// 008a10b5  8b4324               mov eax, dword ptr [ebx + 0x24]
// 008a10b8  8b3cb0               mov edi, dword ptr [eax + esi*4]
// 008a10bb  eb02                 jmp 0x8a10bf
// 008a10bd  33ff                 xor edi, edi
// 008a10bf  8bcf                 mov ecx, edi
// 008a10c1  e8aad2ffff           call 0x89e370
// 008a10c6  85c0                 test eax, eax
// 008a10c8  7431                 je 0x8a10fb
// 008a10ca  8b5738               mov edx, dword ptr [edi + 0x38]
// 008a10cd  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 008a10d0  8b473c               mov eax, dword ptr [edi + 0x3c]
// 008a10d3  894c2410             mov dword ptr [esp + 0x10], ecx
// 008a10d7  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 008a10da  89542414             mov dword ptr [esp + 0x14], edx
// 008a10de  8b542428             mov edx, dword ptr [esp + 0x28]
// 008a10e2  89442418             mov dword ptr [esp + 0x18], eax
// 008a10e6  8b442424             mov eax, dword ptr [esp + 0x24]
// 008a10ea  52                   push edx
// 008a10eb  894c2420             mov dword ptr [esp + 0x20], ecx
// 008a10ef  50                   push eax
// 008a10f0  8d4c2418             lea ecx, [esp + 0x18]
// 008a10f4  51                   push ecx
// 008a10f5  ffd5                 call ebp
// 008a10f7  85c0                 test eax, eax
// 008a10f9  7519                 jne 0x8a1114
// 008a10fb  8b4328               mov eax, dword ptr [ebx + 0x28]
// 008a10fe  46                   inc esi
// 008a10ff  3bf0                 cmp esi, eax
// 008a1101  7ca5                 jl 0x8a10a8
// 008a1103  5f                   pop edi
// 008a1104  5e                   pop esi
// 008a1105  5d                   pop ebp
// 008a1106  33c0                 xor eax, eax
// 008a1108  5b                   pop ebx
// 008a1109  83c410               add esp, 0x10
// 008a110c  c20800               ret 8
// 008a110f  e8386bf0ff           call 0x7a7c4c
// 008a1114  8bc7                 mov eax, edi
// 008a1116  5f                   pop edi
// 008a1117  5e                   pop esi
// 008a1118  5d                   pop ebp
// 008a1119  5b                   pop ebx
// 008a111a  83c410               add esp, 0x10
// 008a111d  c20800               ret 8
// library xtp-13.2.1/Source\Ribbon\XTPRibbonGroups.cpp (function ?HitTest@CXTPRibbonGroups@@QBEPAVCXTPRibbonGroup@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonGroups.cpp
