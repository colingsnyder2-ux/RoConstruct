// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Pair {
    int first;
    int second;
};

struct Object {
    char storage[40];
    Object();
};

struct Counter {
    int value;
    Counter();
    ~Counter();
};

struct Texture {
    Texture(int, int, int);
    ~Texture();
};

struct S {
    int first;
    Counter second;
    Texture texture;
    S(const Pair&);
    void set(Object*);
    void finish();
};

inline Counter::Counter() : value(0)
{
}

S::S(const Pair& value)
    : first(0), second(), texture(value.first, value.second, 0)
{
    set(new Object);
    finish();
}
