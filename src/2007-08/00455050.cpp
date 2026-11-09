// from server: 79% by EspClaude
// roc-cl: 50727
// from server: 100% by colin
// roc 2008-06 004581a0  unit: CRobloxReportView::CStatsItemRecord  size: 335 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004581a0
//
// 004581a0  6aff                 push -1
// 004581a2  68ea267c00           push 0x7c26ea
// 004581a7  64a100000000         mov eax, dword ptr fs:[0]
// 004581ad  50                   push eax
// 004581ae  64892500000000       mov dword ptr fs:[0], esp
// 004581b5  83ec10               sub esp, 0x10
// 004581b8  56                   push esi
// 004581b9  57                   push edi
// 004581ba  8bf9                 mov edi, ecx
// 004581bc  8d44242c             lea eax, [esp + 0x2c]
// 004581c0  50                   push eax
// 004581c1  8d4c2414             lea ecx, [esp + 0x14]
// 004581c5  51                   push ecx
// 004581c6  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004581ce  e80dedffff           call 0x456ee0
// 004581d3  83c408               add esp, 8
// 004581d6  837c241000           cmp dword ptr [esp + 0x10], 0
// 004581db  c644242001           mov byte ptr [esp + 0x20], 1
// 004581e0  0f8485000000         je 0x45826b
// 004581e6  68b0000000           push 0xb0
// 004581eb  e800002700           call 0x6c81f0
// 004581f0  89442408             mov dword ptr [esp + 8], eax
// 004581f4  c644242002           mov byte ptr [esp + 0x20], 2
// 004581f9  85c0                 test eax, eax
// 004581fb  7457                 je 0x458254
// 004581fd  8b5748               mov edx, dword ptr [edi + 0x48]
// 00458200  83ec08               sub esp, 8
// 00458203  8bf4                 mov esi, esp
// 00458205  8916                 mov dword ptr [esi], edx
// 00458207  8b574c               mov edx, dword ptr [edi + 0x4c]
// 0045820a  89642414             mov dword ptr [esp + 0x14], esp
// 0045820e  895604               mov dword ptr [esi + 4], edx
// 00458211  85d2                 test edx, edx
// 00458213  740c                 je 0x458221
// 00458215  83c204               add edx, 4
// 00458218  b901000000           mov ecx, 1
// 0045821d  f00fc10a             lock xadd dword ptr [edx], ecx
// 00458221  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00458225  83ec08               sub esp, 8
// 00458228  8bd4                 mov edx, esp
// 0045822a  890a                 mov dword ptr [edx], ecx
// 0045822c  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00458230  894a04               mov dword ptr [edx + 4], ecx
// 00458233  8b542424             mov edx, dword ptr [esp + 0x24]
// 00458237  8964241c             mov dword ptr [esp + 0x1c], esp
// 0045823b  85d2                 test edx, edx
// 0045823d  740c                 je 0x45824b
// 0045823f  83c204               add edx, 4
// 00458242  b901000000           mov ecx, 1
// 00458247  f00fc10a             lock xadd dword ptr [edx], ecx
// 0045824b  8bc8                 mov ecx, eax
// 0045824d  e84efaffff           call 0x457ca0
// 00458252  eb02                 jmp 0x458256
// 00458254  33c0                 xor eax, eax
// 00458256  50                   push eax
// 00458257  8d4fac               lea ecx, [edi - 0x54]
// 0045825a  c644242401           mov byte ptr [esp + 0x24], 1
// 0045825f  e81cff2700           call 0x6d8180
// 00458264  8bc8                 mov ecx, eax
// 00458266  e835fa2700           call 0x6d7ca0
// 0045826b  8b742414             mov esi, dword ptr [esp + 0x14]
// 0045826f  c644242000           mov byte ptr [esp + 0x20], 0
// 00458274  85f6                 test esi, esi
// 00458276  742a                 je 0x4582a2
// 00458278  8d5604               lea edx, [esi + 4]
// 0045827b  83c8ff               or eax, 0xffffffff
// 0045827e  f00fc102             lock xadd dword ptr [edx], eax
// 00458282  751e                 jne 0x4582a2
// 00458284  8b16                 mov edx, dword ptr [esi]
// 00458286  8b4204               mov eax, dword ptr [edx + 4]
// 00458289  8bce                 mov ecx, esi
// 0045828b  ffd0                 call eax
// 0045828d  8d4e08               lea ecx, [esi + 8]
// 00458290  83caff               or edx, 0xffffffff
// 00458293  f00fc111             lock xadd dword ptr [ecx], edx
// 00458297  7509                 jne 0x4582a2
// 00458299  8b06                 mov eax, dword ptr [esi]
// 0045829b  8b5008               mov edx, dword ptr [eax + 8]
// 0045829e  8bce                 mov ecx, esi
// 004582a0  ffd2                 call edx
// 004582a2  8b742430             mov esi, dword ptr [esp + 0x30]
// 004582a6  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 004582ae  85f6                 test esi, esi
// 004582b0  742a                 je 0x4582dc
// 004582b2  8d4604               lea eax, [esi + 4]
// 004582b5  83c9ff               or ecx, 0xffffffff
// 004582b8  f00fc108             lock xadd dword ptr [eax], ecx
// 004582bc  751e                 jne 0x4582dc
// 004582be  8b16                 mov edx, dword ptr [esi]
// 004582c0  8b4204               mov eax, dword ptr [edx + 4]
// 004582c3  8bce                 mov ecx, esi
// 004582c5  ffd0                 call eax
// 004582c7  8d4e08               lea ecx, [esi + 8]
// 004582ca  83caff               or edx, 0xffffffff
// 004582cd  f00fc111             lock xadd dword ptr [ecx], edx
// 004582d1  7509                 jne 0x4582dc
// 004582d3  8b06                 mov eax, dword ptr [esi]
// 004582d5  8b5008               mov edx, dword ptr [eax + 8]
// 004582d8  8bce                 mov ecx, esi
// 004582da  ffd2                 call edx
// 004582dc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004582e0  5f                   pop edi
// 004582e1  64890d00000000       mov dword ptr fs:[0], ecx
// 004582e8  5e                   pop esi
// 004582e9  83c41c               add esp, 0x1c
// 004582ec  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedIncrement(count);
    }
}

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

Shared __cdecl convert(const Shared&);

struct Item {
    char storage[0xb0];

    static void* __stdcall operator new(unsigned int);
    static void __stdcall operator delete(void*);
    Item(Shared, Shared);
};

struct Records {
    void update();
};

struct Owner {
    Records* insert(Item*);
};

struct S {
    char padding[0x48];
    Shared member;

    void f(unsigned int, Shared);
};

void S::f(unsigned int, Shared argument)
{
    Shared value = convert(argument);
    if (value.object) {
        Item* item = new Item(value, member);
        reinterpret_cast<Owner*>(reinterpret_cast<char*>(this) - 0x54)
            ->insert(item)->update();
    }
}
