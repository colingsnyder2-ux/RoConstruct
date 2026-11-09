// from server: 100% by king_originala
#pragma optimize("", off)

struct S;
struct VChunk;

struct Result {
    unsigned int value;
    S* owner;

    void __thiscall initialize(unsigned int, S*);
    bool operator==(const Result&) const;
    bool operator!=(const Result&) const;
    Result operator++(int);
};

struct S {
    Result begin();
    Result end();
    VChunk** slot();
    Result erase(Result);
    Result convert(Result);
    Result f(Result, Result);
};

Result S::f(Result first, Result last)
{
    if (first == begin() && last == end()) {
        slot();
        return begin();
    } else {
        while (first != last)
            erase(first++);

        return convert(first);
    }
}
