// from server: 100% by king_originala
struct Object {
    void fill(void *result, int value);
};

struct S {
    Object *object;
    int value;
    void *f(void *result);
};

void *S::f(void *result)
{
    volatile int temporary = 0;
    object->fill(result, value);
    return result;
}
