// from server: 100% by auto
// roc 2011-06 00636a70  unit: FLog::VFastLogSettingsItem::?$FactoryProduct::Creator  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00636a70
//
// 00636a70  8b542404             mov edx, dword ptr [esp + 4]
// 00636a74  57                   push edi
// 00636a75  8bf9                 mov edi, ecx
// 00636a77  85d2                 test edx, edx
// 00636a79  750f                 jne 0x636a8a
// 00636a7b  33c0                 xor eax, eax
// 00636a7d  50                   push eax
// 00636a7e  52                   push edx
// 00636a7f  e8bcfdffff           call 0x636840
// 00636a84  8bc7                 mov eax, edi
// 00636a86  5f                   pop edi
// 00636a87  c20400               ret 4
// 00636a8a  8bc2                 mov eax, edx
// 00636a8c  56                   push esi
// 00636a8d  8d7001               lea esi, [eax + 1]
// 00636a90  8a08                 mov cl, byte ptr [eax]
// 00636a92  40                   inc eax
// 00636a93  84c9                 test cl, cl
// 00636a95  75f9                 jne 0x636a90
// 00636a97  2bc6                 sub eax, esi
// 00636a99  5e                   pop esi
// 00636a9a  50                   push eax
// 00636a9b  52                   push edx
// 00636a9c  8bcf                 mov ecx, edi
// 00636a9e  e89dfdffff           call 0x636840
// 00636aa3  8bc7                 mov eax, edi
// 00636aa5  5f                   pop edi
// 00636aa6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ??4?$CSimpleStringT@D$0A@@ATL@@QAEAAV01@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
