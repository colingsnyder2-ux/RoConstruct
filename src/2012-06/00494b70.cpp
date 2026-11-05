// from server: 45% by Intel


struct CRobloxView {
    int f_00494b70(void* arg1, void** arg2);
};

extern "C" void* __cdecl alloc_004287b0(unsigned int size);
extern "C" void __cdecl free_00428700(void* ptr);
extern "C" void __stdcall method_0048a090(CRobloxView* thisptr, void* arg);
extern "C" void* __stdcall method_00494140(void* thisptr, CRobloxView* view, void* arg);

int CRobloxView::f_00494b70(void* arg1, void** arg2)
{
    void* allocated = alloc_004287b0(0x28);
    void* result = 0;

    if (allocated != 0) {
        result = method_00494140(allocated, this, arg1);
    }

    method_0048a090(this, result);
    *arg2 = result;

    if (result != 0) {
        free_00428700((char*)result + 5);
    }

    return (int)arg2;
}
