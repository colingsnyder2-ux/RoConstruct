// from server: 16% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct VCAppIObjectSafetyRobloxImpl {
    void assign(void* p);
};

extern "C" __declspec(dllimport) void* __stdcall sym_func_77e6d0();
extern "C" void __stdcall sub_544ce0(void* p);

void VCAppIObjectSafetyRobloxImpl::assign(void* p)
{
    void* h = sym_func_77e6d0();
    if (h != 0)
        sub_544ce0(h);
}
