// from server: 100% by king_originala
struct S {
    char padding[0x104];
    S* parent;
    bool f(S* node);
};

struct PartInstance : S {
    char padding2[0x1f0 - 0x108];
    bool locked;
};

struct GetSetImpl {
    static PartInstance* get(PartInstance* p);
};

struct Humanoid {
    int f() const;
};

struct UnlockedPartByLocalCharacter {
    int unused;
    S* character;
    int unused2;
    Humanoid* humanoid;
    int f(PartInstance* part);
};

int UnlockedPartByLocalCharacter::f(PartInstance* part)
{
    int result = 2;
    if (character && humanoid) {
        PartInstance* instance = GetSetImpl::get(part);
        if (instance->f(character))
            result = (unsigned char)humanoid->f() != 0;
    }

    if (result == 2)
        result = GetSetImpl::get(part)->locked ? 0 : 2;

    return result;
}
