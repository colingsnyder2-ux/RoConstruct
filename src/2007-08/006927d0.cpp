// from server: 100% by auto
// roc 2007-08 006927d0  unit: CXTPStatusBarPane  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006927d0
//
// 006927d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006927d4  83ec10               sub esp, 0x10
// 006927d7  53                   push ebx
// 006927d8  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006927dc  56                   push esi
// 006927dd  8bf1                 mov esi, ecx
// 006927df  8bc8                 mov ecx, eax
// 006927e1  81e1ffff4000         and ecx, 0x40ffff
// 006927e7  254e00bfff           and eax, 0xffbf004e
// 006927ec  898e80000000         mov dword ptr [esi + 0x80], ecx
// 006927f2  83c84e               or eax, 0x4e
// 006927f5  57                   push edi
// 006927f6  8bcb                 mov ecx, ebx
// 006927f8  8bf8                 mov edi, eax
// 006927fa  e8135c0a00           call 0x738412
// 006927ff  a900000400           test eax, 0x40000
// 00692804  7406                 je 0x69280c
// 00692806  81cf00010000         or edi, 0x100
// 0069280c  6800100000           push 0x1000
// 00692811  e8565f0a00           call 0x73876c
// 00692816  8d54240c             lea edx, [esp + 0xc]
// 0069281a  52                   push edx
// 0069281b  ff1514ee7700         call dword ptr [0x77ee14]
// 00692821  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00692825  8b542424             mov edx, dword ptr [esp + 0x24]
// 00692829  6a00                 push 0
// 0069282b  50                   push eax
// 0069282c  53                   push ebx
// 0069282d  8d4c2418             lea ecx, [esp + 0x18]
// 00692831  51                   push ecx
// 00692832  0bd7                 or edx, edi
// 00692834  52                   push edx
// 00692835  6a00                 push 0
// 00692837  6890097d00           push 0x7d0990
// 0069283c  8bce                 mov ecx, esi
// 0069283e  e897d4f9ff           call 0x62fcda
// 00692843  5f                   pop edi
// 00692844  5e                   pop esi
// 00692845  5b                   pop ebx
// 00692846  83c410               add esp, 0x10
// 00692849  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?CreateEx@CStatusBar@@UAEHPAVCWnd@@KKI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
