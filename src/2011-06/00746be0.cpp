// from server: 44% by atomic.potato
struct Elem {
    char pad[36];
};

struct Vec {
    Elem* begin;
    Elem* end;
    Elem* cap;
};

struct S {
    Vec v;
    S* assign(S* other);
};

extern "C" void __cdecl free_(void*);
extern "C" Elem* __cdecl alloc_fill(Elem*, Elem*, Elem*, int, int, int);
extern "C" Elem* __cdecl copy_range(Elem*, Elem*, Elem*);
extern "C" bool __cdecl reserve_check(S*, int);
extern "C" Elem* __cdecl move_range(S*, Elem*, Elem*, Elem*);

S* S::assign(S* other) {
    if (this == other) return this;
    int n = (int)((other->v.end - other->v.begin) / 36);
    if (n == 0) {
        if (this->v.begin != this->v.end) {
            this->v.end = alloc_fill(this->v.begin, this->v.end, this->v.end, 0, 0, 0);
        }
        return this;
    }
    int cur = (int)((this->v.end - this->v.begin) / 36);
    if ((unsigned)n <= (unsigned)cur) {
        Elem* src = other->v.begin;
        Elem* dst = this->v.begin;
        alloc_fill(dst, dst, src, 0, 0, 0);
        this->v.end = this->v.begin + n * 36;
        return this;
    }
    int cap = this->v.begin ? (int)((this->v.cap - this->v.begin) / 36) : 0;
    if ((unsigned)n <= (unsigned)cap) {
        Elem* mid = other->v.begin + cur * 36;
        copy_range(this->v.begin, other->v.begin, mid);
        this->v.end = move_range(this, mid, other->v.end, this->v.end);
        return this;
    }
    if (this->v.begin) free_(this->v.begin);
    if (reserve_check(this, n)) {
        this->v.end = move_range(this, other->v.begin, other->v.end, this->v.begin);
    }
    return this;
}
