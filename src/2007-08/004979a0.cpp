// from server: 33% by colin
// roc 2007-08 004979a0  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004979a0
//
// 004979a0  32c0                 xor al, al
// 004979a2  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004979a5  64890d00000000       mov dword ptr fs:[0], ecx
// 004979ac  59                   pop ecx
// 004979ad  5f                   pop edi
// 004979ae  5e                   pop esi
// 004979af  5b                   pop ebx
// 004979b0  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004979b3  33cd                 xor ecx, ebp
// 004979b5  e864901900           call 0x630a1e
// 004979ba  8be5                 mov esp, ebp
// 004979bc  5d                   pop ebp
// 004979bd  c20800               ret 8

extern "C" void __cdecl func_00630a1e();

struct S {
    char f(int, int);
};

char S::f(int, int)
{
    func_00630a1e();
    return 0;
}
