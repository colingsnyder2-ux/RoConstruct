// from server: 100% by king_originala
#pragma optimize("", off)

struct AtomicInt32 {
    int value;
    void increment();
};

struct Object {
    unsigned int unused;
    AtomicInt32 count;
};

struct S {
    Object* pointer;
    void reset();
    void f(Object* other);
};

void S::f(Object* other) {
    if (other != pointer) {
        reset();
        if (other != 0) {
            do {} while (0);
            pointer = other;
            do {} while (0);
            pointer->count.increment();
        }
    }
}
