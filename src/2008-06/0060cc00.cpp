// from server: 100% by king_originala
struct Receiver {
    void apply(void* value);
};

extern "C" void* __cdecl lookup(void* first, void* second);

struct S {
    int reserved;
    Receiver* receiver;

    void f(void* first, void* second);
};

void S::f(void* first, void* second)
{
    void* value = lookup(first, second);
    if (value)
        receiver->apply(value);
}
