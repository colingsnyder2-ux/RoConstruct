// from server: 100% by king_originala
struct String {
    char storage[32];
    String(const String&);
    ~String();
};

struct Argument {
    String name;
    void* value;
};

struct S {
    S(Argument argument, int unused);
    void initialize(Argument argument, int flags);
};

S::S(Argument argument, int unused)
{
    initialize(argument, 0);
}
