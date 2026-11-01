// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

extern const float axisValue;

void __cdecl update(void *, const Vector3 &, Vector3 *);
bool __cdecl isZero(const Vector3 *);
bool __cdecl advance(void *, void *);
void __cdecl finish(void *, Vector3 *, void *);

void __cdecl process(void *object, Vector3 *result, void *context)
{
    Vector3 direction = { 0.0f, axisValue, 0.0f };
    update(object, direction, result);
    if (isZero(result))
        return;

    do {
        if (!advance(object, context)) {
            finish(object, result, context);
            return;
        }
        direction.x = 0.0f;
        direction.y = axisValue;
        direction.z = 0.0f;
        update(object, direction, result);
    } while (!isZero(result));
}
