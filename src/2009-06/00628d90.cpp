// from server: 84% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005ff1a0  unit: RBX::Tool  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ff1a0
//
// 005ff1a0  6aff                 push -1
// 005ff1a2  683bf47b00           push 0x7bf43b
// 005ff1a7  64a100000000         mov eax, dword ptr fs:[0]
// 005ff1ad  50                   push eax
// 005ff1ae  64892500000000       mov dword ptr fs:[0], esp
// 005ff1b5  51                   push ecx
// 005ff1b6  56                   push esi
// 005ff1b7  8bf1                 mov esi, ecx
// 005ff1b9  57                   push edi
// 005ff1ba  8bbe04010000         mov edi, dword ptr [esi + 0x104]
// 005ff1c0  85ff                 test edi, edi
// 005ff1c2  7460                 je 0x5ff224
// 005ff1c4  56                   push esi
// 005ff1c5  e8d6bae9ff           call 0x49aca0
// 005ff1ca  83c404               add esp, 4
// 005ff1cd  3bf8                 cmp edi, eax
// 005ff1cf  7553                 jne 0x5ff224
// 005ff1d1  56                   push esi
// 005ff1d2  e8792ce9ff           call 0x491e50
// 005ff1d7  6a2c                 push 0x2c
// 005ff1d9  8986ac010000         mov dword ptr [esi + 0x1ac], eax
// 005ff1df  e83c170a00           call 0x6a0920
// 005ff1e4  83c408               add esp, 8
// 005ff1e7  89442408             mov dword ptr [esp + 8], eax
// 005ff1eb  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005ff1f3  85c0                 test eax, eax
// 005ff1f5  7411                 je 0x5ff208
// 005ff1f7  8b8eac010000         mov ecx, dword ptr [esi + 0x1ac]
// 005ff1fd  56                   push esi
// 005ff1fe  51                   push ecx
// 005ff1ff  8bc8                 mov ecx, eax
// 005ff201  e87af0ffff           call 0x5fe280
// 005ff206  eb02                 jmp 0x5ff20a
// 005ff208  33c0                 xor eax, eax
// 005ff20a  8b8eac010000         mov ecx, dword ptr [esi + 0x1ac]
// 005ff210  50                   push eax
// 005ff211  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 005ff219  898600020000         mov dword ptr [esi + 0x200], eax
// 005ff21f  e89c2dfaff           call 0x5a1fc0
// 005ff224  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005ff228  5f                   pop edi
// 005ff229  5e                   pop esi
// 005ff22a  64890d00000000       mov dword ptr fs:[0], ecx
// 005ff231  83c410               add esp, 0x10
// 005ff234  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

namespace RBX {
struct Instance {
    virtual ~Instance();
    char pad[0x100];
    Instance* next;
};

struct Tool;
struct Action;

struct ServiceProvider : Instance {
    ServiceProvider* finish();
    void attach(Action*);
};

struct Action {
    char storage[0x2c];
    Action(ServiceProvider*, Tool*);
};

struct Tool : Instance {
    char pad108[0xa4];
    ServiceProvider* provider;
    char pad1b0[0x50];
    Action* action;

    void update();
};
}

RBX::Instance* __cdecl func_0049aca0(RBX::Instance*);
RBX::ServiceProvider* __cdecl func_00491e50(RBX::Instance*);

void RBX::Tool::update()
{
    Instance* parent = next;
    if (parent && parent == func_0049aca0(this)) {
        provider = func_00491e50(this);
        action = new Action(provider, this);
        provider->attach(action);
    }
}
