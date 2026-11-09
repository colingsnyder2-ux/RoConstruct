// from server: 100% by auto
// roc 2010-06 0076f6b0  unit: RBX::ScoreHud  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076f6b0
//
// 0076f6b0  83ec08               sub esp, 8
// 0076f6b3  53                   push ebx
// 0076f6b4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0076f6b8  56                   push esi
// 0076f6b9  8bf1                 mov esi, ecx
// 0076f6bb  8b4610               mov eax, dword ptr [esi + 0x10]
// 0076f6be  57                   push edi
// 0076f6bf  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0076f6c2  8bc8                 mov ecx, eax
// 0076f6c4  2bcf                 sub ecx, edi
// 0076f6c6  c1f903               sar ecx, 3
// 0076f6c9  3bcb                 cmp ecx, ebx
// 0076f6cb  7705                 ja 0x76f6d2
// 0076f6cd  e81e27d1ff           call 0x481df0
// 0076f6d2  3bf8                 cmp edi, eax
// 0076f6d4  7606                 jbe 0x76f6dc
// 0076f6d6  ff150ca99e00         call dword ptr [0x9ea90c]
// 0076f6dc  8b36                 mov esi, dword ptr [esi]
// 0076f6de  55                   push ebp
// 0076f6df  8bee                 mov ebp, esi
// 0076f6e1  897c2414             mov dword ptr [esp + 0x14], edi
// 0076f6e5  85f6                 test esi, esi
// 0076f6e7  7518                 jne 0x76f701
// 0076f6e9  ff150ca99e00         call dword ptr [0x9ea90c]
// 0076f6ef  33c0                 xor eax, eax
// 0076f6f1  8d3cdf               lea edi, [edi + ebx*8]
// 0076f6f4  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0076f6f7  7713                 ja 0x76f70c
// 0076f6f9  85f6                 test esi, esi
// 0076f6fb  7408                 je 0x76f705
// 0076f6fd  8b36                 mov esi, dword ptr [esi]
// 0076f6ff  eb06                 jmp 0x76f707
// 0076f701  8b06                 mov eax, dword ptr [esi]
// 0076f703  ebec                 jmp 0x76f6f1
// 0076f705  33f6                 xor esi, esi
// 0076f707  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0076f70a  730a                 jae 0x76f716
// 0076f70c  8b350ca99e00         mov esi, dword ptr [0x9ea90c]
// 0076f712  ffd6                 call esi
// 0076f714  eb06                 jmp 0x76f71c
// 0076f716  8b350ca99e00         mov esi, dword ptr [0x9ea90c]
// 0076f71c  85ed                 test ebp, ebp
// 0076f71e  7517                 jne 0x76f737
// 0076f720  ffd6                 call esi
// 0076f722  33c0                 xor eax, eax
// 0076f724  5d                   pop ebp
// 0076f725  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0076f728  7202                 jb 0x76f72c
// 0076f72a  ffd6                 call esi
// 0076f72c  8bc7                 mov eax, edi
// 0076f72e  5f                   pop edi
// 0076f72f  5e                   pop esi
// 0076f730  5b                   pop ebx
// 0076f731  83c408               add esp, 8
// 0076f734  c20400               ret 4
// 0076f737  8b4500               mov eax, dword ptr [ebp]
// 0076f73a  ebe8                 jmp 0x76f724
// standard library vector<double> (function ?at@?$vector@NV?$allocator@N@std@@@std@@QBEABNI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
