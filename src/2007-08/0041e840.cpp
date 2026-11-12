// from server: 100% by EspClaude
// from server: 44% by colin
// roc 2007-08 0041e840  unit: RBX::VInstance::?$MarshaledListener  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041e840
//
// 0041e840  51                   push ecx
// 0041e841  56                   push esi
// 0041e842  57                   push edi
// 0041e843  6a20                 push 0x20
// 0041e845  8bf9                 mov edi, ecx
// 0041e847  e8aa162100           call 0x62fef6
// 0041e84c  83c404               add esp, 4
// 0041e84f  85c0                 test eax, eax
// 0041e851  745d                 je 0x41e8b0
// 0041e853  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0041e857  83ec10               sub esp, 0x10
// 0041e85a  8bd4                 mov edx, esp
// 0041e85c  890a                 mov dword ptr [edx], ecx
// 0041e85e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0041e862  894a04               mov dword ptr [edx + 4], ecx
// 0041e865  8b742428             mov esi, dword ptr [esp + 0x28]
// 0041e869  85f6                 test esi, esi
// 0041e86b  89642418             mov dword ptr [esp + 0x18], esp
// 0041e86f  740c                 je 0x41e87d
// 0041e871  83c604               add esi, 4
// 0041e874  b901000000           mov ecx, 1
// 0041e879  f00fc10e             lock xadd dword ptr [esi], ecx
// 0041e87d  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0041e881  894a08               mov dword ptr [edx + 8], ecx
// 0041e884  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0041e888  894a0c               mov dword ptr [edx + 0xc], ecx
// 0041e88b  8b542430             mov edx, dword ptr [esp + 0x30]
// 0041e88f  85d2                 test edx, edx
// 0041e891  740c                 je 0x41e89f
// 0041e893  83c204               add edx, 4
// 0041e896  b901000000           mov ecx, 1
// 0041e89b  f00fc10a             lock xadd dword ptr [edx], ecx
// 0041e89f  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041e8a3  52                   push edx
// 0041e8a4  57                   push edi
// 0041e8a5  8bc8                 mov ecx, eax
// 0041e8a7  e844fcffff           call 0x41e4f0
// 0041e8ac  8bf0                 mov esi, eax
// 0041e8ae  eb02                 jmp 0x41e8b2
// 0041e8b0  33f6                 xor esi, esi
// 0041e8b2  8d442410             lea eax, [esp + 0x10]
// 0041e8b6  50                   push eax
// 0041e8b7  8d4f04               lea ecx, [edi + 4]
// 0041e8ba  89742414             mov dword ptr [esp + 0x14], esi
// 0041e8be  e8fd650400           call 0x464ec0
// 0041e8c3  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0041e8c6  56                   push esi
// 0041e8c7  e874480100           call 0x433140
// 0041e8cc  8d4c2414             lea ecx, [esp + 0x14]
// 0041e8d0  e82bf1ffff           call 0x41da00
// 0041e8d5  5f                   pop edi
// 0041e8d6  5e                   pop esi
// 0041e8d7  59                   pop ecx
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

void* __cdecl operator new(unsigned int) throw();

struct RefCount {
    long reserved;
    volatile long count;

    void addRef() throw();
};

__forceinline void RefCount::addRef() throw()
{
    volatile long* p = &count;
    _ReadWriteBarrier();
    _InterlockedExchangeAdd(p, 1);
}

struct Bundle {
    void* first;
    RefCount* firstCount;
    void* second;
    RefCount* secondCount;

    Bundle(const Bundle& other) throw();
    ~Bundle() throw();
};

__forceinline Bundle::Bundle(const Bundle& other) throw()
{
    first = other.first;
    firstCount = other.firstCount;
    if (firstCount)
        firstCount->addRef();

    second = other.second;
    secondCount = other.secondCount;
    if (secondCount)
        secondCount->addRef();
}

struct Listener;

struct Node {
    char storage[32];
    Node(Listener* owner, int arg, Bundle value) throw();
};

struct Queue {
    char storage[20];
    void append(int* value) throw();
};

struct Messenger {
    void method(int arg) throw();
};

struct Listener {
    int reserved;
    Queue queue;
    Messenger* messenger;

    void method(int arg, Bundle value) throw();
};

void Listener::method(int arg, Bundle value) throw()
{
    int node = reinterpret_cast<int>(new Node(this, arg, value));
    arg = node;
    queue.append(&arg);
    messenger->method(node);
}
