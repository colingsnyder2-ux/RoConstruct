// from server: 100% by king_originala
extern const float value_00843764;
extern const float value_0081e704;

struct S
{
    void func_00598c70();
    void func_00598c90();
};

struct Part
{
    S* object;
    void setShouldRender(int value);
    void func_005f1430(int value);
    void func_005f14f0(float value);
    void func_005f15c0(float value);
};

void __stdcall func_00619b90(Part* part)
{
    part->object->func_00598c70();
    part->setShouldRender(7);
    part->func_005f1430(1);
    part->func_005f14f0(value_00843764);
    part->func_005f15c0(value_0081e704);
    part->object->func_00598c90();
}
