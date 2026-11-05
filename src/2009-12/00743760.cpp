// from server: 100% by atomic.potato
extern "C" void __stdcall Notify(int);

struct S {
    char padding[168];
    int value;
    void Set(int);
};

void S::Set(int v)
{
    if (value != v) {
        value = v;
        Notify(0xB96D1C);
    }
}
