// from server: 100% by auto
// roc 2010-06 004eea50  unit: RBX::Network::Replicator::NewInstanceItem  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004eea50
//
// 004eea50  83ec08               sub esp, 8
// 004eea53  53                   push ebx
// 004eea54  55                   push ebp
// 004eea55  56                   push esi
// 004eea56  8bf1                 mov esi, ecx
// 004eea58  8b4610               mov eax, dword ptr [esi + 0x10]
// 004eea5b  57                   push edi
// 004eea5c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004eea5f  8bc8                 mov ecx, eax
// 004eea61  2bcf                 sub ecx, edi
// 004eea63  f7c1fcffffff         test ecx, 0xfffffffc
// 004eea69  7504                 jne 0x4eea6f
// 004eea6b  33db                 xor ebx, ebx
// 004eea6d  eb27                 jmp 0x4eea96
// 004eea6f  3bf8                 cmp edi, eax
// 004eea71  7606                 jbe 0x4eea79
// 004eea73  ff150ca99e00         call dword ptr [0x9ea90c]
// 004eea79  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004eea7d  8b06                 mov eax, dword ptr [esi]
// 004eea7f  85c9                 test ecx, ecx
// 004eea81  7404                 je 0x4eea87
// 004eea83  3bc8                 cmp ecx, eax
// 004eea85  7406                 je 0x4eea8d
// 004eea87  ff150ca99e00         call dword ptr [0x9ea90c]
// 004eea8d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004eea91  2bdf                 sub ebx, edi
// 004eea93  c1fb02               sar ebx, 2
// 004eea96  8b542428             mov edx, dword ptr [esp + 0x28]
// 004eea9a  8b442424             mov eax, dword ptr [esp + 0x24]
// 004eea9e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004eeaa2  52                   push edx
// 004eeaa3  6a01                 push 1
// 004eeaa5  50                   push eax
// 004eeaa6  51                   push ecx
// 004eeaa7  8bce                 mov ecx, esi
// 004eeaa9  e872f5ffff           call 0x4ee020
// 004eeaae  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004eeab1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004eeab4  7606                 jbe 0x4eeabc
// 004eeab6  ff150ca99e00         call dword ptr [0x9ea90c]
// 004eeabc  8b36                 mov esi, dword ptr [esi]
// 004eeabe  8bee                 mov ebp, esi
// 004eeac0  897c2414             mov dword ptr [esp + 0x14], edi
// 004eeac4  85f6                 test esi, esi
// 004eeac6  7518                 jne 0x4eeae0
// 004eeac8  ff150ca99e00         call dword ptr [0x9ea90c]
// 004eeace  33c0                 xor eax, eax
// 004eead0  8d3c9f               lea edi, [edi + ebx*4]
// 004eead3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004eead6  7713                 ja 0x4eeaeb
// 004eead8  85f6                 test esi, esi
// 004eeada  7408                 je 0x4eeae4
// 004eeadc  8b36                 mov esi, dword ptr [esi]
// 004eeade  eb06                 jmp 0x4eeae6
// 004eeae0  8b06                 mov eax, dword ptr [esi]
// 004eeae2  ebec                 jmp 0x4eead0
// 004eeae4  33f6                 xor esi, esi
// 004eeae6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004eeae9  7306                 jae 0x4eeaf1
// 004eeaeb  ff150ca99e00         call dword ptr [0x9ea90c]
// 004eeaf1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004eeaf5  897804               mov dword ptr [eax + 4], edi
// 004eeaf8  5f                   pop edi
// 004eeaf9  5e                   pop esi
// 004eeafa  8928                 mov dword ptr [eax], ebp
// 004eeafc  5d                   pop ebp
// 004eeafd  5b                   pop ebx
// 004eeafe  83c408               add esp, 8
// 004eeb01  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
