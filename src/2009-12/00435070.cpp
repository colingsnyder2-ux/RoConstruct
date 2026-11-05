// from server: 100% by auto
// roc 2009-12 00435070  unit: IIHAAH::?$CMap  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00435070
//
// 00435070  56                   push esi
// 00435071  57                   push edi
// 00435072  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00435076  8bf1                 mov esi, ecx
// 00435078  3bf7                 cmp esi, edi
// 0043507a  0f84d0000000         je 0x435150
// 00435080  53                   push ebx
// 00435081  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 00435084  55                   push ebp
// 00435085  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 00435088  8bc3                 mov eax, ebx
// 0043508a  2bc5                 sub eax, ebp
// 0043508c  c1f802               sar eax, 2
// 0043508f  85c0                 test eax, eax
// 00435091  750e                 jne 0x4350a1
// 00435093  e848feffff           call 0x434ee0
// 00435098  5d                   pop ebp
// 00435099  5b                   pop ebx
// 0043509a  5f                   pop edi
// 0043509b  8bc6                 mov eax, esi
// 0043509d  5e                   pop esi
// 0043509e  c20400               ret 4
// 004350a1  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004350a4  8b5610               mov edx, dword ptr [esi + 0x10]
// 004350a7  2bd1                 sub edx, ecx
// 004350a9  c1fa02               sar edx, 2
// 004350ac  3bc2                 cmp eax, edx
// 004350ae  7726                 ja 0x4350d6
// 004350b0  51                   push ecx
// 004350b1  53                   push ebx
// 004350b2  55                   push ebp
// 004350b3  e8f8eaffff           call 0x433bb0
// 004350b8  8b4710               mov eax, dword ptr [edi + 0x10]
// 004350bb  2b470c               sub eax, dword ptr [edi + 0xc]
// 004350be  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004350c1  83c40c               add esp, 0xc
// 004350c4  5d                   pop ebp
// 004350c5  c1f802               sar eax, 2
// 004350c8  5b                   pop ebx
// 004350c9  8d1481               lea edx, [ecx + eax*4]
// 004350cc  5f                   pop edi
// 004350cd  895610               mov dword ptr [esi + 0x10], edx
// 004350d0  8bc6                 mov eax, esi
// 004350d2  5e                   pop esi
// 004350d3  c20400               ret 4
// 004350d6  85c9                 test ecx, ecx
// 004350d8  7504                 jne 0x4350de
// 004350da  33db                 xor ebx, ebx
// 004350dc  eb08                 jmp 0x4350e6
// 004350de  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 004350e1  2bd9                 sub ebx, ecx
// 004350e3  c1fb02               sar ebx, 2
// 004350e6  3bc3                 cmp eax, ebx
// 004350e8  772c                 ja 0x435116
// 004350ea  8bc5                 mov eax, ebp
// 004350ec  51                   push ecx
// 004350ed  8d1c90               lea ebx, [eax + edx*4]
// 004350f0  53                   push ebx
// 004350f1  50                   push eax
// 004350f2  e8b9eaffff           call 0x433bb0
// 004350f7  8b4610               mov eax, dword ptr [esi + 0x10]
// 004350fa  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004350fd  83c40c               add esp, 0xc
// 00435100  50                   push eax
// 00435101  51                   push ecx
// 00435102  53                   push ebx
// 00435103  8bce                 mov ecx, esi
// 00435105  e8c69c0700           call 0x4aedd0
// 0043510a  5d                   pop ebp
// 0043510b  5b                   pop ebx
// 0043510c  894610               mov dword ptr [esi + 0x10], eax
// 0043510f  5f                   pop edi
// 00435110  8bc6                 mov eax, esi
// 00435112  5e                   pop esi
// 00435113  c20400               ret 4
// 00435116  85c9                 test ecx, ecx
// 00435118  7409                 je 0x435123
// 0043511a  51                   push ecx
// 0043511b  e83ae73b00           call 0x7f385a
// 00435120  83c404               add esp, 4
// 00435123  8b4710               mov eax, dword ptr [edi + 0x10]
// 00435126  2b470c               sub eax, dword ptr [edi + 0xc]
// 00435129  8bce                 mov ecx, esi
// 0043512b  c1f802               sar eax, 2
// 0043512e  50                   push eax
// 0043512f  e86cf50000           call 0x4446a0
// 00435134  84c0                 test al, al
// 00435136  7416                 je 0x43514e
// 00435138  8b560c               mov edx, dword ptr [esi + 0xc]
// 0043513b  8b4710               mov eax, dword ptr [edi + 0x10]
// 0043513e  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00435141  52                   push edx
// 00435142  50                   push eax
// 00435143  51                   push ecx
// 00435144  8bce                 mov ecx, esi
// 00435146  e8859c0700           call 0x4aedd0
// 0043514b  894610               mov dword ptr [esi + 0x10], eax
// 0043514e  5d                   pop ebp
// 0043514f  5b                   pop ebx
// 00435150  5f                   pop edi
// 00435151  8bc6                 mov eax, esi
// 00435153  5e                   pop esi
// 00435154  c20400               ret 4
// standard library vector<ptr> (function ??4?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
