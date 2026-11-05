// from server: 100% by auto
// roc 2009-06 0053ae70  unit: RBX::VerticalCylinderBuilder  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0053ae70
//
// 0053ae70  56                   push esi
// 0053ae71  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0053ae75  57                   push edi
// 0053ae76  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0053ae7a  8bc6                 mov eax, esi
// 0053ae7c  8bcf                 mov ecx, edi
// 0053ae7e  85f6                 test esi, esi
// 0053ae80  7614                 jbe 0x53ae96
// 0053ae82  8b542414             mov edx, dword ptr [esp + 0x14]
// 0053ae86  53                   push ebx
// 0053ae87  668b1a               mov bx, word ptr [edx]
// 0053ae8a  668919               mov word ptr [ecx], bx
// 0053ae8d  48                   dec eax
// 0053ae8e  83c102               add ecx, 2
// 0053ae91  85c0                 test eax, eax
// 0053ae93  77f2                 ja 0x53ae87
// 0053ae95  5b                   pop ebx
// 0053ae96  8d0477               lea eax, [edi + esi*2]
// 0053ae99  5f                   pop edi
// 0053ae9a  5e                   pop esi
// 0053ae9b  c20c00               ret 0xc
// standard library vector<short> (function ?_Ufill@?$vector@FV?$allocator@F@std@@@std@@IAEPAFPAFIABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
