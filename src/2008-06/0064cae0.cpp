// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 0064cae0  unit: RBX::HUMAN::Climbing  size: 268 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064cae0
//
// 0064cae0  64a100000000         mov eax, dword ptr fs:[0]
// 0064cae6  6aff                 push -1
// 0064cae8  6876b17d00           push 0x7db176
// 0064caed  50                   push eax
// 0064caee  64892500000000       mov dword ptr fs:[0], esp
// 0064caf5  83ec60               sub esp, 0x60
// 0064caf8  53                   push ebx
// 0064caf9  56                   push esi
// 0064cafa  8b742478             mov esi, dword ptr [esp + 0x78]
// 0064cafe  8bd9                 mov ebx, ecx
// 0064cb00  57                   push edi
// 0064cb01  53                   push ebx
// 0064cb02  8bce                 mov ecx, esi
// 0064cb04  e8278dffff           call 0x645830
// 0064cb09  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0064cb0c  56                   push esi
// 0064cb0d  e81ec20100           call 0x668d30
// 0064cb12  80bea800000000       cmp byte ptr [esi + 0xa8], 0
// 0064cb19  7512                 jne 0x64cb2d
// 0064cb1b  80bea900000000       cmp byte ptr [esi + 0xa9], 0
// 0064cb22  7509                 jne 0x64cb2d
// 0064cb24  80beaa00000000       cmp byte ptr [esi + 0xaa], 0
// 0064cb2b  7447                 je 0x64cb74
// 0064cb2d  6888000000           push 0x88
// 0064cb32  e8e93d0500           call 0x6a0920
// 0064cb37  8bf8                 mov edi, eax
// 0064cb39  83c404               add esp, 4
// 0064cb3c  897c247c             mov dword ptr [esp + 0x7c], edi
// 0064cb40  c744247400000000     mov dword ptr [esp + 0x74], 0
// 0064cb48  85ff                 test edi, edi
// 0064cb4a  746f                 je 0x64cbbb
// 0064cb4c  8d4c240c             lea ecx, [esp + 0xc]
// 0064cb50  e87bb7e2ff           call 0x4782d0
// 0064cb55  50                   push eax
// 0064cb56  8d4c2440             lea ecx, [esp + 0x40]
// 0064cb5a  e871b7e2ff           call 0x4782d0
// 0064cb5f  50                   push eax
// 0064cb60  6a00                 push 0
// 0064cb62  56                   push esi
// 0064cb63  8bcf                 mov ecx, edi
// 0064cb65  e8568affff           call 0x6455c0
// 0064cb6a  c707ccb08400         mov dword ptr [edi], 0x84b0cc
// 0064cb70  8bf7                 mov esi, edi
// 0064cb72  eb49                 jmp 0x64cbbd
// 0064cb74  6888000000           push 0x88
// 0064cb79  e8a23d0500           call 0x6a0920
// 0064cb7e  8bf8                 mov edi, eax
// 0064cb80  83c404               add esp, 4
// 0064cb83  897c247c             mov dword ptr [esp + 0x7c], edi
// 0064cb87  c744247401000000     mov dword ptr [esp + 0x74], 1
// 0064cb8f  85ff                 test edi, edi
// 0064cb91  7428                 je 0x64cbbb
// 0064cb93  8d4c243c             lea ecx, [esp + 0x3c]
// 0064cb97  e834b7e2ff           call 0x4782d0
// 0064cb9c  50                   push eax
// 0064cb9d  8d4c2410             lea ecx, [esp + 0x10]
// 0064cba1  e82ab7e2ff           call 0x4782d0
// 0064cba6  50                   push eax
// 0064cba7  6a00                 push 0
// 0064cba9  56                   push esi
// 0064cbaa  8bcf                 mov ecx, edi
// 0064cbac  e80f8affff           call 0x6455c0
// 0064cbb1  c7070cb18400         mov dword ptr [edi], 0x84b10c
// 0064cbb7  8bf7                 mov esi, edi
// 0064cbb9  eb02                 jmp 0x64cbbd
// 0064cbbb  33f6                 xor esi, esi
// 0064cbbd  53                   push ebx
// 0064cbbe  8bce                 mov ecx, esi
// 0064cbc0  c7442478ffffffff     mov dword ptr [esp + 0x78], 0xffffffff
// 0064cbc8  e8638cffff           call 0x645830
// 0064cbcd  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0064cbd0  8b01                 mov eax, dword ptr [ecx]
// 0064cbd2  8b5010               mov edx, dword ptr [eax + 0x10]
// 0064cbd5  56                   push esi
// 0064cbd6  ffd2                 call edx
// 0064cbd8  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0064cbdc  5f                   pop edi
// 0064cbdd  5e                   pop esi
// 0064cbde  5b                   pop ebx
// 0064cbdf  64890d00000000       mov dword ptr fs:[0], ecx
// 0064cbe6  83c46c               add esp, 0x6c
// 0064cbe9  c20400               ret 4

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Common {
    virtual void slot0();
    int owner;
    void f(int value);
};

struct Input : Common {
    char padding[160];
    unsigned char flag0;
    unsigned char flag1;
    unsigned char flag2;
};

struct Temporary {
    char data[48];
    Temporary();
};

struct State : Common {
    char padding[128];
    State(Input*, int, const Temporary&, const Temporary&);
};

struct ActiveState : State {
    ActiveState(Input*, int);
    virtual void slot0();
};

struct InactiveState : State {
    InactiveState(Input*, int);
    virtual void slot0();
};

struct Stage {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(Common*);
    void remove(Input*);
};

struct Holder {
    char padding[8];
    Stage* stage;
    void f(Input*);
};

__forceinline ActiveState::ActiveState(Input* input, int value)
    : State(input, value, Temporary(), Temporary())
{
}

__forceinline InactiveState::InactiveState(Input* input, int value)
    : State(input, value, Temporary(), Temporary())
{
}

void Holder::f(Input* input)
{
    input->f((int)this);
    stage->remove(input);

    Common* replacement;
    bool active = input->flag0 || input->flag1 || input->flag2;
    if (active)
        replacement = new ActiveState(input, 0);
    else
        replacement = new InactiveState(input, 0);

    replacement->f((int)this);
    stage->slot4(replacement);
}
