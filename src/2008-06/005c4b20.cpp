// from server: 100% by king_originala
struct String {
    unsigned char storage[28];
    ~String();
};

extern void (__thiscall *string_destroy)(String*);

inline String::~String()
{
    string_destroy(this);
}

struct Argument {
    unsigned int first;
    String text;
    unsigned int extra[2];
};

bool __cdecl func_0060a2f0();
void* __cdecl operator new(unsigned int);
void __cdecl func_005c4a00(void*, Argument*);
extern unsigned char function_table[];

struct S {
    const void* table;
    unsigned int reserved;
    void* object;

    S(Argument argument);
};

S::S(Argument argument)
{
    table = 0;
    if (!reinterpret_cast<bool (__cdecl *)(Argument*)>(
            func_0060a2f0)(&argument)) {
        void* p = operator new(36);
        func_005c4a00(p, &argument);
        object = p;
        table = function_table;
    } else {
        table = 0;
    }
}
