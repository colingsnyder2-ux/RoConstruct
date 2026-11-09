// from server: 66% by atomic.potato
struct SomeClass {
    int method(int* out);
};

int __cdecl func2(SomeClass* p, int res);

int func(SomeClass* p) {
    int local;
    int res = p->method(&local);
    return func2(p, res);
}
