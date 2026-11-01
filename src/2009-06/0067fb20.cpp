// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Geometry;
struct Object;
struct Connection;

Connection* __cdecl findConnection(Geometry* a, Geometry* b, int flags);
bool __cdecl isLocked(Object* o);

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual bool active();

    char padding[0xc];
    Geometry* first;
    Geometry* second;
};

struct Handler {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void remove(Object* object);
};

struct Result {
    unsigned long words[3];
};

struct Collection {
    char storage[0x20];
    void insert(Result* result, Object* volatile* object);
};

struct S {
    char padding0[0x54];
    Collection collection;
    unsigned long count;
    char padding1[0xb8 - 0x78];
    Handler* handler;

    void removeConnection(Connection* connection);
    void f(Object* volatile object);
};

void S::f(Object* volatile object)
{
    Object* current = object;
    Geometry* a = current->first;
    Geometry* b = current->second;
    if (a && b && a != b) {
        Connection* connection = findConnection(a, b, 0);
        if (connection && !isLocked((Object*)connection) && !isLocked(current))
            removeConnection(connection);
    }

    handler->remove(current);
    ++count;

    if (current->active()) {
        Result result;
        collection.insert(&result, &object);
    }
}
