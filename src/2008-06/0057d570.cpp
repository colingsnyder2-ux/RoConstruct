// from server: 100% by king_originala
struct Result {
    void func_005cc040(int);
};

struct Proxy {
    virtual void slot0();
    virtual Result* slot1();
};

struct Owner {
    char padding[0x288];
    Proxy proxy;
};

struct S {
    char padding[0x0c];
    Owner* owner;
    void func_0057d570();
};

void S::func_0057d570()
{
    Result* result = owner->proxy.slot1();
    result->func_005cc040(-1);
}
