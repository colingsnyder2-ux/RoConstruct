// from server: 100% by king_originala
struct String {
    char data[28];
    ~String();
};

struct Argument {
    unsigned int prefix[2];
    String text;
    unsigned int suffix[6];
};

extern bool __cdecl func_0060a2f0();
extern void* __cdecl operator new(unsigned int);
extern void __cdecl func_00418fb0(void*, const Argument*);
extern const unsigned char functionTable[];

struct S {
    const void* table;
    unsigned int reserved;
    void* object;

    S(Argument argument);
};

S::S(Argument argument)
{
    table = 0;
    if (!reinterpret_cast<bool (__cdecl *)(const Argument*)>(
            &func_0060a2f0)(&argument)) {
        void* storage = operator new(0x38);
        func_00418fb0(storage, &argument);
        object = storage;
        table = functionTable;
    } else {
        table = 0;
    }
}
