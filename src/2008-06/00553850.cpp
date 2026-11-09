// from server: 100% by king_originala
#pragma optimize("", off)

struct S;

struct Result {
    void initialize(unsigned long value, S* owner);
};

struct S {
    unsigned char padding[12];
    unsigned long value;
    Result* f(Result* result);
};

Result* S::f(Result* result)
{
    result->initialize(value, this);
    return result;
}
