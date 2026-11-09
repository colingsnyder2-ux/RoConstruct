// from server: 100% by king_originala
extern void __cdecl alignedFree(void *);

struct Buffer {
    void *data;
    int size;
    int capacity;

    Buffer() : size(0), capacity(0) { data = 0; }
    ~Buffer() { alignedFree(data); }
};

extern void __cdecl prepare(void *, Buffer *);
extern void __cdecl construct(void *, Buffer *, int, int);

struct S {
    char padding[8];
    char storage[32];
    int value;

    void *f(void *, int);
};

void *S::f(void *result, int argument)
{
    Buffer buffer;
    prepare(storage, &buffer);
    construct(result, &buffer, argument, value);
    return result;
}
