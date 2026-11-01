// from server: 100% by king_originala
struct S;

struct Result {
    unsigned int value;
    S *owner;

    bool __thiscall equal(const Result *other);
    bool __thiscall notEqual(const Result *other);
    Result *__thiscall post(Result *result, int);
};

struct S {
    Result *__thiscall begin(Result *result);
    Result *__thiscall end(Result *result);
    void __thiscall clear();
    Result *__thiscall erase(Result *result, Result position);
    Result *__thiscall finish(Result *result, Result position);
    Result *__thiscall f(Result *result, Result first, Result last);
};

#pragma optimize("", off)
Result *S::f(Result *result, Result first, Result last)
{
    Result beginResult;
    Result endResult;
    Result postResult;
    Result eraseResult;

    if (first.equal(begin(&postResult)) &&
        last.equal(end(&endResult))) {
        clear();
        begin(result);
        return result;
    } else {
        while (first.notEqual(&last)) {
            erase(&beginResult, *first.post(&eraseResult, 0));
        }
        finish(result, first);
        return result;
    }
}
#pragma optimize("", on)
