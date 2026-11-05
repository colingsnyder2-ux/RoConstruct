// from server: 100% by auto
// roc 2010-06 00796030  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00796030
//
// 00796030  83ec08               sub esp, 8
// 00796033  55                   push ebp
// 00796034  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0079603a  56                   push esi
// 0079603b  8bf1                 mov esi, ecx
// 0079603d  57                   push edi
// 0079603e  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00796041  397e0c               cmp dword ptr [esi + 0xc], edi
// 00796044  7602                 jbe 0x796048
// 00796046  ffd5                 call ebp
// 00796048  8b36                 mov esi, dword ptr [esi]
// 0079604a  53                   push ebx
// 0079604b  8bde                 mov ebx, esi
// 0079604d  897c2414             mov dword ptr [esp + 0x14], edi
// 00796051  85f6                 test esi, esi
// 00796053  7514                 jne 0x796069
// 00796055  ffd5                 call ebp
// 00796057  33c0                 xor eax, eax
// 00796059  8d4ffc               lea ecx, [edi - 4]
// 0079605c  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 0079605f  7713                 ja 0x796074
// 00796061  85f6                 test esi, esi
// 00796063  7408                 je 0x79606d
// 00796065  8b36                 mov esi, dword ptr [esi]
// 00796067  eb06                 jmp 0x79606f
// 00796069  8b06                 mov eax, dword ptr [esi]
// 0079606b  ebec                 jmp 0x796059
// 0079606d  33f6                 xor esi, esi
// 0079606f  3b4e0c               cmp ecx, dword ptr [esi + 0xc]
// 00796072  7302                 jae 0x796076
// 00796074  ffd5                 call ebp
// 00796076  8d77fc               lea esi, [edi - 4]
// 00796079  85db                 test ebx, ebx
// 0079607b  7515                 jne 0x796092
// 0079607d  ffd5                 call ebp
// 0079607f  33c0                 xor eax, eax
// 00796081  5b                   pop ebx
// 00796082  3b7010               cmp esi, dword ptr [eax + 0x10]
// 00796085  7202                 jb 0x796089
// 00796087  ffd5                 call ebp
// 00796089  5f                   pop edi
// 0079608a  8bc6                 mov eax, esi
// 0079608c  5e                   pop esi
// 0079608d  5d                   pop ebp
// 0079608e  83c408               add esp, 8
// 00796091  c3                   ret 
// 00796092  8b03                 mov eax, dword ptr [ebx]
// 00796094  ebeb                 jmp 0x796081
// standard library vector<ptr> (function ?back@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAPAUT@@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
