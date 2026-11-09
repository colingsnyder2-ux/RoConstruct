// from server: 100% by king_originala
#pragma optimize("", off)

struct AtomicInt32 {
    long value;
    unsigned int decrement();
};

struct Ref {
    virtual ~Ref();
    AtomicInt32 count;
    void dispose();
};

struct WeakReferenceCountedPointer {
    Ref* pointer;
    void reset();
};

void WeakReferenceCountedPointer::reset()
{
    if (pointer != 0) {
        do {} while (0);
        do {} while (0);

        if (pointer->count.decrement() == 0) {
            pointer->dispose();
            delete pointer;
        }
        pointer = 0;
    }
}
