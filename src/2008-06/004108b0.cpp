// from server: 100% by colin
// from server: 91% by colin
// roc 2008-06 004108b0  unit: UIEnumConnections::V?$CComEnum::?$CComObject  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004108b0
//
// 004108b0  6aff                 push -1
// 004108b2  68d1d57b00           push 0x7bd5d1
// 004108b7  64a100000000         mov eax, dword ptr fs:[0]
// 004108bd  50                   push eax
// 004108be  64892500000000       mov dword ptr fs:[0], esp
// 004108c5  51                   push ecx
// 004108c6  53                   push ebx
// 004108c7  56                   push esi
// 004108c8  8bf1                 mov esi, ecx
// 004108ca  89742408             mov dword ptr [esp + 8], esi
// 004108ce  e88d510500           call 0x465a60
// 004108d3  33db                 xor ebx, ebx
// 004108d5  899ef8000000         mov dword ptr [esi + 0xf8], ebx
// 004108db  8d8efc000000         lea ecx, [esi + 0xfc]
// 004108e1  895c2414             mov dword ptr [esp + 0x14], ebx
// 004108e5  c70614d88000         mov dword ptr [esi], 0x80d814
// 004108eb  e840ffffff           call 0x410830
// 004108f0  8d8e1c010000         lea ecx, [esi + 0x11c]
// 004108f6  c644241401           mov byte ptr [esp + 0x14], 1
// 004108fb  899e18010000         mov dword ptr [esi + 0x118], ebx
// 00410901  e89a142b00           call 0x6c1da0
// 00410906  899ec4020000         mov dword ptr [esi + 0x2c4], ebx
// 0041090c  8d8ecc020000         lea ecx, [esi + 0x2cc]
// 00410912  889ec8020000         mov byte ptr [esi + 0x2c8], bl
// 00410918  889ec9020000         mov byte ptr [esi + 0x2c9], bl
// 0041091e  ff15043f8000         call dword ptr [0x803f04]
// 00410924  c644241404           mov byte ptr [esp + 0x14], 4
// 00410929  e852052b00           call 0x6c0e80
// 0041092e  50                   push eax
// 0041092f  e84cea0100           call 0x42f380
// 00410934  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00410938  83c404               add esp, 4
// 0041093b  8bc6                 mov eax, esi
// 0041093d  5e                   pop esi
// 0041093e  5b                   pop ebx
// 0041093f  64890d00000000       mov dword ptr fs:[0], ecx
// 00410946  83c410               add esp, 0x10
// 00410949  c3                   ret 

// from server: 90% by king_originala
// roc 2008-06 004108b0  unit: UIEnumConnections::V?$CComEnum::?$CComObject  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004108b0
//
// 004108b0  6aff                 push -1
// 004108b2  68d1d57b00           push 0x7bd5d1
// 004108b7  64a100000000         mov eax, dword ptr fs:[0]
// 004108bd  50                   push eax
// 004108be  64892500000000       mov dword ptr fs:[0], esp
// 004108c5  51                   push ecx
// 004108c6  53                   push ebx
// 004108c7  56                   push esi
// 004108c8  8bf1                 mov esi, ecx
// 004108ca  89742408             mov dword ptr [esp + 8], esi
// 004108ce  e88d510500           call 0x465a60
// 004108d3  33db                 xor ebx, ebx
// 004108d5  899ef8000000         mov dword ptr [esi + 0xf8], ebx
// 004108db  8d8efc000000         lea ecx, [esi + 0xfc]
// 004108e1  895c2414             mov dword ptr [esp + 0x14], ebx
// 004108e5  c70614d88000         mov dword ptr [esi], 0x80d814
// 004108eb  e840ffffff           call 0x410830
// 004108f0  8d8e1c010000         lea ecx, [esi + 0x11c]
// 004108f6  c644241401           mov byte ptr [esp + 0x14], 1
// 004108fb  899e18010000         mov dword ptr [esi + 0x118], ebx
// 00410901  e89a142b00           call 0x6c1da0
// 00410906  899ec4020000         mov dword ptr [esi + 0x2c4], ebx
// 0041090c  8d8ecc020000         lea ecx, [esi + 0x2cc]
// 00410912  889ec8020000         mov byte ptr [esi + 0x2c8], bl
// 00410918  889ec9020000         mov byte ptr [esi + 0x2c9], bl
// 0041091e  ff15043f8000         call dword ptr [0x803f04]
// 00410924  c644241404           mov byte ptr [esp + 0x14], 4
// 00410929  e852052b00           call 0x6c0e80
// 0041092e  50                   push eax
// 0041092f  e84cea0100           call 0x42f380
// 00410934  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00410938  83c404               add esp, 4
// 0041093b  8bc6                 mov eax, esi
// 0041093d  5e                   pop esi
// 0041093e  5b                   pop ebx
// 0041093f  64890d00000000       mov dword ptr fs:[0], ecx
// 00410946  83c410               add esp, 0x10
// 00410949  c3                   ret 

struct Base {
    virtual ~Base();
    char storage[0xF4];
    Base();
};

struct Parent : Base {
    unsigned long reserved;
    Parent();
};

inline Parent::Parent() : reserved(0)
{
}

struct Member {
    char storage[0x1C];
    Member();
    ~Member();
};

struct Buffer {
    char storage[0x1A8];
    Buffer();
    ~Buffer();
};

struct Connection {
    void *pointer;
    Connection();
    ~Connection();
};

inline Connection::Connection() : pointer(0)
{
}

struct Lock {
    unsigned long storage;
    __declspec(dllimport) Lock() throw();
    ~Lock();
};

extern void * __cdecl getContext();
extern void __cdecl registerContext(void *);

struct S : Parent {
    Member member;
    unsigned long count;
    Buffer buffer;
    Connection connection;
    bool flag1;
    bool flag2;
    Lock lock;

    S();
    virtual ~S();
};

S::S()
    : count(0),
      flag1(false),
      flag2(false)
{
    registerContext(getContext());
}
