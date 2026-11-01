// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0063c280  unit: RBX::DebrisService  size: 285 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063c280
//
// 0063c280  83ec0c               sub esp, 0xc
// 0063c283  53                   push ebx
// 0063c284  56                   push esi
// 0063c285  8bf1                 mov esi, ecx
// 0063c287  33db                 xor ebx, ebx
// 0063c289  399e4c010000         cmp dword ptr [esi + 0x14c], ebx
// 0063c28f  57                   push edi
// 0063c290  0f8eda000000         jle 0x63c370
// 0063c296  eb08                 jmp 0x63c2a0
// 0063c298  8da42400000000       lea esp, [esp]
// 0063c29f  90                   nop 
// 0063c2a0  8bbe48010000         mov edi, dword ptr [esi + 0x148]
// 0063c2a6  8b864c010000         mov eax, dword ptr [esi + 0x14c]
// 0063c2ac  03c7                 add eax, edi
// 0063c2ae  3bf8                 cmp edi, eax
// 0063c2b0  7606                 jbe 0x63c2b8
// 0063c2b2  ff1590288000         call dword ptr [0x802890]
// 0063c2b8  8b8e30010000         mov ecx, dword ptr [esi + 0x130]
// 0063c2be  894c2410             mov dword ptr [esp + 0x10], ecx
// 0063c2c2  8d4c2410             lea ecx, [esp + 0x10]
// 0063c2c6  897c2414             mov dword ptr [esp + 0x14], edi
// 0063c2ca  e831f1ffff           call 0x63b400
// 0063c2cf  8b10                 mov edx, dword ptr [eax]
// 0063c2d1  83ec08               sub esp, 8
// 0063c2d4  8bcc                 mov ecx, esp
// 0063c2d6  8911                 mov dword ptr [ecx], edx
// 0063c2d8  8b4004               mov eax, dword ptr [eax + 4]
// 0063c2db  89642414             mov dword ptr [esp + 0x14], esp
// 0063c2df  894104               mov dword ptr [ecx + 4], eax
// 0063c2e2  3bc3                 cmp eax, ebx
// 0063c2e4  740c                 je 0x63c2f2
// 0063c2e6  83c008               add eax, 8
// 0063c2e9  b901000000           mov ecx, 1
// 0063c2ee  f00fc108             lock xadd dword ptr [eax], ecx
// 0063c2f2  e8c9f2ffff           call 0x63b5c0
// 0063c2f7  83c408               add esp, 8
// 0063c2fa  399e4c010000         cmp dword ptr [esi + 0x14c], ebx
// 0063c300  746e                 je 0x63c370
// 0063c302  8b8648010000         mov eax, dword ptr [esi + 0x148]
// 0063c308  8b8e40010000         mov ecx, dword ptr [esi + 0x140]
// 0063c30e  8bd0                 mov edx, eax
// 0063c310  d1ea                 shr edx, 1
// 0063c312  8b1491               mov edx, dword ptr [ecx + edx*4]
// 0063c315  83e001               and eax, 1
// 0063c318  8b4cc204             mov ecx, dword ptr [edx + eax*8 + 4]
// 0063c31c  8d44c204             lea eax, [edx + eax*8 + 4]
// 0063c320  3bcb                 cmp ecx, ebx
// 0063c322  7413                 je 0x63c337
// 0063c324  8d4108               lea eax, [ecx + 8]
// 0063c327  83caff               or edx, 0xffffffff
// 0063c32a  f00fc110             lock xadd dword ptr [eax], edx
// 0063c32e  7507                 jne 0x63c337
// 0063c330  8b01                 mov eax, dword ptr [ecx]
// 0063c332  8b5008               mov edx, dword ptr [eax + 8]
// 0063c335  ffd2                 call edx
// 0063c337  ff8648010000         inc dword ptr [esi + 0x148]
// 0063c33d  8b8e44010000         mov ecx, dword ptr [esi + 0x144]
// 0063c343  8b8648010000         mov eax, dword ptr [esi + 0x148]
// 0063c349  03c9                 add ecx, ecx
// 0063c34b  3bc8                 cmp ecx, eax
// 0063c34d  7706                 ja 0x63c355
// 0063c34f  899e48010000         mov dword ptr [esi + 0x148], ebx
// 0063c355  83864c010000ff       add dword ptr [esi + 0x14c], -1
// 0063c35c  7506                 jne 0x63c364
// 0063c35e  899e48010000         mov dword ptr [esi + 0x148], ebx
// 0063c364  399e4c010000         cmp dword ptr [esi + 0x14c], ebx
// 0063c36a  0f8f30ffffff         jg 0x63c2a0
// 0063c370  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0063c374  3bcb                 cmp ecx, ebx
// 0063c376  7414                 je 0x63c38c
// 0063c378  e8a35ce5ff           call 0x492020
// 0063c37d  898654010000         mov dword ptr [esi + 0x154], eax
// 0063c383  5f                   pop edi
// 0063c384  5e                   pop esi
// 0063c385  5b                   pop ebx
// 0063c386  83c40c               add esp, 0xc
// 0063c389  c20800               ret 8
// 0063c38c  33c0                 xor eax, eax
// 0063c38e  5f                   pop edi
// 0063c38f  898654010000         mov dword ptr [esi + 0x154], eax
// 0063c395  5e                   pop esi
// 0063c396  5b                   pop ebx
// 0063c397  83c40c               add esp, 0xc
// 0063c39a  c20800               ret 8

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Control
{
    virtual void slot0();
    virtual void slot1();
    virtual void release();
    long spare;
    volatile long references;

    void addRef();
    void releaseRef();
};

inline void Control::addRef()
{
    _InterlockedIncrement(&references);
}

inline void Control::releaseRef()
{
    if (_InterlockedDecrement(&references) == 0)
        release();
}

struct Count
{
    Control* pointer;

    Count(const Count& other);
    ~Count();
};

inline Count::Count(const Count& other) : pointer(other.pointer)
{
    if (pointer)
        pointer->addRef();
}

inline Count::~Count()
{
    if (pointer)
        pointer->releaseRef();
}

struct Shared
{
    void* object;
    Count control;

    Shared(const Shared& other);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
}

inline Shared::~Shared()
{
}

struct Iterator
{
    void* owner;
    unsigned int offset;

    const Shared& get();
};

extern void __cdecl consume(Shared value);

struct Source
{
    unsigned long get();
};

struct DebrisService
{
    unsigned char padding0[0x8c];
    void* owner;
    unsigned char padding1[12];
    Shared** map;
    unsigned int mapSize;
    unsigned int offset;
    int count;
    unsigned long spare;
    unsigned long result;

    void clear(void* unused, Source* source);
};

void DebrisService::clear(void* unused, Source* source)
{
    while (count > 0)
    {
        unsigned int position = offset;
        if (position > position + count)
            _invalid_parameter_noinfo();

        Iterator iterator;
        iterator.owner = owner;
        iterator.offset = position;
        consume(iterator.get());

        if (count != 0)
        {
            map[offset >> 1][offset & 1].~Shared();

            ++offset;
            if (mapSize * 2 <= offset)
                offset = 0;

            if (--count == 0)
                offset = 0;
        }
    }

    result = source ? source->get() : 0;
}
