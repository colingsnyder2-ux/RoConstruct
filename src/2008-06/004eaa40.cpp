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

inline Counter::Counter() : value(0)
{
}

struct Texture {
    int storage[3];
    Texture(int, int, int);
    ~Texture();
};

struct Part {
    int first;
    Counter second;
    Texture texture;

    Part(const Pair&);
    void set(Object*);
    void finish();
};

Part::Part(const Pair& value)
    : first(0), second(), texture(value.first, value.second, 0)
{
    set(new Object);
    finish();
}
