// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

extern const float directionY;

void __cdecl transform(void*, const Vector3&, Vector3&);
bool __cdecl invalid(const Vector3&);
bool __cdecl advance(void*, void*);

void __cdecl update(void* object, Vector3& result, void* state)
{
    Vector3 direction = { 0.0f, directionY, 0.0f };
    transform(object, direction, result);

    while (!invalid(result) && advance(object, state)) {
        direction.x = 0.0f;
        direction.y = directionY;
        direction.z = 0.0f;
        transform(object, direction, result);
    }
}
