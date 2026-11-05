// from server: 100% by auto
// roc 2010-06 006ebbc0  unit: RBX::VBadgeService::?$BoundYieldFuncDesc  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006ebbc0
//
// 006ebbc0  83ec08               sub esp, 8
// 006ebbc3  53                   push ebx
// 006ebbc4  55                   push ebp
// 006ebbc5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 006ebbcb  56                   push esi
// 006ebbcc  8bf1                 mov esi, ecx
// 006ebbce  8b4618               mov eax, dword ptr [esi + 0x18]
// 006ebbd1  8b18                 mov ebx, dword ptr [eax]
// 006ebbd3  8b06                 mov eax, dword ptr [esi]
// 006ebbd5  57                   push edi
// 006ebbd6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006ebbda  85ff                 test edi, edi
// 006ebbdc  7404                 je 0x6ebbe2
// 006ebbde  3bf8                 cmp edi, eax
// 006ebbe0  7406                 je 0x6ebbe8
// 006ebbe2  ffd5                 call ebp
// 006ebbe4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006ebbe8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006ebbec  7562                 jne 0x6ebc50
// 006ebbee  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006ebbf2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006ebbf5  8b06                 mov eax, dword ptr [esi]
// 006ebbf7  85c9                 test ecx, ecx
// 006ebbf9  7404                 je 0x6ebbff
// 006ebbfb  3bc8                 cmp ecx, eax
// 006ebbfd  7406                 je 0x6ebc05
// 006ebbff  ffd5                 call ebp
// 006ebc01  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006ebc05  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006ebc09  7545                 jne 0x6ebc50
// 006ebc0b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006ebc0e  8b5104               mov edx, dword ptr [ecx + 4]
// 006ebc11  52                   push edx
// 006ebc12  8bce                 mov ecx, esi
// 006ebc14  e857f0ffff           call 0x6eac70
// 006ebc19  8b4618               mov eax, dword ptr [esi + 0x18]
// 006ebc1c  894004               mov dword ptr [eax + 4], eax
// 006ebc1f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006ebc22  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006ebc29  8900                 mov dword ptr [eax], eax
// 006ebc2b  8b4618               mov eax, dword ptr [esi + 0x18]
// 006ebc2e  894008               mov dword ptr [eax + 8], eax
// 006ebc31  8b4618               mov eax, dword ptr [esi + 0x18]
// 006ebc34  8b16                 mov edx, dword ptr [esi]
// 006ebc36  8b08                 mov ecx, dword ptr [eax]
// 006ebc38  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ebc3c  5f                   pop edi
// 006ebc3d  5e                   pop esi
// 006ebc3e  5d                   pop ebp
// 006ebc3f  894804               mov dword ptr [eax + 4], ecx
// 006ebc42  8910                 mov dword ptr [eax], edx
// 006ebc44  5b                   pop ebx
// 006ebc45  83c408               add esp, 8
// 006ebc48  c21400               ret 0x14
// 006ebc4b  eb03                 jmp 0x6ebc50
// 006ebc4d  8d4900               lea ecx, [ecx]
// 006ebc50  85ff                 test edi, edi
// 006ebc52  7406                 je 0x6ebc5a
// 006ebc54  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006ebc58  7406                 je 0x6ebc60
// 006ebc5a  ffd5                 call ebp
// 006ebc5c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006ebc60  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006ebc64  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006ebc68  741d                 je 0x6ebc87
// 006ebc6a  8d4c2420             lea ecx, [esp + 0x20]
// 006ebc6e  e83d38f7ff           call 0x65f4b0
// 006ebc73  53                   push ebx
// 006ebc74  57                   push edi
// 006ebc75  8d442418             lea eax, [esp + 0x18]
// 006ebc79  50                   push eax
// 006ebc7a  8bce                 mov ecx, esi
// 006ebc7c  e80fedffff           call 0x6ea990
// 006ebc81  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006ebc85  ebc9                 jmp 0x6ebc50
// 006ebc87  8b36                 mov esi, dword ptr [esi]
// 006ebc89  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ebc8d  5f                   pop edi
// 006ebc8e  8930                 mov dword ptr [eax], esi
// 006ebc90  5e                   pop esi
// 006ebc91  5d                   pop ebp
// 006ebc92  895804               mov dword ptr [eax + 4], ebx
// 006ebc95  5b                   pop ebx
// 006ebc96  83c408               add esp, 8
// 006ebc99  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
