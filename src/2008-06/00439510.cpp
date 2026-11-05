// from server: 100% by auto
// roc 2008-06 00439510  unit: CSelectionPropGrid  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00439510
//
// 00439510  56                   push esi
// 00439511  57                   push edi
// 00439512  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00439516  8bf1                 mov esi, ecx
// 00439518  3bf7                 cmp esi, edi
// 0043951a  0f84d0000000         je 0x4395f0
// 00439520  53                   push ebx
// 00439521  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 00439524  55                   push ebp
// 00439525  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 00439528  8bc3                 mov eax, ebx
// 0043952a  2bc5                 sub eax, ebp
// 0043952c  c1f802               sar eax, 2
// 0043952f  85c0                 test eax, eax
// 00439531  750e                 jne 0x439541
// 00439533  e8e8fdffff           call 0x439320
// 00439538  5d                   pop ebp
// 00439539  5b                   pop ebx
// 0043953a  5f                   pop edi
// 0043953b  8bc6                 mov eax, esi
// 0043953d  5e                   pop esi
// 0043953e  c20400               ret 4
// 00439541  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00439544  8b5610               mov edx, dword ptr [esi + 0x10]
// 00439547  2bd1                 sub edx, ecx
// 00439549  c1fa02               sar edx, 2
// 0043954c  3bc2                 cmp eax, edx
// 0043954e  7726                 ja 0x439576
// 00439550  51                   push ecx
// 00439551  53                   push ebx
// 00439552  55                   push ebp
// 00439553  e898f4ffff           call 0x4389f0
// 00439558  8b4710               mov eax, dword ptr [edi + 0x10]
// 0043955b  2b470c               sub eax, dword ptr [edi + 0xc]
// 0043955e  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00439561  83c40c               add esp, 0xc
// 00439564  5d                   pop ebp
// 00439565  c1f802               sar eax, 2
// 00439568  5b                   pop ebx
// 00439569  8d1481               lea edx, [ecx + eax*4]
// 0043956c  5f                   pop edi
// 0043956d  895610               mov dword ptr [esi + 0x10], edx
// 00439570  8bc6                 mov eax, esi
// 00439572  5e                   pop esi
// 00439573  c20400               ret 4
// 00439576  85c9                 test ecx, ecx
// 00439578  7504                 jne 0x43957e
// 0043957a  33db                 xor ebx, ebx
// 0043957c  eb08                 jmp 0x439586
// 0043957e  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 00439581  2bd9                 sub ebx, ecx
// 00439583  c1fb02               sar ebx, 2
// 00439586  3bc3                 cmp eax, ebx
// 00439588  772c                 ja 0x4395b6
// 0043958a  8bc5                 mov eax, ebp
// 0043958c  51                   push ecx
// 0043958d  8d1c90               lea ebx, [eax + edx*4]
// 00439590  53                   push ebx
// 00439591  50                   push eax
// 00439592  e859f4ffff           call 0x4389f0
// 00439597  8b4610               mov eax, dword ptr [esi + 0x10]
// 0043959a  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0043959d  83c40c               add esp, 0xc
// 004395a0  50                   push eax
// 004395a1  51                   push ecx
// 004395a2  53                   push ebx
// 004395a3  8bce                 mov ecx, esi
// 004395a5  e856a6feff           call 0x423c00
// 004395aa  5d                   pop ebp
// 004395ab  5b                   pop ebx
// 004395ac  894610               mov dword ptr [esi + 0x10], eax
// 004395af  5f                   pop edi
// 004395b0  8bc6                 mov eax, esi
// 004395b2  5e                   pop esi
// 004395b3  c20400               ret 4
// 004395b6  85c9                 test ecx, ecx
// 004395b8  7409                 je 0x4395c3
// 004395ba  51                   push ecx
// 004395bb  e8ba702600           call 0x6a067a
// 004395c0  83c404               add esp, 4
// 004395c3  8b4710               mov eax, dword ptr [edi + 0x10]
// 004395c6  2b470c               sub eax, dword ptr [edi + 0xc]
// 004395c9  8bce                 mov ecx, esi
// 004395cb  c1f802               sar eax, 2
// 004395ce  50                   push eax
// 004395cf  e80cf5ffff           call 0x438ae0
// 004395d4  84c0                 test al, al
// 004395d6  7416                 je 0x4395ee
// 004395d8  8b560c               mov edx, dword ptr [esi + 0xc]
// 004395db  8b4710               mov eax, dword ptr [edi + 0x10]
// 004395de  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 004395e1  52                   push edx
// 004395e2  50                   push eax
// 004395e3  51                   push ecx
// 004395e4  8bce                 mov ecx, esi
// 004395e6  e815a6feff           call 0x423c00
// 004395eb  894610               mov dword ptr [esi + 0x10], eax
// 004395ee  5d                   pop ebp
// 004395ef  5b                   pop ebx
// 004395f0  5f                   pop edi
// 004395f1  8bc6                 mov eax, esi
// 004395f3  5e                   pop esi
// 004395f4  c20400               ret 4
// standard library vector<ptr> (function ??4?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
