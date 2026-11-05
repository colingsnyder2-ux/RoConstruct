// from server: 100% by EspClaude
// from server: 69% by king_originala
// roc 2008-06 0042c0d0  unit: RBX::Reflection::$$A6AXPBVPropertyDescriptor::V?$function::?$holder  size: 474 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042c0d0
//
// 0042c0d0  6aff                 push -1
// 0042c0d2  6869f67b00           push 0x7bf669
// 0042c0d7  64a100000000         mov eax, dword ptr fs:[0]
// 0042c0dd  50                   push eax
// 0042c0de  64892500000000       mov dword ptr fs:[0], esp
// 0042c0e5  83ec58               sub esp, 0x58
// 0042c0e8  53                   push ebx
// 0042c0e9  55                   push ebp
// 0042c0ea  56                   push esi
// 0042c0eb  8bf1                 mov esi, ecx
// 0042c0ed  33db                 xor ebx, ebx
// 0042c0ef  895e04               mov dword ptr [esi + 4], ebx
// 0042c0f2  57                   push edi
// 0042c0f3  89742418             mov dword ptr [esp + 0x18], esi
// 0042c0f7  895e08               mov dword ptr [esi + 8], ebx
// 0042c0fa  8d4e0c               lea ecx, [esi + 0xc]
// 0042c0fd  895c2470             mov dword ptr [esp + 0x70], ebx
// 0042c101  c70654068100         mov dword ptr [esi], 0x810654
// 0042c107  e8d42e0800           call 0x4aefe0
// 0042c10c  885e28               mov byte ptr [esi + 0x28], bl
// 0042c10f  895e2c               mov dword ptr [esi + 0x2c], ebx
// 0042c112  8b442478             mov eax, dword ptr [esp + 0x78]
// 0042c116  c644247002           mov byte ptr [esp + 0x70], 2
// 0042c11b  894630               mov dword ptr [esi + 0x30], eax
// 0042c11e  3bc3                 cmp eax, ebx
// 0042c120  7408                 je 0x42c12a
// 0042c122  8b08                 mov ecx, dword ptr [eax]
// 0042c124  8b5104               mov edx, dword ptr [ecx + 4]
// 0042c127  50                   push eax
// 0042c128  ffd2                 call edx
// 0042c12a  6a30                 push 0x30
// 0042c12c  c644247403           mov byte ptr [esp + 0x74], 3
// 0042c131  e8ea472700           call 0x6a0920
// 0042c136  8be8                 mov ebp, eax
// 0042c138  83c404               add esp, 4
// 0042c13b  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0042c13f  c644247004           mov byte ptr [esp + 0x70], 4
// 0042c144  3beb                 cmp ebp, ebx
// 0042c146  7439                 je 0x42c181
// 0042c148  83ec20               sub esp, 0x20
// 0042c14b  33c9                 xor ecx, ecx
// 0042c14d  8bf9                 mov edi, ecx
// 0042c14f  8bcc                 mov ecx, esp
// 0042c151  89642440             mov dword ptr [esp + 0x40], esp
// 0042c155  53                   push ebx
// 0042c156  b800c04200           mov eax, 0x42c000
// 0042c15b  8bd0                 mov edx, eax
// 0042c15d  83ec10               sub esp, 0x10
// 0042c160  8bc4                 mov eax, esp
// 0042c162  8910                 mov dword ptr [eax], edx
// 0042c164  8b542464             mov edx, dword ptr [esp + 0x64]
// 0042c168  897804               mov dword ptr [eax + 4], edi
// 0042c16b  897008               mov dword ptr [eax + 8], esi
// 0042c16e  89500c               mov dword ptr [eax + 0xc], edx
// 0042c171  e85af5ffff           call 0x42b6d0
// 0042c176  8bcd                 mov ecx, ebp
// 0042c178  e833ebffff           call 0x42acb0
// 0042c17d  8bf8                 mov edi, eax
// 0042c17f  eb02                 jmp 0x42c183
// 0042c181  33ff                 xor edi, edi
// 0042c183  c644247003           mov byte ptr [esp + 0x70], 3
// 0042c188  397e2c               cmp dword ptr [esi + 0x2c], edi
// 0042c18b  741e                 je 0x42c1ab
// 0042c18d  3bfb                 cmp edi, ebx
// 0042c18f  7408                 je 0x42c199
// 0042c191  8b07                 mov eax, dword ptr [edi]
// 0042c193  8b4804               mov ecx, dword ptr [eax + 4]
// 0042c196  57                   push edi
// 0042c197  ffd1                 call ecx
// 0042c199  8b462c               mov eax, dword ptr [esi + 0x2c]
// 0042c19c  3bc3                 cmp eax, ebx
// 0042c19e  7408                 je 0x42c1a8
// 0042c1a0  8b10                 mov edx, dword ptr [eax]
// 0042c1a2  50                   push eax
// 0042c1a3  8b4208               mov eax, dword ptr [edx + 8]
// 0042c1a6  ffd0                 call eax
// 0042c1a8  897e2c               mov dword ptr [esi + 0x2c], edi
// 0042c1ab  8b442478             mov eax, dword ptr [esp + 0x78]
// 0042c1af  895c2414             mov dword ptr [esp + 0x14], ebx
// 0042c1b3  3bc3                 cmp eax, ebx
// 0042c1b5  7411                 je 0x42c1c8
// 0042c1b7  8b08                 mov ecx, dword ptr [eax]
// 0042c1b9  8d542414             lea edx, [esp + 0x14]
// 0042c1bd  52                   push edx
// 0042c1be  685c058100           push 0x81055c
// 0042c1c3  50                   push eax
// 0042c1c4  8b01                 mov eax, dword ptr [ecx]
// 0042c1c6  ffd0                 call eax
// 0042c1c8  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0042c1cc  b305                 mov bl, 5
// 0042c1ce  6844068100           push 0x810644
// 0042c1d3  8d4c247c             lea ecx, [esp + 0x7c]
// 0042c1d7  885c2474             mov byte ptr [esp + 0x74], bl
// 0042c1db  e8a04ffdff           call 0x401180
// 0042c1e0  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 0042c1e3  8b00                 mov eax, dword ptr [eax]
// 0042c1e5  8b17                 mov edx, dword ptr [edi]
// 0042c1e7  8d6c2410             lea ebp, [esp + 0x10]
// 0042c1eb  55                   push ebp
// 0042c1ec  51                   push ecx
// 0042c1ed  50                   push eax
// 0042c1ee  8b8208010000         mov eax, dword ptr [edx + 0x108]
// 0042c1f4  57                   push edi
// 0042c1f5  c684248000000006     mov byte ptr [esp + 0x80], 6
// 0042c1fd  ffd0                 call eax
// 0042c1ff  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0042c203  51                   push ecx
// 0042c204  8bf8                 mov edi, eax
// 0042c206  885c2474             mov byte ptr [esp + 0x74], bl
// 0042c20a  ff1544298000         call dword ptr [0x802944]
// 0042c210  85ff                 test edi, edi
// 0042c212  7431                 je 0x42c245
// 0042c214  6830068100           push 0x810630
// 0042c219  8d4c2428             lea ecx, [esp + 0x28]
// 0042c21d  ff1558248000         call dword ptr [0x802458]
// 0042c223  8d542424             lea edx, [esp + 0x24]
// 0042c227  52                   push edx
// 0042c228  8d4c2444             lea ecx, [esp + 0x44]
// 0042c22c  c644247407           mov byte ptr [esp + 0x74], 7
// 0042c231  e81adbfdff           call 0x409d50
// 0042c236  68c81b8d00           push 0x8d1bc8
// 0042c23b  8d442444             lea eax, [esp + 0x44]
// 0042c23f  50                   push eax
// 0042c240  e847532700           call 0x6a158c
// 0042c245  66837c241000         cmp word ptr [esp + 0x10], 0
// 0042c24b  7531                 jne 0x42c27e
// 0042c24d  6830068100           push 0x810630
// 0042c252  8d4c2428             lea ecx, [esp + 0x28]
// 0042c256  ff1558248000         call dword ptr [0x802458]
// 0042c25c  8d4c2424             lea ecx, [esp + 0x24]
// 0042c260  51                   push ecx
// 0042c261  8d4c2444             lea ecx, [esp + 0x44]
// 0042c265  c644247408           mov byte ptr [esp + 0x74], 8
// 0042c26a  e8e1dafdff           call 0x409d50
// 0042c26f  68c81b8d00           push 0x8d1bc8
// 0042c274  8d542444             lea edx, [esp + 0x44]
// 0042c278  52                   push edx
// 0042c279  e80e532700           call 0x6a158c
// 0042c27e  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042c282  c644247003           mov byte ptr [esp + 0x70], 3
// 0042c287  85c0                 test eax, eax
// 0042c289  7408                 je 0x42c293
// 0042c28b  8b08                 mov ecx, dword ptr [eax]
// 0042c28d  8b5108               mov edx, dword ptr [ecx + 8]
// 0042c290  50                   push eax
// 0042c291  ffd2                 call edx
// 0042c293  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 0042c297  5f                   pop edi
// 0042c298  8bc6                 mov eax, esi
// 0042c29a  5e                   pop esi
// 0042c29b  5d                   pop ebp
// 0042c29c  64890d00000000       mov dword ptr fs:[0], ecx
// 0042c2a3  5b                   pop ebx
// 0042c2a4  83c464               add esp, 0x64
// 0042c2a7  c20400               ret 4

typedef unsigned long ULONG;
typedef long HRESULT;

struct Guid {
    unsigned long a;
    unsigned short b, c;
    unsigned char d[8];
};

extern const Guid inputInterface;

struct Interface {
    virtual HRESULT __stdcall query(const Guid &, void **) = 0;
    virtual ULONG __stdcall addRef() = 0;
    virtual ULONG __stdcall release() = 0;
    virtual void __stdcall r0() = 0;
    virtual void __stdcall r1() = 0;
    virtual void __stdcall r2() = 0;
    virtual void __stdcall r3() = 0;
    virtual void __stdcall r4() = 0;
    virtual void __stdcall r5() = 0;
    virtual void __stdcall r6() = 0;
    virtual void __stdcall r7() = 0;
    virtual void __stdcall r8() = 0;
    virtual void __stdcall r9() = 0;
    virtual void __stdcall r10() = 0;
    virtual void __stdcall r11() = 0;
    virtual void __stdcall r12() = 0;
    virtual void __stdcall r13() = 0;
    virtual void __stdcall r14() = 0;
    virtual void __stdcall r15() = 0;
    virtual void __stdcall r16() = 0;
    virtual void __stdcall r17() = 0;
    virtual void __stdcall r18() = 0;
    virtual void __stdcall r19() = 0;
    virtual void __stdcall r20() = 0;
    virtual void __stdcall r21() = 0;
    virtual void __stdcall r22() = 0;
    virtual void __stdcall r23() = 0;
    virtual void __stdcall r24() = 0;
    virtual void __stdcall r25() = 0;
    virtual void __stdcall r26() = 0;
    virtual void __stdcall r27() = 0;
    virtual void __stdcall r28() = 0;
    virtual void __stdcall r29() = 0;
    virtual void __stdcall r30() = 0;
    virtual void __stdcall r31() = 0;
    virtual void __stdcall r32() = 0;
    virtual void __stdcall r33() = 0;
    virtual void __stdcall r34() = 0;
    virtual void __stdcall r35() = 0;
    virtual void __stdcall r36() = 0;
    virtual void __stdcall r37() = 0;
    virtual void __stdcall r38() = 0;
    virtual void __stdcall r39() = 0;
    virtual void __stdcall r40() = 0;
    virtual void __stdcall r41() = 0;
    virtual void __stdcall r42() = 0;
    virtual void __stdcall r43() = 0;
    virtual void __stdcall r44() = 0;
    virtual void __stdcall r45() = 0;
    virtual void __stdcall r46() = 0;
    virtual void __stdcall r47() = 0;
    virtual void __stdcall r48() = 0;
    virtual void __stdcall r49() = 0;
    virtual void __stdcall r50() = 0;
    virtual void __stdcall r51() = 0;
    virtual void __stdcall r52() = 0;
    virtual void __stdcall r53() = 0;
    virtual void __stdcall r54() = 0;
    virtual void __stdcall r55() = 0;
    virtual void __stdcall r56() = 0;
    virtual void __stdcall r57() = 0;
    virtual void __stdcall r58() = 0;
    virtual void __stdcall r59() = 0;
    virtual void __stdcall r60() = 0;
    virtual void __stdcall r61() = 0;
    virtual void __stdcall r62() = 0;
    virtual HRESULT __stdcall attach(unsigned short *, Interface *, short *) = 0;
};

struct InterfacePtr {
    Interface *p;

    InterfacePtr(Interface *value = 0) : p(value) {
        if (p)
            p->addRef();
    }

    operator Interface *() const { return p; }
    ~InterfacePtr() {
        if (p)
            p->release();
    }

    void assign(Interface *value) {
        if (p != value) {
            if (value)
                value->addRef();
            if (p)
                p->release();
            p = value;
        }
    }
};

struct QIPtr {
    Interface *p;
    QIPtr(Interface *value) : p(0) {
        if (value)
            value->query(inputInterface, reinterpret_cast<void **>(&p));
    }
    ~QIPtr() {
        if (p)
            p->release();
    }
};

struct State {
    unsigned char storage[28];
    State();
    ~State();
};

struct __multiple_inheritance Handler;

struct BoundHandler {
    void (Handler::*function)();
    Handler *object;
    unsigned char argument;
};

inline BoundHandler bindHandler(void (Handler::*f)(), Handler *o)
{
    BoundHandler b;
    b.function = f;
    b.object = o;
    return b;
}

struct Function {
    unsigned char storage[32];
    Function(BoundHandler, int);
    Function(const Function &);
    ~Function();
};

struct Callback {
    unsigned char storage[48];
    Callback(Function);
};

extern "C" __declspec(dllimport) void __stdcall SysFreeString(unsigned short *);

struct WideString {
    unsigned short *value;
    WideString(const char *);
    operator unsigned short *() const { return value; }
    ~WideString() {
        SysFreeString(value);
    }
};

struct __declspec(dllimport) String {
    unsigned char storage[28];
    String(const char *);
    ~String();
};

struct Error {
    unsigned char storage[40];
    Error(const String &);
    Error(const Error &);
    ~Error();
};

struct RefBase {
    unsigned long references;
    RefBase() : references(0) {}
};

struct HandlerBase : RefBase {
    virtual void dispatch();
    void *owner;

    HandlerBase() : owner(0) {}
    ~HandlerBase();
};

struct Noncopyable {};

struct Handler : HandlerBase, Noncopyable {
    State state;
    bool active;
    InterfacePtr callback;
    InterfacePtr source;

    Handler(Interface *);
    void eventHandler();
};

Handler::Handler(Interface *value)
    : active(false), callback(0), source(value)
{
    Callback *created = new Callback(Function(bindHandler(&Handler::eventHandler, this), 0));
    callback.assign(reinterpret_cast<Interface *>(created));

    QIPtr input(value);

    Interface *element = input.p;
    short attached;
    HRESULT result = element->attach(
        WideString("onchange"), callback, &attached);

    if (result != 0) {
        String message("attachEvent failed");
        throw Error(message);
    }

    if (attached == 0) {
        String message("attachEvent failed");
        throw Error(message);
    }
}
