// from server: 100% by king_originala
extern "C" int __stdcall helper(void *, int);

struct S {
    void *state;
    int f(int arg);
};

int S::f(int arg) {
    return helper(state, arg);
}
