// from server: 100% by auto
// roc 2011-06 007630e0  unit: seg_00760000  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007630e0
//
// 007630e0  8b442410             mov eax, dword ptr [esp + 0x10]
// 007630e4  83ec08               sub esp, 8
// 007630e7  56                   push esi
// 007630e8  8b742410             mov esi, dword ptr [esp + 0x10]
// 007630ec  85c0                 test eax, eax
// 007630ee  7504                 jne 0x7630f4
// 007630f0  33c9                 xor ecx, ecx
// 007630f2  eb0c                 jmp 0x763100
// 007630f4  8bce                 mov ecx, esi
// 007630f6  e8b5f0ffff           call 0x7621b0
// 007630fb  2b4620               sub eax, dword ptr [esi + 0x20]
// 007630fe  8bc8                 mov ecx, eax
// 00763100  8b442414             mov eax, dword ptr [esp + 0x14]
// 00763104  40                   inc eax
// 00763105  c1e004               shl eax, 4
// 00763108  8bd0                 mov edx, eax
// 0076310a  8b4608               mov eax, dword ptr [esi + 8]
// 0076310d  57                   push edi
// 0076310e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00763112  2bc2                 sub eax, edx
// 00763114  89442408             mov dword ptr [esp + 8], eax
// 00763118  2b4620               sub eax, dword ptr [esi + 0x20]
// 0076311b  51                   push ecx
// 0076311c  50                   push eax
// 0076311d  8d442410             lea eax, [esp + 0x10]
// 00763121  50                   push eax
// 00763122  68c0307600           push 0x7630c0
// 00763127  56                   push esi
// 00763128  897c2420             mov dword ptr [esp + 0x20], edi
// 0076312c  e81fbb0100           call 0x77ec50
// 00763131  83c414               add esp, 0x14
// 00763134  83ffff               cmp edi, -1
// 00763137  5f                   pop edi
// 00763138  750e                 jne 0x763148
// 0076313a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0076313d  8b7608               mov esi, dword ptr [esi + 8]
// 00763140  3b7108               cmp esi, dword ptr [ecx + 8]
// 00763143  7203                 jb 0x763148
// 00763145  897108               mov dword ptr [ecx + 8], esi
// 00763148  5e                   pop esi
// 00763149  83c408               add esp, 8
// 0076314c  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
