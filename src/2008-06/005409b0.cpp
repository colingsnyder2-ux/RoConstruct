// from server: 100% by king_originala
struct S;

struct Result {
    void __thiscall initialize(unsigned int value, S* owner);
};

struct S {
    unsigned char padding[24];
    unsigned int value;
    Result* __thiscall f(Result* result);
};

#pragma optimize("", off)
Result* S::f(Result* result)
{
    result->initialize(value, this);
    return result;
}
#pragma optimize("", on)
