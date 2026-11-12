// from server: 93% by EspClaude
// from server: 51% by colin
// roc 2007-08 00489940  unit: RBX::Network::VPlayer::?$Notifier  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00489940
//
// 00489940  55                   push ebp
// 00489941  8bec                 mov ebp, esp
// 00489943  6aff                 push -1
// 00489945  6800707400           push 0x747000
// 0048994a  64a100000000         mov eax, dword ptr fs:[0]
// 00489950  50                   push eax
// 00489951  83ec08               sub esp, 8
// 00489954  53                   push ebx
// 00489955  56                   push esi
// 00489956  57                   push edi
// 00489957  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048995c  33c5                 xor eax, ebp
// 0048995e  50                   push eax
// 0048995f  8d45f4               lea eax, [ebp - 0xc]
// 00489962  64a300000000         mov dword ptr fs:[0], eax
// 00489968  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048996b  8bf1                 mov esi, ecx
// 0048996d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00489970  e8ebe7ffff           call 0x488160
// 00489975  894604               mov dword ptr [esi + 4], eax
// 00489978  c6400e01             mov byte ptr [eax + 0xe], 1
// 0048997c  8b4604               mov eax, dword ptr [esi + 4]
// 0048997f  894004               mov dword ptr [eax + 4], eax
// 00489982  8b4604               mov eax, dword ptr [esi + 4]
// 00489985  8900                 mov dword ptr [eax], eax
// 00489987  8b4604               mov eax, dword ptr [esi + 4]
// 0048998a  894008               mov dword ptr [eax + 8], eax
// 0048998d  8b4508               mov eax, dword ptr [ebp + 8]
// 00489990  50                   push eax
// 00489991  8bce                 mov ecx, esi
// 00489993  c7460800000000       mov dword ptr [esi + 8], 0
// 0048999a  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004899a1  e8dafcffff           call 0x489680
// 004899a6  8bc6                 mov eax, esi
// 004899a8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004899ab  64890d00000000       mov dword ptr fs:[0], ecx
// 004899b2  59                   pop ecx
// 004899b3  5f                   pop edi
// 004899b4  5e                   pop esi
// 004899b5  5b                   pop ebx
// 004899b6  8be5                 mov esp, ebp
// 004899b8  5d                   pop ebp
// 004899b9  c20400               ret 4

#include <set>

// VS2005 _Tree copy constructor: _Init() (head node Isnil at +0xe => 1-byte
// value_type), then _TRY_BEGIN _Copy(_Right) _CATCH_ALL _Tidy().
template class std::_Tree<std::_Tset_traits<char, std::less<char>, std::allocator<char>, false> >;
