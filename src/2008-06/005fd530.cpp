// from server: 100% by king_originala
#pragma float_control(precise, off)

extern const float scale;

struct V {
    float x, y, z;
};

struct B {
    V* get(V*, int);
};

struct S {
    V* f(V*);
};

V* S::f(V* result)
{
    float factor = scale;
    V temporary;
    V* value = ((B*)((char*)this + 460))->get(&temporary, 2);
    result->x = value->x * factor;
    result->y = value->y * factor;
    result->z = value->z * factor;
    return result;
}
