// from server: 93% by EspClaude
// roc 2007-08 005cfbf0  unit: RBX::LocalBackpackItem  size: 55 bytes
// roc-flags: /O2 /GS /EHsc /MD /fp:fast
struct Vector2 {
    float x;
    float y;
    Vector2() {}
    Vector2(float a, float b) : x(a), y(b) {}
};

struct S_func_005cfbf0 {
    Vector2 f();
};

extern float G_func_00796468;
extern "C" Vector2* __cdecl func_00555990(Vector2* a, Vector2* b);

Vector2 S_func_005cfbf0::f()
{
    Vector2 a(G_func_00796468, G_func_00796468);
    Vector2 b;
    float s = func_00555990(&b, &a)->x;
    return Vector2(s, s);
}
