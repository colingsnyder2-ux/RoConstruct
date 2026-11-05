// from server: 100% by auto
// roc 2010-06 009557b0  unit: seg_00950000  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009557b0
//
// 009557b0  8b542404             mov edx, dword ptr [esp + 4]
// 009557b4  56                   push esi
// 009557b5  8bf1                 mov esi, ecx
// 009557b7  81faffffff7f         cmp edx, 0x7fffffff
// 009557bd  7605                 jbe 0x9557c4
// 009557bf  e82ce6acff           call 0x423df0
// 009557c4  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 009557c7  85c9                 test ecx, ecx
// 009557c9  7504                 jne 0x9557cf
// 009557cb  33c0                 xor eax, eax
// 009557cd  eb07                 jmp 0x9557d6
// 009557cf  8b4614               mov eax, dword ptr [esi + 0x14]
// 009557d2  2bc1                 sub eax, ecx
// 009557d4  d1f8                 sar eax, 1
// 009557d6  3bc2                 cmp eax, edx
// 009557d8  736f                 jae 0x955849
// 009557da  53                   push ebx
// 009557db  57                   push edi
// 009557dc  6a00                 push 0
// 009557de  52                   push edx
// 009557df  e88cd5bcff           call 0x522d70
// 009557e4  8b7e10               mov edi, dword ptr [esi + 0x10]
// 009557e7  83c408               add esp, 8
// 009557ea  8bd8                 mov ebx, eax
// 009557ec  397e0c               cmp dword ptr [esi + 0xc], edi
// 009557ef  7606                 jbe 0x9557f7
// 009557f1  ff150ca99e00         call dword ptr [0x9ea90c]
// 009557f7  55                   push ebp
// 009557f8  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 009557fb  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 009557fe  7606                 jbe 0x955806
// 00955800  ff150ca99e00         call dword ptr [0x9ea90c]
// 00955806  2bfd                 sub edi, ebp
// 00955808  d1ff                 sar edi, 1
// 0095580a  7410                 je 0x95581c
// 0095580c  8d043f               lea eax, [edi + edi]
// 0095580f  50                   push eax
// 00955810  55                   push ebp
// 00955811  50                   push eax
// 00955812  53                   push ebx
// 00955813  ff1580a89e00         call dword ptr [0x9ea880]
// 00955819  83c410               add esp, 0x10
// 0095581c  8b460c               mov eax, dword ptr [esi + 0xc]
// 0095581f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00955822  2bf8                 sub edi, eax
// 00955824  d1ff                 sar edi, 1
// 00955826  5d                   pop ebp
// 00955827  85c0                 test eax, eax
// 00955829  7409                 je 0x955834
// 0095582b  50                   push eax
// 0095582c  e86921e5ff           call 0x7a799a
// 00955831  83c404               add esp, 4
// 00955834  8b442410             mov eax, dword ptr [esp + 0x10]
// 00955838  8d147b               lea edx, [ebx + edi*2]
// 0095583b  8d0c43               lea ecx, [ebx + eax*2]
// 0095583e  5f                   pop edi
// 0095583f  895e0c               mov dword ptr [esi + 0xc], ebx
// 00955842  894e14               mov dword ptr [esi + 0x14], ecx
// 00955845  895610               mov dword ptr [esi + 0x10], edx
// 00955848  5b                   pop ebx
// 00955849  5e                   pop esi
// 0095584a  c20400               ret 4
// standard library vector<short> (function ?reserve@?$vector@FV?$allocator@F@std@@@std@@QAEXI@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
