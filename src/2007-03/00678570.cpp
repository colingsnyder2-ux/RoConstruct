// from server: 100% by auto
// roc 2007-03 00678570  unit: seg_00670000  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00678570
//
// 00678570  53                   push ebx
// 00678571  56                   push esi
// 00678572  8bf1                 mov esi, ecx
// 00678574  e87b290c00           call 0x73aef4
// 00678579  8bd8                 mov ebx, eax
// 0067857b  8b06                 mov eax, dword ptr [esi]
// 0067857d  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 00678583  8bce                 mov ecx, esi
// 00678585  ffd2                 call edx
// 00678587  6a00                 push 0
// 00678589  8bce                 mov ecx, esi
// 0067858b  e87c290c00           call 0x73af0c
// 00678590  8d86b0000000         lea eax, [esi + 0xb0]
// 00678596  85c0                 test eax, eax
// 00678598  7449                 je 0x6785e3
// 0067859a  83782000             cmp dword ptr [eax + 0x20], 0
// 0067859e  7443                 je 0x6785e3
// 006785a0  8b4620               mov eax, dword ptr [esi + 0x20]
// 006785a3  57                   push edi
// 006785a4  8b3d50ee7700         mov edi, dword ptr [0x77ee50]
// 006785aa  6a00                 push 0
// 006785ac  6a00                 push 0
// 006785ae  6a31                 push 0x31
// 006785b0  50                   push eax
// 006785b1  ffd7                 call edi
// 006785b3  50                   push eax
// 006785b4  e81361faff           call 0x61e6cc
// 006785b9  85c0                 test eax, eax
// 006785bb  7514                 jne 0x6785d1
// 006785bd  8b8ed0000000         mov ecx, dword ptr [esi + 0xd0]
// 006785c3  6a01                 push 1
// 006785c5  50                   push eax
// 006785c6  6a30                 push 0x30
// 006785c8  51                   push ecx
// 006785c9  ffd7                 call edi
// 006785cb  5f                   pop edi
// 006785cc  5e                   pop esi
// 006785cd  8bc3                 mov eax, ebx
// 006785cf  5b                   pop ebx
// 006785d0  c3                   ret 
// 006785d1  8b4004               mov eax, dword ptr [eax + 4]
// 006785d4  8b8ed0000000         mov ecx, dword ptr [esi + 0xd0]
// 006785da  6a01                 push 1
// 006785dc  50                   push eax
// 006785dd  6a30                 push 0x30
// 006785df  51                   push ecx
// 006785e0  ffd7                 call edi
// 006785e2  5f                   pop edi
// 006785e3  5e                   pop esi
// 006785e4  8bc3                 mov eax, ebx
// 006785e6  5b                   pop ebx
// 006785e7  c3                   ret 
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorDialog.cpp (function ?OnInitDialog@CXTPColorDialog@@MAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorDialog.cpp
