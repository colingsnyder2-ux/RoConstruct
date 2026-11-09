// from server: 54% by atomic.potato
struct S_0079b020 {
    char pad0[56];
    int* field_28;
    int* field_38;

    bool __thiscall f(S_0079b020* arg);
};

struct S_esi {
    char pad0[40];
    int* field_28;
};

extern "C" int* __cdecl func_0052acb0();
extern "C" bool __stdcall func_006c8100(int*);
extern "C" void __stdcall func_00795770(int*);

bool __thiscall S_0079b020::f(S_0079b020* arg) {
    if (!arg)
        return false;

    S_esi* esi = (S_esi*)arg->field_38;
    if (!esi)
        return false;

    int* edi = esi->field_28;
    int* eax = func_0052acb0();
    bool result = func_006c8100(edi);
    if (!result)
        return false;

    func_00795770((int*)esi);
    return true;
}
