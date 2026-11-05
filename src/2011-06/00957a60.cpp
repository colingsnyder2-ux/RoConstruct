// from server: 56% by atomic.potato
struct Elem {
    char pad[12];
};

struct Vec {
    Elem* begin;
    Elem* end;
    Elem* cap;
    void insert(Elem* pos, unsigned int n, const Elem& val);
    void insert_impl(Elem* pos, unsigned int n, const Elem* val);
};

void Vec::insert(Elem* pos, unsigned int n, const Elem& val) {
    Elem* first = begin;
    int count = (int)((end - first) / 12);
    int idx;
    if (count == 0) {
        idx = 0;
    } else {
        idx = (int)((pos - first) / 12);
    }
    Elem* p = pos;
    unsigned int cnt = n;
    const Elem* v = &val;
    insert_impl(p, cnt, v);
    begin = first;
    Elem* result = begin + idx * 3;
    *(Elem**)val.pad = result;
}
