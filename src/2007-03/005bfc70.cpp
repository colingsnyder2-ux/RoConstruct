// from server: 100% by auto
// roc 2007-03 005bfc70  unit: seg_005b0000  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005bfc70
//
// 005bfc70  53                   push ebx
// 005bfc71  55                   push ebp
// 005bfc72  56                   push esi
// 005bfc73  8b742410             mov esi, dword ptr [esp + 0x10]
// 005bfc77  8b6e28               mov ebp, dword ptr [esi + 0x28]
// 005bfc7a  57                   push edi
// 005bfc7b  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005bfc7f  8d4701               lea eax, [edi + 1]
// 005bfc82  3daaaaaa0a           cmp eax, 0xaaaaaaa
// 005bfc87  7723                 ja 0x5bfcac
// 005bfc89  8b4630               mov eax, dword ptr [esi + 0x30]
// 005bfc8c  8d0c7f               lea ecx, [edi + edi*2]
// 005bfc8f  03c9                 add ecx, ecx
// 005bfc91  8d1440               lea edx, [eax + eax*2]
// 005bfc94  03d2                 add edx, edx
// 005bfc96  03c9                 add ecx, ecx
// 005bfc98  03c9                 add ecx, ecx
// 005bfc9a  51                   push ecx
// 005bfc9b  03d2                 add edx, edx
// 005bfc9d  03d2                 add edx, edx
// 005bfc9f  52                   push edx
// 005bfca0  55                   push ebp
// 005bfca1  56                   push esi
// 005bfca2  e8f9d60300           call 0x5fd3a0
// 005bfca7  83c410               add esp, 0x10
// 005bfcaa  eb09                 jmp 0x5bfcb5
// 005bfcac  56                   push esi
// 005bfcad  e8ced60300           call 0x5fd380
// 005bfcb2  83c404               add esp, 4
// 005bfcb5  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005bfcb8  8bd8                 mov ebx, eax
// 005bfcba  2bcd                 sub ecx, ebp
// 005bfcbc  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005bfcc1  f7e9                 imul ecx
// 005bfcc3  c1fa02               sar edx, 2
// 005bfcc6  8bc2                 mov eax, edx
// 005bfcc8  c1e81f               shr eax, 0x1f
// 005bfccb  03c2                 add eax, edx
// 005bfccd  8d0440               lea eax, [eax + eax*2]
// 005bfcd0  8d0cc3               lea ecx, [ebx + eax*8]
// 005bfcd3  8d147f               lea edx, [edi + edi*2]
// 005bfcd6  897e30               mov dword ptr [esi + 0x30], edi
// 005bfcd9  8d44d3e8             lea eax, [ebx + edx*8 - 0x18]
// 005bfcdd  5f                   pop edi
// 005bfcde  895e28               mov dword ptr [esi + 0x28], ebx
// 005bfce1  894e14               mov dword ptr [esi + 0x14], ecx
// 005bfce4  894624               mov dword ptr [esi + 0x24], eax
// 005bfce7  5e                   pop esi
// 005bfce8  5d                   pop ebp
// 005bfce9  5b                   pop ebx
// 005bfcea  c3                   ret 
// library lua-5.1.1/ldo.c (function _luaD_reallocCI)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
