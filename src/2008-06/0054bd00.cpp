// from server: 100% by king_originala
struct Result {
    unsigned int value;
    unsigned int owner;
    bool equal(const Result* other);
    unsigned int get();
};

struct Comparator {
    bool less(unsigned int key, unsigned int value);
};

unsigned int __cdecl convert(unsigned int value);

struct S {
    unsigned char padding[8];
    Comparator comparator;

    Result* find(Result* result, unsigned int key);
    Result* end(Result* result);
    Result* f(Result* result, unsigned int key);
};

#pragma optimize("", off)
Result* S::f(Result* result, unsigned int key)
{
    struct Locals {
        Result secondEnd;
        Result firstEnd;
        const Result* selected;
        Result found;
    } locals;

    find(&locals.found, key);
    locals.selected = locals.found.equal(end(&locals.firstEnd)) ||
                      comparator.less(key, convert(locals.found.get()))
                    ? end(&locals.secondEnd)
                    : &locals.found;

    *result = *locals.selected;
    return result;
}
