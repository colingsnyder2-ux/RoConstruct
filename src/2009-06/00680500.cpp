// from server: 100% by auto
// roc 2009-06 00680500  unit: RBX::Mechanism  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00680500
//
// 00680500  83ec18               sub esp, 0x18
// 00680503  53                   push ebx
// 00680504  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00680508  56                   push esi
// 00680509  8bf1                 mov esi, ecx
// 0068050b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0068050e  57                   push edi
// 0068050f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00680512  8bc7                 mov eax, edi
// 00680514  2bc1                 sub eax, ecx
// 00680516  c1f802               sar eax, 2
// 00680519  3bd8                 cmp ebx, eax
// 0068051b  762f                 jbe 0x68054c
// 0068051d  3bcf                 cmp ecx, edi
// 0068051f  7606                 jbe 0x680527
// 00680521  ff15ace98900         call dword ptr [0x89e9ac]
// 00680527  8b5610               mov edx, dword ptr [esi + 0x10]
// 0068052a  2b560c               sub edx, dword ptr [esi + 0xc]
// 0068052d  8b06                 mov eax, dword ptr [esi]
// 0068052f  8d4c242c             lea ecx, [esp + 0x2c]
// 00680533  51                   push ecx
// 00680534  c1fa02               sar edx, 2
// 00680537  2bda                 sub ebx, edx
// 00680539  53                   push ebx
// 0068053a  57                   push edi
// 0068053b  50                   push eax
// 0068053c  8bce                 mov ecx, esi
// 0068053e  e84dde0700           call 0x6fe390
// 00680543  5f                   pop edi
// 00680544  5e                   pop esi
// 00680545  5b                   pop ebx
// 00680546  83c418               add esp, 0x18
// 00680549  c20800               ret 8
// 0068054c  7352                 jae 0x6805a0
// 0068054e  3bcf                 cmp ecx, edi
// 00680550  7606                 jbe 0x680558
// 00680552  ff15ace98900         call dword ptr [0x89e9ac]
// 00680558  8b06                 mov eax, dword ptr [esi]
// 0068055a  55                   push ebp
// 0068055b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0068055e  89442418             mov dword ptr [esp + 0x18], eax
// 00680562  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 00680565  7606                 jbe 0x68056d
// 00680567  ff15ace98900         call dword ptr [0x89e9ac]
// 0068056d  8b0e                 mov ecx, dword ptr [esi]
// 0068056f  53                   push ebx
// 00680570  8d542424             lea edx, [esp + 0x24]
// 00680574  894c2414             mov dword ptr [esp + 0x14], ecx
// 00680578  52                   push edx
// 00680579  8d4c2418             lea ecx, [esp + 0x18]
// 0068057d  896c241c             mov dword ptr [esp + 0x1c], ebp
// 00680581  e87afeffff           call 0x680400
// 00680586  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0068058a  8b5004               mov edx, dword ptr [eax + 4]
// 0068058d  8b00                 mov eax, dword ptr [eax]
// 0068058f  57                   push edi
// 00680590  51                   push ecx
// 00680591  52                   push edx
// 00680592  50                   push eax
// 00680593  8d4c2428             lea ecx, [esp + 0x28]
// 00680597  51                   push ecx
// 00680598  8bce                 mov ecx, esi
// 0068059a  e881dc0700           call 0x6fe220
// 0068059f  5d                   pop ebp
// 006805a0  5f                   pop edi
// 006805a1  5e                   pop esi
// 006805a2  5b                   pop ebx
// 006805a3  83c418               add esp, 0x18
// 006805a6  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
