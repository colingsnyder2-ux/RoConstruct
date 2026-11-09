// from server: 100% by colin
// from server: 99% by colin
// roc 2008-06 00596f90  unit: RBX::worker_thread::Udata::?$sp_counted_impl_p  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00596f90
//
// 00596f90  6aff                 push -1
// 00596f92  6859237d00           push 0x7d2359
// 00596f97  64a100000000         mov eax, dword ptr fs:[0]
// 00596f9d  50                   push eax
// 00596f9e  64892500000000       mov dword ptr fs:[0], esp
// 00596fa5  83ec08               sub esp, 8
// 00596fa8  57                   push edi
// 00596fa9  8bf9                 mov edi, ecx
// 00596fab  8d44241c             lea eax, [esp + 0x1c]
// 00596faf  50                   push eax
// 00596fb0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00596fb8  c70700000000         mov dword ptr [edi], 0
// 00596fbe  e82d330700           call 0x60a2f0
// 00596fc3  83c404               add esp, 4
// 00596fc6  84c0                 test al, al
// 00596fc8  753d                 jne 0x597007
// 00596fca  56                   push esi
// 00596fcb  6a30                 push 0x30
// 00596fcd  e84e991000           call 0x6a0920
// 00596fd2  8bf0                 mov esi, eax
// 00596fd4  83c404               add esp, 4
// 00596fd7  89742408             mov dword ptr [esp + 8], esi
// 00596fdb  8974240c             mov dword ptr [esp + 0xc], esi
// 00596fdf  c644241801           mov byte ptr [esp + 0x18], 1
// 00596fe4  85f6                 test esi, esi
// 00596fe6  7413                 je 0x596ffb
// 00596fe8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00596fec  8d542428             lea edx, [esp + 0x28]
// 00596ff0  890e                 mov dword ptr [esi], ecx
// 00596ff2  8d4e08               lea ecx, [esi + 8]
// 00596ff5  52                   push edx
// 00596ff6  e895efffff           call 0x595f90
// 00596ffb  897708               mov dword ptr [edi + 8], esi
// 00596ffe  c70750238300         mov dword ptr [edi], 0x832350
// 00597004  5e                   pop esi
// 00597005  eb06                 jmp 0x59700d
// 00597007  c70700000000         mov dword ptr [edi], 0
// 0059700d  8d4c2424             lea ecx, [esp + 0x24]
// 00597011  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00597019  e8f286f0ff           call 0x49f710
// 0059701e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00597022  8bc7                 mov eax, edi
// 00597024  5f                   pop edi
// 00597025  64890d00000000       mov dword ptr fs:[0], ecx
// 0059702c  83c414               add esp, 0x14
// 0059702f  c23400               ret 0x34

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

__forceinline void* __cdecl operator new(size_t, void* p)
{
    return p;
}

inline void __cdecl operator delete(void* p, void*)
{
    operator delete(p);
}

struct Argument {
    char storage[44];
    ~Argument();
};

struct Stored {
    char storage[40];
    Stored(const Argument&);
};

struct Holder {
    Stored value;
    __forceinline Holder(const Argument& a) : value(a) {}
};

struct Block {
    void* pointer;
    unsigned int padding;
    Holder value;

    Block(void*, const Argument&);
};

__forceinline Block::Block(void* p, const Argument& a)
    : pointer(p), value(a)
{
}

extern bool __cdecl func_0060a2f0(void**);
extern unsigned char manager;

struct S {
    void* table;
    unsigned int padding;
    Block* object;

    S(void*, unsigned int, Argument);
};

S::S(void* p, unsigned int, Argument a)
{
    table = 0;
    if (!func_0060a2f0(&p)) {
        Block* storage = static_cast<Block*>(operator new(sizeof(Block)));
        new (storage) Block(p, a);
        object = storage;
        table = &manager;
    } else {
        table = 0;
    }
}
