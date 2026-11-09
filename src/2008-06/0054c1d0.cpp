// from server: 100% by king_originala
#pragma optimize("", off)

struct S;

struct Result {
    void initialize(int value, S* owner);
};

struct S {
    char padding[16];
    int value;
    Result* f(Result* result);
};

Result* S::f(Result* result)
{
    result->initialize(value, this);
    return result;
}
