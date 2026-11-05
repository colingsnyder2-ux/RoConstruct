// from server: 100% by auto
// roc 2009-06 00403ed0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403ed0
//
// 00403ed0  51                   push ecx
// 00403ed1  53                   push ebx
// 00403ed2  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00403ed6  8bc1                 mov eax, ecx
// 00403ed8  89442404             mov dword ptr [esp + 4], eax
// 00403edc  85db                 test ebx, ebx
// 00403ede  7475                 je 0x403f55
// 00403ee0  55                   push ebp
// 00403ee1  8b2d38e38900         mov ebp, dword ptr [0x89e338]
// 00403ee7  56                   push esi
// 00403ee8  57                   push edi
// 00403ee9  6a00                 push 0
// 00403eeb  6a00                 push 0
// 00403eed  6aff                 push -1
// 00403eef  53                   push ebx
// 00403ef0  6a00                 push 0
// 00403ef2  6a03                 push 3
// 00403ef4  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00403efc  ffd5                 call ebp
// 00403efe  8bf0                 mov esi, eax
// 00403f00  8d46ff               lea eax, [esi - 1]
// 00403f03  50                   push eax
// 00403f04  6a00                 push 0
// 00403f06  ff1540ea8900         call dword ptr [0x89ea40]
// 00403f0c  8bf8                 mov edi, eax
// 00403f0e  85ff                 test edi, edi
// 00403f10  7423                 je 0x403f35
// 00403f12  56                   push esi
// 00403f13  57                   push edi
// 00403f14  6aff                 push -1
// 00403f16  53                   push ebx
// 00403f17  6a00                 push 0
// 00403f19  6a03                 push 3
// 00403f1b  ffd5                 call ebp
// 00403f1d  3bc6                 cmp eax, esi
// 00403f1f  7414                 je 0x403f35
// 00403f21  57                   push edi
// 00403f22  ff153cea8900         call dword ptr [0x89ea3c]
// 00403f28  8d4c2418             lea ecx, [esp + 0x18]
// 00403f2c  e87ffcffff           call 0x403bb0
// 00403f31  33ff                 xor edi, edi
// 00403f33  eb09                 jmp 0x403f3e
// 00403f35  8d4c2418             lea ecx, [esp + 0x18]
// 00403f39  e872fcffff           call 0x403bb0
// 00403f3e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00403f42  8939                 mov dword ptr [ecx], edi
// 00403f44  85ff                 test edi, edi
// 00403f46  5f                   pop edi
// 00403f47  5e                   pop esi
// 00403f48  5d                   pop ebp
// 00403f49  7515                 jne 0x403f60
// 00403f4b  680e000780           push 0x8007000e
// 00403f50  e85befffff           call 0x402eb0
// 00403f55  c70000000000         mov dword ptr [eax], 0
// 00403f5b  5b                   pop ebx
// 00403f5c  59                   pop ecx
// 00403f5d  c20400               ret 4
// 00403f60  8bc1                 mov eax, ecx
// 00403f62  5b                   pop ebx
// 00403f63  59                   pop ecx
// 00403f64  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobals.cpp (function ??0CComBSTR@ATL@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobals.cpp
