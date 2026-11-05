// from server: 100% by auto
// roc 2010-06 006097e0  unit: std::strstream  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006097e0
//
// 006097e0  53                   push ebx
// 006097e1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 006097e5  55                   push ebp
// 006097e6  56                   push esi
// 006097e7  57                   push edi
// 006097e8  8bf9                 mov edi, ecx
// 006097ea  85db                 test ebx, ebx
// 006097ec  7470                 je 0x60985e
// 006097ee  8b2daca39e00         mov ebp, dword ptr [0x9ea3ac]
// 006097f4  6a00                 push 0
// 006097f6  6a00                 push 0
// 006097f8  6a00                 push 0
// 006097fa  6a00                 push 0
// 006097fc  6aff                 push -1
// 006097fe  53                   push ebx
// 006097ff  6a00                 push 0
// 00609801  6a03                 push 3
// 00609803  ffd5                 call ebp
// 00609805  8bf0                 mov esi, eax
// 00609807  4e                   dec esi
// 00609808  85f6                 test esi, esi
// 0060980a  7e52                 jle 0x60985e
// 0060980c  8b07                 mov eax, dword ptr [edi]
// 0060980e  8b50f8               mov edx, dword ptr [eax - 8]
// 00609811  83e810               sub eax, 0x10
// 00609814  b901000000           mov ecx, 1
// 00609819  2b480c               sub ecx, dword ptr [eax + 0xc]
// 0060981c  2bd6                 sub edx, esi
// 0060981e  0bca                 or ecx, edx
// 00609820  7d08                 jge 0x60982a
// 00609822  56                   push esi
// 00609823  8bcf                 mov ecx, edi
// 00609825  e846b4dfff           call 0x404c70
// 0060982a  8b07                 mov eax, dword ptr [edi]
// 0060982c  6a00                 push 0
// 0060982e  6a00                 push 0
// 00609830  56                   push esi
// 00609831  50                   push eax
// 00609832  6aff                 push -1
// 00609834  53                   push ebx
// 00609835  6a00                 push 0
// 00609837  6a03                 push 3
// 00609839  ffd5                 call ebp
// 0060983b  8b07                 mov eax, dword ptr [edi]
// 0060983d  3b70f8               cmp esi, dword ptr [eax - 8]
// 00609840  7f12                 jg 0x609854
// 00609842  8970f4               mov dword ptr [eax - 0xc], esi
// 00609845  8b0f                 mov ecx, dword ptr [edi]
// 00609847  8bc7                 mov eax, edi
// 00609849  5f                   pop edi
// 0060984a  c6040e00             mov byte ptr [esi + ecx], 0
// 0060984e  5e                   pop esi
// 0060984f  5d                   pop ebp
// 00609850  5b                   pop ebx
// 00609851  c20400               ret 4
// 00609854  6857000780           push 0x80070057
// 00609859  e87293dfff           call 0x402bd0
// 0060985e  8bcf                 mov ecx, edi
// 00609860  e82b76f9ff           call 0x5a0e90
// 00609865  8bc7                 mov eax, edi
// 00609867  5f                   pop edi
// 00609868  5e                   pop esi
// 00609869  5d                   pop ebp
// 0060986a  5b                   pop ebx
// 0060986b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ??4?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV01@PB_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
