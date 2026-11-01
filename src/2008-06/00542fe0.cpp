// from server: 100% by king_originala
#pragma optimize("", off)

struct S;

struct Result {
    unsigned int value;
    S* owner;

    void __thiscall initialize(unsigned int, S*);
    bool __thiscall equal(const Result&);
    bool __thiscall different(const Result&);
    Result __thiscall advance(int);
};

struct S {
    Result __thiscall begin();
    Result __thiscall end();
    void __thiscall clear();
    Result __thiscall erase(Result);
    Result __thiscall finish(Result);
    Result __thiscall f(Result, Result);
};

Result S::f(Result first, Result last)
{
    if (first.equal(begin()) && last.equal(end())) {
        clear();
        return begin();
    } else {
        while (first.different(last))
            erase(first.advance(0));

        return finish(first);
    }
}
