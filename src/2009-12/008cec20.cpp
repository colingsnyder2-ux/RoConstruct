// from server: 100% by auto
// roc 2009-12 008cec20  unit: CXTPTabManager::CNavigateButtonClose  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008cec20
//
// 008cec20  83ec18               sub esp, 0x18
// 008cec23  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008cec27  8b442420             mov eax, dword ptr [esp + 0x20]
// 008cec2b  03c1                 add eax, ecx
// 008cec2d  53                   push ebx
// 008cec2e  99                   cdq 
// 008cec2f  55                   push ebp
// 008cec30  2bc2                 sub eax, edx
// 008cec32  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 008cec36  56                   push esi
// 008cec37  8b742428             mov esi, dword ptr [esp + 0x28]
// 008cec3b  57                   push edi
// 008cec3c  8bf8                 mov edi, eax
// 008cec3e  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 008cec42  03c2                 add eax, edx
// 008cec44  99                   cdq 
// 008cec45  2bc2                 sub eax, edx
// 008cec47  8bd8                 mov ebx, eax
// 008cec49  d1fb                 sar ebx, 1
// 008cec4b  d1ff                 sar edi, 1
// 008cec4d  8d6bfd               lea ebp, [ebx - 3]
// 008cec50  8d47fc               lea eax, [edi - 4]
// 008cec53  55                   push ebp
// 008cec54  50                   push eax
// 008cec55  8d4c2420             lea ecx, [esp + 0x20]
// 008cec59  51                   push ecx
// 008cec5a  8bce                 mov ecx, esi
// 008cec5c  8944241c             mov dword ptr [esp + 0x1c], eax
// 008cec60  e8dd5af2ff           call 0x7f4742
// 008cec65  8d4304               lea eax, [ebx + 4]
// 008cec68  8d4f03               lea ecx, [edi + 3]
// 008cec6b  50                   push eax
// 008cec6c  894c2418             mov dword ptr [esp + 0x18], ecx
// 008cec70  51                   push ecx
// 008cec71  8bce                 mov ecx, esi
// 008cec73  89442434             mov dword ptr [esp + 0x34], eax
// 008cec77  e8c05af2ff           call 0x7f473c
// 008cec7c  8d47fd               lea eax, [edi - 3]
// 008cec7f  55                   push ebp
// 008cec80  50                   push eax
// 008cec81  8d542428             lea edx, [esp + 0x28]
// 008cec85  52                   push edx
// 008cec86  8bce                 mov ecx, esi
// 008cec88  89442424             mov dword ptr [esp + 0x24], eax
// 008cec8c  e8b15af2ff           call 0x7f4742
// 008cec91  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008cec95  50                   push eax
// 008cec96  83c704               add edi, 4
// 008cec99  57                   push edi
// 008cec9a  8bce                 mov ecx, esi
// 008cec9c  e89b5af2ff           call 0x7f473c
// 008ceca1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008ceca5  8d6b03               lea ebp, [ebx + 3]
// 008ceca8  55                   push ebp
// 008ceca9  51                   push ecx
// 008cecaa  8d542428             lea edx, [esp + 0x28]
// 008cecae  52                   push edx
// 008cecaf  8bce                 mov ecx, esi
// 008cecb1  e88c5af2ff           call 0x7f4742
// 008cecb6  8b442414             mov eax, dword ptr [esp + 0x14]
// 008cecba  83c3fc               add ebx, -4
// 008cecbd  53                   push ebx
// 008cecbe  50                   push eax
// 008cecbf  8bce                 mov ecx, esi
// 008cecc1  e8765af2ff           call 0x7f473c
// 008cecc6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008cecca  55                   push ebp
// 008ceccb  51                   push ecx
// 008ceccc  8d542428             lea edx, [esp + 0x28]
// 008cecd0  52                   push edx
// 008cecd1  8bce                 mov ecx, esi
// 008cecd3  e86a5af2ff           call 0x7f4742
// 008cecd8  53                   push ebx
// 008cecd9  57                   push edi
// 008cecda  8bce                 mov ecx, esi
// 008cecdc  e85b5af2ff           call 0x7f473c
// 008cece1  5f                   pop edi
// 008cece2  5e                   pop esi
// 008cece3  5d                   pop ebp
// 008cece4  5b                   pop ebx
// 008cece5  83c418               add esp, 0x18
// 008cece8  c21400               ret 0x14
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?DrawEntry@CNavigateButtonClose@CXTPTabManager@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
