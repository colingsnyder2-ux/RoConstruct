// from server: 100% by king_originala
struct Table {
    void (__cdecl *manage)(void *, void *, int);
};

struct Argument {
    unsigned char prefix[8];
    Table *table;
    unsigned char padding[4];
    unsigned char data[24];

    ~Argument();
};

inline Argument::~Argument()
{
    if (table) {
        void (__cdecl *fn)(void *, void *, int) = table->manage;
        if (fn)
            fn(data, data, 1);
    }
}

struct S {
    Table *table;
    unsigned char padding[4];
    unsigned char data[24];

    S(Argument arg);
};

S::S(Argument arg)
{
    table = 0;
    if (arg.table) {
        table = arg.table;
        table->manage(arg.data, data, 0);
    }
}
