// from server: 100% by king_originala
struct Token {
    float& __thiscall get();
};

struct S {
    void __thiscall initialize(Token* token, float& value);
    S* __thiscall f();
};

#pragma optimize("", off)
S* S::f()
{
    Token first;
    Token second;
    initialize(&second, first.get());
    return this;
}
#pragma optimize("", on)
