// from server: 100% by auto
// roc 2011-06 004046c0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004046c0
//
// 004046c0  51                   push ecx
// 004046c1  53                   push ebx
// 004046c2  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 004046c6  8bc1                 mov eax, ecx
// 004046c8  89442404             mov dword ptr [esp + 4], eax
// 004046cc  85db                 test ebx, ebx
// 004046ce  7475                 je 0x404745
// 004046d0  55                   push ebp
// 004046d1  8b2d9003a400         mov ebp, dword ptr [0xa40390]
// 004046d7  56                   push esi
// 004046d8  57                   push edi
// 004046d9  6a00                 push 0
// 004046db  6a00                 push 0
// 004046dd  6aff                 push -1
// 004046df  53                   push ebx
// 004046e0  6a00                 push 0
// 004046e2  6a03                 push 3
// 004046e4  c744243000000000     mov dword ptr [esp + 0x30], 0
// 004046ec  ffd5                 call ebp
// 004046ee  8bf0                 mov esi, eax
// 004046f0  8d46ff               lea eax, [esi - 1]
// 004046f3  50                   push eax
// 004046f4  6a00                 push 0
// 004046f6  ff15fc0aa400         call dword ptr [0xa40afc]
// 004046fc  8bf8                 mov edi, eax
// 004046fe  85ff                 test edi, edi
// 00404700  7423                 je 0x404725
// 00404702  56                   push esi
// 00404703  57                   push edi
// 00404704  6aff                 push -1
// 00404706  53                   push ebx
// 00404707  6a00                 push 0
// 00404709  6a03                 push 3
// 0040470b  ffd5                 call ebp
// 0040470d  3bc6                 cmp eax, esi
// 0040470f  7414                 je 0x404725
// 00404711  57                   push edi
// 00404712  ff15000ba400         call dword ptr [0xa40b00]
// 00404718  8d4c2418             lea ecx, [esp + 0x18]
// 0040471c  e89ffbffff           call 0x4042c0
// 00404721  33ff                 xor edi, edi
// 00404723  eb09                 jmp 0x40472e
// 00404725  8d4c2418             lea ecx, [esp + 0x18]
// 00404729  e892fbffff           call 0x4042c0
// 0040472e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00404732  8939                 mov dword ptr [ecx], edi
// 00404734  85ff                 test edi, edi
// 00404736  5f                   pop edi
// 00404737  5e                   pop esi
// 00404738  5d                   pop ebp
// 00404739  7515                 jne 0x404750
// 0040473b  680e000780           push 0x8007000e
// 00404740  e85beeffff           call 0x4035a0
// 00404745  c70000000000         mov dword ptr [eax], 0
// 0040474b  5b                   pop ebx
// 0040474c  59                   pop ecx
// 0040474d  c20400               ret 4
// 00404750  8bc1                 mov eax, ecx
// 00404752  5b                   pop ebx
// 00404753  59                   pop ecx
// 00404754  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobals.cpp (function ??0CComBSTR@ATL@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobals.cpp
