// from server: 100% by king_originala
struct Result {
    int unused;
    int first;
    int second;
    unsigned char flag;
};

struct Tail {
    void finish();
};

struct Product {
    char padding[16];
    Tail tail;
};

struct S {
    Result* f(Result* out, void* object, int value, int context);
    Product& make(void* object, Result* out, int* context, int value, int zero);
};

Result* S::f(Result* out, void* object, int value, int context)
{
    volatile int local = 0;
    if (object) {
        make(object, out, &context, value, 0).tail.finish();
    } else {
        out->first = 0;
        out->second = 0;
        out->flag = 0;
    }
    return out;
}
