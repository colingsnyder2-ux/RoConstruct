// from server: 100% by king_originala
struct Bucket;

struct Result {
    void* value;
    Bucket* owner;
    void initialize(void* value, Bucket* owner);
};

struct Bucket {
    Result* begin(Result* result);
    Result* end(Result* result);
    Result erase(Result first, Result last);
    void clear();
};

#pragma optimize("", off)
void Bucket::clear()
{
    struct Locals {
        Result firstTemporary;
        Result first;
        Result lastTemporary;
        Result last;
    } locals;

    locals.last = *end(&locals.lastTemporary);
    locals.first = *begin(&locals.firstTemporary);
    erase(locals.first, locals.last);
}
