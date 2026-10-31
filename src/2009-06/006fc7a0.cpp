// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0066fc00  unit: RBX::AdornRbxGfx  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066fc00
//
// 0066fc00  51                   push ecx
// 0066fc01  c7042400000000       mov dword ptr [esp], 0
// 0066fc08  a158da9700           mov eax, dword ptr [0x97da58]
// 0066fc0d  890424               mov dword ptr [esp], eax
// 0066fc10  40                   inc eax
// 0066fc11  56                   push esi
// 0066fc12  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0066fc16  a358da9700           mov dword ptr [0x97da58], eax
// 0066fc1b  8d442404             lea eax, [esp + 4]
// 0066fc1f  50                   push eax
// 0066fc20  56                   push esi
// 0066fc21  e8cae2f4ff           call 0x5bdef0
// 0066fc26  83c408               add esp, 8
// 0066fc29  8bc6                 mov eax, esi
// 0066fc2b  5e                   pop esi
// 0066fc2c  59                   pop ecx
// 0066fc2d  c20400               ret 4

struct S {
    int f(int);
};

extern "C" int __cdecl sub_5BDEF0(int, int*);

int S::f(int a) {
    int local = 0;
    local = *(int*)0x97DA58;
    *(int*)0x97DA58 = local + 1;
    sub_5BDEF0(a, &local);
    return a;
}
