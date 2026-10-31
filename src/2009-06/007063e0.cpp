// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005964f0  unit: RBX::worker_thread::Udata::?$sp_counted_impl_p  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005964f0
//
// 005964f0  6aff                 push -1
// 005964f2  6848227d00           push 0x7d2248
// 005964f7  64a100000000         mov eax, dword ptr fs:[0]
// 005964fd  50                   push eax
// 005964fe  64892500000000       mov dword ptr fs:[0], esp
// 00596505  83ec08               sub esp, 8
// 00596508  56                   push esi
// 00596509  8bf1                 mov esi, ecx
// 0059650b  83ec1c               sub esp, 0x1c
// 0059650e  8d442458             lea eax, [esp + 0x58]
// 00596512  89642420             mov dword ptr [esp + 0x20], esp
// 00596516  8bcc                 mov ecx, esp
// 00596518  50                   push eax
// 00596519  c744243401000000     mov dword ptr [esp + 0x34], 1
// 00596521  ff155c248000         call dword ptr [0x80245c]
// 00596527  83ec20               sub esp, 0x20
// 0059652a  8bc4                 mov eax, esp
// 0059652c  c70000000000         mov dword ptr [eax], 0
// 00596532  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 00596536  c644245002           mov byte ptr [esp + 0x50], 2
// 0059653b  89642444             mov dword ptr [esp + 0x44], esp
// 0059653f  85c9                 test ecx, ecx
// 00596541  7418                 je 0x59655b
// 00596543  8908                 mov dword ptr [eax], ecx
// 00596545  8b542458             mov edx, dword ptr [esp + 0x58]
// 00596549  83c008               add eax, 8
// 0059654c  6a00                 push 0
// 0059654e  50                   push eax
// 0059654f  8b02                 mov eax, dword ptr [edx]
// 00596551  8d4c2468             lea ecx, [esp + 0x68]
// 00596555  51                   push ecx
// 00596556  ffd0                 call eax
// 00596558  83c40c               add esp, 0xc
// 0059655b  8bce                 mov ecx, esi
// 0059655d  c644245001           mov byte ptr [esp + 0x50], 1
// 00596562  e8d9fdffff           call 0x596340
// 00596567  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0059656b  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0059656f  894e40               mov dword ptr [esi + 0x40], ecx
// 00596572  c644241400           mov byte ptr [esp + 0x14], 0
// 00596577  85c0                 test eax, eax
// 00596579  741d                 je 0x596598
// 0059657b  8b00                 mov eax, dword ptr [eax]
// 0059657d  85c0                 test eax, eax
// 0059657f  740f                 je 0x596590
// 00596581  8d542424             lea edx, [esp + 0x24]
// 00596585  6a01                 push 1
// 00596587  52                   push edx
// 00596588  8bca                 mov ecx, edx
// 0059658a  51                   push ecx
// 0059658b  ffd0                 call eax
// 0059658d  83c40c               add esp, 0xc
// 00596590  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00596598  8d4c243c             lea ecx, [esp + 0x3c]
// 0059659c  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005965a4  ff1568248000         call dword ptr [0x802468]
// 005965aa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005965ae  8bc6                 mov eax, esi
// 005965b0  64890d00000000       mov dword ptr fs:[0], ecx
// 005965b7  5e                   pop esi
// 005965b8  83c414               add esp, 0x14
// 005965bb  c24000               ret 0x40

struct String;

extern String* (__thiscall *copy_string)(String*, const String&);
extern void (__thiscall *destroy_string)(String*);

struct String {
    unsigned char data[28];

    String(const String& other);
    ~String();
};

inline String::String(const String& other) {
    copy_string(this, other);
}

inline String::~String() {
    destroy_string(this);
}

struct Function {
    typedef void (__cdecl *Manager)(const void*, void*, int);

    struct Table {
        Manager invoke;
    };

    Table* manager;
    unsigned int reserved;
    unsigned char storage[24];

    Function(const Function& other);
    ~Function();
};

inline Function::Function(const Function& other) : manager(0) {
    if (other.manager) {
        manager = other.manager;
        other.manager->invoke(other.storage, storage, 0);
    }
}

inline Function::~Function() {
    if (manager) {
        Manager invoke = manager->invoke;
        if (invoke)
            invoke(storage, storage, 1);
        manager = 0;
    }
}

struct S {
    unsigned char data[64];
    int value;

    void initialize(Function function, String text);
    S(Function function, String text, int number);
};

S::S(Function function, String text, int number) {
    initialize(function, text);
    value = number;
}
