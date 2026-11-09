// from server: 100% by king_originala
struct Table {
    void (__cdecl *manage)(void*, void*, int);
};

struct Function {
    Table* table;
    unsigned char padding[4];
    unsigned char data[24];

    Function(const Function&);
    ~Function();
};

inline Function::Function(const Function& other) : table(0)
{
    if (other.table) {
        table = other.table;
        other.table->manage(
            const_cast<unsigned char*>(other.data), data, 0);
    }
}

inline Function::~Function()
{
    if (table) {
        void (__cdecl *manage)(void*, void*, int) = table->manage;
        if (manage)
            manage(data, data, 1);
    }
}

struct Base {
    Base(void*, void*, Function);
};

struct S : Base {
    S(void*, void*, Function);
};

S::S(void* first, void* second, Function function)
    : Base(first, second, function)
{
}
