// from server: 96% by atomic.potato
struct S_func_0049b430 {
    char pad0[0x34];
    void* field34;
    void* field38;
    void* method(void*);
};

extern "C" void* __stdcall sub_005df560(void*);
extern "C" void* __stdcall sub_00590400(void*);

void* S_func_0049b430::method(void* arg)
{
    sub_005df560(arg);
    field34 = sub_00590400(field34);
    field38 = sub_00590400(field38);
    return this;
}
