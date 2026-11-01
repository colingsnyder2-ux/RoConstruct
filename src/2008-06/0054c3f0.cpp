// from server: 100% by king_originala
struct S;

struct Result {
    unsigned int value;
    void* node;

    void __thiscall initialize(unsigned int, S*);
    bool __thiscall operator==(const Result&) const;
    void* __thiscall get() const;
};

struct Compare {
    bool __thiscall operator()(const unsigned int&, const unsigned int&) const;
};

extern const unsigned int& __cdecl keyOf(void*);

struct S {
    unsigned char padding[8];
    Compare compare;

    Result __thiscall lower_bound(const unsigned int&);
    Result __thiscall end();
    Result __thiscall f(const unsigned int&);
};

#pragma optimize("", off)
Result S::f(const unsigned int& key)
{
    Result candidate = lower_bound(key);
    return !(candidate == end()) && !compare(key, keyOf(candidate.get()))
        ? candidate
        : end();
}
