// from server: 100% by EspClaude
// from server: 95% by EspClaude
// roc 2009-06 0066b290  unit: RBX::Humanoid  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0066b290
//
// 0066b290  56                   push esi
// 0066b291  57                   push edi
// 0066b292  8bf9                 mov edi, ecx
// 0066b294  8db7d4feffff         lea esi, [edi - 0x12c]
// 0066b29a  56                   push esi
// 0066b29b  e81016e6ff           call 0x4cc8b0
// 0066b2a0  83c404               add esp, 4
// 0066b2a3  85c0                 test eax, eax
// 0066b2a5  7424                 je 0x66b2cb
// 0066b2a7  6a00                 push 0
// 0066b2a9  6888619e00           push 0x9e6188
// 0066b2ae  6840be9d00           push 0x9dbe40
// 0066b2b3  6a00                 push 0
// 0066b2b5  50                   push eax
// 0066b2b6  e8bfe90a00           call 0x719c7a
// 0066b2bb  83c414               add esp, 0x14
// 0066b2be  85c0                 test eax, eax
// 0066b2c0  7409                 je 0x66b2cb
// 0066b2c2  8bc8                 mov ecx, eax
// 0066b2c4  e877cfffff           call 0x668240
// 0066b2c9  eb02                 jmp 0x66b2cd
// 0066b2cb  33c0                 xor eax, eax
// 0066b2cd  81c7d4feffff         add edi, 0xfffffed4
// 0066b2d3  3bf8                 cmp edi, eax
// 0066b2d5  7427                 je 0x66b2fe
// 0066b2d7  56                   push esi
// 0066b2d8  e8532ffcff           call 0x62e230
// 0066b2dd  83c404               add esp, 4
// 0066b2e0  85c0                 test eax, eax
// 0066b2e2  741a                 je 0x66b2fe
// 0066b2e4  8d8818010000         lea ecx, [eax + 0x118]
// 0066b2ea  8b01                 mov eax, dword ptr [ecx]
// 0066b2ec  8b500c               mov edx, dword ptr [eax + 0xc]
// 0066b2ef  ffd2                 call edx
// 0066b2f1  50                   push eax
// 0066b2f2  8b442410             mov eax, dword ptr [esp + 0x10]
// 0066b2f6  50                   push eax
// 0066b2f7  8bce                 mov ecx, esi
// 0066b2f9  e8a2fcffff           call 0x66afa0
// 0066b2fe  5f                   pop edi
// 0066b2ff  5e                   pop esi
// 0066b300  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 005db960  unit: RBX::Humanoid  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005db960
//
// 005db960  56                   push esi
// 005db961  57                   push edi
// 005db962  8bf9                 mov edi, ecx
// 005db964  8db7c4feffff         lea esi, [edi - 0x12c]
// 005db96a  56                   push esi
// 005db96b  e830f3ebff           call 0x49aca0
// 005db970  83c404               add esp, 4
// 005db973  85c0                 test eax, eax
// 005db975  7424                 je 0x5db99b
// 005db977  6a00                 push 0
// 005db979  68402a9300           push 0x932a40
// 005db97e  687c909200           push 0x92907c
// 005db983  6a00                 push 0
// 005db985  50                   push eax
// 005db986  e83b5e0c00           call 0x6a17c6
// 005db98b  83c414               add esp, 0x14
// 005db98e  85c0                 test eax, eax
// 005db990  7409                 je 0x5db99b
// 005db992  8bc8                 mov ecx, eax
// 005db994  e8f7ccffff           call 0x5d8690
// 005db999  eb02                 jmp 0x5db99d
// 005db99b  33c0                 xor eax, eax
// 005db99d  81c7c4feffff         add edi, 0xfffffec4
// 005db9a3  3bf8                 cmp edi, eax
// 005db9a5  7427                 je 0x5db9ce
// 005db9a7  56                   push esi
// 005db9a8  e8d379fcff           call 0x5a3380
// 005db9ad  83c404               add esp, 4
// 005db9b0  85c0                 test eax, eax
// 005db9b2  741a                 je 0x5db9ce
// 005db9b4  8d8888020000         lea ecx, [eax + 0x288]
// 005db9ba  8b01                 mov eax, dword ptr [ecx]
// 005db9bc  8b5008               mov edx, dword ptr [eax + 8]
// 005db9bf  ffd2                 call edx
// 005db9c1  50                   push eax
// 005db9c2  8b442410             mov eax, dword ptr [esp + 0x10]
// 005db9c6  50                   push eax
// 005db9c7  8bce                 mov ecx, esi
// 005db9c9  e8b2fcffff           call 0x5db680
// 005db9ce  5f                   pop edi
// 005db9cf  5e                   pop esi
// 005db9d0  c20400               ret 4

struct Humanoid;

struct Model
{
    Humanoid* getHumanoid();
};

struct ValueSource
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* getValue();
};

struct Context
{
    char padding[0x118];
    ValueSource source;
};

struct Humanoid
{
    void setValue(int argument, void* value);
};

struct S
{
    void func_005db960(int argument);
};

extern "C" void* __cdecl getCharacter(Humanoid*);
extern "C" Context* __cdecl getContext(Humanoid*);
extern "C" void* __cdecl runtimeCast(void*, int, const void*, const void*, int);

extern char instanceType;
extern char modelType;

__forceinline Humanoid* findHumanoid(Humanoid* owner)
{
    void* character = getCharacter(owner);
    if (character)
    {
        Model* model = static_cast<Model*>(
            runtimeCast(character, 0, &instanceType, &modelType, 0));
        if (model)
            return model->getHumanoid();
    }
    return 0;
}

void S::func_005db960(int argument)
{
    Humanoid* owner = reinterpret_cast<Humanoid*>(
        reinterpret_cast<char*>(this) - 0x12c);

    Humanoid* current = findHumanoid(owner);

    if (reinterpret_cast<Humanoid*>(
            reinterpret_cast<char*>(this) - 0x12c) != current)
    {
        Context* context = getContext(owner);
        if (context)
            owner->setValue(argument, context->source.getValue());
    }
}
