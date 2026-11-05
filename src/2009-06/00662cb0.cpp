// from server: 100% by EspClaude
// from server: 94% by atomic.potato
// roc 2009-06 00662cb0  unit: RBX::$03W4SurfaceType::?$SurfaceGetSet  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00662cb0
//
// 00662cb0  8b442404             mov eax, dword ptr [esp + 4]
// 00662cb4  56                   push esi
// 00662cb5  8bf1                 mov esi, ecx
// 00662cb7  85c0                 test eax, eax
// 00662cb9  7414                 je 0x662ccf
// 00662cbb  8d48e8               lea ecx, [eax - 0x18]
// 00662cbe  e88d8fffff           call 0x65bc50
// 00662cc3  8d4808               lea ecx, [eax + 8]
// 00662cc6  8b4604               mov eax, dword ptr [esi + 4]
// 00662cc9  ffd0                 call eax
// 00662ccb  5e                   pop esi
// 00662ccc  c20400               ret 4
// 00662ccf  33c9                 xor ecx, ecx
// 00662cd1  e87a8fffff           call 0x65bc50
// 00662cd6  8d4808               lea ecx, [eax + 8]
// 00662cd9  8b4604               mov eax, dword ptr [esi + 4]
// 00662cdc  ffd0                 call eax
// 00662cde  5e                   pop esi
// 00662cdf  c20400               ret 4

struct S_func_0065bc50 {
    char pad0[308];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void* m_fn;
    void g(void*);
};

void S::g(void* p)
{
    S_func_0065bc50* o;
    if (p) {
        o = (S_func_0065bc50*)((char*)p - 0x18);
    } else {
        o = 0;
    }
    int* r = o->f();
    void* fn = m_fn;
    ((void (__thiscall*)(void*))fn)((char*)r + 8);
}
