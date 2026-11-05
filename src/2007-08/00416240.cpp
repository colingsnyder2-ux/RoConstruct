// from server: 100% by auto
// roc 2007-08 00416240  unit: VCLuaFunction::?$CComAggObject  size: 410 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00416240
//
// 00416240  83ec70               sub esp, 0x70
// 00416243  53                   push ebx
// 00416244  56                   push esi
// 00416245  8b74247c             mov esi, dword ptr [esp + 0x7c]
// 00416249  85f6                 test esi, esi
// 0041624b  0f8480010000         je 0x4163d1
// 00416251  8b842480000000       mov eax, dword ptr [esp + 0x80]
// 00416258  85c0                 test eax, eax
// 0041625a  0f8471010000         je 0x4163d1
// 00416260  8b9c2484000000       mov ebx, dword ptr [esp + 0x84]
// 00416267  85db                 test ebx, ebx
// 00416269  0f8462010000         je 0x4163d1
// 0041626f  83bc248800000000     cmp dword ptr [esp + 0x88], 0
// 00416277  0f8454010000         je 0x4163d1
// 0041627d  66837b4000           cmp word ptr [ebx + 0x40], 0
// 00416282  55                   push ebp
// 00416283  57                   push edi
// 00416284  0f8529010000         jne 0x4163b3
// 0041628a  83c004               add eax, 4
// 0041628d  8d4c2418             lea ecx, [esp + 0x18]
// 00416291  89442418             mov dword ptr [esp + 0x18], eax
// 00416295  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0041629a  e841c7feff           call 0x4029e0
// 0041629f  85c0                 test eax, eax
// 004162a1  7c4f                 jl 0x4162f2
// 004162a3  66837b4000           cmp word ptr [ebx + 0x40], 0
// 004162a8  0f85fc000000         jne 0x4163aa
// 004162ae  8b4330               mov eax, dword ptr [ebx + 0x30]
// 004162b1  85c0                 test eax, eax
// 004162b3  8b2d1cec7700         mov ebp, dword ptr [0x77ec1c]
// 004162b9  7475                 je 0x416330
// 004162bb  8b4b28               mov ecx, dword ptr [ebx + 0x28]
// 004162be  8b5308               mov edx, dword ptr [ebx + 8]
// 004162c1  894c2410             mov dword ptr [esp + 0x10], ecx
// 004162c5  8d4c2420             lea ecx, [esp + 0x20]
// 004162c9  51                   push ecx
// 004162ca  50                   push eax
// 004162cb  6a00                 push 0
// 004162cd  89542420             mov dword ptr [esp + 0x20], edx
// 004162d1  c744242c30000000     mov dword ptr [esp + 0x2c], 0x30
// 004162d9  ffd5                 call ebp
// 004162db  85c0                 test eax, eax
// 004162dd  7527                 jne 0x416306
// 004162df  8b4330               mov eax, dword ptr [ebx + 0x30]
// 004162e2  8b4e04               mov ecx, dword ptr [esi + 4]
// 004162e5  8d542420             lea edx, [esp + 0x20]
// 004162e9  52                   push edx
// 004162ea  50                   push eax
// 004162eb  51                   push ecx
// 004162ec  ffd5                 call ebp
// 004162ee  85c0                 test eax, eax
// 004162f0  7514                 jne 0x416306
// 004162f2  8d4c2418             lea ecx, [esp + 0x18]
// 004162f6  e885780000           call 0x41db80
// 004162fb  5f                   pop edi
// 004162fc  5d                   pop ebp
// 004162fd  5e                   pop esi
// 004162fe  6633c0               xor ax, ax
// 00416301  5b                   pop ebx
// 00416302  83c470               add esp, 0x70
// 00416305  c3                   ret 
// 00416306  8b542414             mov edx, dword ptr [esp + 0x14]
// 0041630a  b90c000000           mov ecx, 0xc
// 0041630f  8d742420             lea esi, [esp + 0x20]
// 00416313  8bfb                 mov edi, ebx
// 00416315  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00416317  8b4308               mov eax, dword ptr [ebx + 8]
// 0041631a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041631e  8bb42484000000       mov esi, dword ptr [esp + 0x84]
// 00416325  894334               mov dword ptr [ebx + 0x34], eax
// 00416328  894b28               mov dword ptr [ebx + 0x28], ecx
// 0041632b  895308               mov dword ptr [ebx + 8], edx
// 0041632e  eb1b                 jmp 0x41634b
// 00416330  837b3c00             cmp dword ptr [ebx + 0x3c], 0
// 00416334  7404                 je 0x41633a
// 00416336  33c0                 xor eax, eax
// 00416338  eb03                 jmp 0x41633d
// 0041633a  8b4608               mov eax, dword ptr [esi + 8]
// 0041633d  8b4b38               mov ecx, dword ptr [ebx + 0x38]
// 00416340  51                   push ecx
// 00416341  50                   push eax
// 00416342  ff1520ec7700         call dword ptr [0x77ec20]
// 00416348  89431c               mov dword ptr [ebx + 0x1c], eax
// 0041634b  8b4604               mov eax, dword ptr [esi + 4]
// 0041634e  816304ffbfffff       and dword ptr [ebx + 4], 0xffffbfff
// 00416355  837b2800             cmp dword ptr [ebx + 0x28], 0
// 00416359  894314               mov dword ptr [ebx + 0x14], eax
// 0041635c  7512                 jne 0x416370
// 0041635e  53                   push ebx
// 0041635f  8d7342               lea esi, [ebx + 0x42]
// 00416362  6a25                 push 0x25
// 00416364  56                   push esi
// 00416365  e8f6d3ffff           call 0x413760
// 0041636a  83c40c               add esp, 0xc
// 0041636d  897328               mov dword ptr [ebx + 0x28], esi
// 00416370  8b4328               mov eax, dword ptr [ebx + 0x28]
// 00416373  8d542450             lea edx, [esp + 0x50]
// 00416377  52                   push edx
// 00416378  b90c000000           mov ecx, 0xc
// 0041637d  8bf3                 mov esi, ebx
// 0041637f  8d7c2454             lea edi, [esp + 0x54]
// 00416383  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00416385  8b4b14               mov ecx, dword ptr [ebx + 0x14]
// 00416388  50                   push eax
// 00416389  51                   push ecx
// 0041638a  ffd5                 call ebp
// 0041638c  6685c0               test ax, ax
// 0041638f  66894340             mov word ptr [ebx + 0x40], ax
// 00416393  7515                 jne 0x4163aa
// 00416395  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 0041639c  53                   push ebx
// 0041639d  50                   push eax
// 0041639e  e8adf9ffff           call 0x415d50
// 004163a3  83c408               add esp, 8
// 004163a6  66894340             mov word ptr [ebx + 0x40], ax
// 004163aa  8d4c2418             lea ecx, [esp + 0x18]
// 004163ae  e8cd770000           call 0x41db80
// 004163b3  837b3000             cmp dword ptr [ebx + 0x30], 0
// 004163b7  740c                 je 0x4163c5
// 004163b9  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 004163bc  8b942490000000       mov edx, dword ptr [esp + 0x90]
// 004163c3  890a                 mov dword ptr [edx], ecx
// 004163c5  668b4340             mov ax, word ptr [ebx + 0x40]
// 004163c9  5f                   pop edi
// 004163ca  5d                   pop ebp
// 004163cb  5e                   pop esi
// 004163cc  5b                   pop ebx
// 004163cd  83c470               add esp, 0x70
// 004163d0  c3                   ret 
// 004163d1  5e                   pop esi
// 004163d2  6633c0               xor ax, ax
// 004163d5  5b                   pop ebx
// 004163d6  83c470               add esp, 0x70
// 004163d9  c3                   ret 
// library atl-8.0/atl.cpp (function ??$AtlModuleRegisterWndClassInfoT@VAtlModuleRegisterWndClassInfoParamA@ATL@@@ATL@@YAGPAU_ATL_BASE_MODULE70@0@PAU_ATL_WIN_MODULE70@0@PAU_ATL_WNDCLASSINFOA@0@PAP6GJPAUHWND__@@IIJ@ZVAtlModuleRegisterWndClassInfoParamA@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
