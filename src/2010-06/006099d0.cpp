// from server: 100% by auto
// roc 2010-06 006099d0  unit: std::strstream  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006099d0
//
// 006099d0  8b542404             mov edx, dword ptr [esp + 4]
// 006099d4  57                   push edi
// 006099d5  8bf9                 mov edi, ecx
// 006099d7  85d2                 test edx, edx
// 006099d9  750f                 jne 0x6099ea
// 006099db  33c0                 xor eax, eax
// 006099dd  50                   push eax
// 006099de  52                   push edx
// 006099df  e88cfeffff           call 0x609870
// 006099e4  8bc7                 mov eax, edi
// 006099e6  5f                   pop edi
// 006099e7  c20400               ret 4
// 006099ea  8bc2                 mov eax, edx
// 006099ec  56                   push esi
// 006099ed  8d7001               lea esi, [eax + 1]
// 006099f0  8a08                 mov cl, byte ptr [eax]
// 006099f2  40                   inc eax
// 006099f3  84c9                 test cl, cl
// 006099f5  75f9                 jne 0x6099f0
// 006099f7  2bc6                 sub eax, esi
// 006099f9  5e                   pop esi
// 006099fa  50                   push eax
// 006099fb  52                   push edx
// 006099fc  8bcf                 mov ecx, edi
// 006099fe  e86dfeffff           call 0x609870
// 00609a03  8bc7                 mov eax, edi
// 00609a05  5f                   pop edi
// 00609a06  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ??4?$CSimpleStringT@D$0A@@ATL@@QAEAAV01@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
