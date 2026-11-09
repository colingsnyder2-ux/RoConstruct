// from server: 100% by king_originala
struct S;

struct Listener {
    void notify(S** value);
};

struct S {
    void f(Listener* listener);
};

void S::f(Listener* listener)
{
    S* owner = reinterpret_cast<S*>(reinterpret_cast<char*>(this) - 468);
    listener->notify(&owner);
}
