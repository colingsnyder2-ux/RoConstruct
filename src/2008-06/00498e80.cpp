// from server: 100% by king_originala
void __cdecl alignedFree(void*);

struct Array {
    void* data;
    int size;
    int capacity;

    Array(const Array&);
    ~Array();
};

__forceinline Array::~Array()
{
    alignedFree(data);
}

struct Payload {
    Array array;
    volatile bool first;
    volatile bool second;
};

struct Base {
    Base(int, int, Payload);
};

struct S : Base {
    S(int, int, Payload);
};

S::S(volatile int a, volatile int b, Payload payload)
    : Base(a, b, payload)
{
}
