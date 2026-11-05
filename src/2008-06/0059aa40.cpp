// from server: 100% by king_originala
struct Action {
    bool check();
};

struct Entry {
    char pad[16];
    Action* action;
};

struct Registry {
    Entry* lookup(void* key);
};

struct S_func_0059aa40 {
    bool f();
};

bool S_func_0059aa40::f()
{
    char* owner = reinterpret_cast<char*>(this) - 0x1c0;
    void* key = owner ? reinterpret_cast<char*>(this) - 0x1ac : 0;
    Entry* entry = reinterpret_cast<Registry*>(0x976164)->lookup(key);
    int unavailable = (!entry || entry->action->check()) ? 1 : 0;
    return !static_cast<unsigned char>(unavailable);
}
