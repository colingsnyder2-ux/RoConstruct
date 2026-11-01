// from server: 100% by auto
// roc 2009-06 007f4070  unit: CXTPTabManager::CNavigateButtonClose  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f4070
//
// 007f4070  83ec18               sub esp, 0x18
// 007f4073  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007f4077  8b442420             mov eax, dword ptr [esp + 0x20]
// 007f407b  03c1                 add eax, ecx
// 007f407d  53                   push ebx
// 007f407e  99                   cdq 
// 007f407f  55                   push ebp
// 007f4080  2bc2                 sub eax, edx
// 007f4082  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007f4086  56                   push esi
// 007f4087  8b742428             mov esi, dword ptr [esp + 0x28]
// 007f408b  57                   push edi
// 007f408c  8bf8                 mov edi, eax
// 007f408e  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 007f4092  03c2                 add eax, edx
// 007f4094  99                   cdq 
// 007f4095  2bc2                 sub eax, edx
// 007f4097  8bd8                 mov ebx, eax
// 007f4099  d1fb                 sar ebx, 1
// 007f409b  d1ff                 sar edi, 1
// 007f409d  8d6bfd               lea ebp, [ebx - 3]
// 007f40a0  8d47fc               lea eax, [edi - 4]
// 007f40a3  55                   push ebp
// 007f40a4  50                   push eax
// 007f40a5  8d4c2420             lea ecx, [esp + 0x20]
// 007f40a9  51                   push ecx
// 007f40aa  8bce                 mov ecx, esi
// 007f40ac  8944241c             mov dword ptr [esp + 0x1c], eax
// 007f40b0  e85958f2ff           call 0x71990e
// 007f40b5  8d4304               lea eax, [ebx + 4]
// 007f40b8  8d4f03               lea ecx, [edi + 3]
// 007f40bb  50                   push eax
// 007f40bc  894c2418             mov dword ptr [esp + 0x18], ecx
// 007f40c0  51                   push ecx
// 007f40c1  8bce                 mov ecx, esi
// 007f40c3  89442434             mov dword ptr [esp + 0x34], eax
// 007f40c7  e83c58f2ff           call 0x719908
// 007f40cc  8d47fd               lea eax, [edi - 3]
// 007f40cf  55                   push ebp
// 007f40d0  50                   push eax
// 007f40d1  8d542428             lea edx, [esp + 0x28]
// 007f40d5  52                   push edx
// 007f40d6  8bce                 mov ecx, esi
// 007f40d8  89442424             mov dword ptr [esp + 0x24], eax
// 007f40dc  e82d58f2ff           call 0x71990e
// 007f40e1  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007f40e5  50                   push eax
// 007f40e6  83c704               add edi, 4
// 007f40e9  57                   push edi
// 007f40ea  8bce                 mov ecx, esi
// 007f40ec  e81758f2ff           call 0x719908
// 007f40f1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007f40f5  8d6b03               lea ebp, [ebx + 3]
// 007f40f8  55                   push ebp
// 007f40f9  51                   push ecx
// 007f40fa  8d542428             lea edx, [esp + 0x28]
// 007f40fe  52                   push edx
// 007f40ff  8bce                 mov ecx, esi
// 007f4101  e80858f2ff           call 0x71990e
// 007f4106  8b442414             mov eax, dword ptr [esp + 0x14]
// 007f410a  83c3fc               add ebx, -4
// 007f410d  53                   push ebx
// 007f410e  50                   push eax
// 007f410f  8bce                 mov ecx, esi
// 007f4111  e8f257f2ff           call 0x719908
// 007f4116  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007f411a  55                   push ebp
// 007f411b  51                   push ecx
// 007f411c  8d542428             lea edx, [esp + 0x28]
// 007f4120  52                   push edx
// 007f4121  8bce                 mov ecx, esi
// 007f4123  e8e657f2ff           call 0x71990e
// 007f4128  53                   push ebx
// 007f4129  57                   push edi
// 007f412a  8bce                 mov ecx, esi
// 007f412c  e8d757f2ff           call 0x719908
// 007f4131  5f                   pop edi
// 007f4132  5e                   pop esi
// 007f4133  5d                   pop ebp
// 007f4134  5b                   pop ebx
// 007f4135  83c418               add esp, 0x18
// 007f4138  c21400               ret 0x14
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?DrawEntry@CNavigateButtonClose@CXTPTabManager@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
