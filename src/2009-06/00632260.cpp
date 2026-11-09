// from server: 100% by auto
// roc 2009-06 00632260  unit: std::strstream  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00632260
//
// 00632260  53                   push ebx
// 00632261  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00632265  55                   push ebp
// 00632266  56                   push esi
// 00632267  57                   push edi
// 00632268  8bf9                 mov edi, ecx
// 0063226a  85db                 test ebx, ebx
// 0063226c  7470                 je 0x6322de
// 0063226e  8b2d3ce28900         mov ebp, dword ptr [0x89e23c]
// 00632274  6a00                 push 0
// 00632276  6a00                 push 0
// 00632278  6a00                 push 0
// 0063227a  6a00                 push 0
// 0063227c  6aff                 push -1
// 0063227e  53                   push ebx
// 0063227f  6a00                 push 0
// 00632281  6a03                 push 3
// 00632283  ffd5                 call ebp
// 00632285  8bf0                 mov esi, eax
// 00632287  4e                   dec esi
// 00632288  85f6                 test esi, esi
// 0063228a  7e52                 jle 0x6322de
// 0063228c  8b07                 mov eax, dword ptr [edi]
// 0063228e  8b50f8               mov edx, dword ptr [eax - 8]
// 00632291  83e810               sub eax, 0x10
// 00632294  b901000000           mov ecx, 1
// 00632299  2b480c               sub ecx, dword ptr [eax + 0xc]
// 0063229c  2bd6                 sub edx, esi
// 0063229e  0bca                 or ecx, edx
// 006322a0  7d08                 jge 0x6322aa
// 006322a2  56                   push esi
// 006322a3  8bcf                 mov ecx, edi
// 006322a5  e8c62cddff           call 0x404f70
// 006322aa  8b07                 mov eax, dword ptr [edi]
// 006322ac  6a00                 push 0
// 006322ae  6a00                 push 0
// 006322b0  56                   push esi
// 006322b1  50                   push eax
// 006322b2  6aff                 push -1
// 006322b4  53                   push ebx
// 006322b5  6a00                 push 0
// 006322b7  6a03                 push 3
// 006322b9  ffd5                 call ebp
// 006322bb  8b07                 mov eax, dword ptr [edi]
// 006322bd  3b70f8               cmp esi, dword ptr [eax - 8]
// 006322c0  7f12                 jg 0x6322d4
// 006322c2  8970f4               mov dword ptr [eax - 0xc], esi
// 006322c5  8b0f                 mov ecx, dword ptr [edi]
// 006322c7  8bc7                 mov eax, edi
// 006322c9  5f                   pop edi
// 006322ca  c6040e00             mov byte ptr [esi + ecx], 0
// 006322ce  5e                   pop esi
// 006322cf  5d                   pop ebp
// 006322d0  5b                   pop ebx
// 006322d1  c20400               ret 4
// 006322d4  6857000780           push 0x80070057
// 006322d9  e8d20bddff           call 0x402eb0
// 006322de  8bcf                 mov ecx, edi
// 006322e0  e86b6efaff           call 0x5d9150
// 006322e5  8bc7                 mov eax, edi
// 006322e7  5f                   pop edi
// 006322e8  5e                   pop esi
// 006322e9  5d                   pop ebp
// 006322ea  5b                   pop ebx
// 006322eb  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ??4?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV01@PB_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
