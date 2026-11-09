// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

extern const float directionY;
void __cdecl transform(void* object, const Vector3& direction, Vector3& result);
bool __cdecl invalid(const Vector3& result);
bool __cdecl advance(void* object, void* state);
void __cdecl update(void* object, Vector3& result, void* state);

void __cdecl process(void* object, Vector3& result, void* state)
{
    Vector3 direction = { 0.0f, directionY, 0.0f };
    transform(object, direction, result);

    while (!invalid(result)) {
        if (advance(object, state)) {
            update(object, result, state);
            break;
        }

        direction.x = 0.0f;
        direction.y = directionY;
        direction.z = 0.0f;
        transform(object, direction, result);
    }
}
