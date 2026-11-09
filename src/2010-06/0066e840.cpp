// from server: 100% by Yeetserama
// roc 2010-06 0066e840  unit: RBX::VPartInstance::?$FilteredSelection  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0066e840
//
// 0066e840  8b442404             mov eax, dword ptr [esp + 4]
// 0066e844  50                   push eax
// 0066e845  e856eae5ff           call 0x4cd2a0
// 0066e84a  83c404               add esp, 4
// 0066e84d  85c0                 test eax, eax
// 0066e84f  7422                 je 0x66e873
// 0066e851  6a00                 push 0
// 0066e853  687846b800           push 0xb84678
// 0066e858  68408eb700           push 0xb78e40
// 0066e85d  6a00                 push 0
// 0066e85f  50                   push eax
// 0066e860  e885a31300           call 0x7a8bea
// 0066e865  83c414               add esp, 0x14
// 0066e868  85c0                 test eax, eax
// 0066e86a  7407                 je 0x66e873
// 0066e86c  8bc8                 mov ecx, eax
// 0066e86e  e9fdfbffff           jmp 0x66e470
// 0066e873  33c0                 xor eax, eax
// 0066e875  c3                   ret 
// copied from an identical function in another client (function ?findHumanoid@ns_ROCX00001a@@YAPAUHumanoid@1@PAU21@@Z)

namespace ns_ROCX00001a {
// from server: 100% by king_originala
struct Humanoid;

struct Model
{
    Humanoid* getHumanoid();
};

struct ValueSource
{
    virtual void slot0();
    virtual void slot1();
    virtual void* getValue();
};

struct Context
{
    char padding[0x288];
    ValueSource source;
};

struct Humanoid
{
    void setValue(int argument, void* value);
};

struct S
{
    void fn_ROCX00001a_005db960(int argument);
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

void S::fn_ROCX00001a_005db960(int argument)
{
    Humanoid* owner = reinterpret_cast<Humanoid*>(
        reinterpret_cast<char*>(this) - 0x13c);

    Humanoid* current = findHumanoid(owner);

    if (reinterpret_cast<Humanoid*>(
            reinterpret_cast<char*>(this) - 0x13c) != current)
    {
        Context* context = getContext(owner);
        if (context)
            owner->setValue(argument, context->source.getValue());
    }
}
}
