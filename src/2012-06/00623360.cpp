// from server: 100% by tajop
typedef unsigned int size_t_;

struct Elem { int a, b, c; };
struct Alloc {};
struct Tag {};

Elem* allocateElems(size_t_ count, Elem* hint);
Elem* uninitCopy(Elem* first, Elem* last, Elem* dest, Alloc& al, Tag cat, Tag checked);
__declspec(noreturn) void throwTooLong();

inline Tag ptrCat(Elem*&, Elem*&)
{
    Tag cat;
    return cat;
}

inline Elem* uncheckedCopy(Elem* first, Elem* last, Elem* dest, Alloc& al)
{
    return uninitCopy(first, last, dest, al, ptrCat(first, dest), Tag());
}

struct S {
    Alloc al;
    Elem* first;
    Elem* last;
    Elem* end;
    S(const S& other);
    void tidy();
};

S::S(const S& other)
{
    size_t_ count = other.last - other.first;
    first = 0;
    last = 0;
    end = 0;
    if (count != 0) {
        if (count > 0x15555555)
            throwTooLong();
        first = allocateElems(count, (Elem*)0);
        last = first;
        end = first + count;
        try {
            last = uncheckedCopy(other.first, other.last, first, al);
        } catch (...) {
            tidy();
            throw;
        }
    }
}
