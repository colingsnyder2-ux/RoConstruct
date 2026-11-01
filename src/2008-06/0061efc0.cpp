// from server: 100% by king_originala
struct Text {
    char storage[28];
    ~Text();
};

struct Error {
    char storage[40];
    Error(const Text&);
    Error(const Error&);
    ~Error();
};

struct EnumType;

struct EnumVTable {
    void* first;
    void* (__thiscall *find)(EnumType*, const char*);
};

struct EnumType {
    EnumVTable* table;
};

extern Text __cdecl format(const char*, ...);
extern void __cdecl assign(void*, void*);

int __cdecl convert(EnumType** type, const char* name, void* result)
{
    void* item = (*type)->table->find(*type, name);
    if (item) {
        assign(result, item);
        return 1;
    }
    throw Error(format("%s is not a valid EnumItem", name));
}
