// from server: 100% by king_originala
struct ArgumentTail {
    char data[76];
    ~ArgumentTail();
};

struct Argument {
    char data[8];
    ArgumentTail tail;
};

extern bool __cdecl func_0060a2f0(const Argument*);
extern void* __cdecl func_006a0920(unsigned int);
extern void __cdecl func_00596a50(void*, const Argument*);
extern int table_00832358[];

struct S {
    int* table;
    char padding[4];
    void* object;

    S(Argument argument);
};

S::S(Argument argument)
{
    table = 0;
    if (!func_0060a2f0(&argument)) {
        void* p = func_006a0920(80);
        func_00596a50(p, &argument);
        object = p;
        table = table_00832358;
    } else {
        table = 0;
    }
}
