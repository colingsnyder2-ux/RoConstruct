// from server: 100% by Xemicl
// from server: 95% by tajop
// roc 2012-06 004dfae0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004dfae0
//
// 004dfae0  6aff                 push -1
// 004dfae2  680c68ac00           push 0xac680c
// 004dfae7  64a100000000         mov eax, dword ptr fs:[0]
// 004dfaed  50                   push eax
// 004dfaee  64892500000000       mov dword ptr fs:[0], esp
// 004dfaf5  51                   push ecx
// 004dfaf6  56                   push esi
// 004dfaf7  57                   push edi
// 004dfaf8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004dfafc  d907                 fld dword ptr [edi]
// 004dfafe  8bf1                 mov esi, ecx
// 004dfb00  8d4f08               lea ecx, [edi + 8]
// 004dfb03  d91e                 fstp dword ptr [esi]
// 004dfb05  8b4704               mov eax, dword ptr [edi + 4]
// 004dfb08  51                   push ecx
// 004dfb09  8d4e08               lea ecx, [esi + 8]
// 004dfb0c  8974240c             mov dword ptr [esp + 0xc], esi
// 004dfb10  894604               mov dword ptr [esi + 4], eax
// 004dfb13  ff154426b200         call dword ptr [0xb22644]
// 004dfb19  8d5724               lea edx, [edi + 0x24]
// 004dfb1c  52                   push edx
// 004dfb1d  8d4e24               lea ecx, [esi + 0x24]
// 004dfb20  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004dfb28  e803fcffff           call 0x4df730
// 004dfb2d  8b4734               mov eax, dword ptr [edi + 0x34]
// 004dfb30  894634               mov dword ptr [esi + 0x34], eax
// 004dfb33  8b4f38               mov ecx, dword ptr [edi + 0x38]
// 004dfb36  894e38               mov dword ptr [esi + 0x38], ecx
// 004dfb39  8b7f3c               mov edi, dword ptr [edi + 0x3c]
// 004dfb3c  897e3c               mov dword ptr [esi + 0x3c], edi
// 004dfb3f  85ff                 test edi, edi
// 004dfb41  740c                 je 0x4dfb4f
// 004dfb43  83c704               add edi, 4
// 004dfb46  ba01000000           mov edx, 1
// 004dfb4b  f00fc117             lock xadd dword ptr [edi], edx
// 004dfb4f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004dfb53  5f                   pop edi
// 004dfb54  8bc6                 mov eax, esi
// 004dfb56  5e                   pop esi
// 004dfb57  64890d00000000       mov dword ptr fs:[0], ecx
// 004dfb5e  83c410               add esp, 0x10
// 004dfb61  c20400               ret 4

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct __declspec(dllimport) Str {
    char b[0x1c];
    Str(const Str&);
    ~Str();
};

struct Vec {
    int v[4];
    Vec(const Vec&);
    ~Vec();
};

struct Counted {
    void* vt;
    long use;
};

struct Count {
    Counted* pi;
    Count(const Count& r) : pi(r.pi) {
        if (pi != 0) _InterlockedIncrement((volatile long*)&pi->use);
    }
};

struct S {
    float f;
    int i;
    Str s;
    Vec v;
    int a;
    void* p;
    Count c;
    S(const S& o);
};

S::S(const S& o) : f(o.f), i(o.i), s(o.s), v(o.v), a(o.a), p(o.p), c(o.c) {
}
