// from server: 100% by king_originala
struct Geometry;
struct Object;

void* __cdecl findConnection(Geometry* a, Geometry* b);

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual bool active();

    char padding[8];
    Geometry* first;
    Geometry* second;
};

struct Handler {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
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
    char padding0[0x88];
    Handler* handler;
    char padding1[0x38];
    Collection collection;
    unsigned long count;

    void removeConnection(void* connection);
    void f(Object* volatile object);
};

void S::f(Object* volatile object)
{
    Object* current = object;
    Geometry* a = current->first;
    Geometry* b = current->second;
    if (a && b && a != b) {
        void* connection = findConnection(a, b);
        if (connection)
            removeConnection(connection);
    }

    handler->remove(current);
    ++count;

    if (current->active()) {
        Result result;
        collection.insert(&result, &object);
    }
}
