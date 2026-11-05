// from server: 100% by king_originala
struct Error {
    char storage[40];
    Error();
    ~Error();
};

__declspec(noreturn) void __cdecl raise(const Error&);

struct Table {
    void* manager;
    void (__cdecl* invoke)(const void*);
};

struct EventHandler {
    Table* table;
    unsigned int reserved;
    char buffer[16];

    void f() const;
};

void EventHandler::f() const
{
    if (!table)
        raise(Error());

    table->invoke(buffer);
}
