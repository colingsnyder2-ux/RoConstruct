// from server: 100% by auto
// roc 2010-06 00641430  unit: RBX::VInstance::?$NonFactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00641430
//
// 00641430  83ec08               sub esp, 8
// 00641433  53                   push ebx
// 00641434  55                   push ebp
// 00641435  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0064143b  56                   push esi
// 0064143c  8bf1                 mov esi, ecx
// 0064143e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00641441  8b18                 mov ebx, dword ptr [eax]
// 00641443  8b06                 mov eax, dword ptr [esi]
// 00641445  57                   push edi
// 00641446  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0064144a  85ff                 test edi, edi
// 0064144c  7404                 je 0x641452
// 0064144e  3bf8                 cmp edi, eax
// 00641450  7406                 je 0x641458
// 00641452  ffd5                 call ebp
// 00641454  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00641458  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0064145c  7562                 jne 0x6414c0
// 0064145e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00641462  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00641465  8b06                 mov eax, dword ptr [esi]
// 00641467  85c9                 test ecx, ecx
// 00641469  7404                 je 0x64146f
// 0064146b  3bc8                 cmp ecx, eax
// 0064146d  7406                 je 0x641475
// 0064146f  ffd5                 call ebp
// 00641471  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00641475  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00641479  7545                 jne 0x6414c0
// 0064147b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0064147e  8b5104               mov edx, dword ptr [ecx + 4]
// 00641481  52                   push edx
// 00641482  8bce                 mov ecx, esi
// 00641484  e837f8ffff           call 0x640cc0
// 00641489  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064148c  894004               mov dword ptr [eax + 4], eax
// 0064148f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00641492  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00641499  8900                 mov dword ptr [eax], eax
// 0064149b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064149e  894008               mov dword ptr [eax + 8], eax
// 006414a1  8b4618               mov eax, dword ptr [esi + 0x18]
// 006414a4  8b16                 mov edx, dword ptr [esi]
// 006414a6  8b08                 mov ecx, dword ptr [eax]
// 006414a8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006414ac  5f                   pop edi
// 006414ad  5e                   pop esi
// 006414ae  5d                   pop ebp
// 006414af  894804               mov dword ptr [eax + 4], ecx
// 006414b2  8910                 mov dword ptr [eax], edx
// 006414b4  5b                   pop ebx
// 006414b5  83c408               add esp, 8
// 006414b8  c21400               ret 0x14
// 006414bb  eb03                 jmp 0x6414c0
// 006414bd  8d4900               lea ecx, [ecx]
// 006414c0  85ff                 test edi, edi
// 006414c2  7406                 je 0x6414ca
// 006414c4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006414c8  7406                 je 0x6414d0
// 006414ca  ffd5                 call ebp
// 006414cc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006414d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006414d4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006414d8  741d                 je 0x6414f7
// 006414da  8d4c2420             lea ecx, [esp + 0x20]
// 006414de  e81d45eaff           call 0x4e5a00
// 006414e3  53                   push ebx
// 006414e4  57                   push edi
// 006414e5  8d442418             lea eax, [esp + 0x18]
// 006414e9  50                   push eax
// 006414ea  8bce                 mov ecx, esi
// 006414ec  e85ff2ffff           call 0x640750
// 006414f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006414f5  ebc9                 jmp 0x6414c0
// 006414f7  8b36                 mov esi, dword ptr [esi]
// 006414f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006414fd  5f                   pop edi
// 006414fe  8930                 mov dword ptr [eax], esi
// 00641500  5e                   pop esi
// 00641501  5d                   pop ebp
// 00641502  895804               mov dword ptr [eax + 4], ebx
// 00641505  5b                   pop ebx
// 00641506  83c408               add esp, 8
// 00641509  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
