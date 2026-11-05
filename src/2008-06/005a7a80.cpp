// from server: 100% by auto
// roc 2008-06 005a7a80  unit: RBX::Log  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a7a80
//
// 005a7a80  8b542404             mov edx, dword ptr [esp + 4]
// 005a7a84  57                   push edi
// 005a7a85  8bf9                 mov edi, ecx
// 005a7a87  85d2                 test edx, edx
// 005a7a89  750f                 jne 0x5a7a9a
// 005a7a8b  33c0                 xor eax, eax
// 005a7a8d  50                   push eax
// 005a7a8e  52                   push edx
// 005a7a8f  e88cfeffff           call 0x5a7920
// 005a7a94  8bc7                 mov eax, edi
// 005a7a96  5f                   pop edi
// 005a7a97  c20400               ret 4
// 005a7a9a  8bc2                 mov eax, edx
// 005a7a9c  56                   push esi
// 005a7a9d  8d7001               lea esi, [eax + 1]
// 005a7aa0  8a08                 mov cl, byte ptr [eax]
// 005a7aa2  40                   inc eax
// 005a7aa3  84c9                 test cl, cl
// 005a7aa5  75f9                 jne 0x5a7aa0
// 005a7aa7  2bc6                 sub eax, esi
// 005a7aa9  5e                   pop esi
// 005a7aaa  50                   push eax
// 005a7aab  52                   push edx
// 005a7aac  8bcf                 mov ecx, edi
// 005a7aae  e86dfeffff           call 0x5a7920
// 005a7ab3  8bc7                 mov eax, edi
// 005a7ab5  5f                   pop edi
// 005a7ab6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ??4?$CSimpleStringT@D$0A@@ATL@@QAEAAV01@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
