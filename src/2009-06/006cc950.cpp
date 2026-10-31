// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00640360  unit: RBX::GameTool  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00640360
//
// 00640360  6aff                 push -1
// 00640362  683beb7d00           push 0x7deb3b
// 00640367  64a100000000         mov eax, dword ptr fs:[0]
// 0064036d  50                   push eax
// 0064036e  64892500000000       mov dword ptr fs:[0], esp
// 00640375  83ec10               sub esp, 0x10
// 00640378  d9ee                 fldz 
// 0064037a  55                   push ebp
// 0064037b  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0064037f  d9542408             fst dword ptr [esp + 8]
// 00640383  56                   push esi
// 00640384  d9542410             fst dword ptr [esp + 0x10]
// 00640388  57                   push edi
// 00640389  d95c2418             fstp dword ptr [esp + 0x18]
// 0064038d  8d442410             lea eax, [esp + 0x10]
// 00640391  50                   push eax
// 00640392  55                   push ebp
// 00640393  8bf9                 mov edi, ecx
// 00640395  e8665cfdff           call 0x616000
// 0064039a  8bf0                 mov esi, eax
// 0064039c  85f6                 test esi, esi
// 0064039e  0f8493000000         je 0x640437
// 006403a4  80bef001000000       cmp byte ptr [esi + 0x1f0], 0
// 006403ab  0f8586000000         jne 0x640437
// 006403b1  8bce                 mov ecx, esi
// 006403b3  e87891f5ff           call 0x599530
// 006403b8  84c0                 test al, al
// 006403ba  757b                 jne 0x640437
// 006403bc  8d4c2410             lea ecx, [esp + 0x10]
// 006403c0  51                   push ecx
// 006403c1  8bcf                 mov ecx, edi
// 006403c3  e8b854fdff           call 0x615880
// 006403c8  84c0                 test al, al
// 006403ca  746b                 je 0x640437
// 006403cc  6a44                 push 0x44
// 006403ce  e84d050600           call 0x6a0920
// 006403d3  83c404               add esp, 4
// 006403d6  8944242c             mov dword ptr [esp + 0x2c], eax
// 006403da  c744242400000000     mov dword ptr [esp + 0x24], 0
// 006403e2  85c0                 test eax, eax
// 006403e4  7429                 je 0x64040f
// 006403e6  83ec08               sub esp, 8
// 006403e9  8bd4                 mov edx, esp
// 006403eb  c70200000000         mov dword ptr [edx], 0
// 006403f1  89642414             mov dword ptr [esp + 0x14], esp
// 006403f5  c7420400000000       mov dword ptr [edx + 4], 0
// 006403fc  8b5718               mov edx, dword ptr [edi + 0x18]
// 006403ff  52                   push edx
// 00640400  8d4c241c             lea ecx, [esp + 0x1c]
// 00640404  51                   push ecx
// 00640405  56                   push esi
// 00640406  8bc8                 mov ecx, eax
// 00640408  e8135b0200           call 0x665f20
// 0064040d  eb02                 jmp 0x640411
// 0064040f  33c0                 xor eax, eax
// 00640411  8b10                 mov edx, dword ptr [eax]
// 00640413  8bc8                 mov ecx, eax
// 00640415  8b4204               mov eax, dword ptr [edx + 4]
// 00640418  55                   push ebp
// 00640419  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00640421  ffd0                 call eax
// 00640423  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00640427  64890d00000000       mov dword ptr fs:[0], ecx
// 0064042e  5f                   pop edi
// 0064042f  5e                   pop esi
// 00640430  5d                   pop ebp
// 00640431  83c41c               add esp, 0x1c
// 00640434  c20400               ret 4
// 00640437  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0064043b  5f                   pop edi
// 0064043c  5e                   pop esi
// 0064043d  33c0                 xor eax, eax
// 0064043f  64890d00000000       mov dword ptr fs:[0], ecx
// 00640446  5d                   pop ebp
// 00640447  83c41c               add esp, 0x1c
// 0064044a  c20400               ret 4

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Edge;

struct Geometry {
    char padding[0x1F0];
    bool flag;
    Edge* getFirst();
};

struct Vector {
    float x, y, z;
};

struct Control {
    void addRef();
    void release();
};

struct Count {
    Control* pointer;

    Count() : pointer(0) {}

    Count(const Count& other) : pointer(other.pointer)
    {
        if (pointer)
            pointer->addRef();
    }

    ~Count()
    {
        if (pointer)
            pointer->release();
    }
};

struct Pair {
    void* first;
    Count second;

    Pair() : first(0), second() {}
};

struct Action {
    virtual void slot0();
    virtual int invoke(void*);
    char padding[0x40];

    Action(Geometry*, const Vector&, void*, Pair);
};

struct S {
    char padding[0x18];
    void* context;

    int find(void*, Vector*);
    bool check(Vector*);
    int invoke(void*);
};

int S::invoke(void* argument)
{
    Vector position = { 0.0f, 0.0f, 0.0f };
    Geometry* geometry = reinterpret_cast<Geometry*>(find(argument, &position));

    if (!geometry || geometry->flag ||
        static_cast<unsigned char>(
            reinterpret_cast<unsigned int>(geometry->getFirst())) ||
        !check(&position))
        return 0;

    Action* action = new Action(geometry, position, context, Pair());
    return action->invoke(argument);
}
