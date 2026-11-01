// from server: 100% by king_originala
extern "C" int __stdcall probe(void *, bool *);

struct S {
    char padding[0x13c];
    void *value;
    bool f();
};

bool S::f()
{
    if (!value)
        return true;

    bool result;
    if (probe(value, &result) == 0x24)
        return true;
    return result;
}
