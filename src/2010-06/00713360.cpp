// from server: 100% by auto
// roc 2010-06 00713360  unit: RBX::BallBallContact  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00713360
//
// 00713360  83ec18               sub esp, 0x18
// 00713363  53                   push ebx
// 00713364  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00713368  56                   push esi
// 00713369  8bf1                 mov esi, ecx
// 0071336b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0071336e  57                   push edi
// 0071336f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00713372  8bc7                 mov eax, edi
// 00713374  2bc1                 sub eax, ecx
// 00713376  c1f803               sar eax, 3
// 00713379  3bd8                 cmp ebx, eax
// 0071337b  762f                 jbe 0x7133ac
// 0071337d  3bcf                 cmp ecx, edi
// 0071337f  7606                 jbe 0x713387
// 00713381  ff150ca99e00         call dword ptr [0x9ea90c]
// 00713387  8b5610               mov edx, dword ptr [esi + 0x10]
// 0071338a  2b560c               sub edx, dword ptr [esi + 0xc]
// 0071338d  8b06                 mov eax, dword ptr [esi]
// 0071338f  8d4c242c             lea ecx, [esp + 0x2c]
// 00713393  51                   push ecx
// 00713394  c1fa03               sar edx, 3
// 00713397  2bda                 sub ebx, edx
// 00713399  53                   push ebx
// 0071339a  57                   push edi
// 0071339b  50                   push eax
// 0071339c  8bce                 mov ecx, esi
// 0071339e  e87d4bf4ff           call 0x657f20
// 007133a3  5f                   pop edi
// 007133a4  5e                   pop esi
// 007133a5  5b                   pop ebx
// 007133a6  83c418               add esp, 0x18
// 007133a9  c20c00               ret 0xc
// 007133ac  7352                 jae 0x713400
// 007133ae  3bcf                 cmp ecx, edi
// 007133b0  7606                 jbe 0x7133b8
// 007133b2  ff150ca99e00         call dword ptr [0x9ea90c]
// 007133b8  8b06                 mov eax, dword ptr [esi]
// 007133ba  55                   push ebp
// 007133bb  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 007133be  89442418             mov dword ptr [esp + 0x18], eax
// 007133c2  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 007133c5  7606                 jbe 0x7133cd
// 007133c7  ff150ca99e00         call dword ptr [0x9ea90c]
// 007133cd  8b0e                 mov ecx, dword ptr [esi]
// 007133cf  53                   push ebx
// 007133d0  8d542424             lea edx, [esp + 0x24]
// 007133d4  894c2414             mov dword ptr [esp + 0x14], ecx
// 007133d8  52                   push edx
// 007133d9  8d4c2418             lea ecx, [esp + 0x18]
// 007133dd  896c241c             mov dword ptr [esp + 0x1c], ebp
// 007133e1  e84a72f9ff           call 0x6aa630
// 007133e6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007133ea  8b5004               mov edx, dword ptr [eax + 4]
// 007133ed  8b00                 mov eax, dword ptr [eax]
// 007133ef  57                   push edi
// 007133f0  51                   push ecx
// 007133f1  52                   push edx
// 007133f2  50                   push eax
// 007133f3  8d4c2428             lea ecx, [esp + 0x28]
// 007133f7  51                   push ecx
// 007133f8  8bce                 mov ecx, esi
// 007133fa  e8c1eb2400           call 0x961fc0
// 007133ff  5d                   pop ebp
// 00713400  5f                   pop edi
// 00713401  5e                   pop esi
// 00713402  5b                   pop ebx
// 00713403  83c418               add esp, 0x18
// 00713406  c20c00               ret 0xc
// standard library vector<pod8> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
