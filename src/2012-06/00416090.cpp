// from server: 100% by Xemicl
// roc 2012-06 00416090  unit: CIDEBrowserView  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00416090
//
// 00416090  6aff                 push -1
// 00416092  68b3ada900           push 0xa9adb3
// 00416097  64a100000000         mov eax, dword ptr fs:[0]
// 0041609d  50                   push eax
// 0041609e  64892500000000       mov dword ptr fs:[0], esp
// 004160a5  51                   push ecx
// 004160a6  53                   push ebx
// 004160a7  56                   push esi
// 004160a8  8bf1                 mov esi, ecx
// 004160aa  89742408             mov dword ptr [esp + 8], esi
// 004160ae  e89def0800           call 0x4a5050
// 004160b3  33db                 xor ebx, ebx
// 004160b5  899ef8000000         mov dword ptr [esi + 0xf8], ebx
// 004160bb  8d8e00010000         lea ecx, [esi + 0x100]
// 004160c1  895c2414             mov dword ptr [esp + 0x14], ebx
// 004160c5  c7062c55b400         mov dword ptr [esi], 0xb4552c
// 004160cb  899efc000000         mov dword ptr [esi + 0xfc], ebx
// 004160d1  e8fa945800           call 0x99f5d0
// 004160d6  899ea8020000         mov dword ptr [esi + 0x2a8], ebx
// 004160dc  8d8eb0020000         lea ecx, [esi + 0x2b0]
// 004160e2  889eac020000         mov byte ptr [esi + 0x2ac], bl
// 004160e8  889ead020000         mov byte ptr [esi + 0x2ad], bl
// 004160ee  ff158447b200         call dword ptr [0xb24784]
// 004160f4  c644241403           mov byte ptr [esp + 0x14], 3
// 004160f9  e842865800           call 0x99e740
// 004160fe  50                   push eax
// 004160ff  e8fc220200           call 0x438400
// 00416104  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00416108  83c404               add esp, 4
// 0041610b  8bc6                 mov eax, esi
// 0041610d  5e                   pop esi
// 0041610e  5b                   pop ebx
// 0041610f  64890d00000000       mov dword ptr fs:[0], ecx
// 00416116  83c410               add esp, 0x10
// 00416119  c3                   ret 
// copied from an identical function in another client (function ??0S@ns_ROCX00001e@@QAE@XZ)

namespace ns_ROCX00001e {
// from server: 80% by EspClaude
// roc 2009-06 0040ddb0  unit: VCBrowserViewExternal::?$CProxy_IBrowserViewExternalEvents  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040ddb0
//
// 0040ddb0  6aff                 push -1
// 0040ddb2  6823d48400           push 0x84d423
// 0040ddb7  64a100000000         mov eax, dword ptr fs:[0]
// 0040ddbd  50                   push eax
// 0040ddbe  64892500000000       mov dword ptr fs:[0], esp
// 0040ddc5  51                   push ecx
// 0040ddc6  53                   push ebx
// 0040ddc7  56                   push esi
// 0040ddc8  8bf1                 mov esi, ecx
// 0040ddca  89742408             mov dword ptr [esp + 8], esi
// 0040ddce  e8cd8a0500           call 0x4668a0
// 0040ddd3  33db                 xor ebx, ebx
// 0040ddd5  899ef8000000         mov dword ptr [esi + 0xf8], ebx
// 0040dddb  8d8e00010000         lea ecx, [esi + 0x100]
// 0040dde1  895c2414             mov dword ptr [esp + 0x14], ebx
// 0040dde5  c70634e18a00         mov dword ptr [esi], 0x8ae134
// 0040ddeb  899efc000000         mov dword ptr [esi + 0xfc], ebx
// 0040ddf1  e8eac43200           call 0x73a2e0
// 0040ddf6  899ea8020000         mov dword ptr [esi + 0x2a8], ebx
// 0040ddfc  8d8eb0020000         lea ecx, [esi + 0x2b0]
// 0040de02  889eac020000         mov byte ptr [esi + 0x2ac], bl
// 0040de08  889ead020000         mov byte ptr [esi + 0x2ad], bl
// 0040de0e  ff15bcfc8900         call dword ptr [0x89fcbc]
// 0040de14  c644241403           mov byte ptr [esp + 0x14], 3
// 0040de19  e8a2b53200           call 0x7393c0
// 0040de1e  50                   push eax
// 0040de1f  e85ca40100           call 0x428280
// 0040de24  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040de28  83c404               add esp, 4
// 0040de2b  8bc6                 mov eax, esi
// 0040de2d  5e                   pop esi
// 0040de2e  5b                   pop ebx
// 0040de2f  64890d00000000       mov dword ptr fs:[0], ecx
// 0040de36  83c410               add esp, 0x10
// 0040de39  c3                   ret 

// from server: 100% by colin
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
}
