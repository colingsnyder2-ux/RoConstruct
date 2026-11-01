// from server: 100% by king_originala
struct Manager;
typedef char *(__thiscall *ManagerFunction)(Manager *);

struct Manager {
    ManagerFunction *vtable;
};

extern Manager manager;
extern "C" void *__cdecl findResource(unsigned int id, void *module);

struct StringBase {
    char *data;
    __forceinline StringBase();
    ~StringBase();
};

struct S : StringBase {
    S(const char *text);
    void loadResource(void *module, unsigned int id);
    void assign(const char *text);
};

__forceinline StringBase::StringBase()
{
    data = manager.vtable[3](&manager) + 16;
}

S::S(const char *text)
{
    if (text != 0 && ((unsigned long)text & 0xffff0000UL) == 0) {
        unsigned int id = (unsigned short)(unsigned long)text;
        void *module = findResource(id, 0);
        if (module != 0)
            loadResource(module, id);
    } else {
        assign(text);
    }
}
