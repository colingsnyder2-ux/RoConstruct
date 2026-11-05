// from server: 100% by king_originala
struct Manager;

struct ManagerTable {
    void* slots[4];
    Manager* (__thiscall *getManager)(Manager*);
};

struct Manager {
    ManagerTable* table;
};

struct Header {
    Manager* manager;
    int length;
    int capacity;
    int references;
};

extern Manager defaultManager;
extern Header* __cdecl retainHeader(Header*);

struct S {
    char* data;
    void assign(const char*, int, Manager*);
    S* right(S*, int);
};

S* S::right(S* result, int count)
{
    volatile int state = 0;

    if (count < 0)
        count = 0;

    int length = (reinterpret_cast<Header*>(data) - 1)->length;

    if (count >= length) {
        result->data = reinterpret_cast<char*>(
            retainHeader(reinterpret_cast<Header*>(data) - 1) + 1);
        return result;
    }

    Manager* manager = (reinterpret_cast<Header*>(data) - 1)->manager;
    if (manager)
        manager = manager->table->getManager(manager);

    if (!manager)
        manager = defaultManager.table->getManager(&defaultManager);

    result->assign(data - count + length, count, manager);
    return result;
}
