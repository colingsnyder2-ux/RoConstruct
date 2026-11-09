// from server: 100% by king_originala
struct S {
    void g(void* result, S* source);
    void* f(void* result, S* owner);
};

void* S::f(void* result, S* owner)
{
    volatile int state;
    owner->g((state = 0, result), this);
    return result;
}
