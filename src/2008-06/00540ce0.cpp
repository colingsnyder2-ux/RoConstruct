// from server: 100% by king_originala
struct S;

struct Result {
    unsigned int value;
    S* owner;
    void __thiscall initialize(unsigned int, S*);
    bool operator==(const Result&) const;
    bool operator!=(const Result&) const;
    Result operator++(int);
};

struct Range {
    Result first;
    Result second;
};

void __cdecl process(Result, Result, int*);

struct S {
    Range __thiscall equal_range(unsigned int);
    Result __thiscall erase(Result, Result);
    int __thiscall f(unsigned int);
};

#pragma optimize("", off)
int S::f(unsigned int key) {
    Range range = equal_range(key);
    int count = 0;
    process(range.first, range.second, &count);
    erase(Result(range.first), Result(range.second));
    return count;
}
