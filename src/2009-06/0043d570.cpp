// from server: 72% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00442900  unit: CDataModelPropGrid  size: 292 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00442900
//
// 00442900  6aff                 push -1
// 00442902  68600c7c00           push 0x7c0c60
// 00442907  64a100000000         mov eax, dword ptr fs:[0]
// 0044290d  50                   push eax
// 0044290e  64892500000000       mov dword ptr fs:[0], esp
// 00442915  83ec0c               sub esp, 0xc
// 00442918  56                   push esi
// 00442919  8bf1                 mov esi, ecx
// 0044291b  8b8654ffffff         mov eax, dword ptr [esi - 0xac]
// 00442921  c744241801000000     mov dword ptr [esp + 0x18], 1
// 00442929  85c0                 test eax, eax
// 0044292b  742a                 je 0x442957
// 0044292d  50                   push eax
// 0044292e  8d4c2408             lea ecx, [esp + 8]
// 00442932  e80960ffff           call 0x438940
// 00442937  6a00                 push 0
// 00442939  8d8ebcfdffff         lea ecx, [esi - 0x244]
// 0044293f  c644241c02           mov byte ptr [esp + 0x1c], 2
// 00442944  e807fdffff           call 0x442650
// 00442949  8d4c2404             lea ecx, [esp + 4]
// 0044294d  c644241801           mov byte ptr [esp + 0x18], 1
// 00442952  e8694a1300           call 0x5773c0
// 00442957  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044295b  898654ffffff         mov dword ptr [esi - 0xac], eax
// 00442961  85c0                 test eax, eax
// 00442963  743c                 je 0x4429a1
// 00442965  50                   push eax
// 00442966  8d4c2408             lea ecx, [esp + 8]
// 0044296a  e8d15fffff           call 0x438940
// 0044296f  8b8e54ffffff         mov ecx, dword ptr [esi - 0xac]
// 00442975  c644241803           mov byte ptr [esp + 0x18], 3
// 0044297a  85c9                 test ecx, ecx
// 0044297c  7407                 je 0x442985
// 0044297e  e82d2afdff           call 0x4153b0
// 00442983  eb02                 jmp 0x442987
// 00442985  33c0                 xor eax, eax
// 00442987  50                   push eax
// 00442988  8d8ebcfdffff         lea ecx, [esi - 0x244]
// 0044298e  e8bdfcffff           call 0x442650
// 00442993  8d4c2404             lea ecx, [esp + 4]
// 00442997  c644241801           mov byte ptr [esp + 0x18], 1
// 0044299c  e81f4a1300           call 0x5773c0
// 004429a1  8b742424             mov esi, dword ptr [esp + 0x24]
// 004429a5  c644241800           mov byte ptr [esp + 0x18], 0
// 004429aa  85f6                 test esi, esi
// 004429ac  742a                 je 0x4429d8
// 004429ae  8d4604               lea eax, [esi + 4]
// 004429b1  83c9ff               or ecx, 0xffffffff
// 004429b4  f00fc108             lock xadd dword ptr [eax], ecx
// 004429b8  751e                 jne 0x4429d8
// 004429ba  8b16                 mov edx, dword ptr [esi]
// 004429bc  8b4204               mov eax, dword ptr [edx + 4]
// 004429bf  8bce                 mov ecx, esi
// 004429c1  ffd0                 call eax
// 004429c3  8d4e08               lea ecx, [esi + 8]
// 004429c6  83caff               or edx, 0xffffffff
// 004429c9  f00fc111             lock xadd dword ptr [ecx], edx
// 004429cd  7509                 jne 0x4429d8
// 004429cf  8b06                 mov eax, dword ptr [esi]
// 004429d1  8b5008               mov edx, dword ptr [eax + 8]
// 004429d4  8bce                 mov ecx, esi
// 004429d6  ffd2                 call edx
// 004429d8  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 004429dc  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004429e4  85f6                 test esi, esi
// 004429e6  742a                 je 0x442a12
// 004429e8  8d4604               lea eax, [esi + 4]
// 004429eb  83c9ff               or ecx, 0xffffffff
// 004429ee  f00fc108             lock xadd dword ptr [eax], ecx
// 004429f2  751e                 jne 0x442a12
// 004429f4  8b16                 mov edx, dword ptr [esi]
// 004429f6  8b4204               mov eax, dword ptr [edx + 4]
// 004429f9  8bce                 mov ecx, esi
// 004429fb  ffd0                 call eax
// 004429fd  8d4e08               lea ecx, [esi + 8]
// 00442a00  83caff               or edx, 0xffffffff
// 00442a03  f00fc111             lock xadd dword ptr [ecx], edx
// 00442a07  7509                 jne 0x442a12
// 00442a09  8b06                 mov eax, dword ptr [esi]
// 00442a0b  8b5008               mov edx, dword ptr [eax + 8]
// 00442a0e  8bce                 mov ecx, esi
// 00442a10  ffd2                 call edx
// 00442a12  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00442a16  5e                   pop esi
// 00442a17  64890d00000000       mov dword ptr fs:[0], ecx
// 00442a1e  83c418               add esp, 0x18
// 00442a21  c21000               ret 0x10

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Object {
    void* get();
};

struct Shared {
    Object* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Guard {
    char storage[12];
    Guard(Object*);
    ~Guard();
};

struct Grid {
    void set(void*);
};

struct CDataModelPropGrid {
    void f(Shared, Shared);
};

void CDataModelPropGrid::f(Shared value, Shared other)
{
    Object*& current =
        *reinterpret_cast<Object**>(reinterpret_cast<char*>(this) - 0xac);

    if (current) {
        Guard guard(current);
        reinterpret_cast<Grid*>(reinterpret_cast<char*>(this) - 0x244)->set(0);
    }

    current = value.object;
    if (current) {
        Guard guard(current);
        reinterpret_cast<Grid*>(reinterpret_cast<char*>(this) - 0x244)->set(
            current ? current->get() : 0);
    }
}
