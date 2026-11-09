// from server: 100% by king_originala
struct S {
    bool f(S* node);
};

struct PartInstance;

struct GetSetImpl {
    static PartInstance* get(PartInstance* p);
};

struct Humanoid {
    int f() const;
};

struct PartByLocalCharacter {
    unsigned char padding0[4];
    S* character;
    unsigned char padding8[4];
    Humanoid* humanoid;

    int f(PartInstance* part);
};

int PartByLocalCharacter::f(PartInstance* part)
{
    if (character != 0 && humanoid != 0) {
        S* node = reinterpret_cast<S*>(GetSetImpl::get(part));
        if (node->f(character))
            return static_cast<unsigned char>(humanoid->f()) != 0;
    }
    return 2;
}
