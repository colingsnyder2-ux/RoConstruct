// from server: 100% by colin
// from server: 98% by colin
// roc 2008-06 0043e960  unit: RBX::Soundscape::VSoundId::?$ContentItem  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043e960
//
// 0043e960  6aff                 push -1
// 0043e962  6899087c00           push 0x7c0899
// 0043e967  64a100000000         mov eax, dword ptr fs:[0]
// 0043e96d  50                   push eax
// 0043e96e  64892500000000       mov dword ptr fs:[0], esp
// 0043e975  83ec40               sub esp, 0x40
// 0043e978  56                   push esi
// 0043e979  8bf1                 mov esi, ecx
// 0043e97b  8b86c4000000         mov eax, dword ptr [esi + 0xc4]
// 0043e981  8b4034               mov eax, dword ptr [eax + 0x34]
// 0043e984  83e800               sub eax, 0
// 0043e987  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 0043e98f  745e                 je 0x43e9ef
// 0043e991  83e801               sub eax, 1
// 0043e994  7432                 je 0x43e9c8
// 0043e996  8d4c2454             lea ecx, [esp + 0x54]
// 0043e99a  ff15e03e8000         call dword ptr [0x803ee0]
// 0043e9a0  50                   push eax
// 0043e9a1  8d4c2408             lea ecx, [esp + 8]
// 0043e9a5  e8168effff           call 0x4377c0
// 0043e9aa  50                   push eax
// 0043e9ab  8bce                 mov ecx, esi
// 0043e9ad  c644245001           mov byte ptr [esp + 0x50], 1
// 0043e9b2  e809fbffff           call 0x43e4c0
// 0043e9b7  8d4c2404             lea ecx, [esp + 4]
// 0043e9bb  c644244c00           mov byte ptr [esp + 0x4c], 0
// 0043e9c0  ff1568248000         call dword ptr [0x802468]
// 0043e9c6  eb33                 jmp 0x43e9fb
// 0043e9c8  8d4c2424             lea ecx, [esp + 0x24]
// 0043e9cc  e87fe6ffff           call 0x43d050
// 0043e9d1  50                   push eax
// 0043e9d2  8bce                 mov ecx, esi
// 0043e9d4  c644245002           mov byte ptr [esp + 0x50], 2
// 0043e9d9  e8e2faffff           call 0x43e4c0
// 0043e9de  8d4c2424             lea ecx, [esp + 0x24]
// 0043e9e2  c644244c00           mov byte ptr [esp + 0x4c], 0
// 0043e9e7  ff1568248000         call dword ptr [0x802468]
// 0043e9ed  eb0c                 jmp 0x43e9fb
// 0043e9ef  8b06                 mov eax, dword ptr [esi]
// 0043e9f1  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 0043e9f7  8bce                 mov ecx, esi
// 0043e9f9  ffd2                 call edx
// 0043e9fb  8d4c2454             lea ecx, [esp + 0x54]
// 0043e9ff  ff15143f8000         call dword ptr [0x803f14]
// 0043ea05  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0043ea09  5e                   pop esi
// 0043ea0a  64890d00000000       mov dword ptr fs:[0], ecx
// 0043ea11  83c44c               add esp, 0x4c
// 0043ea14  c20400               ret 4

// from server: 94% by king_originala
// roc 2008-06 0043e960  unit: RBX::Soundscape::VSoundId::?$ContentItem  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043e960
//
// 0043e960  6aff                 push -1
// 0043e962  6899087c00           push 0x7c0899
// 0043e967  64a100000000         mov eax, dword ptr fs:[0]
// 0043e96d  50                   push eax
// 0043e96e  64892500000000       mov dword ptr fs:[0], esp
// 0043e975  83ec40               sub esp, 0x40
// 0043e978  56                   push esi
// 0043e979  8bf1                 mov esi, ecx
// 0043e97b  8b86c4000000         mov eax, dword ptr [esi + 0xc4]
// 0043e981  8b4034               mov eax, dword ptr [eax + 0x34]
// 0043e984  83e800               sub eax, 0
// 0043e987  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 0043e98f  745e                 je 0x43e9ef
// 0043e991  83e801               sub eax, 1
// 0043e994  7432                 je 0x43e9c8
// 0043e996  8d4c2454             lea ecx, [esp + 0x54]
// 0043e99a  ff15e03e8000         call dword ptr [0x803ee0]
// 0043e9a0  50                   push eax
// 0043e9a1  8d4c2408             lea ecx, [esp + 8]
// 0043e9a5  e8168effff           call 0x4377c0
// 0043e9aa  50                   push eax
// 0043e9ab  8bce                 mov ecx, esi
// 0043e9ad  c644245001           mov byte ptr [esp + 0x50], 1
// 0043e9b2  e809fbffff           call 0x43e4c0
// 0043e9b7  8d4c2404             lea ecx, [esp + 4]
// 0043e9bb  c644244c00           mov byte ptr [esp + 0x4c], 0
// 0043e9c0  ff1568248000         call dword ptr [0x802468]
// 0043e9c6  eb33                 jmp 0x43e9fb
// 0043e9c8  8d4c2424             lea ecx, [esp + 0x24]
// 0043e9cc  e87fe6ffff           call 0x43d050
// 0043e9d1  50                   push eax
// 0043e9d2  8bce                 mov ecx, esi
// 0043e9d4  c644245002           mov byte ptr [esp + 0x50], 2
// 0043e9d9  e8e2faffff           call 0x43e4c0
// 0043e9de  8d4c2424             lea ecx, [esp + 0x24]
// 0043e9e2  c644244c00           mov byte ptr [esp + 0x4c], 0
// 0043e9e7  ff1568248000         call dword ptr [0x802468]
// 0043e9ed  eb0c                 jmp 0x43e9fb
// 0043e9ef  8b06                 mov eax, dword ptr [esi]
// 0043e9f1  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 0043e9f7  8bce                 mov ecx, esi
// 0043e9f9  ffd2                 call edx
// 0043e9fb  8d4c2454             lea ecx, [esp + 0x54]
// 0043e9ff  ff15143f8000         call dword ptr [0x803f14]
// 0043ea05  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0043ea09  5e                   pop esi
// 0043ea0a  64890d00000000       mov dword ptr fs:[0], ecx
// 0043ea11  83c44c               add esp, 0x4c
// 0043ea14  c20400               ret 4

struct Text;
struct Argument;

extern void (__thiscall *destroyText)(Text *);
extern const char *(__thiscall *argumentChars)(Argument *);
extern void (__thiscall *destroyArgument)(Argument *);

struct Text {
    char storage[32];

    Text();
    Text(const char *);
    ~Text() { destroyText(this); }
};

struct __declspec(dllimport) Argument {
    void *value;

    ~Argument() throw();
};

struct State {
    char padding[0x34];
    int kind;
};

#define V(n) virtual void v##n();
struct S {
    V(00) V(01) V(02) V(03) V(04) V(05) V(06) V(07)
    V(08) V(09) V(10) V(11) V(12) V(13) V(14) V(15)
    V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
    V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
    V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47)
    V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55)
    V(56) V(57) V(58) V(59) V(60) V(61)
    virtual void reset();

    char padding[0xC0];
    State *state;

    void assign(const Text &);
    void f(Argument);
};
#undef V

void S::f(Argument argument)
{
    State* s = state;
    switch (s->kind) {
    case 0:
        reset();
        break;
    default:
        assign(Text(argumentChars(&argument)));
        break;
    case 1:
        assign(Text());
        break;
    }
}
