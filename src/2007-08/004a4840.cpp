// from server: 47% by colin
// roc 2007-08 004a4840  unit: RBX::VNetworkSettings::?$FactoryProduct  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a4840
//
// 004a4840  7900                 jns 0x4a4842
// 004a4842  897004               mov dword ptr [eax + 4], esi
// 004a4845  894810               mov dword ptr [eax + 0x10], ecx
// 004a4848  895014               mov dword ptr [eax + 0x14], edx
// 004a484b  8bf8                 mov edi, eax
// 004a484d  eb02                 jmp 0x4a4851
// 004a484f  33ff                 xor edi, edi
// 004a4851  8b4618               mov eax, dword ptr [esi + 0x18]
// 004a4854  3bf8                 cmp edi, eax
// 004a4856  7409                 je 0x4a4861
// 004a4858  50                   push eax
// 004a4859  e804b41800           call 0x62fc62
// 004a485e  83c404               add esp, 4
// 004a4861  8bc6                 mov eax, esi
// 004a4863  897e18               mov dword ptr [esi + 0x18], edi
// 004a4866  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a486a  64890d00000000       mov dword ptr fs:[0], ecx
// 004a4871  59                   pop ecx
// 004a4872  5f                   pop edi
// 004a4873  5e                   pop esi
// 004a4874  83c414               add esp, 0x14
// 004a4877  c21000               ret 0x10

struct S {
    int f(int, int, int, int);
};

extern "C" void __cdecl func_0062fc62(int);

int S::f(int a, int b, int c, int d)
{
    int* p = (int*)this;
    p[1] = a;
    p[4] = b;
    p[5] = c;
    int* q = p;
    if (q != 0) {
        q = 0;
    }
    int old = *(int*)(a + 0x18);
    if (q != (int*)old) {
        func_0062fc62(old);
    }
    *(int*)(a + 0x18) = (int)q;
    return a;
}
