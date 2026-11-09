// from server: 100% by auto
// roc 2009-06 00496980  unit: Ogre::TwoDManager  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00496980
//
// 00496980  55                   push ebp
// 00496981  8bec                 mov ebp, esp
// 00496983  6aff                 push -1
// 00496985  6840668500           push 0x856640
// 0049698a  64a100000000         mov eax, dword ptr fs:[0]
// 00496990  50                   push eax
// 00496991  64892500000000       mov dword ptr fs:[0], esp
// 00496998  83ec1c               sub esp, 0x1c
// 0049699b  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0049699e  53                   push ebx
// 0049699f  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 004969a5  56                   push esi
// 004969a6  894dec               mov dword ptr [ebp - 0x14], ecx
// 004969a9  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004969ac  57                   push edi
// 004969ad  8965f0               mov dword ptr [ebp - 0x10], esp
// 004969b0  8945e0               mov dword ptr [ebp - 0x20], eax
// 004969b3  894de4               mov dword ptr [ebp - 0x1c], ecx
// 004969b6  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004969bd  8d4900               lea ecx, [ecx]
// 004969c0  85c0                 test eax, eax
// 004969c2  7405                 je 0x4969c9
// 004969c4  3b4518               cmp eax, dword ptr [ebp + 0x18]
// 004969c7  7405                 je 0x4969ce
// 004969c9  ffd3                 call ebx
// 004969cb  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004969ce  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004969d1  3b551c               cmp edx, dword ptr [ebp + 0x1c]
// 004969d4  0f84d4000000         je 0x496aae
// 004969da  85c0                 test eax, eax
// 004969dc  7509                 jne 0x4969e7
// 004969de  ffd3                 call ebx
// 004969e0  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004969e3  85c0                 test eax, eax
// 004969e5  7404                 je 0x4969eb
// 004969e7  8b00                 mov eax, dword ptr [eax]
// 004969e9  eb02                 jmp 0x4969ed
// 004969eb  33c0                 xor eax, eax
// 004969ed  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004969f0  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 004969f3  7502                 jne 0x4969f7
// 004969f5  ffd3                 call ebx
// 004969f7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004969fa  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004969fd  8b5104               mov edx, dword ptr [ecx + 4]
// 00496a00  8d7904               lea edi, [ecx + 4]
// 00496a03  83c008               add eax, 8
// 00496a06  50                   push eax
// 00496a07  52                   push edx
// 00496a08  51                   push ecx
// 00496a09  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00496a0c  e87fb21d00           call 0x671c90
// 00496a11  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00496a14  6a01                 push 1
// 00496a16  8bf0                 mov esi, eax
// 00496a18  e8b3b21d00           call 0x671cd0
// 00496a1d  8937                 mov dword ptr [edi], esi
// 00496a1f  8b4604               mov eax, dword ptr [esi + 4]
// 00496a22  8930                 mov dword ptr [eax], esi
// 00496a24  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00496a27  85c0                 test eax, eax
// 00496a29  7509                 jne 0x496a34
// 00496a2b  ffd3                 call ebx
// 00496a2d  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00496a30  85c0                 test eax, eax
// 00496a32  7404                 je 0x496a38
// 00496a34  8b08                 mov ecx, dword ptr [eax]
// 00496a36  eb02                 jmp 0x496a3a
// 00496a38  33c9                 xor ecx, ecx
// 00496a3a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00496a3d  3b5114               cmp edx, dword ptr [ecx + 0x14]
// 00496a40  7505                 jne 0x496a47
// 00496a42  ffd3                 call ebx
// 00496a44  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00496a47  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00496a4a  8b11                 mov edx, dword ptr [ecx]
// 00496a4c  895514               mov dword ptr [ebp + 0x14], edx
// 00496a4f  e96cffffff           jmp 0x4969c0
// standard library list<ptr> (function ??$_Insert@V?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@01@00Uforward_iterator_tag@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
