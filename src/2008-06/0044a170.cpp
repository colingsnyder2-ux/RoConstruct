// from server: 100% by king_originala
struct State {
    void set(int);
};

extern State state;

struct S {
    void* f(const char*, int);
    void* base(const char*, int);
};

void* S::f(const char* name, int flag)
{
    state.set(1);
    return base(name, flag);
}
