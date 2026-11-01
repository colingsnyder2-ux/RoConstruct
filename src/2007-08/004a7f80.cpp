// from server: 68% by colin
struct RBX_Reflection_PropertyDescriptor;

struct RBX_Network_Replicator_ChangePropertyItem
{
    void* field0;
    void* field4;
    RBX_Reflection_PropertyDescriptor* getPropertyDescriptor();
    void* func4(void* arg);
};

extern "C" void* __cdecl sub_00630d36(void* a, void* b, void* c, void* d, void* e);
extern "C" void* __cdecl sub_00630b9e(void* a, void* b);
extern "C" void* __stdcall sub_0077e710(void* a);

void* RBX_Network_Replicator_ChangePropertyItem::func4(void* arg)
{
    void* result = sub_00630d36(field0, 0, (void*)0x887174, (void*)0x887d10, 0);
    if (result == 0)
    {
        void* tmp;
        sub_0077e710(&tmp);
        sub_00630b9e(&tmp, (void*)0x841e0c);
        result = tmp;
    }
    void* vtable = *(void**)result;
    void* fn = *(void**)((char*)vtable + 4);
    void* a = field4;
    void* b = arg;
    typedef void* (__thiscall *FnType)(void*, void*, void*);
    ((FnType)fn)(result, a, b);
    return arg;
}
