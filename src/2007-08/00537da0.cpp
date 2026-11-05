// from server: 100% by colin
// roc 2007-08 00537da0  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00537da0

struct S {
};

void __cdecl f(int a, int b, int c) {
    void (*fn)(int, int) = *(void (**)(int, int))a;
    fn(b, c);
}
