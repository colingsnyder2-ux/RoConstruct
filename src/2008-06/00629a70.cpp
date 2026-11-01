// from server: 100% by king_originala
struct S;
struct Subobject;

extern "C" void* __cdecl check_object(S*);
extern "C" bool __cdecl check_enabled(S*, int);

struct Event {
    void notify(char*);
};

struct Result {
    char pad[16];
    Event event;
};

struct Registry {
    Result* find(Subobject*);
};

extern Registry registry;

struct Subobject {
    char data;
};

struct S {
    char pad[20];
    Subobject subobject;
    void f(int);
};

void S::f(int)
{
    char token;
    if (check_object(this) && check_enabled(this, 1)) {
        Result* result = registry.find(this ? &subobject : 0);
        if (result)
            result->event.notify(&token);
    }
}
