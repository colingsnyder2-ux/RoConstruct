// from server: 100% by auto
// roc 2009-12 007c3130  unit: RBX::Network::$$A6AXABVChatMessage::?$signal::slot  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c3130
//
// 007c3130  83ec08               sub esp, 8
// 007c3133  53                   push ebx
// 007c3134  55                   push ebp
// 007c3135  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007c313b  56                   push esi
// 007c313c  8bf1                 mov esi, ecx
// 007c313e  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c3141  8b18                 mov ebx, dword ptr [eax]
// 007c3143  8b06                 mov eax, dword ptr [esi]
// 007c3145  57                   push edi
// 007c3146  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c314a  85ff                 test edi, edi
// 007c314c  7404                 je 0x7c3152
// 007c314e  3bf8                 cmp edi, eax
// 007c3150  7406                 je 0x7c3158
// 007c3152  ffd5                 call ebp
// 007c3154  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c3158  395c2424             cmp dword ptr [esp + 0x24], ebx
// 007c315c  7562                 jne 0x7c31c0
// 007c315e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c3162  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007c3165  8b06                 mov eax, dword ptr [esi]
// 007c3167  85c9                 test ecx, ecx
// 007c3169  7404                 je 0x7c316f
// 007c316b  3bc8                 cmp ecx, eax
// 007c316d  7406                 je 0x7c3175
// 007c316f  ffd5                 call ebp
// 007c3171  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c3175  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007c3179  7545                 jne 0x7c31c0
// 007c317b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c317e  8b5104               mov edx, dword ptr [ecx + 4]
// 007c3181  52                   push edx
// 007c3182  8bce                 mov ecx, esi
// 007c3184  e817f9ffff           call 0x7c2aa0
// 007c3189  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c318c  894004               mov dword ptr [eax + 4], eax
// 007c318f  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c3192  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007c3199  8900                 mov dword ptr [eax], eax
// 007c319b  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c319e  894008               mov dword ptr [eax + 8], eax
// 007c31a1  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c31a4  8b16                 mov edx, dword ptr [esi]
// 007c31a6  8b08                 mov ecx, dword ptr [eax]
// 007c31a8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c31ac  5f                   pop edi
// 007c31ad  5e                   pop esi
// 007c31ae  5d                   pop ebp
// 007c31af  894804               mov dword ptr [eax + 4], ecx
// 007c31b2  8910                 mov dword ptr [eax], edx
// 007c31b4  5b                   pop ebx
// 007c31b5  83c408               add esp, 8
// 007c31b8  c21400               ret 0x14
// 007c31bb  eb03                 jmp 0x7c31c0
// 007c31bd  8d4900               lea ecx, [ecx]
// 007c31c0  85ff                 test edi, edi
// 007c31c2  7406                 je 0x7c31ca
// 007c31c4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 007c31c8  7406                 je 0x7c31d0
// 007c31ca  ffd5                 call ebp
// 007c31cc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c31d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007c31d4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 007c31d8  741d                 je 0x7c31f7
// 007c31da  8d4c2420             lea ecx, [esp + 0x20]
// 007c31de  e88decffff           call 0x7c1e70
// 007c31e3  53                   push ebx
// 007c31e4  57                   push edi
// 007c31e5  8d442418             lea eax, [esp + 0x18]
// 007c31e9  50                   push eax
// 007c31ea  8bce                 mov ecx, esi
// 007c31ec  e87ffbffff           call 0x7c2d70
// 007c31f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c31f5  ebc9                 jmp 0x7c31c0
// 007c31f7  8b36                 mov esi, dword ptr [esi]
// 007c31f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c31fd  5f                   pop edi
// 007c31fe  8930                 mov dword ptr [eax], esi
// 007c3200  5e                   pop esi
// 007c3201  5d                   pop ebp
// 007c3202  895804               mov dword ptr [eax + 4], ebx
// 007c3205  5b                   pop ebx
// 007c3206  83c408               add esp, 8
// 007c3209  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
