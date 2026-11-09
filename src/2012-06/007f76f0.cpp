// from server: 40% by Intel
struct VInstance {
    void* vfptr;
};

struct NonFactoryProduct {
    void* vfptr;

    int __cdecl method(int a1, VInstance* a2, int* a3);
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);
extern "C" int __stdcall type_info_equals(void* a, void* b);
extern "C" void __stdcall unknown_call_0xdd5248(int a1, int a2);

int NonFactoryProduct::method(int a1, VInstance* a2, int* a3) {
    if (!a1) {
        VInstance* v = a2;
        NonFactoryProduct* obj = (NonFactoryProduct*)operator_new(0x38);
        if (obj) {
            obj->vfptr = v->vfptr;
            *a3 = (int)obj;
        } else {
            *a3 = 0;
        }
        return 0;
    }
    if (a1 == 1) {
        *a3 = *(int*)a2;
        *(int*)a2 = 0;
        return 0;
    }
    if (a1 == 2) {
        int* ptr = (int*)*a3;
        if (ptr) {
            int vfptr_val = ptr[0];
            if (vfptr_val) {
                typedef void (__thiscall* FuncType)(int*, int, int);
                FuncType func = (FuncType)*(int*)vfptr_val;
                if (func) {
                    func(ptr + 2, 2, 2);
                }
            }
            *ptr = 0;
            operator_delete(ptr);
        }
        *a3 = 0;
        return 0;
    }
    if (a1 == 3) {
        int* ptr = (int*)*a3;
        if (type_info_equals(ptr, (void*)0xdd5248)) {
            *a3 = *(int*)a2;
            return 0;
        }
        *a3 = 0;
        return 0;
    }
    *a3 = 0xdd5248;
    *(char*)(*a3 + 4) = 0;
    *(char*)(*a3 + 5) = 0;
    return 0;
}
