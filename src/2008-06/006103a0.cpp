// from server: 100% by king_originala
struct Vector3
{
    float x, y, z;
    Vector3(float a, float b, float c);
};

__forceinline Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

extern const float directionY;
void __cdecl transform(void*, const Vector3&, Vector3&);
bool __cdecl invalid(const Vector3&);
bool __cdecl advance(void*, void*);
void __cdecl update(void*, Vector3&, void*);

void __cdecl process(void* object, Vector3& result, void* state)
{
    transform(object, Vector3(0.0f, directionY, 0.0f), result);
    while (!invalid(result))
    {
        if (advance(object, state))
        {
            update(object, result, state);
            return;
        }
        transform(object, Vector3(0.0f, directionY, 0.0f), result);
    }
}
