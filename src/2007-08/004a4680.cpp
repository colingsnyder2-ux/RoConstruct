// from server: 53% by colin
// roc 2007-08 004a4680  unit: RBX::VNetworkSettings::?$FactoryProduct  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a4680
//
// 004a4680  7900                 jns 0x4a4682
// 004a4682  897004               mov dword ptr [eax + 4], esi
// 004a4685  894810               mov dword ptr [eax + 0x10], ecx
// 004a4688  895014               mov dword ptr [eax + 0x14], edx
// 004a468b  8bf8                 mov edi, eax
// 004a468d  eb02                 jmp 0x4a4691
// 004a468f  33ff                 xor edi, edi
// 004a4691  8b4618               mov eax, dword ptr [esi + 0x18]
// 004a4694  3bf8                 cmp edi, eax
// 004a4696  7409                 je 0x4a46a1
// 004a4698  50                   push eax
// 004a4699  e8c4b51800           call 0x62fc62
// 004a469e  83c404               add esp, 4
// 004a46a1  8bc6                 mov eax, esi
// 004a46a3  897e18               mov dword ptr [esi + 0x18], edi
// 004a46a6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a46aa  64890d00000000       mov dword ptr fs:[0], ecx
// 004a46b1  59                   pop ecx
// 004a46b2  5f                   pop edi
// 004a46b3  5e                   pop esi
// 004a46b4  83c414               add esp, 0x14
// 004a46b7  c21000               ret 0x10

struct S {
    int f(int, int, int, int);
};

extern "C" void __cdecl sub_0062FC62(int);

int S::f(int a, int b, int c, int d)
{
    int* p = (int*)a;
    p[1] = b;
    p[4] = c;
    p[5] = d;
    int* q = p;
    if (q != 0)
        q = 0;
    int old = *(int*)(b + 0x18);
    if (q != (int*)old) {
        sub_0062FC62(old);
    }
    *(int*)(b + 0x18) = (int)q;
    return b;
}
