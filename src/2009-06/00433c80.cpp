// from server: 100% by auto
// roc 2009-06 00433c80  unit: IIHAAH::?$CMap  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00433c80
//
// 00433c80  56                   push esi
// 00433c81  57                   push edi
// 00433c82  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00433c86  8bf1                 mov esi, ecx
// 00433c88  3bf7                 cmp esi, edi
// 00433c8a  0f84d0000000         je 0x433d60
// 00433c90  53                   push ebx
// 00433c91  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 00433c94  55                   push ebp
// 00433c95  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 00433c98  8bc3                 mov eax, ebx
// 00433c9a  2bc5                 sub eax, ebp
// 00433c9c  c1f802               sar eax, 2
// 00433c9f  85c0                 test eax, eax
// 00433ca1  750e                 jne 0x433cb1
// 00433ca3  e8c8a40400           call 0x47e170
// 00433ca8  5d                   pop ebp
// 00433ca9  5b                   pop ebx
// 00433caa  5f                   pop edi
// 00433cab  8bc6                 mov eax, esi
// 00433cad  5e                   pop esi
// 00433cae  c20400               ret 4
// 00433cb1  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00433cb4  8b5610               mov edx, dword ptr [esi + 0x10]
// 00433cb7  2bd1                 sub edx, ecx
// 00433cb9  c1fa02               sar edx, 2
// 00433cbc  3bc2                 cmp eax, edx
// 00433cbe  7726                 ja 0x433ce6
// 00433cc0  51                   push ecx
// 00433cc1  53                   push ebx
// 00433cc2  55                   push ebp
// 00433cc3  e868e7ffff           call 0x432430
// 00433cc8  8b4710               mov eax, dword ptr [edi + 0x10]
// 00433ccb  2b470c               sub eax, dword ptr [edi + 0xc]
// 00433cce  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00433cd1  83c40c               add esp, 0xc
// 00433cd4  5d                   pop ebp
// 00433cd5  c1f802               sar eax, 2
// 00433cd8  5b                   pop ebx
// 00433cd9  8d1481               lea edx, [ecx + eax*4]
// 00433cdc  5f                   pop edi
// 00433cdd  895610               mov dword ptr [esi + 0x10], edx
// 00433ce0  8bc6                 mov eax, esi
// 00433ce2  5e                   pop esi
// 00433ce3  c20400               ret 4
// 00433ce6  85c9                 test ecx, ecx
// 00433ce8  7504                 jne 0x433cee
// 00433cea  33db                 xor ebx, ebx
// 00433cec  eb08                 jmp 0x433cf6
// 00433cee  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 00433cf1  2bd9                 sub ebx, ecx
// 00433cf3  c1fb02               sar ebx, 2
// 00433cf6  3bc3                 cmp eax, ebx
// 00433cf8  772c                 ja 0x433d26
// 00433cfa  8bc5                 mov eax, ebp
// 00433cfc  51                   push ecx
// 00433cfd  8d1c90               lea ebx, [eax + edx*4]
// 00433d00  53                   push ebx
// 00433d01  50                   push eax
// 00433d02  e829e7ffff           call 0x432430
// 00433d07  8b4610               mov eax, dword ptr [esi + 0x10]
// 00433d0a  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00433d0d  83c40c               add esp, 0xc
// 00433d10  50                   push eax
// 00433d11  51                   push ecx
// 00433d12  53                   push ebx
// 00433d13  8bce                 mov ecx, esi
// 00433d15  e8a6552a00           call 0x6d92c0
// 00433d1a  5d                   pop ebp
// 00433d1b  5b                   pop ebx
// 00433d1c  894610               mov dword ptr [esi + 0x10], eax
// 00433d1f  5f                   pop edi
// 00433d20  8bc6                 mov eax, esi
// 00433d22  5e                   pop esi
// 00433d23  c20400               ret 4
// 00433d26  85c9                 test ecx, ecx
// 00433d28  7409                 je 0x433d33
// 00433d2a  51                   push ecx
// 00433d2b  e8024d2e00           call 0x718a32
// 00433d30  83c404               add esp, 4
// 00433d33  8b4710               mov eax, dword ptr [edi + 0x10]
// 00433d36  2b470c               sub eax, dword ptr [edi + 0xc]
// 00433d39  8bce                 mov ecx, esi
// 00433d3b  c1f802               sar eax, 2
// 00433d3e  50                   push eax
// 00433d3f  e83ce6ffff           call 0x432380
// 00433d44  84c0                 test al, al
// 00433d46  7416                 je 0x433d5e
// 00433d48  8b560c               mov edx, dword ptr [esi + 0xc]
// 00433d4b  8b4710               mov eax, dword ptr [edi + 0x10]
// 00433d4e  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00433d51  52                   push edx
// 00433d52  50                   push eax
// 00433d53  51                   push ecx
// 00433d54  8bce                 mov ecx, esi
// 00433d56  e865552a00           call 0x6d92c0
// 00433d5b  894610               mov dword ptr [esi + 0x10], eax
// 00433d5e  5d                   pop ebp
// 00433d5f  5b                   pop ebx
// 00433d60  5f                   pop edi
// 00433d61  8bc6                 mov eax, esi
// 00433d63  5e                   pop esi
// 00433d64  c20400               ret 4
// standard library vector<ptr> (function ??4?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
