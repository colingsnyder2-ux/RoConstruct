// from server: 100% by tester
struct S {
};

void __cdecl f(int a, int b, int c) {
    void (*fn)(int, int) = *(void (**)(int, int))a;
    fn(b, c);
}
