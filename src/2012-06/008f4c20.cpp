// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 007fa880  unit: RBX::VInsertService::?$FactoryProduct  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007fa880
//
// 007fa880  64a100000000         mov eax, dword ptr fs:[0]
// 007fa886  6aff                 push -1
// 007fa888  68586bad00           push 0xad6b58
// 007fa88d  50                   push eax
// 007fa88e  64892500000000       mov dword ptr fs:[0], esp
// 007fa895  56                   push esi
// 007fa896  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007fa89e  8d711c               lea esi, [ecx + 0x1c]
// 007fa8a1  e83ae8f0ff           call 0x7090e0
// 007fa8a6  8906                 mov dword ptr [esi], eax
// 007fa8a8  e8d369ecff           call 0x6c1280
// 007fa8ad  8d4c2418             lea ecx, [esp + 0x18]
// 007fa8b1  51                   push ecx
// 007fa8b2  50                   push eax
// 007fa8b3  8d54241c             lea edx, [esp + 0x1c]
// 007fa8b7  52                   push edx
// 007fa8b8  e8234ae8ff           call 0x67f2e0
// 007fa8bd  83c404               add esp, 4
// 007fa8c0  50                   push eax
// 007fa8c1  8bce                 mov ecx, esi
// 007fa8c3  e8b8ebf0ff           call 0x709480
// 007fa8c8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007fa8cc  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 007fa8d4  85c0                 test eax, eax
// 007fa8d6  740d                 je 0x7fa8e5
// 007fa8d8  8b5004               mov edx, dword ptr [eax + 4]
// 007fa8db  8d4c2420             lea ecx, [esp + 0x20]
// 007fa8df  51                   push ecx
// 007fa8e0  ffd2                 call edx
// 007fa8e2  83c404               add esp, 4
// 007fa8e5  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007fa8e9  64890d00000000       mov dword ptr fs:[0], ecx
// 007fa8f0  5e                   pop esi
// 007fa8f1  83c40c               add esp, 0xc
// 007fa8f4  c24800               ret 0x48


struct Mgr_007fa880 { void* a; void (*destroy)(void*); };
struct Fn_007fa880 {
    int x;
    Mgr_007fa880* mgr;
    char buf[60];
    Fn_007fa880(const Fn_007fa880&);
    ~Fn_007fa880() { if (mgr) mgr->destroy(buf); }
};
struct Key_007fa880 { int v; };
struct Sub_007fa880 {
    int v;
    void set(int a, int b, const Fn_007fa880& f);
};
int make_007fa880();
int get_007fa880();
int conv_007fa880(const Key_007fa880& k);
struct S_007fa880 {
    char pad[0x1c];
    Sub_007fa880 sub;
    void f(Key_007fa880 k, Fn_007fa880 fn);
};
void S_007fa880::f(Key_007fa880 k, Fn_007fa880 fn)
{
    sub.v = make_007fa880();
    int b = get_007fa880();
    sub.set(conv_007fa880(k), b, fn);
}
