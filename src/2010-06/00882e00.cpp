// from server: 100% by auto
// roc 2010-06 00882e00  unit: CXTPTabManager::CNavigateButtonClose  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882e00
//
// 00882e00  83ec18               sub esp, 0x18
// 00882e03  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00882e07  8b442420             mov eax, dword ptr [esp + 0x20]
// 00882e0b  03c1                 add eax, ecx
// 00882e0d  53                   push ebx
// 00882e0e  99                   cdq 
// 00882e0f  55                   push ebp
// 00882e10  2bc2                 sub eax, edx
// 00882e12  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00882e16  56                   push esi
// 00882e17  8b742428             mov esi, dword ptr [esp + 0x28]
// 00882e1b  57                   push edi
// 00882e1c  8bf8                 mov edi, eax
// 00882e1e  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00882e22  03c2                 add eax, edx
// 00882e24  99                   cdq 
// 00882e25  2bc2                 sub eax, edx
// 00882e27  8bd8                 mov ebx, eax
// 00882e29  d1fb                 sar ebx, 1
// 00882e2b  d1ff                 sar edi, 1
// 00882e2d  8d6bfd               lea ebp, [ebx - 3]
// 00882e30  8d47fc               lea eax, [edi - 4]
// 00882e33  55                   push ebp
// 00882e34  50                   push eax
// 00882e35  8d4c2420             lea ecx, [esp + 0x20]
// 00882e39  51                   push ecx
// 00882e3a  8bce                 mov ecx, esi
// 00882e3c  8944241c             mov dword ptr [esp + 0x1c], eax
// 00882e40  e8375af2ff           call 0x7a887c
// 00882e45  8d4304               lea eax, [ebx + 4]
// 00882e48  8d4f03               lea ecx, [edi + 3]
// 00882e4b  50                   push eax
// 00882e4c  894c2418             mov dword ptr [esp + 0x18], ecx
// 00882e50  51                   push ecx
// 00882e51  8bce                 mov ecx, esi
// 00882e53  89442434             mov dword ptr [esp + 0x34], eax
// 00882e57  e81a5af2ff           call 0x7a8876
// 00882e5c  8d47fd               lea eax, [edi - 3]
// 00882e5f  55                   push ebp
// 00882e60  50                   push eax
// 00882e61  8d542428             lea edx, [esp + 0x28]
// 00882e65  52                   push edx
// 00882e66  8bce                 mov ecx, esi
// 00882e68  89442424             mov dword ptr [esp + 0x24], eax
// 00882e6c  e80b5af2ff           call 0x7a887c
// 00882e71  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00882e75  50                   push eax
// 00882e76  83c704               add edi, 4
// 00882e79  57                   push edi
// 00882e7a  8bce                 mov ecx, esi
// 00882e7c  e8f559f2ff           call 0x7a8876
// 00882e81  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00882e85  8d6b03               lea ebp, [ebx + 3]
// 00882e88  55                   push ebp
// 00882e89  51                   push ecx
// 00882e8a  8d542428             lea edx, [esp + 0x28]
// 00882e8e  52                   push edx
// 00882e8f  8bce                 mov ecx, esi
// 00882e91  e8e659f2ff           call 0x7a887c
// 00882e96  8b442414             mov eax, dword ptr [esp + 0x14]
// 00882e9a  83c3fc               add ebx, -4
// 00882e9d  53                   push ebx
// 00882e9e  50                   push eax
// 00882e9f  8bce                 mov ecx, esi
// 00882ea1  e8d059f2ff           call 0x7a8876
// 00882ea6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00882eaa  55                   push ebp
// 00882eab  51                   push ecx
// 00882eac  8d542428             lea edx, [esp + 0x28]
// 00882eb0  52                   push edx
// 00882eb1  8bce                 mov ecx, esi
// 00882eb3  e8c459f2ff           call 0x7a887c
// 00882eb8  53                   push ebx
// 00882eb9  57                   push edi
// 00882eba  8bce                 mov ecx, esi
// 00882ebc  e8b559f2ff           call 0x7a8876
// 00882ec1  5f                   pop edi
// 00882ec2  5e                   pop esi
// 00882ec3  5d                   pop ebp
// 00882ec4  5b                   pop ebx
// 00882ec5  83c418               add esp, 0x18
// 00882ec8  c21400               ret 0x14
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?DrawEntry@CNavigateButtonClose@CXTPTabManager@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
