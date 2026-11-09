// from server: 100% by auto
// roc 2010-06 004811e0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004811e0
//
// 004811e0  8b542404             mov edx, dword ptr [esp + 4]
// 004811e4  83ec10               sub esp, 0x10
// 004811e7  53                   push ebx
// 004811e8  55                   push ebp
// 004811e9  57                   push edi
// 004811ea  8bf9                 mov edi, ecx
// 004811ec  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004811ef  8b4104               mov eax, dword ptr [ecx + 4]
// 004811f2  80781500             cmp byte ptr [eax + 0x15], 0
// 004811f6  8bd9                 mov ebx, ecx
// 004811f8  751a                 jne 0x481214
// 004811fa  8b0a                 mov ecx, dword ptr [edx]
// 004811fc  8d642400             lea esp, [esp]
// 00481200  39480c               cmp dword ptr [eax + 0xc], ecx
// 00481203  7d05                 jge 0x48120a
// 00481205  8b4008               mov eax, dword ptr [eax + 8]
// 00481208  eb04                 jmp 0x48120e
// 0048120a  8bd8                 mov ebx, eax
// 0048120c  8b00                 mov eax, dword ptr [eax]
// 0048120e  80781500             cmp byte ptr [eax + 0x15], 0
// 00481212  74ec                 je 0x481200
// 00481214  8b4718               mov eax, dword ptr [edi + 0x18]
// 00481217  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0048121d  56                   push esi
// 0048121e  8b37                 mov esi, dword ptr [edi]
// 00481220  89442414             mov dword ptr [esp + 0x14], eax
// 00481224  85f6                 test esi, esi
// 00481226  7404                 je 0x48122c
// 00481228  3bf6                 cmp esi, esi
// 0048122a  740c                 je 0x481238
// 0048122c  ffd5                 call ebp
// 0048122e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00481232  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00481238  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 0048123c  7407                 je 0x481245
// 0048123e  8b0a                 mov ecx, dword ptr [edx]
// 00481240  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 00481243  7d26                 jge 0x48126b
// 00481245  8b12                 mov edx, dword ptr [edx]
// 00481247  8d442410             lea eax, [esp + 0x10]
// 0048124b  50                   push eax
// 0048124c  53                   push ebx
// 0048124d  56                   push esi
// 0048124e  8d4c2424             lea ecx, [esp + 0x24]
// 00481252  51                   push ecx
// 00481253  8bcf                 mov ecx, edi
// 00481255  89542420             mov dword ptr [esp + 0x20], edx
// 00481259  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00481261  e89afdffff           call 0x481000
// 00481266  8b30                 mov esi, dword ptr [eax]
// 00481268  8b5804               mov ebx, dword ptr [eax + 4]
// 0048126b  85f6                 test esi, esi
// 0048126d  7516                 jne 0x481285
// 0048126f  ffd5                 call ebp
// 00481271  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 00481274  5e                   pop esi
// 00481275  7502                 jne 0x481279
// 00481277  ffd5                 call ebp
// 00481279  5f                   pop edi
// 0048127a  5d                   pop ebp
// 0048127b  8d4310               lea eax, [ebx + 0x10]
// 0048127e  5b                   pop ebx
// 0048127f  83c410               add esp, 0x10
// 00481282  c20400               ret 4
// 00481285  8b36                 mov esi, dword ptr [esi]
// 00481287  ebe8                 jmp 0x481271
// standard library map_int<ptr> (function ??A?$map@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@@std@@QAEAAPAUT@@ABH@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
