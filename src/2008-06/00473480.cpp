// from server: 72% by king_originala
extern const char exceptionType;
extern "C" void __stdcall throwException(void *, const void *);

struct Storage {
    char bytes[92];
};

struct S {
    void prepare();
    void f(Storage storage);
};

void S::f(Storage storage)
{
    prepare();
    throwException(storage.bytes + 88, &exceptionType);
    __assume(0);
}
