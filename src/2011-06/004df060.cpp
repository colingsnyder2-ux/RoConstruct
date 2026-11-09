// from server: 30% by atomic.potato
extern "C" void __stdcall boost_intrusive_ptr_add_ref(void* p);
extern "C" void* __cdecl sub_4de8a0(void* p);

struct S_func_004df060 {
};

void __cdecl f(void** a1)
{
    int flag = 0;
    void* v = sub_4de8a0(&a1);
    *a1 = v;
    if (*a1 != 0) {
        int c = 1;
        if (c != 0) {
            boost_intrusive_ptr_add_ref(*a1);
        }
    }
    flag |= 1;
}
