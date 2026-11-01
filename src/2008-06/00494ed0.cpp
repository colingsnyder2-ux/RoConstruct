// from server: 100% by king_originala
struct Argument {
    char data[40];
    ~Argument();
};

extern "C" bool __cdecl func_0060a2f0();
void* __cdecl operator new(unsigned int);
extern "C" void __cdecl initialize(void*, const Argument*);
extern unsigned char functionTable[];

struct S {
    const void* table;
    unsigned int reserved;
    void* object;

    S(Argument argument);
};

S::S(Argument argument)
{
    table = 0;
    if (!reinterpret_cast<bool (__cdecl*)(const Argument*)>(
            func_0060a2f0)(&argument)) {
        void* p = operator new(36);
        initialize(p, &argument);
        object = p;
        table = functionTable;
    } else {
        table = 0;
    }
}
