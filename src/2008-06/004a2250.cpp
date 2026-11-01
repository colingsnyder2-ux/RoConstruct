// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();
extern "C" void __cdecl range_callback(void *);
extern "C" int __cdecl process_range(
    void *, void *, void (__cdecl *)(void *));

struct Range {
    unsigned char padding[12];
    unsigned char *begin;
    unsigned char *end;
};

struct S {
    unsigned char padding[264];
    Range *range;
    int f();
};

int S::f()
{
    Range *r = range;
    if (r) {
        void (__cdecl *invalid)() = invalid_parameter_noinfo;
        unsigned char *last = r->end;
        if (r->begin > last)
            invalid();

        unsigned char *first = range->begin;
        if (first > range->end)
            invalid();

        return process_range(first, last, range_callback);
    }
    return 0;
}
