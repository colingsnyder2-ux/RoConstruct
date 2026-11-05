// from server: 100% by auto
// roc 2009-12 00403b90  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00403b90
//
// 00403b90  51                   push ecx
// 00403b91  53                   push ebx
// 00403b92  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00403b96  8bc1                 mov eax, ecx
// 00403b98  89442404             mov dword ptr [esp + 4], eax
// 00403b9c  85db                 test ebx, ebx
// 00403b9e  7475                 je 0x403c15
// 00403ba0  55                   push ebp
// 00403ba1  8b2d40b29800         mov ebp, dword ptr [0x98b240]
// 00403ba7  56                   push esi
// 00403ba8  57                   push edi
// 00403ba9  6a00                 push 0
// 00403bab  6a00                 push 0
// 00403bad  6aff                 push -1
// 00403baf  53                   push ebx
// 00403bb0  6a00                 push 0
// 00403bb2  6a03                 push 3
// 00403bb4  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00403bbc  ffd5                 call ebp
// 00403bbe  8bf0                 mov esi, eax
// 00403bc0  8d46ff               lea eax, [esi - 1]
// 00403bc3  50                   push eax
// 00403bc4  6a00                 push 0
// 00403bc6  ff1510ba9800         call dword ptr [0x98ba10]
// 00403bcc  8bf8                 mov edi, eax
// 00403bce  85ff                 test edi, edi
// 00403bd0  7423                 je 0x403bf5
// 00403bd2  56                   push esi
// 00403bd3  57                   push edi
// 00403bd4  6aff                 push -1
// 00403bd6  53                   push ebx
// 00403bd7  6a00                 push 0
// 00403bd9  6a03                 push 3
// 00403bdb  ffd5                 call ebp
// 00403bdd  3bc6                 cmp eax, esi
// 00403bdf  7414                 je 0x403bf5
// 00403be1  57                   push edi
// 00403be2  ff1590ba9800         call dword ptr [0x98ba90]
// 00403be8  8d4c2418             lea ecx, [esp + 0x18]
// 00403bec  e88ffcffff           call 0x403880
// 00403bf1  33ff                 xor edi, edi
// 00403bf3  eb09                 jmp 0x403bfe
// 00403bf5  8d4c2418             lea ecx, [esp + 0x18]
// 00403bf9  e882fcffff           call 0x403880
// 00403bfe  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00403c02  8939                 mov dword ptr [ecx], edi
// 00403c04  85ff                 test edi, edi
// 00403c06  5f                   pop edi
// 00403c07  5e                   pop esi
// 00403c08  5d                   pop ebp
// 00403c09  7515                 jne 0x403c20
// 00403c0b  680e000780           push 0x8007000e
// 00403c10  e86befffff           call 0x402b80
// 00403c15  c70000000000         mov dword ptr [eax], 0
// 00403c1b  5b                   pop ebx
// 00403c1c  59                   pop ecx
// 00403c1d  c20400               ret 4
// 00403c20  8bc1                 mov eax, ecx
// 00403c22  5b                   pop ebx
// 00403c23  59                   pop ecx
// 00403c24  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobals.cpp (function ??0CComBSTR@ATL@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobals.cpp
