// from server: 100% by auto
// roc 2011-06 00459570  unit: CRobloxApp  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00459570
//
// 00459570  53                   push ebx
// 00459571  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00459575  85db                 test ebx, ebx
// 00459577  750a                 jne 0x459583
// 00459579  6803400080           push 0x80004003
// 0045957e  e81da0faff           call 0x4035a0
// 00459583  57                   push edi
// 00459584  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00459588  85ff                 test edi, edi
// 0045958a  750a                 jne 0x459596
// 0045958c  6803400080           push 0x80004003
// 00459591  e80aa0faff           call 0x4035a0
// 00459596  55                   push ebp
// 00459597  56                   push esi
// 00459598  6a00                 push 0
// 0045959a  ff15e419a400         call dword ptr [0xa419e4]
// 004595a0  8b2d7401a400         mov ebp, dword ptr [0xa40174]
// 004595a6  8bf0                 mov esi, eax
// 004595a8  6a58                 push 0x58
// 004595aa  56                   push esi
// 004595ab  ffd5                 call ebp
// 004595ad  6a5a                 push 0x5a
// 004595af  56                   push esi
// 004595b0  8944241c             mov dword ptr [esp + 0x1c], eax
// 004595b4  ffd5                 call ebp
// 004595b6  56                   push esi
// 004595b7  6a00                 push 0
// 004595b9  8be8                 mov ebp, eax
// 004595bb  ff15dc19a400         call dword ptr [0xa419dc]
// 004595c1  8b03                 mov eax, dword ptr [ebx]
// 004595c3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004595c7  8b35dc01a400         mov esi, dword ptr [0xa401dc]
// 004595cd  68ec090000           push 0x9ec
// 004595d2  50                   push eax
// 004595d3  51                   push ecx
// 004595d4  ffd6                 call esi
// 004595d6  8907                 mov dword ptr [edi], eax
// 004595d8  8b5304               mov edx, dword ptr [ebx + 4]
// 004595db  68ec090000           push 0x9ec
// 004595e0  52                   push edx
// 004595e1  55                   push ebp
// 004595e2  ffd6                 call esi
// 004595e4  5e                   pop esi
// 004595e5  5d                   pop ebp
// 004595e6  894704               mov dword ptr [edi + 4], eax
// 004595e9  5f                   pop edi
// 004595ea  5b                   pop ebx
// 004595eb  c20800               ret 8
// library atl-8.0/atl.cpp (function _AtlHiMetricToPixel@8)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
