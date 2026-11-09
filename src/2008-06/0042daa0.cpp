// from server: 100% by auto
// roc 2008-06 0042daa0  unit: VCLuaFunction::?$CComObject  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042daa0
//
// 0042daa0  83ec08               sub esp, 8
// 0042daa3  56                   push esi
// 0042daa4  8bf1                 mov esi, ecx
// 0042daa6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0042daa9  57                   push edi
// 0042daaa  85c9                 test ecx, ecx
// 0042daac  7504                 jne 0x42dab2
// 0042daae  33c0                 xor eax, eax
// 0042dab0  eb08                 jmp 0x42daba
// 0042dab2  8b4614               mov eax, dword ptr [esi + 0x14]
// 0042dab5  2bc1                 sub eax, ecx
// 0042dab7  c1f803               sar eax, 3
// 0042daba  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0042dabd  8bd7                 mov edx, edi
// 0042dabf  2bd1                 sub edx, ecx
// 0042dac1  c1fa03               sar edx, 3
// 0042dac4  3bd0                 cmp edx, eax
// 0042dac6  7331                 jae 0x42daf9
// 0042dac8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042dacc  c644240800           mov byte ptr [esp + 8], 0
// 0042dad1  8b442408             mov eax, dword ptr [esp + 8]
// 0042dad5  50                   push eax
// 0042dad6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042dada  51                   push ecx
// 0042dadb  8d5608               lea edx, [esi + 8]
// 0042dade  52                   push edx
// 0042dadf  50                   push eax
// 0042dae0  6a01                 push 1
// 0042dae2  57                   push edi
// 0042dae3  e888f9ffff           call 0x42d470
// 0042dae8  83c418               add esp, 0x18
// 0042daeb  83c708               add edi, 8
// 0042daee  897e10               mov dword ptr [esi + 0x10], edi
// 0042daf1  5f                   pop edi
// 0042daf2  5e                   pop esi
// 0042daf3  83c408               add esp, 8
// 0042daf6  c20400               ret 4
// 0042daf9  3bcf                 cmp ecx, edi
// 0042dafb  7606                 jbe 0x42db03
// 0042dafd  ff1590288000         call dword ptr [0x802890]
// 0042db03  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042db07  8b06                 mov eax, dword ptr [esi]
// 0042db09  51                   push ecx
// 0042db0a  57                   push edi
// 0042db0b  50                   push eax
// 0042db0c  8d542414             lea edx, [esp + 0x14]
// 0042db10  52                   push edx
// 0042db11  8bce                 mov ecx, esi
// 0042db13  e868feffff           call 0x42d980
// 0042db18  5f                   pop edi
// 0042db19  5e                   pop esi
// 0042db1a  83c408               add esp, 8
// 0042db1d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
