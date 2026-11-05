// from server: 100% by king_originala
struct Owner {
    char padding[112];
};

struct Outer {
    int unused;
    Owner* owner;
};

struct Member {
    int value;
    char padding[12];

    void initialize(int, void*, int);
};

struct S {
    int padding[2];
    Member member;
    float weight;
    int unused;
    int value;

    S(const int&, int);
    void prepare();
    void reset();
    void finish();
};

S::S(const int& argument, int mode)
{
    prepare();
    reset();

    Outer* outer = this
        ? reinterpret_cast<Outer*>(reinterpret_cast<char*>(this) - 12)
        : 0;
    Owner* owner = outer->owner;
    void* context = owner
        ? reinterpret_cast<char*>(owner) + 112
        : 0;

    member.initialize(mode, context, argument);
    weight = 1.0f;
    value = member.value;
    finish();
}
