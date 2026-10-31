// from server: 87% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0063b9d0  unit: RBX::P8DebrisService::?$GetSetImpl  size: 253 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063b9d0
//
// 0063b9d0  83ec0c               sub esp, 0xc
// 0063b9d3  53                   push ebx
// 0063b9d4  56                   push esi
// 0063b9d5  8bf1                 mov esi, ecx
// 0063b9d7  8b864c010000         mov eax, dword ptr [esi + 0x14c]
// 0063b9dd  3b8650010000         cmp eax, dword ptr [esi + 0x150]
// 0063b9e3  57                   push edi
// 0063b9e4  0f8edc000000         jle 0x63bac6
// 0063b9ea  33db                 xor ebx, ebx
// 0063b9ec  8d642400             lea esp, [esp]
// 0063b9f0  8bbe48010000         mov edi, dword ptr [esi + 0x148]
// 0063b9f6  8b8e4c010000         mov ecx, dword ptr [esi + 0x14c]
// 0063b9fc  03cf                 add ecx, edi
// 0063b9fe  3bf9                 cmp edi, ecx
// 0063ba00  7606                 jbe 0x63ba08
// 0063ba02  ff1590288000         call dword ptr [0x802890]
// 0063ba08  8b9630010000         mov edx, dword ptr [esi + 0x130]
// 0063ba0e  8d4c2410             lea ecx, [esp + 0x10]
// 0063ba12  89542410             mov dword ptr [esp + 0x10], edx
// 0063ba16  897c2414             mov dword ptr [esp + 0x14], edi
// 0063ba1a  e8e1f9ffff           call 0x63b400
// 0063ba1f  8b10                 mov edx, dword ptr [eax]
// 0063ba21  83ec08               sub esp, 8
// 0063ba24  8bcc                 mov ecx, esp
// 0063ba26  8911                 mov dword ptr [ecx], edx
// 0063ba28  8b4004               mov eax, dword ptr [eax + 4]
// 0063ba2b  89642414             mov dword ptr [esp + 0x14], esp
// 0063ba2f  894104               mov dword ptr [ecx + 4], eax
// 0063ba32  3bc3                 cmp eax, ebx
// 0063ba34  740c                 je 0x63ba42
// 0063ba36  83c008               add eax, 8
// 0063ba39  b901000000           mov ecx, 1
// 0063ba3e  f00fc108             lock xadd dword ptr [eax], ecx
// 0063ba42  e879fbffff           call 0x63b5c0
// 0063ba47  83c408               add esp, 8
// 0063ba4a  399e4c010000         cmp dword ptr [esi + 0x14c], ebx
// 0063ba50  7462                 je 0x63bab4
// 0063ba52  8b8648010000         mov eax, dword ptr [esi + 0x148]
// 0063ba58  8b8e40010000         mov ecx, dword ptr [esi + 0x140]
// 0063ba5e  8bd0                 mov edx, eax
// 0063ba60  d1ea                 shr edx, 1
// 0063ba62  8b1491               mov edx, dword ptr [ecx + edx*4]
// 0063ba65  83e001               and eax, 1
// 0063ba68  8b4cc204             mov ecx, dword ptr [edx + eax*8 + 4]
// 0063ba6c  8d44c204             lea eax, [edx + eax*8 + 4]
// 0063ba70  3bcb                 cmp ecx, ebx
// 0063ba72  7413                 je 0x63ba87
// 0063ba74  8d4108               lea eax, [ecx + 8]
// 0063ba77  83caff               or edx, 0xffffffff
// 0063ba7a  f00fc110             lock xadd dword ptr [eax], edx
// 0063ba7e  7507                 jne 0x63ba87
// 0063ba80  8b01                 mov eax, dword ptr [ecx]
// 0063ba82  8b5008               mov edx, dword ptr [eax + 8]
// 0063ba85  ffd2                 call edx
// 0063ba87  ff8648010000         inc dword ptr [esi + 0x148]
// 0063ba8d  8b8e44010000         mov ecx, dword ptr [esi + 0x144]
// 0063ba93  8b8648010000         mov eax, dword ptr [esi + 0x148]
// 0063ba99  03c9                 add ecx, ecx
// 0063ba9b  3bc8                 cmp ecx, eax
// 0063ba9d  7706                 ja 0x63baa5
// 0063ba9f  899e48010000         mov dword ptr [esi + 0x148], ebx
// 0063baa5  83864c010000ff       add dword ptr [esi + 0x14c], -1
// 0063baac  7506                 jne 0x63bab4
// 0063baae  899e48010000         mov dword ptr [esi + 0x148], ebx
// 0063bab4  8b964c010000         mov edx, dword ptr [esi + 0x14c]
// 0063baba  3b9650010000         cmp edx, dword ptr [esi + 0x150]
// 0063bac0  0f8f2affffff         jg 0x63b9f0
// 0063bac6  5f                   pop edi
// 0063bac7  5e                   pop esi
// 0063bac8  5b                   pop ebx
// 0063bac9  83c40c               add esp, 0xc
// 0063bacc  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Control {
    virtual void first() = 0;
    virtual void second() = 0;
    virtual void dispose() = 0;
    long other;
    volatile long references;

    void addRef();
    void release();
};

inline void Control::addRef() {
    _InterlockedIncrement(&references);
}

inline void Control::release() {
    if (_InterlockedDecrement(&references) == 0)
        dispose();
}

struct Count {
    Control* control;

    Count(const Count& value);
    ~Count();
};

inline Count::Count(const Count& value) : control(value.control) {
    if (control)
        control->addRef();
}

inline Count::~Count() {
    if (control)
        control->release();
}

struct Shared {
    void* object;
    Count count;

    Shared(const Shared& value);
    ~Shared();
};

inline Shared::Shared(const Shared& value)
    : object(value.object), count(value.count) {
}

inline Shared::~Shared() {
}

struct Iterator {
    void* owner;
    unsigned int offset;
    Shared& get();
};

extern void __cdecl removeObject(Shared value);

struct S {
    unsigned char padding[0x130];
    void* owner;
    unsigned char unused[12];
    Shared** map;
    unsigned int mapSize;
    unsigned int offset;
    int size;
    int limit;

    void f();
};

void S::f() {
    while (size > limit) {
        unsigned int front = offset;
        if (front > front + size)
            _invalid_parameter_noinfo();

        Iterator iterator;
        iterator.owner = owner;
        iterator.offset = front;
        removeObject(iterator.get());

        if (size) {
            Shared* value = &map[offset >> 1][offset & 1];
            value->~Shared();

            ++offset;
            if (mapSize * 2 <= offset)
                offset = 0;
            if (--size == 0)
                offset = 0;
        }
    }
}
