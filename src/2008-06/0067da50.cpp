// from server: 100% by king_originala
struct Listener {
    void invoke(void* const& value);
};

struct S {
    char padding[0xD8];
    Listener listener;
    void f(void* value);
};

void S::f(void* value)
{
    void* copy = value;
    listener.invoke(copy);
}
