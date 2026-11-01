// from server: 100% by king_originala
struct Chunk;
struct Bucket;

struct Result {
    void* value;
    Bucket* owner;

    bool operator!=(const Result& other) const;
    void operator++();
    Chunk* operator*() const;
};

struct Bucket {
    Result begin();
    Result end();
};

struct Chunk {
    unsigned char padding[8];
    Bucket bucket;

    float score(void* argument);
    Chunk* f(void* argument);
};

extern "C" const double* __cdecl initialLimit();

#pragma optimize("", off)
Chunk* Chunk::f(void* argument)
{
    struct Locals {
        float best;
        Result finish;
        Chunk* result;
    } locals;

    locals.result = 0;
    locals.best = (float)*initialLimit();
    locals.finish = bucket.end();

    for (Result current = bucket.begin(); current != locals.finish; ++current) {
        float value = (*current)->score(argument);
        if (value < locals.best) {
            locals.result = *current;
            locals.best = value;
        }
    }

    return locals.result;
}
