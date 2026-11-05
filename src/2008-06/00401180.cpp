// from server: 100% by auto
// roc 2008-06 00401180  unit: CInsertObjectDialog  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401180
//
// 00401180  51                   push ecx
// 00401181  53                   push ebx
// 00401182  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00401186  8bc1                 mov eax, ecx
// 00401188  89442404             mov dword ptr [esp + 4], eax
// 0040118c  85db                 test ebx, ebx
// 0040118e  7475                 je 0x401205
// 00401190  55                   push ebp
// 00401191  8b2d1c238000         mov ebp, dword ptr [0x80231c]
// 00401197  56                   push esi
// 00401198  57                   push edi
// 00401199  6a00                 push 0
// 0040119b  6a00                 push 0
// 0040119d  6aff                 push -1
// 0040119f  53                   push ebx
// 004011a0  6a00                 push 0
// 004011a2  6a03                 push 3
// 004011a4  c744243000000000     mov dword ptr [esp + 0x30], 0
// 004011ac  ffd5                 call ebp
// 004011ae  8bf0                 mov esi, eax
// 004011b0  8d46ff               lea eax, [esi - 1]
// 004011b3  50                   push eax
// 004011b4  6a00                 push 0
// 004011b6  ff1540298000         call dword ptr [0x802940]
// 004011bc  8bf8                 mov edi, eax
// 004011be  85ff                 test edi, edi
// 004011c0  7423                 je 0x4011e5
// 004011c2  56                   push esi
// 004011c3  57                   push edi
// 004011c4  6aff                 push -1
// 004011c6  53                   push ebx
// 004011c7  6a00                 push 0
// 004011c9  6a03                 push 3
// 004011cb  ffd5                 call ebp
// 004011cd  3bc6                 cmp eax, esi
// 004011cf  7414                 je 0x4011e5
// 004011d1  57                   push edi
// 004011d2  ff1544298000         call dword ptr [0x802944]
// 004011d8  8d4c2418             lea ecx, [esp + 0x18]
// 004011dc  e86fffffff           call 0x401150
// 004011e1  33ff                 xor edi, edi
// 004011e3  eb09                 jmp 0x4011ee
// 004011e5  8d4c2418             lea ecx, [esp + 0x18]
// 004011e9  e862ffffff           call 0x401150
// 004011ee  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004011f2  8939                 mov dword ptr [ecx], edi
// 004011f4  85ff                 test edi, edi
// 004011f6  5f                   pop edi
// 004011f7  5e                   pop esi
// 004011f8  5d                   pop ebp
// 004011f9  7515                 jne 0x401210
// 004011fb  680e000780           push 0x8007000e
// 00401200  e8fbfdffff           call 0x401000
// 00401205  c70000000000         mov dword ptr [eax], 0
// 0040120b  5b                   pop ebx
// 0040120c  59                   pop ecx
// 0040120d  c20400               ret 4
// 00401210  8bc1                 mov eax, ecx
// 00401212  5b                   pop ebx
// 00401213  59                   pop ecx
// 00401214  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobals.cpp (function ??0CComBSTR@ATL@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobals.cpp
