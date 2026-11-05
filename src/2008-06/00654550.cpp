// from server: 100% by auto
// roc 2008-06 00654550  unit: RBX::ScoreHud  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00654550
//
// 00654550  83ec08               sub esp, 8
// 00654553  53                   push ebx
// 00654554  55                   push ebp
// 00654555  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0065455b  56                   push esi
// 0065455c  8bf1                 mov esi, ecx
// 0065455e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00654561  8b18                 mov ebx, dword ptr [eax]
// 00654563  8b06                 mov eax, dword ptr [esi]
// 00654565  57                   push edi
// 00654566  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0065456a  85ff                 test edi, edi
// 0065456c  7404                 je 0x654572
// 0065456e  3bf8                 cmp edi, eax
// 00654570  7406                 je 0x654578
// 00654572  ffd5                 call ebp
// 00654574  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00654578  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0065457c  7562                 jne 0x6545e0
// 0065457e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00654582  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00654585  8b06                 mov eax, dword ptr [esi]
// 00654587  85c9                 test ecx, ecx
// 00654589  7404                 je 0x65458f
// 0065458b  3bc8                 cmp ecx, eax
// 0065458d  7406                 je 0x654595
// 0065458f  ffd5                 call ebp
// 00654591  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00654595  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00654599  7545                 jne 0x6545e0
// 0065459b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0065459e  8b5104               mov edx, dword ptr [ecx + 4]
// 006545a1  52                   push edx
// 006545a2  8bce                 mov ecx, esi
// 006545a4  e8f7f4ffff           call 0x653aa0
// 006545a9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006545ac  894004               mov dword ptr [eax + 4], eax
// 006545af  8b4618               mov eax, dword ptr [esi + 0x18]
// 006545b2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006545b9  8900                 mov dword ptr [eax], eax
// 006545bb  8b4618               mov eax, dword ptr [esi + 0x18]
// 006545be  894008               mov dword ptr [eax + 8], eax
// 006545c1  8b4618               mov eax, dword ptr [esi + 0x18]
// 006545c4  8b16                 mov edx, dword ptr [esi]
// 006545c6  8b08                 mov ecx, dword ptr [eax]
// 006545c8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006545cc  5f                   pop edi
// 006545cd  5e                   pop esi
// 006545ce  5d                   pop ebp
// 006545cf  894804               mov dword ptr [eax + 4], ecx
// 006545d2  8910                 mov dword ptr [eax], edx
// 006545d4  5b                   pop ebx
// 006545d5  83c408               add esp, 8
// 006545d8  c21400               ret 0x14
// 006545db  eb03                 jmp 0x6545e0
// 006545dd  8d4900               lea ecx, [ecx]
// 006545e0  85ff                 test edi, edi
// 006545e2  7406                 je 0x6545ea
// 006545e4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006545e8  7406                 je 0x6545f0
// 006545ea  ffd5                 call ebp
// 006545ec  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006545f0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006545f4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006545f8  741d                 je 0x654617
// 006545fa  8d4c2420             lea ecx, [esp + 0x20]
// 006545fe  e87dd2f3ff           call 0x591880
// 00654603  53                   push ebx
// 00654604  57                   push edi
// 00654605  8d442418             lea eax, [esp + 0x18]
// 00654609  50                   push eax
// 0065460a  8bce                 mov ecx, esi
// 0065460c  e81ff1ffff           call 0x653730
// 00654611  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00654615  ebc9                 jmp 0x6545e0
// 00654617  8b36                 mov esi, dword ptr [esi]
// 00654619  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065461d  5f                   pop edi
// 0065461e  8930                 mov dword ptr [eax], esi
// 00654620  5e                   pop esi
// 00654621  5d                   pop ebp
// 00654622  895804               mov dword ptr [eax + 4], ebx
// 00654625  5b                   pop ebx
// 00654626  83c408               add esp, 8
// 00654629  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
