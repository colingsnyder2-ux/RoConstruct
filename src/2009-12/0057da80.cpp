// from server: 100% by auto
// roc 2009-12 0057da80  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057da80
//
// 0057da80  83ec18               sub esp, 0x18
// 0057da83  53                   push ebx
// 0057da84  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0057da88  56                   push esi
// 0057da89  8bf1                 mov esi, ecx
// 0057da8b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0057da8e  57                   push edi
// 0057da8f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0057da92  8bc7                 mov eax, edi
// 0057da94  2bc1                 sub eax, ecx
// 0057da96  c1f803               sar eax, 3
// 0057da99  3bd8                 cmp ebx, eax
// 0057da9b  762f                 jbe 0x57dacc
// 0057da9d  3bcf                 cmp ecx, edi
// 0057da9f  7606                 jbe 0x57daa7
// 0057daa1  ff1560b79800         call dword ptr [0x98b760]
// 0057daa7  8b5610               mov edx, dword ptr [esi + 0x10]
// 0057daaa  2b560c               sub edx, dword ptr [esi + 0xc]
// 0057daad  8b06                 mov eax, dword ptr [esi]
// 0057daaf  8d4c242c             lea ecx, [esp + 0x2c]
// 0057dab3  51                   push ecx
// 0057dab4  c1fa03               sar edx, 3
// 0057dab7  2bda                 sub ebx, edx
// 0057dab9  53                   push ebx
// 0057daba  57                   push edi
// 0057dabb  50                   push eax
// 0057dabc  8bce                 mov ecx, esi
// 0057dabe  e89d33f0ff           call 0x480e60
// 0057dac3  5f                   pop edi
// 0057dac4  5e                   pop esi
// 0057dac5  5b                   pop ebx
// 0057dac6  83c418               add esp, 0x18
// 0057dac9  c20c00               ret 0xc
// 0057dacc  7352                 jae 0x57db20
// 0057dace  3bcf                 cmp ecx, edi
// 0057dad0  7606                 jbe 0x57dad8
// 0057dad2  ff1560b79800         call dword ptr [0x98b760]
// 0057dad8  8b06                 mov eax, dword ptr [esi]
// 0057dada  55                   push ebp
// 0057dadb  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0057dade  89442418             mov dword ptr [esp + 0x18], eax
// 0057dae2  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0057dae5  7606                 jbe 0x57daed
// 0057dae7  ff1560b79800         call dword ptr [0x98b760]
// 0057daed  8b0e                 mov ecx, dword ptr [esi]
// 0057daef  53                   push ebx
// 0057daf0  8d542424             lea edx, [esp + 0x24]
// 0057daf4  894c2414             mov dword ptr [esp + 0x14], ecx
// 0057daf8  52                   push edx
// 0057daf9  8d4c2418             lea ecx, [esp + 0x18]
// 0057dafd  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0057db01  e8ba02f4ff           call 0x4bddc0
// 0057db06  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057db0a  8b5004               mov edx, dword ptr [eax + 4]
// 0057db0d  8b00                 mov eax, dword ptr [eax]
// 0057db0f  57                   push edi
// 0057db10  51                   push ecx
// 0057db11  52                   push edx
// 0057db12  50                   push eax
// 0057db13  8d4c2428             lea ecx, [esp + 0x28]
// 0057db17  51                   push ecx
// 0057db18  8bce                 mov ecx, esi
// 0057db1a  e841fbffff           call 0x57d660
// 0057db1f  5d                   pop ebp
// 0057db20  5f                   pop edi
// 0057db21  5e                   pop esi
// 0057db22  5b                   pop ebx
// 0057db23  83c418               add esp, 0x18
// 0057db26  c20c00               ret 0xc
// standard library vector<pod8> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
