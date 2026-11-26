// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 00823830  unit: RBX::$02W4SurfaceType::?$SurfaceGetSet  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00823830
//
// 00823830  8b442404             mov eax, dword ptr [esp + 4]
// 00823834  56                   push esi
// 00823835  8bf1                 mov esi, ecx
// 00823837  85c0                 test eax, eax
// 00823839  7414                 je 0x82384f
// 0082383b  8d48e4               lea ecx, [eax - 0x1c]
// 0082383e  e81dd2f2ff           call 0x750a60
// 00823843  8d4810               lea ecx, [eax + 0x10]
// 00823846  8b4604               mov eax, dword ptr [esi + 4]
// 00823849  ffd0                 call eax
// 0082384b  5e                   pop esi
// 0082384c  c20400               ret 4
// 0082384f  33c9                 xor ecx, ecx
// 00823851  e80ad2f2ff           call 0x750a60
// 00823856  8d4810               lea ecx, [eax + 0x10]
// 00823859  8b4604               mov eax, dword ptr [esi + 4]
// 0082385c  ffd0                 call eax
// 0082385e  5e                   pop esi
// 0082385f  c20400               ret 4

struct S_func_00750a60 {
    char pad0[436];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void (__thiscall *m_cb)(void*);
    void __thiscall set(void* p);
};

void __thiscall S::set(void* p)
{
    S_func_00750a60* o;
    if (p) {
        o = (S_func_00750a60*)((char*)p - 0x1c);
    } else {
        o = 0;
    }
    int* q = o->f();
    m_cb((char*)q + 0x28);
}
