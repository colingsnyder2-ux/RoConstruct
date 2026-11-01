// from server: 100% by auto
// roc 2009-12 007ea500  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ea500
//
// 007ea500  83ec08               sub esp, 8
// 007ea503  56                   push esi
// 007ea504  8bf1                 mov esi, ecx
// 007ea506  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007ea509  57                   push edi
// 007ea50a  85c9                 test ecx, ecx
// 007ea50c  7504                 jne 0x7ea512
// 007ea50e  33c0                 xor eax, eax
// 007ea510  eb08                 jmp 0x7ea51a
// 007ea512  8b4614               mov eax, dword ptr [esi + 0x14]
// 007ea515  2bc1                 sub eax, ecx
// 007ea517  c1f803               sar eax, 3
// 007ea51a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007ea51d  8bd7                 mov edx, edi
// 007ea51f  2bd1                 sub edx, ecx
// 007ea521  c1fa03               sar edx, 3
// 007ea524  3bd0                 cmp edx, eax
// 007ea526  7331                 jae 0x7ea559
// 007ea528  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007ea52c  c644240800           mov byte ptr [esp + 8], 0
// 007ea531  8b442408             mov eax, dword ptr [esp + 8]
// 007ea535  50                   push eax
// 007ea536  8b442418             mov eax, dword ptr [esp + 0x18]
// 007ea53a  51                   push ecx
// 007ea53b  8d5608               lea edx, [esi + 8]
// 007ea53e  52                   push edx
// 007ea53f  50                   push eax
// 007ea540  6a01                 push 1
// 007ea542  57                   push edi
// 007ea543  e8e8d8eaff           call 0x697e30
// 007ea548  83c418               add esp, 0x18
// 007ea54b  83c708               add edi, 8
// 007ea54e  897e10               mov dword ptr [esi + 0x10], edi
// 007ea551  5f                   pop edi
// 007ea552  5e                   pop esi
// 007ea553  83c408               add esp, 8
// 007ea556  c20400               ret 4
// 007ea559  3bcf                 cmp ecx, edi
// 007ea55b  7606                 jbe 0x7ea563
// 007ea55d  ff1560b79800         call dword ptr [0x98b760]
// 007ea563  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007ea567  8b06                 mov eax, dword ptr [esi]
// 007ea569  51                   push ecx
// 007ea56a  57                   push edi
// 007ea56b  50                   push eax
// 007ea56c  8d542414             lea edx, [esp + 0x14]
// 007ea570  52                   push edx
// 007ea571  8bce                 mov ecx, esi
// 007ea573  e80861f6ff           call 0x750680
// 007ea578  5f                   pop edi
// 007ea579  5e                   pop esi
// 007ea57a  83c408               add esp, 8
// 007ea57d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
