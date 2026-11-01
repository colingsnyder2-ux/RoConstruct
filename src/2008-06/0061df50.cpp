// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Vector3 {
    float x, y, z;
    Vector3(float, float, float) throw();
    Vector3(const Vector3&) throw();
};

inline Vector3::Vector3(float a, float b, float c) throw()
    : x(a), y(c), z(b) {}

inline Vector3::Vector3(const Vector3& v) throw()
    : x(v.x), y(v.y), z(v.z) {}

struct Transform {
    float rotation[9];
    float translation[3];
    Vector3 apply(const Vector3&) const throw();
};

extern void* transformType;
extern void* vectorType;
extern Vector3 zeroVector;
extern unsigned int zeroInitialized;

extern "C" void* __cdecl getArgument(void*, int, void*);
extern "C" int __cdecl lua_gettop(void*);
extern "C" void __cdecl pushVector(void*, Vector3) throw();

int __cdecl transformArguments(void* state)
{
    Transform* transform =
        static_cast<Transform*>(getArgument(state, 1, transformType));
    int count = lua_gettop(state) - 1;

    if (count == 0) {
        if (!(zeroInitialized & 1)) {
            zeroInitialized |= 1;
            zeroVector.x = 0.0f;
            zeroVector.y = 0.0f;
            zeroVector.z = 0.0f;
        }
        pushVector(state, transform->apply(zeroVector));
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        const Vector3* v =
            static_cast<const Vector3*>(getArgument(state, i + 2, vectorType));

        pushVector(state, Vector3(
            transform->rotation[0] * v->x +
            transform->rotation[1] * v->y +
            transform->rotation[2] * v->z +
            transform->translation[0],
            transform->rotation[6] * v->x +
            transform->rotation[7] * v->y +
            transform->rotation[8] * v->z +
            transform->translation[2],
            transform->rotation[3] * v->x +
            transform->rotation[4] * v->y +
            transform->rotation[5] * v->z +
            transform->translation[1]));
    }

    return count;
}
