// from server: 100% by colin
// from server: 99% by king_originala
// roc 2008-06 0063a920  unit: RBX::VBrickColor::V?$Value::?$FactoryProduct::Creator  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063a920
//
// 0063a920  64a100000000         mov eax, dword ptr fs:[0]
// 0063a926  6aff                 push -1
// 0063a928  6868917d00           push 0x7d9168
// 0063a92d  50                   push eax
// 0063a92e  8b442410             mov eax, dword ptr [esp + 0x10]
// 0063a932  64892500000000       mov dword ptr fs:[0], esp
// 0063a939  83ec08               sub esp, 8
// 0063a93c  56                   push esi
// 0063a93d  8bf1                 mov esi, ecx
// 0063a93f  8b8e30010000         mov ecx, dword ptr [esi + 0x130]
// 0063a945  57                   push edi
// 0063a946  3bc8                 cmp ecx, eax
// 0063a948  0f84ad000000         je 0x63a9fb
// 0063a94e  50                   push eax
// 0063a94f  8d44240c             lea eax, [esp + 0xc]
// 0063a953  50                   push eax
// 0063a954  e8e7e0fdff           call 0x618a40
// 0063a959  83c408               add esp, 8
// 0063a95c  8b08                 mov ecx, dword ptr [eax]
// 0063a95e  83c004               add eax, 4
// 0063a961  898e30010000         mov dword ptr [esi + 0x130], ecx
// 0063a967  50                   push eax
// 0063a968  8d8e34010000         lea ecx, [esi + 0x134]
// 0063a96e  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0063a976  e8357cdcff           call 0x4025b0
// 0063a97b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0063a97f  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0063a987  85c0                 test eax, eax
// 0063a989  742c                 je 0x63a9b7
// 0063a98b  8bf8                 mov edi, eax
// 0063a98d  83c004               add eax, 4
// 0063a990  83caff               or edx, 0xffffffff
// 0063a993  f00fc110             lock xadd dword ptr [eax], edx
// 0063a997  751e                 jne 0x63a9b7
// 0063a999  8b07                 mov eax, dword ptr [edi]
// 0063a99b  8b5004               mov edx, dword ptr [eax + 4]
// 0063a99e  8bcf                 mov ecx, edi
// 0063a9a0  ffd2                 call edx
// 0063a9a2  8d4708               lea eax, [edi + 8]
// 0063a9a5  83c9ff               or ecx, 0xffffffff
// 0063a9a8  f00fc108             lock xadd dword ptr [eax], ecx
// 0063a9ac  7509                 jne 0x63a9b7
// 0063a9ae  8b17                 mov edx, dword ptr [edi]
// 0063a9b0  8b4208               mov eax, dword ptr [edx + 8]
// 0063a9b3  8bcf                 mov ecx, edi
// 0063a9b5  ffd0                 call eax
// 0063a9b7  6864d39700           push 0x97d364
// 0063a9bc  8bce                 mov ecx, esi
// 0063a9be  e83d31ddff           call 0x40db00
// 0063a9c3  8b9630010000         mov edx, dword ptr [esi + 0x130]
// 0063a9c9  83ec08               sub esp, 8
// 0063a9cc  8bc4                 mov eax, esp
// 0063a9ce  8910                 mov dword ptr [eax], edx
// 0063a9d0  8d4e14               lea ecx, [esi + 0x14]
// 0063a9d3  8bb634010000         mov esi, dword ptr [esi + 0x134]
// 0063a9d9  89642428             mov dword ptr [esp + 0x28], esp
// 0063a9dd  897004               mov dword ptr [eax + 4], esi
// 0063a9e0  85f6                 test esi, esi
// 0063a9e2  740c                 je 0x63a9f0
// 0063a9e4  83c604               add esi, 4
// 0063a9e7  b801000000           mov eax, 1
// 0063a9ec  f00fc106             lock xadd dword ptr [esi], eax
// 0063a9f0  51                   push ecx
// 0063a9f1  b930d39700           mov ecx, 0x97d330
// 0063a9f6  e80528e6ff           call 0x49d200
// 0063a9fb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063a9ff  5f                   pop edi
// 0063aa00  64890d00000000       mov dword ptr fs:[0], ecx
// 0063aa07  5e                   pop esi
// 0063aa08  83c414               add esp, 0x14
// 0063aa0b  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct CountPtr {
    Control* p;
    CountPtr(const CountPtr&);
    ~CountPtr();
    CountPtr& operator=(const CountPtr&);
};

__forceinline CountPtr::CountPtr(const CountPtr& other) : p(other.p) {
    if (p)
        _InterlockedIncrement(&p->strong);
}

__forceinline CountPtr::~CountPtr() {
    if (p) {
        Control* q = p;
        if (_InterlockedDecrement(&q->strong) == 0) {
            q->dispose();
            if (_InterlockedDecrement(&q->weak) == 0)
                q->destroy();
        }
    }
}

struct Value {
    int value;
    CountPtr count;
};

extern Value __cdecl makeValue(int);

struct Descriptor {
    void emit(void*, Value);
};

extern Descriptor changedDescriptor;
extern char propertyDescriptor;

struct S {
    char prefix[0x130];
    Value current;
    void notify(const void*);
    void set(int);
};

void S::set(int value) {
    int old = current.value;
    if (old != value) {
        current = makeValue(value);
        notify(&propertyDescriptor);
        void* object = prefix + 0x14;
        changedDescriptor.emit(object, current);
    }
}
