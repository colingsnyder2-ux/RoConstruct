// from server: 100% by auto
// roc 2009-12 00445430  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00445430
//
// 00445430  56                   push esi
// 00445431  57                   push edi
// 00445432  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00445436  8bf1                 mov esi, ecx
// 00445438  3bf7                 cmp esi, edi
// 0044543a  0f84d0000000         je 0x445510
// 00445440  53                   push ebx
// 00445441  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 00445444  55                   push ebp
// 00445445  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 00445448  8bc3                 mov eax, ebx
// 0044544a  2bc5                 sub eax, ebp
// 0044544c  c1f802               sar eax, 2
// 0044544f  85c0                 test eax, eax
// 00445451  750e                 jne 0x445461
// 00445453  e8e8fcffff           call 0x445140
// 00445458  5d                   pop ebp
// 00445459  5b                   pop ebx
// 0044545a  5f                   pop edi
// 0044545b  8bc6                 mov eax, esi
// 0044545d  5e                   pop esi
// 0044545e  c20400               ret 4
// 00445461  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00445464  8b5610               mov edx, dword ptr [esi + 0x10]
// 00445467  2bd1                 sub edx, ecx
// 00445469  c1fa02               sar edx, 2
// 0044546c  3bc2                 cmp eax, edx
// 0044546e  7726                 ja 0x445496
// 00445470  51                   push ecx
// 00445471  53                   push ebx
// 00445472  55                   push ebp
// 00445473  e8e8f2ffff           call 0x444760
// 00445478  8b4710               mov eax, dword ptr [edi + 0x10]
// 0044547b  2b470c               sub eax, dword ptr [edi + 0xc]
// 0044547e  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00445481  83c40c               add esp, 0xc
// 00445484  5d                   pop ebp
// 00445485  c1f802               sar eax, 2
// 00445488  5b                   pop ebx
// 00445489  8d1481               lea edx, [ecx + eax*4]
// 0044548c  5f                   pop edi
// 0044548d  895610               mov dword ptr [esi + 0x10], edx
// 00445490  8bc6                 mov eax, esi
// 00445492  5e                   pop esi
// 00445493  c20400               ret 4
// 00445496  85c9                 test ecx, ecx
// 00445498  7504                 jne 0x44549e
// 0044549a  33db                 xor ebx, ebx
// 0044549c  eb08                 jmp 0x4454a6
// 0044549e  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 004454a1  2bd9                 sub ebx, ecx
// 004454a3  c1fb02               sar ebx, 2
// 004454a6  3bc3                 cmp eax, ebx
// 004454a8  772c                 ja 0x4454d6
// 004454aa  8bc5                 mov eax, ebp
// 004454ac  51                   push ecx
// 004454ad  8d1c90               lea ebx, [eax + edx*4]
// 004454b0  53                   push ebx
// 004454b1  50                   push eax
// 004454b2  e8a9f2ffff           call 0x444760
// 004454b7  8b4610               mov eax, dword ptr [esi + 0x10]
// 004454ba  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004454bd  83c40c               add esp, 0xc
// 004454c0  50                   push eax
// 004454c1  51                   push ecx
// 004454c2  53                   push ebx
// 004454c3  8bce                 mov ecx, esi
// 004454c5  e876862d00           call 0x71db40
// 004454ca  5d                   pop ebp
// 004454cb  5b                   pop ebx
// 004454cc  894610               mov dword ptr [esi + 0x10], eax
// 004454cf  5f                   pop edi
// 004454d0  8bc6                 mov eax, esi
// 004454d2  5e                   pop esi
// 004454d3  c20400               ret 4
// 004454d6  85c9                 test ecx, ecx
// 004454d8  7409                 je 0x4454e3
// 004454da  51                   push ecx
// 004454db  e87ae33a00           call 0x7f385a
// 004454e0  83c404               add esp, 4
// 004454e3  8b4710               mov eax, dword ptr [edi + 0x10]
// 004454e6  2b470c               sub eax, dword ptr [edi + 0xc]
// 004454e9  8bce                 mov ecx, esi
// 004454eb  c1f802               sar eax, 2
// 004454ee  50                   push eax
// 004454ef  e8acf1ffff           call 0x4446a0
// 004454f4  84c0                 test al, al
// 004454f6  7416                 je 0x44550e
// 004454f8  8b560c               mov edx, dword ptr [esi + 0xc]
// 004454fb  8b4710               mov eax, dword ptr [edi + 0x10]
// 004454fe  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00445501  52                   push edx
// 00445502  50                   push eax
// 00445503  51                   push ecx
// 00445504  8bce                 mov ecx, esi
// 00445506  e835862d00           call 0x71db40
// 0044550b  894610               mov dword ptr [esi + 0x10], eax
// 0044550e  5d                   pop ebp
// 0044550f  5b                   pop ebx
// 00445510  5f                   pop edi
// 00445511  8bc6                 mov eax, esi
// 00445513  5e                   pop esi
// 00445514  c20400               ret 4
// standard library vector<ptr> (function ??4?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
