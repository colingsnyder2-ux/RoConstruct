// from server: 100% by Xemicl
// roc 2012-06 004156c0  unit: CIDEBrowserView  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004156c0
//
// 004156c0  64a100000000         mov eax, dword ptr fs:[0]
// 004156c6  6aff                 push -1
// 004156c8  680aada900           push 0xa9ad0a
// 004156cd  50                   push eax
// 004156ce  64892500000000       mov dword ptr fs:[0], esp
// 004156d5  56                   push esi
// 004156d6  57                   push edi
// 004156d7  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004156db  837f0800             cmp dword ptr [edi + 8], 0
// 004156df  8bf1                 mov esi, ecx
// 004156e1  0f84df000000         je 0x4157c6
// 004156e7  8b4714               mov eax, dword ptr [edi + 0x14]
// 004156ea  50                   push eax
// 004156eb  e8309c5800           call 0x99f320
// 004156f0  50                   push eax
// 004156f1  e8f0cd5600           call 0x9824e6
// 004156f6  83c408               add esp, 8
// 004156f9  85c0                 test eax, eax
// 004156fb  0f84c5000000         je 0x4157c6
// 00415701  813fc9800000         cmp dword ptr [edi], 0x80c9
// 00415707  0f85b9000000         jne 0x4157c6
// 0041570d  83befc00000000       cmp dword ptr [esi + 0xfc], 0
// 00415714  7538                 jne 0x41574e
// 00415716  68e0010000           push 0x1e0
// 0041571b  e8fac95600           call 0x98211a
// 00415720  83c404               add esp, 4
// 00415723  89442418             mov dword ptr [esp + 0x18], eax
// 00415727  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041572f  85c0                 test eax, eax
// 00415731  740b                 je 0x41573e
// 00415733  6a00                 push 0
// 00415735  8bc8                 mov ecx, eax
// 00415737  e8e49d5700           call 0x98f520
// 0041573c  eb02                 jmp 0x415740
// 0041573e  33c0                 xor eax, eax
// 00415740  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00415748  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0041574e  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 00415754  6a01                 push 1
// 00415756  e835915700           call 0x98e890
// 0041575b  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 00415761  68c051b400           push 0xb451c0
// 00415766  e835f95600           call 0x9850a0
// 0041576b  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 00415771  83b94801000001       cmp dword ptr [ecx + 0x148], 1
// 00415778  740f                 je 0x415789
// 0041577a  c7814801000001000000 mov dword ptr [ecx + 0x148], 1
// 00415784  e8f7ef5600           call 0x984780
// 00415789  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 0041578f  6a28                 push 0x28
// 00415791  e88af35600           call 0x984b20
// 00415796  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 0041579c  8b11                 mov edx, dword ptr [ecx]
// 0041579e  8b4268               mov eax, dword ptr [edx + 0x68]
// 004157a1  6a01                 push 1
// 004157a3  ffd0                 call eax
// 004157a5  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 004157ab  894f04               mov dword ptr [edi + 4], ecx
// 004157ae  b801000000           mov eax, 1
// 004157b3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004157b7  64890d00000000       mov dword ptr fs:[0], ecx
// 004157be  5f                   pop edi
// 004157bf  5e                   pop esi
// 004157c0  83c40c               add esp, 0xc
// 004157c3  c20400               ret 4
// 004157c6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004157ca  5f                   pop edi
// 004157cb  33c0                 xor eax, eax
// 004157cd  64890d00000000       mov dword ptr fs:[0], ecx
// 004157d4  5e                   pop esi
// 004157d5  83c40c               add esp, 0xc
// 004157d8  c20400               ret 4
// copied from an identical function in another client (function ?f@CBrowserView@@QAEHPAURequest@@@Z)

// from server: 100% by king_originala
// roc 2008-06 0040e670  unit: CBrowserView  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e670
//
// 0040e670  64a100000000         mov eax, dword ptr fs:[0]
// 0040e676  6aff                 push -1
// 0040e678  682ad47b00           push 0x7bd42a
// 0040e67d  50                   push eax
// 0040e67e  64892500000000       mov dword ptr fs:[0], esp
// 0040e685  56                   push esi
// 0040e686  57                   push edi
// 0040e687  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0040e68b  837f0800             cmp dword ptr [edi + 8], 0
// 0040e68f  8bf1                 mov esi, ecx
// 0040e691  0f84df000000         je 0x40e776
// 0040e697  8b4714               mov eax, dword ptr [edi + 0x14]
// 0040e69a  50                   push eax
// 0040e69b  e870342b00           call 0x6c1b10
// 0040e6a0  50                   push eax
// 0040e6a1  e880252900           call 0x6a0c26
// 0040e6a6  83c408               add esp, 8
// 0040e6a9  85c0                 test eax, eax
// 0040e6ab  0f84c5000000         je 0x40e776
// 0040e6b1  813fc9800000         cmp dword ptr [edi], 0x80c9
// 0040e6b7  0f85b9000000         jne 0x40e776
// 0040e6bd  83be1801000000       cmp dword ptr [esi + 0x118], 0
// 0040e6c4  7538                 jne 0x40e6fe
// 0040e6c6  68e0010000           push 0x1e0
// 0040e6cb  e850222900           call 0x6a0920
// 0040e6d0  83c404               add esp, 4
// 0040e6d3  89442418             mov dword ptr [esp + 0x18], eax
// 0040e6d7  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040e6df  85c0                 test eax, eax
// 0040e6e1  740b                 je 0x40e6ee
// 0040e6e3  6a00                 push 0
// 0040e6e5  8bc8                 mov ecx, eax
// 0040e6e7  e874922900           call 0x6a7960
// 0040e6ec  eb02                 jmp 0x40e6f0
// 0040e6ee  33c0                 xor eax, eax
// 0040e6f0  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0040e6f8  898618010000         mov dword ptr [esi + 0x118], eax
// 0040e6fe  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e704  6a01                 push 1
// 0040e706  e8a5852900           call 0x6a6cb0
// 0040e70b  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e711  687cd38000           push 0x80d37c
// 0040e716  e825d22900           call 0x6ab940
// 0040e71b  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e721  83b94801000001       cmp dword ptr [ecx + 0x148], 1
// 0040e728  740f                 je 0x40e739
// 0040e72a  c7814801000001000000 mov dword ptr [ecx + 0x148], 1
// 0040e734  e887c82900           call 0x6aafc0
// 0040e739  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e73f  6a28                 push 0x28
// 0040e741  e81acc2900           call 0x6ab360
// 0040e746  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e74c  8b11                 mov edx, dword ptr [ecx]
// 0040e74e  8b4268               mov eax, dword ptr [edx + 0x68]
// 0040e751  6a01                 push 1
// 0040e753  ffd0                 call eax
// 0040e755  8b8e18010000         mov ecx, dword ptr [esi + 0x118]
// 0040e75b  894f04               mov dword ptr [edi + 4], ecx
// 0040e75e  b801000000           mov eax, 1
// 0040e763  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040e767  64890d00000000       mov dword ptr fs:[0], ecx
// 0040e76e  5f                   pop edi
// 0040e76f  5e                   pop esi
// 0040e770  83c40c               add esp, 0xc
// 0040e773  c20400               ret 4
// 0040e776  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040e77a  5f                   pop edi
// 0040e77b  33c0                 xor eax, eax
// 0040e77d  64890d00000000       mov dword ptr fs:[0], ecx
// 0040e784  5e                   pop esi
// 0040e785  83c40c               add esp, 0xc
// 0040e788  c20400               ret 4

// from server: 96% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern "C" int __cdecl lookup(int);
extern "C" int __cdecl validate(int);

struct Control {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void enable(int);

    char padding[0x144];
    int mode;
    char tail[0x94];

    Control(int);
    void setEditable(int);
    void setCaption(const char*);
    void updateMode();
    void setWidth(int);
    __forceinline void setMode(int);
};

__forceinline void Control::setMode(int value)
{
    if (mode != value) {
        mode = value;
        updateMode();
    }
}

struct Request {
    unsigned int code;
    Control* control;
    int enabled;
    int reserved[2];
    int id;
};

struct CBrowserView {
    char padding[0xfc];
    Control* control;
    int f(Request*);
};

int CBrowserView::f(Request* volatile input)
{
    Request* request=input;
    if (request->enabled &&
        validate(lookup(request->id)) &&
        request->code == 0x80c9) {
        if (!control)
            control = new Control(0);

        control->setEditable(1);
        control->setCaption("Address");
        control->setMode(1);
        control->setWidth(40);
        control->enable(1);
        request->control = control;
        return 1;
    }
    return 0;
}