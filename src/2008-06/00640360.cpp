// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Edge;

struct Geometry {
    char padding[0x1F0];
    bool flag;
    Edge* getFirst();
};

struct Vector {
    float x, y, z;
};

struct Control {
    void addRef();
    void release();
};

struct Count {
    Control* pointer;

    Count() : pointer(0) {}

    Count(const Count& other) : pointer(other.pointer)
    {
        if (pointer)
            pointer->addRef();
    }

    ~Count()
    {
        if (pointer)
            pointer->release();
    }
};

struct Pair {
    void* first;
    Count second;

    Pair() : first(0), second() {}
};

struct Action {
    virtual void slot0();
    virtual int invoke(void*);
    char padding[0x40];

    Action(Geometry*, const Vector&, void*, Pair);
};

struct S {
    char padding[0x18];
    void* context;

    int find(void*, Vector*);
    bool check(Vector*);
    int invoke(void*);
};

int S::invoke(void* argument)
{
    Vector position = { 0.0f, 0.0f, 0.0f };
    Geometry* geometry = reinterpret_cast<Geometry*>(find(argument, &position));

    if (!geometry || geometry->flag ||
        static_cast<unsigned char>(
            reinterpret_cast<unsigned int>(geometry->getFirst())) ||
        !check(&position))
        return 0;

    Action* action = new Action(geometry, position, context, Pair());
    return action->invoke(argument);
}
