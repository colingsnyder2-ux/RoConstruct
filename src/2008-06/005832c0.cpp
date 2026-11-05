// from server: 100% by king_originala
struct Receiver {
    void invoke(void* const* value);
};

struct Target {
    unsigned long padding;
    Receiver receiver;
};

struct S {
    unsigned long padding;
    void* value;
    Target* target;
    void f();
};

void S::f()
{
    if (target) {
        void* copy = value;
        target->receiver.invoke(&copy);
    }
}
