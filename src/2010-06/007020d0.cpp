// from server: 76% by atomic.potato
extern "C" void __cdecl sub_006fe450(float);

struct EventDesc
{
    void __thiscall f(float);
};

struct GlobalType
{
    void __thiscall g(EventDesc*, float);
};

GlobalType* const g_object = (GlobalType*)0x00c225c0;

void __thiscall EventDesc::f(float value)
{
    sub_006fe450(value);
    g_object->g(this, value);
}
