// from server: 100% by auto
// roc 2009-12 0069def0  unit: std::strstream  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0069def0
//
// 0069def0  53                   push ebx
// 0069def1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0069def5  55                   push ebp
// 0069def6  56                   push esi
// 0069def7  57                   push edi
// 0069def8  8bf9                 mov edi, ecx
// 0069defa  85db                 test ebx, ebx
// 0069defc  7470                 je 0x69df6e
// 0069defe  8b2d3cb29800         mov ebp, dword ptr [0x98b23c]
// 0069df04  6a00                 push 0
// 0069df06  6a00                 push 0
// 0069df08  6a00                 push 0
// 0069df0a  6a00                 push 0
// 0069df0c  6aff                 push -1
// 0069df0e  53                   push ebx
// 0069df0f  6a00                 push 0
// 0069df11  6a03                 push 3
// 0069df13  ffd5                 call ebp
// 0069df15  8bf0                 mov esi, eax
// 0069df17  4e                   dec esi
// 0069df18  85f6                 test esi, esi
// 0069df1a  7e52                 jle 0x69df6e
// 0069df1c  8b07                 mov eax, dword ptr [edi]
// 0069df1e  8b50f8               mov edx, dword ptr [eax - 8]
// 0069df21  83e810               sub eax, 0x10
// 0069df24  b901000000           mov ecx, 1
// 0069df29  2b480c               sub ecx, dword ptr [eax + 0xc]
// 0069df2c  2bd6                 sub edx, esi
// 0069df2e  0bca                 or ecx, edx
// 0069df30  7d08                 jge 0x69df3a
// 0069df32  56                   push esi
// 0069df33  8bcf                 mov ecx, edi
// 0069df35  e8066dd6ff           call 0x404c40
// 0069df3a  8b07                 mov eax, dword ptr [edi]
// 0069df3c  6a00                 push 0
// 0069df3e  6a00                 push 0
// 0069df40  56                   push esi
// 0069df41  50                   push eax
// 0069df42  6aff                 push -1
// 0069df44  53                   push ebx
// 0069df45  6a00                 push 0
// 0069df47  6a03                 push 3
// 0069df49  ffd5                 call ebp
// 0069df4b  8b07                 mov eax, dword ptr [edi]
// 0069df4d  3b70f8               cmp esi, dword ptr [eax - 8]
// 0069df50  7f12                 jg 0x69df64
// 0069df52  8970f4               mov dword ptr [eax - 0xc], esi
// 0069df55  8b0f                 mov ecx, dword ptr [edi]
// 0069df57  8bc7                 mov eax, edi
// 0069df59  5f                   pop edi
// 0069df5a  c6040e00             mov byte ptr [esi + ecx], 0
// 0069df5e  5e                   pop esi
// 0069df5f  5d                   pop ebp
// 0069df60  5b                   pop ebx
// 0069df61  c20400               ret 4
// 0069df64  6857000780           push 0x80070057
// 0069df69  e8124cd6ff           call 0x402b80
// 0069df6e  8bcf                 mov ecx, edi
// 0069df70  e88b10faff           call 0x63f000
// 0069df75  8bc7                 mov eax, edi
// 0069df77  5f                   pop edi
// 0069df78  5e                   pop esi
// 0069df79  5d                   pop ebp
// 0069df7a  5b                   pop ebx
// 0069df7b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ??4?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV01@PB_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
