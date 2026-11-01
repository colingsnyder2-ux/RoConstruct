// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct S {
    Vector3 get();
};

extern void __cdecl consume(void* destination, const Vector3& value);

void __cdecl f(S* object, void* destination)
{
    consume(destination, object->get());
}
