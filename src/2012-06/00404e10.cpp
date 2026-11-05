// from server: 100% by auto
// roc 2012-06 00404e10  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404e10
//
// 00404e10  51                   push ecx
// 00404e11  53                   push ebx
// 00404e12  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00404e16  8bc1                 mov eax, ecx
// 00404e18  89442404             mov dword ptr [esp + 4], eax
// 00404e1c  85db                 test ebx, ebx
// 00404e1e  7475                 je 0x404e95
// 00404e20  55                   push ebp
// 00404e21  8b2dcc21b200         mov ebp, dword ptr [0xb221cc]
// 00404e27  56                   push esi
// 00404e28  57                   push edi
// 00404e29  6a00                 push 0
// 00404e2b  6a00                 push 0
// 00404e2d  6aff                 push -1
// 00404e2f  53                   push ebx
// 00404e30  6a00                 push 0
// 00404e32  6a03                 push 3
// 00404e34  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00404e3c  ffd5                 call ebp
// 00404e3e  8bf0                 mov esi, eax
// 00404e40  8d46ff               lea eax, [esi - 1]
// 00404e43  50                   push eax
// 00404e44  6a00                 push 0
// 00404e46  ff15082bb200         call dword ptr [0xb22b08]
// 00404e4c  8bf8                 mov edi, eax
// 00404e4e  85ff                 test edi, edi
// 00404e50  7423                 je 0x404e75
// 00404e52  56                   push esi
// 00404e53  57                   push edi
// 00404e54  6aff                 push -1
// 00404e56  53                   push ebx
// 00404e57  6a00                 push 0
// 00404e59  6a03                 push 3
// 00404e5b  ffd5                 call ebp
// 00404e5d  3bc6                 cmp eax, esi
// 00404e5f  7414                 je 0x404e75
// 00404e61  57                   push edi
// 00404e62  ff15042bb200         call dword ptr [0xb22b04]
// 00404e68  8d4c2418             lea ecx, [esp + 0x18]
// 00404e6c  e8effbffff           call 0x404a60
// 00404e71  33ff                 xor edi, edi
// 00404e73  eb09                 jmp 0x404e7e
// 00404e75  8d4c2418             lea ecx, [esp + 0x18]
// 00404e79  e8e2fbffff           call 0x404a60
// 00404e7e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00404e82  8939                 mov dword ptr [ecx], edi
// 00404e84  85ff                 test edi, edi
// 00404e86  5f                   pop edi
// 00404e87  5e                   pop esi
// 00404e88  5d                   pop ebp
// 00404e89  7515                 jne 0x404ea0
// 00404e8b  680e000780           push 0x8007000e
// 00404e90  e81bf3ffff           call 0x4041b0
// 00404e95  c70000000000         mov dword ptr [eax], 0
// 00404e9b  5b                   pop ebx
// 00404e9c  59                   pop ecx
// 00404e9d  c20400               ret 4
// 00404ea0  8bc1                 mov eax, ecx
// 00404ea2  5b                   pop ebx
// 00404ea3  59                   pop ecx
// 00404ea4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobals.cpp (function ??0CComBSTR@ATL@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobals.cpp
