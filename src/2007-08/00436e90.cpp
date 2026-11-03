// from server: 95% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00435eb0  unit: CClassTreeView  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00435eb0
//
// 00435eb0  6aff                 push -1
// 00435eb2  6838017c00           push 0x7c0138
// 00435eb7  64a100000000         mov eax, dword ptr fs:[0]
// 00435ebd  50                   push eax
// 00435ebe  64892500000000       mov dword ptr fs:[0], esp
// 00435ec5  83ec34               sub esp, 0x34
// 00435ec8  53                   push ebx
// 00435ec9  55                   push ebp
// 00435eca  56                   push esi
// 00435ecb  57                   push edi
// 00435ecc  8bf1                 mov esi, ecx
// 00435ece  e8efad2600           call 0x6a0cc2
// 00435ed3  e888d9ffff           call 0x433860
// 00435ed8  8bf8                 mov edi, eax
// 00435eda  8bcf                 mov ecx, edi
// 00435edc  897c2410             mov dword ptr [esp + 0x10], edi
// 00435ee0  e8abd11200           call 0x563090
// 00435ee5  c644241401           mov byte ptr [esp + 0x14], 1
// 00435eea  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 00435ef2  e8294efdff           call 0x40ad20
// 00435ef7  50                   push eax
// 00435ef8  8bce                 mov ecx, esi
// 00435efa  e8f1f0ffff           call 0x434ff0
// 00435eff  b8003d4300           mov eax, 0x433d00
// 00435f04  8be8                 mov ebp, eax
// 00435f06  8d442418             lea eax, [esp + 0x18]
// 00435f0a  33c9                 xor ecx, ecx
// 00435f0c  50                   push eax
// 00435f0d  894c243c             mov dword ptr [esp + 0x3c], ecx
// 00435f11  e80a611300           call 0x56c020
// 00435f16  8d4c2424             lea ecx, [esp + 0x24]
// 00435f1a  51                   push ecx
// 00435f1b  8bd8                 mov ebx, eax
// 00435f1d  e8ce601300           call 0x56bff0
// 00435f22  8b542440             mov edx, dword ptr [esp + 0x40]
// 00435f26  83ec08               sub esp, 8
// 00435f29  8bcc                 mov ecx, esp
// 00435f2b  8929                 mov dword ptr [ecx], ebp
// 00435f2d  895104               mov dword ptr [ecx + 4], edx
// 00435f30  8b542450             mov edx, dword ptr [esp + 0x50]
// 00435f34  897108               mov dword ptr [ecx + 8], esi
// 00435f37  89510c               mov dword ptr [ecx + 0xc], edx
// 00435f3a  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00435f3d  8b13                 mov edx, dword ptr [ebx]
// 00435f3f  51                   push ecx
// 00435f40  8b4804               mov ecx, dword ptr [eax + 4]
// 00435f43  52                   push edx
// 00435f44  8b10                 mov edx, dword ptr [eax]
// 00435f46  51                   push ecx
// 00435f47  52                   push edx
// 00435f48  8d442454             lea eax, [esp + 0x54]
// 00435f4c  50                   push eax
// 00435f4d  e87eefffff           call 0x434ed0
// 00435f52  8b5620               mov edx, dword ptr [esi + 0x20]
// 00435f55  83c424               add esp, 0x24
// 00435f58  8d4c2428             lea ecx, [esp + 0x28]
// 00435f5c  51                   push ecx
// 00435f5d  6a00                 push 0
// 00435f5f  6815110000           push 0x1115
// 00435f64  52                   push edx
// 00435f65  c74424380000ffff     mov dword ptr [esp + 0x38], 0xffff0000
// 00435f6d  c744243cd0354300     mov dword ptr [esp + 0x3c], 0x4335d0
// 00435f75  ff15142e8000         call dword ptr [0x802e14]
// 00435f7b  8bcf                 mov ecx, edi
// 00435f7d  c744244cffffffff     mov dword ptr [esp + 0x4c], 0xffffffff
// 00435f85  e856d11200           call 0x5630e0
// 00435f8a  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00435f8e  5f                   pop edi
// 00435f8f  5e                   pop esi
// 00435f90  5d                   pop ebp
// 00435f91  64890d00000000       mov dword ptr fs:[0], ecx
// 00435f98  5b                   pop ebx
// 00435f99  83c440               add esp, 0x40
// 00435f9c  c3                   ret 

extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);

struct Mutex
{
    void lock();
    void unlock();
};

Mutex* __cdecl getMutex();
void* __cdecl getDescriptor();

struct Lock
{
    Mutex* mutex;
    bool locked;

    Lock(Mutex*);
    ~Lock();
};

inline Lock::Lock(Mutex* p) : mutex(p)
{
    mutex->lock();
    locked = true;
}

inline Lock::~Lock()
{
    mutex->unlock();
}

struct Iterator
{
    unsigned int first;
    unsigned int second;
};

Iterator* __cdecl getEnd(Iterator*);
Iterator* __cdecl getBegin(Iterator*);

struct __multiple_inheritance CClassTreeView;
typedef void (CClassTreeView::*VisitFunction)(void*);

struct Function
{
    VisitFunction callback;
    CClassTreeView* object;
    int extra;
};

Function __cdecl visitRange(Iterator, Iterator, Function);
int __stdcall compareItems(long, long, long);

struct SortInfo
{
    void* parent;
    int (__stdcall *compare)(long, long, long);
    long parameter;
};

struct BaseFirst
{
    char storage[0x10];
};

struct BaseSecond
{
    char storage[0x10];
};

struct CClassTreeView : BaseFirst, BaseSecond
{
    void* window;

    void baseInitialize();
    void populate(void*);
    void visitItem(void*);
    void initialize();
};

void CClassTreeView::initialize()
{
    baseInitialize();
    Lock lock(getMutex());
    populate(getDescriptor());

    Function function;
    function.callback = &CClassTreeView::visitItem;
    function.object = this;

    Iterator endStorage;
    Iterator beginStorage;
    Iterator* end = getEnd(&endStorage);
    Iterator* begin = getBegin(&beginStorage);
    visitRange(*begin, *end, function);

    SortInfo sort;
    sort.parent = (void*)0xffff0000;
    sort.compare = compareItems;
    SendMessageA(window, 0x1115, 0, (long)&sort);
}
