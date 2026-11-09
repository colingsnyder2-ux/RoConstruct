// from server: 100% by king_originala
struct Object {
    virtual ~Object();
};

struct Result {
    void release();
};

struct ObjectArray {
    Object** data;
    int count;
    int capacity;
    void resize(int, int);
};

struct OtherArray {
    void* data;
    int count;
    int capacity;
    void resize(int, int);
};

struct Contact {
    char padding[0x34];
    ObjectArray objects;
    OtherArray others;

    Result* find(Object*);
    void clear();
};

void Contact::clear()
{
    for (int i = 0; i < objects.count; ++i) {
        Object*& object = objects.data[i];
        find(object)->release();
        delete object;
        object = 0;
    }
    objects.resize(0, 0);
    others.resize(0, 0);
}
