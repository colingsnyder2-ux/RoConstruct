// from server: 100% by auto
// roc 2009-12 0057ca60  unit: RBX::SceneUpdater  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057ca60
//
// 0057ca60  55                   push ebp
// 0057ca61  8bec                 mov ebp, esp
// 0057ca63  6aff                 push -1
// 0057ca65  68e0c29300           push 0x93c2e0
// 0057ca6a  64a100000000         mov eax, dword ptr fs:[0]
// 0057ca70  50                   push eax
// 0057ca71  64892500000000       mov dword ptr fs:[0], esp
// 0057ca78  83ec1c               sub esp, 0x1c
// 0057ca7b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0057ca7e  53                   push ebx
// 0057ca7f  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 0057ca85  56                   push esi
// 0057ca86  894dec               mov dword ptr [ebp - 0x14], ecx
// 0057ca89  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0057ca8c  57                   push edi
// 0057ca8d  8965f0               mov dword ptr [ebp - 0x10], esp
// 0057ca90  8945e0               mov dword ptr [ebp - 0x20], eax
// 0057ca93  894de4               mov dword ptr [ebp - 0x1c], ecx
// 0057ca96  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0057ca9d  8d4900               lea ecx, [ecx]
// 0057caa0  85c0                 test eax, eax
// 0057caa2  7405                 je 0x57caa9
// 0057caa4  3b4518               cmp eax, dword ptr [ebp + 0x18]
// 0057caa7  7405                 je 0x57caae
// 0057caa9  ffd3                 call ebx
// 0057caab  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0057caae  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0057cab1  3b551c               cmp edx, dword ptr [ebp + 0x1c]
// 0057cab4  0f84d4000000         je 0x57cb8e
// 0057caba  85c0                 test eax, eax
// 0057cabc  7509                 jne 0x57cac7
// 0057cabe  ffd3                 call ebx
// 0057cac0  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0057cac3  85c0                 test eax, eax
// 0057cac5  7404                 je 0x57cacb
// 0057cac7  8b00                 mov eax, dword ptr [eax]
// 0057cac9  eb02                 jmp 0x57cacd
// 0057cacb  33c0                 xor eax, eax
// 0057cacd  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0057cad0  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 0057cad3  7502                 jne 0x57cad7
// 0057cad5  ffd3                 call ebx
// 0057cad7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0057cada  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0057cadd  8b5104               mov edx, dword ptr [ecx + 4]
// 0057cae0  8d7904               lea edi, [ecx + 4]
// 0057cae3  83c008               add eax, 8
// 0057cae6  50                   push eax
// 0057cae7  52                   push edx
// 0057cae8  51                   push ecx
// 0057cae9  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0057caec  e83ff9ffff           call 0x57c430
// 0057caf1  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0057caf4  6a01                 push 1
// 0057caf6  8bf0                 mov esi, eax
// 0057caf8  e853eb1000           call 0x68b650
// 0057cafd  8937                 mov dword ptr [edi], esi
// 0057caff  8b4604               mov eax, dword ptr [esi + 4]
// 0057cb02  8930                 mov dword ptr [eax], esi
// 0057cb04  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0057cb07  85c0                 test eax, eax
// 0057cb09  7509                 jne 0x57cb14
// 0057cb0b  ffd3                 call ebx
// 0057cb0d  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0057cb10  85c0                 test eax, eax
// 0057cb12  7404                 je 0x57cb18
// 0057cb14  8b08                 mov ecx, dword ptr [eax]
// 0057cb16  eb02                 jmp 0x57cb1a
// 0057cb18  33c9                 xor ecx, ecx
// 0057cb1a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0057cb1d  3b5114               cmp edx, dword ptr [ecx + 0x14]
// 0057cb20  7505                 jne 0x57cb27
// 0057cb22  ffd3                 call ebx
// 0057cb24  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0057cb27  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0057cb2a  8b11                 mov edx, dword ptr [ecx]
// 0057cb2c  895514               mov dword ptr [ebp + 0x14], edx
// 0057cb2f  e96cffffff           jmp 0x57caa0
// standard library list<ptr> (function ??$_Insert@V?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@01@00Uforward_iterator_tag@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
