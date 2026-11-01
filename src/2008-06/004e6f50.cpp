// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern "C" void __stdcall copy_element(void*, const void*);
extern "C" void __stdcall destroy_element(void*);
extern "C" void __stdcall copy_array(
    void*, const void*, unsigned int, int,
    void (__stdcall *)(void*, const void*),
    void (__stdcall *)(void*));

struct Handle {
    unsigned int value;
    Handle(const Handle&);
};

inline Handle::Handle(const Handle& other)
{
    copy_array(this, &other, 4, 1, copy_element, destroy_element);
}

struct Vector {
    float x, y, z;
    Vector(const Vector&);
};

inline Vector::Vector(const Vector& other)
    : x(other.x), y(other.y), z(other.z)
{
}

struct S {
    int value;
    Vector position;
    Handle handle;
    S* child;

    S(Vector, Handle, int, S*);
    S* clone();
};

S* S::clone()
{
    return new S(position, handle, value, child ? child->clone() : 0);
}
