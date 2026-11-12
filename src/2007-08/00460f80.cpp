// from server: 100% by EspClaude
// from server: 43% by tester
// roc 2007-08 00460f80  unit: RBX::VInstance::?$MarshaledListener::EventData  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460f80
//
// 00460f80  6aff                 push -1
// 00460f82  68c3287400           push 0x7428c3
// 00460f87  64a100000000         mov eax, dword ptr fs:[0]
// 00460f8d  50                   push eax
// 00460f8e  51                   push ecx
// 00460f8f  56                   push esi
// 00460f90  57                   push edi
// 00460f91  a188518b00           mov eax, dword ptr [0x8b5188]
// 00460f96  33c4                 xor eax, esp
// 00460f98  50                   push eax
// 00460f99  8d442410             lea eax, [esp + 0x10]
// 00460f9d  64a300000000         mov dword ptr fs:[0], eax
// 00460fa3  8bf9                 mov edi, ecx
// 00460fa5  897c240c             mov dword ptr [esp + 0xc], edi
// 00460fa9  c707944b7900         mov dword ptr [edi], 0x794b94
// 00460faf  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00460fb2  85c9                 test ecx, ecx
// 00460fb4  c744241801000000     mov dword ptr [esp + 0x18], 1
// 00460fbc  7406                 je 0x460fc4
// 00460fbe  57                   push edi
// 00460fbf  e8bc6bfdff           call 0x437b80
// 00460fc4  8b7708               mov esi, dword ptr [edi + 8]
// 00460fc7  85f6                 test esi, esi
// 00460fc9  c644241800           mov byte ptr [esp + 0x18], 0
// 00460fce  742a                 je 0x460ffa
// 00460fd0  8d4604               lea eax, [esi + 4]
// 00460fd3  83c9ff               or ecx, 0xffffffff
// 00460fd6  f00fc108             lock xadd dword ptr [eax], ecx
// 00460fda  751e                 jne 0x460ffa
// 00460fdc  8b16                 mov edx, dword ptr [esi]
// 00460fde  8b4204               mov eax, dword ptr [edx + 4]
// 00460fe1  8bce                 mov ecx, esi
// 00460fe3  ffd0                 call eax
// 00460fe5  8d4e08               lea ecx, [esi + 8]
// 00460fe8  83caff               or edx, 0xffffffff
// 00460feb  f00fc111             lock xadd dword ptr [ecx], edx
// 00460fef  7509                 jne 0x460ffa
// 00460ff1  8b06                 mov eax, dword ptr [esi]
// 00460ff3  8b5008               mov edx, dword ptr [eax + 8]
// 00460ff6  8bce                 mov ecx, esi
// 00460ff8  ffd2                 call edx
// 00460ffa  c707687f7800         mov dword ptr [edi], 0x787f68
// 00461000  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00461004  64890d00000000       mov dword ptr fs:[0], ecx
// 0046100b  59                   pop ecx
// 0046100c  5f                   pop edi
// 0046100d  5e                   pop esi
// 0046100e  83c410               add esp, 0x10
// 00461011  c3                   ret 
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* pointer;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p)
    {
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct S;

struct Owner
{
    void detach(S*);
};

struct Base
{
    virtual ~Base();
};

inline Base::~Base()
{
}

struct S : Base
{
    Shared connection;
    Owner* owner;

    virtual ~S();
};

S::~S()
{
    if (owner)
        owner->detach(this);
}
