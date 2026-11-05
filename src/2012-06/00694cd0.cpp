// from server: 100% by tajop
inline void* operator new(unsigned int, void* p) throw() { return p; }

void destroy_fn(void* p);
void clone_fn(void* p);

struct Table {
    void (*destroy)(void*);
    void (*clone)(void*);
    Table() {
        clone = clone_fn;
        destroy = destroy_fn;
    }
    virtual ~Table();
};

struct Holder {
    Table* table;
    int object;
    Holder& assign(const int& x);
};

Holder& Holder::assign(const int& x) {
    static Table t;
    if (table == &t) {
        object = x;
        return *this;
    }
    if (table) {
        table->destroy(&object);
        table = 0;
    }
    new (&object) int(x);
    table = &t;
    return *this;
}
