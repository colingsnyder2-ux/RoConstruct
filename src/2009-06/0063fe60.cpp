// from server: 100% by auto
// roc 2009-06 0063fe60  unit: RBX::Accoutrement  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063fe60
//
// 0063fe60  83ec18               sub esp, 0x18
// 0063fe63  53                   push ebx
// 0063fe64  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0063fe68  56                   push esi
// 0063fe69  8bf1                 mov esi, ecx
// 0063fe6b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0063fe6e  57                   push edi
// 0063fe6f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0063fe72  8bc7                 mov eax, edi
// 0063fe74  2bc1                 sub eax, ecx
// 0063fe76  c1f802               sar eax, 2
// 0063fe79  3bd8                 cmp ebx, eax
// 0063fe7b  762f                 jbe 0x63feac
// 0063fe7d  3bcf                 cmp ecx, edi
// 0063fe7f  7606                 jbe 0x63fe87
// 0063fe81  ff15ace98900         call dword ptr [0x89e9ac]
// 0063fe87  8b5610               mov edx, dword ptr [esi + 0x10]
// 0063fe8a  2b560c               sub edx, dword ptr [esi + 0xc]
// 0063fe8d  8b06                 mov eax, dword ptr [esi]
// 0063fe8f  8d4c242c             lea ecx, [esp + 0x2c]
// 0063fe93  51                   push ecx
// 0063fe94  c1fa02               sar edx, 2
// 0063fe97  2bda                 sub ebx, edx
// 0063fe99  53                   push ebx
// 0063fe9a  57                   push edi
// 0063fe9b  50                   push eax
// 0063fe9c  8bce                 mov ecx, esi
// 0063fe9e  e8cd550600           call 0x6a5470
// 0063fea3  5f                   pop edi
// 0063fea4  5e                   pop esi
// 0063fea5  5b                   pop ebx
// 0063fea6  83c418               add esp, 0x18
// 0063fea9  c20800               ret 8
// 0063feac  7352                 jae 0x63ff00
// 0063feae  3bcf                 cmp ecx, edi
// 0063feb0  7606                 jbe 0x63feb8
// 0063feb2  ff15ace98900         call dword ptr [0x89e9ac]
// 0063feb8  8b06                 mov eax, dword ptr [esi]
// 0063feba  55                   push ebp
// 0063febb  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0063febe  89442418             mov dword ptr [esp + 0x18], eax
// 0063fec2  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0063fec5  7606                 jbe 0x63fecd
// 0063fec7  ff15ace98900         call dword ptr [0x89e9ac]
// 0063fecd  8b0e                 mov ecx, dword ptr [esi]
// 0063fecf  53                   push ebx
// 0063fed0  8d542424             lea edx, [esp + 0x24]
// 0063fed4  894c2414             mov dword ptr [esp + 0x14], ecx
// 0063fed8  52                   push edx
// 0063fed9  8d4c2418             lea ecx, [esp + 0x18]
// 0063fedd  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0063fee1  e81a050400           call 0x680400
// 0063fee6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0063feea  8b5004               mov edx, dword ptr [eax + 4]
// 0063feed  8b00                 mov eax, dword ptr [eax]
// 0063feef  57                   push edi
// 0063fef0  51                   push ecx
// 0063fef1  52                   push edx
// 0063fef2  50                   push eax
// 0063fef3  8d4c2428             lea ecx, [esp + 0x28]
// 0063fef7  51                   push ecx
// 0063fef8  8bce                 mov ecx, esi
// 0063fefa  e8f108e0ff           call 0x4407f0
// 0063feff  5d                   pop ebp
// 0063ff00  5f                   pop edi
// 0063ff01  5e                   pop esi
// 0063ff02  5b                   pop ebx
// 0063ff03  83c418               add esp, 0x18
// 0063ff06  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
