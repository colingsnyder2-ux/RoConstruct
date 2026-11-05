// from server: 100% by tester
#pragma optimize("", off)

struct S {
    void* pointer;
    void assign(void*);
    S(const S&);
};

S::S(const S& other) {
    pointer = 0;
    assign(other.pointer);
}
