// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS /EHsc /MD
typedef unsigned int size_t;

void * __cdecl operator new(size_t, void *);
void __cdecl operator delete(void *, void *);

struct V {
    float x, y, z;
    V(const V &);
    V &operator=(const V &);
};

struct S {
    V *data;
    int count;
    int capacity;

    bool contains(const V &);
    void resize(int, bool);
    void append(const V &, const V &);
};

#pragma strict_gs_check(on)
#pragma optimize("", off)

void S::append(const V &a, const V &b)
{
    if (contains(a) || contains(b)) {
        V copies[2] = { a, b };
        append(copies[0], copies[1]);
    } else if (count + 1 < capacity) {
        new (data + count) V(a);
        new (data + count + 1) V(b);
        count += 2;
    } else {
        resize(count + 2, false);
        data[count - 2] = a;
        data[count - 1] = b;
    }
}

#pragma optimize("", on)
#pragma strict_gs_check(off)
