// from server: 100% by auto
// roc 2007-03 0067c1f0  unit: seg_00670000  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067c1f0
//
// 0067c1f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0067c1f4  83ec10               sub esp, 0x10
// 0067c1f7  53                   push ebx
// 0067c1f8  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0067c1fc  56                   push esi
// 0067c1fd  8bf1                 mov esi, ecx
// 0067c1ff  8bc8                 mov ecx, eax
// 0067c201  81e1ffff4000         and ecx, 0x40ffff
// 0067c207  254e00bfff           and eax, 0xffbf004e
// 0067c20c  898e80000000         mov dword ptr [esi + 0x80], ecx
// 0067c212  83c84e               or eax, 0x4e
// 0067c215  57                   push edi
// 0067c216  8bcb                 mov ecx, ebx
// 0067c218  8bf8                 mov edi, eax
// 0067c21a  e8a5e90b00           call 0x73abc4
// 0067c21f  a900000400           test eax, 0x40000
// 0067c224  7406                 je 0x67c22c
// 0067c226  81cf00010000         or edi, 0x100
// 0067c22c  6800100000           push 0x1000
// 0067c231  e806ed0b00           call 0x73af3c
// 0067c236  8d54240c             lea edx, [esp + 0xc]
// 0067c23a  52                   push edx
// 0067c23b  ff1514ef7700         call dword ptr [0x77ef14]
// 0067c241  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0067c245  8b542424             mov edx, dword ptr [esp + 0x24]
// 0067c249  6a00                 push 0
// 0067c24b  50                   push eax
// 0067c24c  53                   push ebx
// 0067c24d  8d4c2418             lea ecx, [esp + 0x18]
// 0067c251  51                   push ecx
// 0067c252  0bd7                 or edx, edi
// 0067c254  52                   push edx
// 0067c255  6a00                 push 0
// 0067c257  68c0d57c00           push 0x7cd5c0
// 0067c25c  8bce                 mov ecx, esi
// 0067c25e  e80b1ffaff           call 0x61e16e
// 0067c263  5f                   pop edi
// 0067c264  5e                   pop esi
// 0067c265  5b                   pop ebx
// 0067c266  83c410               add esp, 0x10
// 0067c269  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?CreateEx@CStatusBar@@UAEHPAVCWnd@@KKI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
