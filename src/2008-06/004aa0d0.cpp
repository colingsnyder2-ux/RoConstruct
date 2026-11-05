// from server: 100% by king_originala
extern "C" int __cdecl lookup(int value);

struct S {
    bool resolve(int value, int &index);
    void *get(const int &index);
    void *f(int value);
};

void *S::f(int value)
{
    if (resolve(lookup(value), value))
        return get(value);
    return 0;
}
