// from server: 100% by auto
// roc 2008-06 004c7700  unit: RBX::VInstance::?$Association::Item  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c7700
//
// 004c7700  56                   push esi
// 004c7701  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c7705  57                   push edi
// 004c7706  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004c770a  8bc6                 mov eax, esi
// 004c770c  8bcf                 mov ecx, edi
// 004c770e  85f6                 test esi, esi
// 004c7710  7610                 jbe 0x4c7722
// 004c7712  8b542414             mov edx, dword ptr [esp + 0x14]
// 004c7716  d902                 fld dword ptr [edx]
// 004c7718  48                   dec eax
// 004c7719  d919                 fstp dword ptr [ecx]
// 004c771b  83c104               add ecx, 4
// 004c771e  85c0                 test eax, eax
// 004c7720  77f4                 ja 0x4c7716
// 004c7722  8d04b7               lea eax, [edi + esi*4]
// 004c7725  5f                   pop edi
// 004c7726  5e                   pop esi
// 004c7727  c20c00               ret 0xc
// standard library vector<float> (function ?_Ufill@?$vector@MV?$allocator@M@std@@@std@@IAEPAMPAMIABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
