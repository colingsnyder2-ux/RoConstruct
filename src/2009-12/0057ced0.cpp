// from server: 100% by auto
// roc 2009-12 0057ced0  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057ced0
//
// 0057ced0  8b542404             mov edx, dword ptr [esp + 4]
// 0057ced4  56                   push esi
// 0057ced5  8bf1                 mov esi, ecx
// 0057ced7  81faffffff3f         cmp edx, 0x3fffffff
// 0057cedd  7605                 jbe 0x57cee4
// 0057cedf  e87c52ecff           call 0x442160
// 0057cee4  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0057cee7  85c9                 test ecx, ecx
// 0057cee9  7504                 jne 0x57ceef
// 0057ceeb  33c0                 xor eax, eax
// 0057ceed  eb08                 jmp 0x57cef7
// 0057ceef  8b4614               mov eax, dword ptr [esi + 0x14]
// 0057cef2  2bc1                 sub eax, ecx
// 0057cef4  c1f802               sar eax, 2
// 0057cef7  3bc2                 cmp eax, edx
// 0057cef9  7377                 jae 0x57cf72
// 0057cefb  53                   push ebx
// 0057cefc  57                   push edi
// 0057cefd  6a00                 push 0
// 0057ceff  52                   push edx
// 0057cf00  e83b3aebff           call 0x430940
// 0057cf05  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0057cf08  83c408               add esp, 8
// 0057cf0b  8bd8                 mov ebx, eax
// 0057cf0d  397e0c               cmp dword ptr [esi + 0xc], edi
// 0057cf10  7606                 jbe 0x57cf18
// 0057cf12  ff1560b79800         call dword ptr [0x98b760]
// 0057cf18  55                   push ebp
// 0057cf19  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0057cf1c  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0057cf1f  7606                 jbe 0x57cf27
// 0057cf21  ff1560b79800         call dword ptr [0x98b760]
// 0057cf27  2bfd                 sub edi, ebp
// 0057cf29  c1ff02               sar edi, 2
// 0057cf2c  85ff                 test edi, edi
// 0057cf2e  7614                 jbe 0x57cf44
// 0057cf30  8d04bd00000000       lea eax, [edi*4]
// 0057cf37  50                   push eax
// 0057cf38  55                   push ebp
// 0057cf39  50                   push eax
// 0057cf3a  53                   push ebx
// 0057cf3b  ff15c0b79800         call dword ptr [0x98b7c0]
// 0057cf41  83c410               add esp, 0x10
// 0057cf44  8b460c               mov eax, dword ptr [esi + 0xc]
// 0057cf47  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0057cf4a  2bf8                 sub edi, eax
// 0057cf4c  c1ff02               sar edi, 2
// 0057cf4f  5d                   pop ebp
// 0057cf50  85c0                 test eax, eax
// 0057cf52  7409                 je 0x57cf5d
// 0057cf54  50                   push eax
// 0057cf55  e800692700           call 0x7f385a
// 0057cf5a  83c404               add esp, 4
// 0057cf5d  8b442410             mov eax, dword ptr [esp + 0x10]
// 0057cf61  8d14bb               lea edx, [ebx + edi*4]
// 0057cf64  8d0c83               lea ecx, [ebx + eax*4]
// 0057cf67  5f                   pop edi
// 0057cf68  895e0c               mov dword ptr [esi + 0xc], ebx
// 0057cf6b  894e14               mov dword ptr [esi + 0x14], ecx
// 0057cf6e  895610               mov dword ptr [esi + 0x10], edx
// 0057cf71  5b                   pop ebx
// 0057cf72  5e                   pop esi
// 0057cf73  c20400               ret 4
// standard library vector<ptr> (function ?reserve@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
