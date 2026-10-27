extern "C" __stdcall func_at_80245c(void);
extern "C" __stdcall func_at_802468(void*, void*);
extern "C" __stdcall func_409ef0(void);
extern "C" __stdcall func_40a500(const void*);

struct RBX::Reflection::$$A6AXPBVPropertyDescriptor::V?$function::?$holder {
    void* object;
};

void __thiscall RBX::Reflection::$$A6AXPBVPropertyDescriptor::V?$function::?$holder::invoke()
{
    if (object == 0) {
        func_409ef0();
    } else {
        func_at_80245c();
        func_at_802468(0, 0);
    }
}