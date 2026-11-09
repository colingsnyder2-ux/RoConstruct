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
