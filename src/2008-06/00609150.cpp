// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*) throw();

struct Matrix {
    float elements[9];
};

struct Value {
    Matrix rotation;
    float x, y, z;
    Value();
};

struct S {
    unsigned char padding[0x19c];
    Value* value;
    void f(const Value& source);
};

void S::f(const Value& source)
{
    if (!value) {
        Value* replacement = new Value;
        Value* previous = value;
        value = replacement;
        if (previous)
            operator delete(previous);

        Value* destination = value;
        destination->rotation = source.rotation;
        destination->x = source.x;
        destination->y = source.y;
        destination->z = source.z;
    }
}
