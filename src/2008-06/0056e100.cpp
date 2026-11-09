// from server: 100% by king_originala
struct Result {
    char storage[28];
    Result(const Result&);
    ~Result();
};

Result __cdecl convert(const bool& value);

struct Getter {
    virtual void slot0();
    virtual void slot1();
    virtual bool get(void* instance);
};

struct S {
    char padding[24];
    Getter* getter;

    Result f(void* instance);
};

Result S::f(void* instance)
{
    return convert(getter->get(instance));
}
