// from server: 100% by auto
// roc 2010-06 0089d050  unit: CXTPTabPaintManager::CColorSetOffice2003  size: 302 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089d050
//
// 0089d050  8b442408             mov eax, dword ptr [esp + 8]
// 0089d054  83782000             cmp dword ptr [eax + 0x20], 0
// 0089d058  53                   push ebx
// 0089d059  55                   push ebp
// 0089d05a  56                   push esi
// 0089d05b  57                   push edi
// 0089d05c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0089d060  8bf1                 mov esi, ecx
// 0089d062  bd12000000           mov ebp, 0x12
// 0089d067  0f84f3000000         je 0x89d160
// 0089d06d  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0089d070  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 0089d073  3bc8                 cmp ecx, eax
// 0089d075  7552                 jne 0x89d0c9
// 0089d077  83782400             cmp dword ptr [eax + 0x24], 0
// 0089d07b  7452                 je 0x89d0cf
// 0089d07d  83be1402000000       cmp dword ptr [esi + 0x214], 0
// 0089d084  7535                 jne 0x89d0bb
// 0089d086  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0089d08a  8b11                 mov edx, dword ptr [ecx]
// 0089d08c  6a21                 push 0x21
// 0089d08e  6a32                 push 0x32
// 0089d090  83ec10               sub esp, 0x10
// 0089d093  8bc4                 mov eax, esp
// 0089d095  8910                 mov dword ptr [eax], edx
// 0089d097  8b5104               mov edx, dword ptr [ecx + 4]
// 0089d09a  895004               mov dword ptr [eax + 4], edx
// 0089d09d  8b5108               mov edx, dword ptr [ecx + 8]
// 0089d0a0  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0089d0a3  895008               mov dword ptr [eax + 8], edx
// 0089d0a6  89480c               mov dword ptr [eax + 0xc], ecx
// 0089d0a9  57                   push edi
// 0089d0aa  8bce                 mov ecx, esi
// 0089d0ac  e83fffffff           call 0x89cff0
// 0089d0b1  bd2f000000           mov ebp, 0x2f
// 0089d0b6  e9a5000000           jmp 0x89d160
// 0089d0bb  6a00                 push 0
// 0089d0bd  68ffcf8b00           push 0x8bcfff
// 0089d0c2  68fe8e4b00           push 0x4b8efe
// 0089d0c7  eb55                 jmp 0x89d11e
// 0089d0c9  83782400             cmp dword ptr [eax + 0x24], 0
// 0089d0cd  7508                 jne 0x89d0d7
// 0089d0cf  3bc8                 cmp ecx, eax
// 0089d0d1  0f8589000000         jne 0x89d160
// 0089d0d7  83be1402000000       cmp dword ptr [esi + 0x214], 0
// 0089d0de  7532                 jne 0x89d112
// 0089d0e0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0089d0e4  8b11                 mov edx, dword ptr [ecx]
// 0089d0e6  6a1f                 push 0x1f
// 0089d0e8  6a20                 push 0x20
// 0089d0ea  83ec10               sub esp, 0x10
// 0089d0ed  8bc4                 mov eax, esp
// 0089d0ef  8910                 mov dword ptr [eax], edx
// 0089d0f1  8b5104               mov edx, dword ptr [ecx + 4]
// 0089d0f4  895004               mov dword ptr [eax + 4], edx
// 0089d0f7  8b5108               mov edx, dword ptr [ecx + 8]
// 0089d0fa  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0089d0fd  895008               mov dword ptr [eax + 8], edx
// 0089d100  89480c               mov dword ptr [eax + 0xc], ecx
// 0089d103  57                   push edi
// 0089d104  8bce                 mov ecx, esi
// 0089d106  e8e5feffff           call 0x89cff0
// 0089d10b  bd2d000000           mov ebp, 0x2d
// 0089d110  eb4e                 jmp 0x89d160
// 0089d112  6a00                 push 0
// 0089d114  68ffd49700           push 0x97d4ff
// 0089d119  68fff2c800           push 0xc8f2ff
// 0089d11e  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0089d122  53                   push ebx
// 0089d123  57                   push edi
// 0089d124  e8d741f6ff           call 0x801300
// 0089d129  8bc8                 mov ecx, eax
// 0089d12b  e80042f6ff           call 0x801330
// 0089d130  8b8610020000         mov eax, dword ptr [esi + 0x210]
// 0089d136  83f8ff               cmp eax, -1
// 0089d139  7506                 jne 0x89d141
// 0089d13b  8b860c020000         mov eax, dword ptr [esi + 0x20c]
// 0089d141  8b8e10020000         mov ecx, dword ptr [esi + 0x210]
// 0089d147  83f9ff               cmp ecx, -1
// 0089d14a  7508                 jne 0x89d154
// 0089d14c  8bb60c020000         mov esi, dword ptr [esi + 0x20c]
// 0089d152  eb02                 jmp 0x89d156
// 0089d154  8bf1                 mov esi, ecx
// 0089d156  50                   push eax
// 0089d157  56                   push esi
// 0089d158  53                   push ebx
// 0089d159  8bcf                 mov ecx, edi
// 0089d15b  e8d8b5f0ff           call 0x7a8738
// 0089d160  e8bb69f4ff           call 0x7e3b20
// 0089d165  55                   push ebp
// 0089d166  8bc8                 mov ecx, eax
// 0089d168  e84361f4ff           call 0x7e32b0
// 0089d16d  8b17                 mov edx, dword ptr [edi]
// 0089d16f  50                   push eax
// 0089d170  8b4238               mov eax, dword ptr [edx + 0x38]
// 0089d173  8bcf                 mov ecx, edi
// 0089d175  ffd0                 call eax
// 0089d177  5f                   pop edi
// 0089d178  5e                   pop esi
// 0089d179  5d                   pop ebp
// 0089d17a  5b                   pop ebx
// 0089d17b  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?FillNavigateButton@CColorSetOffice2003@CXTPTabPaintManager@@UAEXPAVCDC@@PAVCXTPTabManagerNavigateButton@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/TabManager/XTPTabPaintManagerColors.cpp
