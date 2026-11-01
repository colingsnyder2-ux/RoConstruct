// from server: 100% by king_originala
struct S
{
    void func_00598c70();
    void func_00598c90();
};

struct Object
{
    S* receiver;
    void func_005f13e0(int value);
    void func_005f1430(int value);
    void func_005f14f0(float value);
    void func_005f15c0(float value);
};

void __stdcall func_00619af0(Object* object)
{
    object->receiver->func_00598c70();
    object->func_005f13e0(6);
    object->func_005f1430(0);
    object->func_005f14f0(0.0f);
    object->func_005f15c0(0.0f);
    object->receiver->func_00598c90();
}
