// from server: 100% by king_originala
extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

struct Object {
    virtual ~Object();
    volatile long references;
    void release();
};

struct Ref {
    Object *p;
    Ref() : p(0) {}
    Ref(Object *q) : p(0) { assign(q); }
    Ref(const Ref &q) : p(0) { assign(q.p); }
    ~Ref();
    void assign(Object *);
    Ref &operator=(const Ref &q) {
        assign(q.p);
        return *this;
    }
};

inline Ref::~Ref()
{
    if (p) {
        if (InterlockedDecrement(&p->references) == 0) {
            p->release();
            if (p)
                delete p;
        }
        p = 0;
    }
}

struct String {
    unsigned char storage[32];
    String(const char *);
    String(const String &);
    ~String();
};

extern void (__thiscall *destroyString)(String *);

inline String::~String()
{
    destroyString(this);
}

extern String __cdecl makeString(const char *);
extern Ref __cdecl load(void *, const String &);

struct Camera {
    unsigned char prefix[4];
    String name;
    Ref cached;
    Ref get(void *);
};

Ref Camera::get(void *context)
{
    if (!cached.p) {
        cached = load(context, name);
        if (!cached.p)
            cached = load(context, makeString("Textures\\ArrowCursor.png"));
    }
    return Ref(cached);
}
