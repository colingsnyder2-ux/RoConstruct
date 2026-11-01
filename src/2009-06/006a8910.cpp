// from server: 95% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005fb650  unit: RBX::Kernel  size: 178 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fb650
//
// 005fb650  6aff                 push -1
// 005fb652  68997d7d00           push 0x7d7d99
// 005fb657  64a100000000         mov eax, dword ptr fs:[0]
// 005fb65d  50                   push eax
// 005fb65e  64892500000000       mov dword ptr fs:[0], esp
// 005fb665  51                   push ecx
// 005fb666  8b442414             mov eax, dword ptr [esp + 0x14]
// 005fb66a  53                   push ebx
// 005fb66b  56                   push esi
// 005fb66c  8bf1                 mov esi, ecx
// 005fb66e  33db                 xor ebx, ebx
// 005fb670  89742408             mov dword ptr [esp + 8], esi
// 005fb674  894604               mov dword ptr [esi + 4], eax
// 005fb677  895e08               mov dword ptr [esi + 8], ebx
// 005fb67a  6a3c                 push 0x3c
// 005fb67c  895c2418             mov dword ptr [esp + 0x18], ebx
// 005fb680  c7065c108400         mov dword ptr [esi], 0x84105c
// 005fb686  885e0c               mov byte ptr [esi + 0xc], bl
// 005fb689  e892520a00           call 0x6a0920
// 005fb68e  83c404               add esp, 4
// 005fb691  8944241c             mov dword ptr [esp + 0x1c], eax
// 005fb695  c644241401           mov byte ptr [esp + 0x14], 1
// 005fb69a  3bc3                 cmp eax, ebx
// 005fb69c  7409                 je 0x5fb6a7
// 005fb69e  8bc8                 mov ecx, eax
// 005fb6a0  e84bffffff           call 0x5fb5f0
// 005fb6a5  eb02                 jmp 0x5fb6a9
// 005fb6a7  33c0                 xor eax, eax
// 005fb6a9  894610               mov dword ptr [esi + 0x10], eax
// 005fb6ac  895e18               mov dword ptr [esi + 0x18], ebx
// 005fb6af  895e1c               mov dword ptr [esi + 0x1c], ebx
// 005fb6b2  895e14               mov dword ptr [esi + 0x14], ebx
// 005fb6b5  6848c00000           push 0xc048
// 005fb6ba  c644241802           mov byte ptr [esp + 0x18], 2
// 005fb6bf  e85c520a00           call 0x6a0920
// 005fb6c4  83c404               add esp, 4
// 005fb6c7  8944241c             mov dword ptr [esp + 0x1c], eax
// 005fb6cb  c644241403           mov byte ptr [esp + 0x14], 3
// 005fb6d0  3bc3                 cmp eax, ebx
// 005fb6d2  740e                 je 0x5fb6e2
// 005fb6d4  68443f8300           push 0x833f44
// 005fb6d9  8bc8                 mov ecx, eax
// 005fb6db  e8c08cfcff           call 0x5c43a0
// 005fb6e0  eb02                 jmp 0x5fb6e4
// 005fb6e2  33c0                 xor eax, eax
// 005fb6e4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005fb6e8  894620               mov dword ptr [esi + 0x20], eax
// 005fb6eb  ff05b8b59700         inc dword ptr [0x97b5b8]
// 005fb6f1  8bc6                 mov eax, esi
// 005fb6f3  5e                   pop esi
// 005fb6f4  5b                   pop ebx
// 005fb6f5  64890d00000000       mov dword ptr fs:[0], ecx
// 005fb6fc  83c410               add esp, 0x10
// 005fb6ff  c20400               ret 4

typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern const char itemName[];
extern int kernelCount;

struct Base {
    void* owner;
    int value;

    Base(void*);
    virtual ~Base();
};

inline Base::Base(void* p) : owner(p), value(0) {}

struct Small {
    char storage[0x3c];
    Small();
};

struct Large {
    char storage[0xc048];
    Large(const char*);
};

struct Storage {
    void* first;
    void* last;
    void* end;

    Storage();
    ~Storage();
};

inline Storage::Storage()
{
    last = 0;
    end = 0;
    first = 0;
}

struct Kernel : Base {
    bool enabled;
    Small* small;
    Storage storage;
    Large* large;

    Kernel(void*);
    virtual ~Kernel();
};

Kernel::Kernel(void* p)
    : Base(p),
      enabled(false),
      small(new Small),
      storage(),
      large(new Large(itemName))
{
    ++kernelCount;
}
