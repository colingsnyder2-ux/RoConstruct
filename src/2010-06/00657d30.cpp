// from server: 100% by auto
// roc 2010-06 00657d30  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00657d30
//
// 00657d30  56                   push esi
// 00657d31  57                   push edi
// 00657d32  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00657d36  8bf1                 mov esi, ecx
// 00657d38  3bf7                 cmp esi, edi
// 00657d3a  0f84d0000000         je 0x657e10
// 00657d40  53                   push ebx
// 00657d41  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 00657d44  55                   push ebp
// 00657d45  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 00657d48  8bc3                 mov eax, ebx
// 00657d4a  2bc5                 sub eax, ebp
// 00657d4c  c1f802               sar eax, 2
// 00657d4f  85c0                 test eax, eax
// 00657d51  750e                 jne 0x657d61
// 00657d53  e8c8fb1200           call 0x787920
// 00657d58  5d                   pop ebp
// 00657d59  5b                   pop ebx
// 00657d5a  5f                   pop edi
// 00657d5b  8bc6                 mov eax, esi
// 00657d5d  5e                   pop esi
// 00657d5e  c20400               ret 4
// 00657d61  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00657d64  8b5610               mov edx, dword ptr [esi + 0x10]
// 00657d67  2bd1                 sub edx, ecx
// 00657d69  c1fa02               sar edx, 2
// 00657d6c  3bc2                 cmp eax, edx
// 00657d6e  7726                 ja 0x657d96
// 00657d70  51                   push ecx
// 00657d71  53                   push ebx
// 00657d72  55                   push ebp
// 00657d73  e858f31200           call 0x7870d0
// 00657d78  8b4710               mov eax, dword ptr [edi + 0x10]
// 00657d7b  2b470c               sub eax, dword ptr [edi + 0xc]
// 00657d7e  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00657d81  83c40c               add esp, 0xc
// 00657d84  5d                   pop ebp
// 00657d85  c1f802               sar eax, 2
// 00657d88  5b                   pop ebx
// 00657d89  8d1481               lea edx, [ecx + eax*4]
// 00657d8c  5f                   pop edi
// 00657d8d  895610               mov dword ptr [esi + 0x10], edx
// 00657d90  8bc6                 mov eax, esi
// 00657d92  5e                   pop esi
// 00657d93  c20400               ret 4
// 00657d96  85c9                 test ecx, ecx
// 00657d98  7504                 jne 0x657d9e
// 00657d9a  33db                 xor ebx, ebx
// 00657d9c  eb08                 jmp 0x657da6
// 00657d9e  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 00657da1  2bd9                 sub ebx, ecx
// 00657da3  c1fb02               sar ebx, 2
// 00657da6  3bc3                 cmp eax, ebx
// 00657da8  772c                 ja 0x657dd6
// 00657daa  8bc5                 mov eax, ebp
// 00657dac  51                   push ecx
// 00657dad  8d1c90               lea ebx, [eax + edx*4]
// 00657db0  53                   push ebx
// 00657db1  50                   push eax
// 00657db2  e819f31200           call 0x7870d0
// 00657db7  8b4610               mov eax, dword ptr [esi + 0x10]
// 00657dba  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00657dbd  83c40c               add esp, 0xc
// 00657dc0  50                   push eax
// 00657dc1  51                   push ecx
// 00657dc2  53                   push ebx
// 00657dc3  8bce                 mov ecx, esi
// 00657dc5  e896802800           call 0x8dfe60
// 00657dca  5d                   pop ebp
// 00657dcb  5b                   pop ebx
// 00657dcc  894610               mov dword ptr [esi + 0x10], eax
// 00657dcf  5f                   pop edi
// 00657dd0  8bc6                 mov eax, esi
// 00657dd2  5e                   pop esi
// 00657dd3  c20400               ret 4
// 00657dd6  85c9                 test ecx, ecx
// 00657dd8  7409                 je 0x657de3
// 00657dda  51                   push ecx
// 00657ddb  e8bafb1400           call 0x7a799a
// 00657de0  83c404               add esp, 4
// 00657de3  8b4710               mov eax, dword ptr [edi + 0x10]
// 00657de6  2b470c               sub eax, dword ptr [edi + 0xc]
// 00657de9  8bce                 mov ecx, esi
// 00657deb  c1f802               sar eax, 2
// 00657dee  50                   push eax
// 00657def  e89cf7ffff           call 0x657590
// 00657df4  84c0                 test al, al
// 00657df6  7416                 je 0x657e0e
// 00657df8  8b560c               mov edx, dword ptr [esi + 0xc]
// 00657dfb  8b4710               mov eax, dword ptr [edi + 0x10]
// 00657dfe  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00657e01  52                   push edx
// 00657e02  50                   push eax
// 00657e03  51                   push ecx
// 00657e04  8bce                 mov ecx, esi
// 00657e06  e855802800           call 0x8dfe60
// 00657e0b  894610               mov dword ptr [esi + 0x10], eax
// 00657e0e  5d                   pop ebp
// 00657e0f  5b                   pop ebx
// 00657e10  5f                   pop edi
// 00657e11  8bc6                 mov eax, esi
// 00657e13  5e                   pop esi
// 00657e14  c20400               ret 4
// standard library vector<ptr> (function ??4?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
