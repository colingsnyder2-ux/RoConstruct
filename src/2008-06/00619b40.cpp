// from server: 100% by king_originala
struct S
{
    void func_00598c70();
    void func_00598c90();
};

struct State
{
    S* object;
    void func_005f13e0(int value);
    void func_005f1430(int value);
    void func_005f14f0(float value);
    void func_005f15c0(float value);
};

extern float value_00843764;
extern float value_0081e704;

void __stdcall func_00619b40(State* state)
{
    state->object->func_00598c70();
    state->func_005f13e0(7);
    state->func_005f1430(2);
    state->func_005f14f0(value_00843764);
    state->func_005f15c0(value_0081e704);
    state->object->func_00598c90();
}
