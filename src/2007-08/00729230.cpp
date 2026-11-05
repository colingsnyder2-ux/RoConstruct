// from server: 100% by auto
// roc 2007-08 00729230  unit: boost::signals::detail::Ubasic_connection::?$sp_counted_impl_p  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00729230
//
// 00729230  55                   push ebp
// 00729231  8bec                 mov ebp, esp
// 00729233  6aff                 push -1
// 00729235  6870bb7600           push 0x76bb70
// 0072923a  64a100000000         mov eax, dword ptr fs:[0]
// 00729240  50                   push eax
// 00729241  83ec10               sub esp, 0x10
// 00729244  53                   push ebx
// 00729245  56                   push esi
// 00729246  57                   push edi
// 00729247  a188518b00           mov eax, dword ptr [0x8b5188]
// 0072924c  33c5                 xor eax, ebp
// 0072924e  50                   push eax
// 0072924f  8d45f4               lea eax, [ebp - 0xc]
// 00729252  64a300000000         mov dword ptr fs:[0], eax
// 00729258  8965f0               mov dword ptr [ebp - 0x10], esp
// 0072925b  894dec               mov dword ptr [ebp - 0x14], ecx
// 0072925e  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00729261  8b7d14               mov edi, dword ptr [ebp + 0x14]
// 00729264  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00729267  8975e4               mov dword ptr [ebp - 0x1c], esi
// 0072926a  897de8               mov dword ptr [ebp - 0x18], edi
// 0072926d  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00729274  85f6                 test esi, esi
// 00729276  7405                 je 0x72927d
// 00729278  3b7518               cmp esi, dword ptr [ebp + 0x18]
// 0072927b  7406                 je 0x729283
// 0072927d  ff15d8e67700         call dword ptr [0x77e6d8]
// 00729283  3b7d1c               cmp edi, dword ptr [ebp + 0x1c]
// 00729286  0f84ac000000         je 0x729338
// 0072928c  85f6                 test esi, esi
// 0072928e  7506                 jne 0x729296
// 00729290  ff15d8e67700         call dword ptr [0x77e6d8]
// 00729296  3b7e04               cmp edi, dword ptr [esi + 4]
// 00729299  7506                 jne 0x7292a1
// 0072929b  ff15d8e67700         call dword ptr [0x77e6d8]
// 007292a1  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 007292a4  8d4708               lea eax, [edi + 8]
// 007292a7  50                   push eax
// 007292a8  8b4304               mov eax, dword ptr [ebx + 4]
// 007292ab  50                   push eax
// 007292ac  53                   push ebx
// 007292ad  e8defcffff           call 0x728f90
// 007292b2  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 007292b5  6a01                 push 1
// 007292b7  8bf0                 mov esi, eax
// 007292b9  e8a2f9ffff           call 0x728c60
// 007292be  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007292c1  897304               mov dword ptr [ebx + 4], esi
// 007292c4  8b4e04               mov ecx, dword ptr [esi + 4]
// 007292c7  8931                 mov dword ptr [ecx], esi
// 007292c9  3b7a04               cmp edi, dword ptr [edx + 4]
// 007292cc  7506                 jne 0x7292d4
// 007292ce  ff15d8e67700         call dword ptr [0x77e6d8]
// 007292d4  8b3f                 mov edi, dword ptr [edi]
// 007292d6  8b7510               mov esi, dword ptr [ebp + 0x10]
// 007292d9  897d14               mov dword ptr [ebp + 0x14], edi
// 007292dc  eb96                 jmp 0x729274
// standard library list<ptr> (function ??$_Insert@V?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Iterator@$00@01@V?$_Const_iterator@$00@01@1Uforward_iterator_tag@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
