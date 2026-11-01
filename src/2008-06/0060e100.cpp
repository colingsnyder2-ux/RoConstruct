// from server: 100% by king_originala
void __cdecl alignedFree(void*);

struct Array
{
    void* data;
    int capacity;
    int size;

    __forceinline Array();
    __forceinline ~Array();
};

__forceinline Array::Array()
{
    capacity = 0;
    size = 0;
    data = 0;
}

__forceinline Array::~Array()
{
    alignedFree(data);
}

struct Vector
{
    float x, y, z;
    Vector(const Vector&);
};

void __cdecl collect(void*, Array*);
Vector __cdecl calculate(const Array*, int, int);

struct Contact
{
    char prefix[8];
    char source[32];
    int value;

    Vector f(int);
};

Vector Contact::f(int index)
{
    Array temporary;
    collect(source, &temporary);
    return calculate(&temporary, index, value);
}
