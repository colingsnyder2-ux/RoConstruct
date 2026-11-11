// from server: 100% by EspClaude
// from server: 71% by tester
// roc 2007-08 0042c1f0  unit: VCLuaFunction::?$CComObjectNoLock  size: 257 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042c1f0
//
// 0042c1f0  6aff                 push -1
// 0042c1f2  68f2d17300           push 0x73d1f2
// 0042c1f7  64a100000000         mov eax, dword ptr fs:[0]
// 0042c1fd  50                   push eax
// 0042c1fe  51                   push ecx
// 0042c1ff  56                   push esi
// 0042c200  57                   push edi
// 0042c201  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042c206  33c4                 xor eax, esp
// 0042c208  50                   push eax
// 0042c209  8d442410             lea eax, [esp + 0x10]
// 0042c20d  64a300000000         mov dword ptr fs:[0], eax
// 0042c213  8bf1                 mov esi, ecx
// 0042c215  8974240c             mov dword ptr [esp + 0xc], esi
// 0042c219  c70644a37800         mov dword ptr [esi], 0x78a344
// 0042c21f  8dbe0c010000         lea edi, [esi + 0x10c]
// 0042c225  8bcf                 mov ecx, edi
// 0042c227  c744241803000000     mov dword ptr [esp + 0x18], 3
// 0042c22f  e89cf8ffff           call 0x42bad0
// 0042c234  8b4704               mov eax, dword ptr [edi + 4]
// 0042c237  50                   push eax
// 0042c238  e8253a2000           call 0x62fc62
// 0042c23d  c7470400000000       mov dword ptr [edi + 4], 0
// 0042c244  8bbe08010000         mov edi, dword ptr [esi + 0x108]
// 0042c24a  83c404               add esp, 4
// 0042c24d  85ff                 test edi, edi
// 0042c24f  c644241802           mov byte ptr [esp + 0x18], 2
// 0042c254  742a                 je 0x42c280
// 0042c256  8d4704               lea eax, [edi + 4]
// 0042c259  83c9ff               or ecx, 0xffffffff
// 0042c25c  f00fc108             lock xadd dword ptr [eax], ecx
// 0042c260  751e                 jne 0x42c280
// 0042c262  8b17                 mov edx, dword ptr [edi]
// 0042c264  8b4204               mov eax, dword ptr [edx + 4]
// 0042c267  8bcf                 mov ecx, edi
// 0042c269  ffd0                 call eax
// 0042c26b  8d4f08               lea ecx, [edi + 8]
// 0042c26e  83caff               or edx, 0xffffffff
// 0042c271  f00fc111             lock xadd dword ptr [ecx], edx
// 0042c275  7509                 jne 0x42c280
// 0042c277  8b07                 mov eax, dword ptr [edi]
// 0042c279  8b5008               mov edx, dword ptr [eax + 8]
// 0042c27c  8bcf                 mov ecx, edi
// 0042c27e  ffd2                 call edx
// 0042c280  8bbe00010000         mov edi, dword ptr [esi + 0x100]
// 0042c286  85ff                 test edi, edi
// 0042c288  c644241801           mov byte ptr [esp + 0x18], 1
// 0042c28d  742a                 je 0x42c2b9
// 0042c28f  8d4704               lea eax, [edi + 4]
// 0042c292  83c9ff               or ecx, 0xffffffff
// 0042c295  f00fc108             lock xadd dword ptr [eax], ecx
// 0042c299  751e                 jne 0x42c2b9
// 0042c29b  8b17                 mov edx, dword ptr [edi]
// 0042c29d  8b4204               mov eax, dword ptr [edx + 4]
// 0042c2a0  8bcf                 mov ecx, edi
// 0042c2a2  ffd0                 call eax
// 0042c2a4  8d4f08               lea ecx, [edi + 8]
// 0042c2a7  83caff               or edx, 0xffffffff
// 0042c2aa  f00fc111             lock xadd dword ptr [ecx], edx
// 0042c2ae  7509                 jne 0x42c2b9
// 0042c2b0  8b07                 mov eax, dword ptr [edi]
// 0042c2b2  8b5008               mov edx, dword ptr [eax + 8]
// 0042c2b5  8bcf                 mov ecx, edi
// 0042c2b7  ffd2                 call edx
// 0042c2b9  8b86f4000000         mov eax, dword ptr [esi + 0xf4]
// 0042c2bf  85c0                 test eax, eax
// 0042c2c1  c644241800           mov byte ptr [esp + 0x18], 0
// 0042c2c6  7408                 je 0x42c2d0
// 0042c2c8  8b08                 mov ecx, dword ptr [eax]
// 0042c2ca  8b5108               mov edx, dword ptr [ecx + 8]
// 0042c2cd  50                   push eax
// 0042c2ce  ffd2                 call edx
// 0042c2d0  8bce                 mov ecx, esi
// 0042c2d2  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0042c2da  e8a1590300           call 0x461c80
// 0042c2df  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042c2e3  64890d00000000       mov dword ptr fs:[0], ecx
// 0042c2ea  59                   pop ecx
// 0042c2eb  5f                   pop edi
// 0042c2ec  5e                   pop esi
// 0042c2ed  83c410               add esp, 0x10
// 0042c2f0  c3                   ret 

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

void __cdecl sub_62FC62(void* p);

struct InnerList {
    void* field0;
    void* field4;
    void clear();
    ~InnerList()
    {
        clear();
        void* p = field4;
        sub_62FC62(p);
        field4 = 0;
    }
};

struct CountBase {
    virtual void slot0() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long useCount;
    volatile long weakCount;

    void release()
    {
        if (_InterlockedDecrement(&useCount) == 0) {
            dispose();
            weakRelease();
        }
    }

    void weakRelease()
    {
        if (_InterlockedDecrement(&weakCount) == 0)
            destroy();
    }
};

struct SharedPtr {
    void* px;
    CountBase* pn;
    ~SharedPtr();
};

inline SharedPtr::~SharedPtr()
{
    CountBase* p = pn;
    if (p && _InterlockedDecrement(&p->useCount) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weakCount) == 0)
            p->destroy();
    }
}

struct IUnknownLike {
    virtual long __stdcall queryInterface(const void*, void**);
    virtual unsigned long __stdcall addRef();
    virtual unsigned long __stdcall release();
};

struct ComPtr {
    IUnknownLike* p;
    ~ComPtr()
    {
        if (p)
            p->release();
    }
};

struct Base {
    virtual ~Base();
};

struct VCLuaFunction : Base {
    char pad[0xf4 - 4];
    ComPtr ptr_f4;
    char pad2[0xfc - 0xf8];
    SharedPtr shared_fc;
    SharedPtr shared_104;
    InnerList list_10c;
    ~VCLuaFunction();
};

VCLuaFunction::~VCLuaFunction()
{
}
