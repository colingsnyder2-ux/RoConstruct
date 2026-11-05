// from server: 100% by auto
// roc 2009-06 0047bf00  unit: Ogre::VRootManager::?$sp_counted_impl_p  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047bf00
//
// 0047bf00  83ec18               sub esp, 0x18
// 0047bf03  53                   push ebx
// 0047bf04  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0047bf08  56                   push esi
// 0047bf09  8bf1                 mov esi, ecx
// 0047bf0b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0047bf0e  57                   push edi
// 0047bf0f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0047bf12  8bc7                 mov eax, edi
// 0047bf14  2bc1                 sub eax, ecx
// 0047bf16  c1f802               sar eax, 2
// 0047bf19  3bd8                 cmp ebx, eax
// 0047bf1b  762f                 jbe 0x47bf4c
// 0047bf1d  3bcf                 cmp ecx, edi
// 0047bf1f  7606                 jbe 0x47bf27
// 0047bf21  ff15ace98900         call dword ptr [0x89e9ac]
// 0047bf27  8b5610               mov edx, dword ptr [esi + 0x10]
// 0047bf2a  2b560c               sub edx, dword ptr [esi + 0xc]
// 0047bf2d  8b06                 mov eax, dword ptr [esi]
// 0047bf2f  8d4c242c             lea ecx, [esp + 0x2c]
// 0047bf33  51                   push ecx
// 0047bf34  c1fa02               sar edx, 2
// 0047bf37  2bda                 sub ebx, edx
// 0047bf39  53                   push ebx
// 0047bf3a  57                   push edi
// 0047bf3b  50                   push eax
// 0047bf3c  8bce                 mov ecx, esi
// 0047bf3e  e8edb9ffff           call 0x477930
// 0047bf43  5f                   pop edi
// 0047bf44  5e                   pop esi
// 0047bf45  5b                   pop ebx
// 0047bf46  83c418               add esp, 0x18
// 0047bf49  c20800               ret 8
// 0047bf4c  7352                 jae 0x47bfa0
// 0047bf4e  3bcf                 cmp ecx, edi
// 0047bf50  7606                 jbe 0x47bf58
// 0047bf52  ff15ace98900         call dword ptr [0x89e9ac]
// 0047bf58  8b06                 mov eax, dword ptr [esi]
// 0047bf5a  55                   push ebp
// 0047bf5b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0047bf5e  89442418             mov dword ptr [esp + 0x18], eax
// 0047bf62  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0047bf65  7606                 jbe 0x47bf6d
// 0047bf67  ff15ace98900         call dword ptr [0x89e9ac]
// 0047bf6d  8b0e                 mov ecx, dword ptr [esi]
// 0047bf6f  53                   push ebx
// 0047bf70  8d542424             lea edx, [esp + 0x24]
// 0047bf74  894c2414             mov dword ptr [esp + 0x14], ecx
// 0047bf78  52                   push edx
// 0047bf79  8d4c2418             lea ecx, [esp + 0x18]
// 0047bf7d  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0047bf81  e87a442000           call 0x680400
// 0047bf86  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0047bf8a  8b5004               mov edx, dword ptr [eax + 4]
// 0047bf8d  8b00                 mov eax, dword ptr [eax]
// 0047bf8f  57                   push edi
// 0047bf90  51                   push ecx
// 0047bf91  52                   push edx
// 0047bf92  50                   push eax
// 0047bf93  8d4c2428             lea ecx, [esp + 0x28]
// 0047bf97  51                   push ecx
// 0047bf98  8bce                 mov ecx, esi
// 0047bf9a  e881222800           call 0x6fe220
// 0047bf9f  5d                   pop ebp
// 0047bfa0  5f                   pop edi
// 0047bfa1  5e                   pop esi
// 0047bfa2  5b                   pop ebx
// 0047bfa3  83c418               add esp, 0x18
// 0047bfa6  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
