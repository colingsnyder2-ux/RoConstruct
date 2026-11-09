// from server: 100% by auto
// roc 2009-12 0069e0e0  unit: std::strstream  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0069e0e0
//
// 0069e0e0  8b542404             mov edx, dword ptr [esp + 4]
// 0069e0e4  57                   push edi
// 0069e0e5  8bf9                 mov edi, ecx
// 0069e0e7  85d2                 test edx, edx
// 0069e0e9  750f                 jne 0x69e0fa
// 0069e0eb  33c0                 xor eax, eax
// 0069e0ed  50                   push eax
// 0069e0ee  52                   push edx
// 0069e0ef  e88cfeffff           call 0x69df80
// 0069e0f4  8bc7                 mov eax, edi
// 0069e0f6  5f                   pop edi
// 0069e0f7  c20400               ret 4
// 0069e0fa  8bc2                 mov eax, edx
// 0069e0fc  56                   push esi
// 0069e0fd  8d7001               lea esi, [eax + 1]
// 0069e100  8a08                 mov cl, byte ptr [eax]
// 0069e102  40                   inc eax
// 0069e103  84c9                 test cl, cl
// 0069e105  75f9                 jne 0x69e100
// 0069e107  2bc6                 sub eax, esi
// 0069e109  5e                   pop esi
// 0069e10a  50                   push eax
// 0069e10b  52                   push edx
// 0069e10c  8bcf                 mov ecx, edi
// 0069e10e  e86dfeffff           call 0x69df80
// 0069e113  8bc7                 mov eax, edi
// 0069e115  5f                   pop edi
// 0069e116  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ??4?$CSimpleStringT@D$0A@@ATL@@QAEAAV01@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
