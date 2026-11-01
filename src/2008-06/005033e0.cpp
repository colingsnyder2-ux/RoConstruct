// from server: 100% by king_originala
extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

struct Object {
    virtual ~Object();
    volatile long references;
    unsigned char padding[32];
    unsigned capacity;

    void release();
    void reset();
};

struct Ref {
    Object *p;

    Ref() : p(0) {}
    Ref(const Ref& other) : p(0) { assign(other.p); }

    Ref& assign(Object *);
    Ref& operator=(const Ref& other) { return assign(other.p); }

    ~Ref() {
        if (p && InterlockedDecrement(&p->references) == 0) {
            p->release();
            if (p)
                delete p;
        }
    }
};

Ref __cdecl createArea(unsigned size, int kind);

struct Input {
    unsigned reserved;
    unsigned count;
};

struct Vertex {
    Ref area;
    unsigned a, b, c, d, e, f, g;

    Vertex(Input *, Ref);
};

struct S {
    unsigned char padding[0x2b0];
    Vertex vertex;
    Ref area;

    void update(Input *);
};

void S::update(Input *input)
{
    unsigned size = input->count * 12 + 16;
    if (area.p && area.p->capacity >= size)
        area.p->reset();
    else
        area = createArea(size, 2);

    vertex = Vertex(input, area);
}
