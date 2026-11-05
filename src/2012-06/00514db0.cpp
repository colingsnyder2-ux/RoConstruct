// from server: 100% by tajop
struct Elem { int v[5]; };
struct It {
    Elem* p;
    It(Elem* q) : p(q) {}
};
struct Vec {
    int alloc;
    Elem* first;
    Elem* last;
    Elem* cap;
    unsigned size() const { return (unsigned)(last - first); }
    It erase(It f, It l);
    void insert_n(It where, unsigned count, const Elem& val);
    void resize(unsigned n, Elem val);
};
void Vec::resize(unsigned n, Elem val) {
    if (size() < n)
        insert_n(It(last), n - size(), val);
    else if (n < size())
        erase(It(first + n), It(last));
}
