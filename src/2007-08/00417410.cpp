// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 00417410  unit: boost::X::U?$last_value::?$holder  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00417410
// 00417410  6aff                 push -1
// 00417412  6878ae7300           push 0x73ae78
// 00417417  64a100000000         mov eax, dword ptr fs:[0]
// 0041741d  50                   push eax
// 0041741e  56                   push esi
// 0041741f  57                   push edi
// 00417420  a188518b00           mov eax, dword ptr [0x8b5188]
// 00417425  33c4                 xor eax, esp
// 00417427  50                   push eax
// 00417428  8d44240c             lea eax, [esp + 0xc]
// 0041742c  64a300000000         mov dword ptr fs:[0], eax
// 00417432  8bf1                 mov esi, ecx
// 00417434  8d44241c             lea eax, [esp + 0x1c]
// 00417438  50                   push eax
// 00417439  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00417441  e88a050700           call 0x4879d0
// 00417446  83c404               add esp, 4
// 00417449  84c0                 test al, al
// 0041744b  7527                 jne 0x417474
// 0041744d  6a38                 push 0x38
// 0041744f  c74608b06a4100       mov dword ptr [esi + 8], 0x416ab0
// 00417456  c706e06a4100         mov dword ptr [esi], 0x416ae0
// 0041745c  e8958a2100           call 0x62fef6
// 00417461  8d4c2420             lea ecx, [esp + 0x20]
// 00417465  8bf8                 mov edi, eax
// 00417467  51                   push ecx
// 00417468  57                   push edi
// 00417469  e8a2e4ffff           call 0x415910
// 0041746e  83c40c               add esp, 0xc
// 00417471  897e04               mov dword ptr [esi + 4], edi
// 00417474  8d4c2424             lea ecx, [esp + 0x24]
// 00417478  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00417480  e87bc8ffff           call 0x413d00
// 00417485  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00417489  64890d00000000       mov dword ptr fs:[0], ecx
// 00417490  59                   pop ecx
// 00417491  5f                   pop edi
// 00417492  5e                   pop esi
// 00417493  83c40c               add esp, 0xc
// 00417496  c23c00               ret 0x3c

void* __cdecl operator new(unsigned int size);

struct Bound {
    ~Bound();
    int storage[12];
};

struct Functor {
    int head[2];
    Bound bound;
};

bool __cdecl has_empty_target(const Functor* f);
void __cdecl construct(Functor* p, const Functor& value);

typedef void* (*Manager)();
typedef void (*Invoker)();

void* manage();
void invoke();

struct Function {
    Manager manager;
    void* functor;
    Invoker invoker;

    void assign_to(Functor f, int);
};

void Function::assign_to(Functor f, int)
{
    if (!has_empty_target(&f)) {
        invoker = &invoke;
        manager = &manage;
        Functor* copy = (Functor*)operator new(sizeof(Functor));
        construct(copy, f);
        functor = copy;
    }
}
