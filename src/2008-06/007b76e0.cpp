// from server: 100% by king_originala
struct PointerSlot {
    void* value;
    void assign(void* value);
};

struct S_func_007b76e0 {
    char pad0[4];
    unsigned char flag;
    char pad1[3];
    PointerSlot first;
    PointerSlot second;
    float x10;
    float x14;
    float x18;
    float x1c;
    float x20;
    float x24;
    float x28;

    S_func_007b76e0& f(const S_func_007b76e0& source);
};

S_func_007b76e0& S_func_007b76e0::f(const S_func_007b76e0& source)
{
    flag = source.flag;
    first.assign(source.first.value);
    second.assign(source.second.value);
    x10 = source.x10;
    x14 = source.x14;
    x18 = source.x18;
    x1c = source.x1c;
    x20 = source.x20;
    x24 = source.x24;
    x28 = source.x28;
    return *this;
}
