// from server: 100% by auto
// roc 2010-06 00403bf0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403bf0
//
// 00403bf0  51                   push ecx
// 00403bf1  53                   push ebx
// 00403bf2  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00403bf6  8bc1                 mov eax, ecx
// 00403bf8  89442404             mov dword ptr [esp + 4], eax
// 00403bfc  85db                 test ebx, ebx
// 00403bfe  7475                 je 0x403c75
// 00403c00  55                   push ebp
// 00403c01  8b2db0a39e00         mov ebp, dword ptr [0x9ea3b0]
// 00403c07  56                   push esi
// 00403c08  57                   push edi
// 00403c09  6a00                 push 0
// 00403c0b  6a00                 push 0
// 00403c0d  6aff                 push -1
// 00403c0f  53                   push ebx
// 00403c10  6a00                 push 0
// 00403c12  6a03                 push 3
// 00403c14  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00403c1c  ffd5                 call ebp
// 00403c1e  8bf0                 mov esi, eax
// 00403c20  8d46ff               lea eax, [esi - 1]
// 00403c23  50                   push eax
// 00403c24  6a00                 push 0
// 00403c26  ff1544aa9e00         call dword ptr [0x9eaa44]
// 00403c2c  8bf8                 mov edi, eax
// 00403c2e  85ff                 test edi, edi
// 00403c30  7423                 je 0x403c55
// 00403c32  56                   push esi
// 00403c33  57                   push edi
// 00403c34  6aff                 push -1
// 00403c36  53                   push ebx
// 00403c37  6a00                 push 0
// 00403c39  6a03                 push 3
// 00403c3b  ffd5                 call ebp
// 00403c3d  3bc6                 cmp eax, esi
// 00403c3f  7414                 je 0x403c55
// 00403c41  57                   push edi
// 00403c42  ff1540aa9e00         call dword ptr [0x9eaa40]
// 00403c48  8d4c2418             lea ecx, [esp + 0x18]
// 00403c4c  e87ffcffff           call 0x4038d0
// 00403c51  33ff                 xor edi, edi
// 00403c53  eb09                 jmp 0x403c5e
// 00403c55  8d4c2418             lea ecx, [esp + 0x18]
// 00403c59  e872fcffff           call 0x4038d0
// 00403c5e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00403c62  8939                 mov dword ptr [ecx], edi
// 00403c64  85ff                 test edi, edi
// 00403c66  5f                   pop edi
// 00403c67  5e                   pop esi
// 00403c68  5d                   pop ebp
// 00403c69  7515                 jne 0x403c80
// 00403c6b  680e000780           push 0x8007000e
// 00403c70  e85befffff           call 0x402bd0
// 00403c75  c70000000000         mov dword ptr [eax], 0
// 00403c7b  5b                   pop ebx
// 00403c7c  59                   pop ecx
// 00403c7d  c20400               ret 4
// 00403c80  8bc1                 mov eax, ecx
// 00403c82  5b                   pop ebx
// 00403c83  59                   pop ecx
// 00403c84  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobals.cpp (function ??0CComBSTR@ATL@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobals.cpp
