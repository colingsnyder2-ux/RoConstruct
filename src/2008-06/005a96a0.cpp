// from server: 100% by king_originala
struct State;

struct Vector3 {
    float x, y, z;
};

extern const char* vectorType;

extern "C" Vector3* __cdecl checkVector(State*, int, const char*);
extern "C" void __cdecl pushBoolean(State*, int);

#pragma float_control(precise, off)

int __cdecl vectorsEqual(State* state)
{
    Vector3* second = checkVector(state, 2, vectorType);
    Vector3* first = checkVector(state, 1, vectorType);

    int equal = (static_cast<double>(first->x) == second->x
              && static_cast<double>(first->y) == second->y
              && static_cast<double>(first->z) == second->z) ? 1 : 0;

    pushBoolean(state, static_cast<unsigned char>(equal));
    return 1;
}
