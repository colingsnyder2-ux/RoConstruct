// from server: 100% by king_originala
extern void __cdecl registerType(void (__cdecl *)(), void *);
extern void __cdecl typeCallback();
extern char typeFlag;
extern void *__cdecl getType();
extern void *__cdecl getSettings();
extern void __cdecl destroyObject(void *);
extern const unsigned long typeTable[];

struct Owner {
    void *pointer;
    explicit Owner(void *);
    ~Owner();
    void *release();
};

__forceinline Owner::Owner(void *p) : pointer(p) {}

__forceinline Owner::~Owner()
{
    if (pointer)
        destroyObject(pointer);
}

__forceinline void *Owner::release()
{
    void *p = pointer;
    pointer = 0;
    return p;
}

extern Owner __cdecl createObject(int, int, int, int);

struct Core {
    const unsigned long *table;
    char storage[20];
    Core(void *, void *, int, int, int);
    ~Core();
};

struct Base : Core {
    void *descriptor;
    Base(void *, void *, int, int, int);
};

__forceinline Base::Base(void *settings, void *type, int a, int b, int g)
    : Core(settings, type, a, b, g), descriptor(type)
{
}

struct S : Base {
    Owner object;
    void *type;
    S(int, int, int, int, int, int, int);
};

S::S(int a, int b, int c, int d, int e, int f, int g)
    : Base(getSettings(),
           (registerType(typeCallback, &typeFlag), getType()),
           a, b, g),
      object((table = typeTable, createObject(c, d, e, f).release())),
      type((registerType(typeCallback, &typeFlag), getType()))
{
}
