// from server: 24% by Intel
typedef unsigned long DWORD;

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);
extern "C" int __stdcall type_info_equal(void*, void*);

struct VTableBase {
    void* vfptr;
    void* field_4;
    void* field_8;
    void* field_C;
    void (*dtor_func)(void*, int, void*);
};

struct FactoryProduct {
    VTableBase* m_ptr;
};

int __cdecl func_00532670(int a1, FactoryProduct* a2, FactoryProduct* a3) {
    if (a1 == 0) {
        VTableBase* src = a2->m_ptr;
        VTableBase* dest = (VTableBase*)operator_new(0x28);
        a3->m_ptr = dest;
        if (dest) {
            dest->vfptr = src->vfptr;
            dest->field_4 = 0;
            dest->field_8 = src->field_8;
            if (src->field_8) {
                dest->field_8 = src->field_8;
                void* vtable = *(void**)src->field_8;
                src = (VTableBase*)((char*)src + 0x10);
                ((void (__cdecl*)(void*, int, void*))vtable)(dest + 2, 0, src);
            }
        } else {
            a3->m_ptr = 0;
        }
        return 0;
    }
    if (a1 == 1) {
        VTableBase* src = a2->m_ptr;
        a3->m_ptr = src;
        a2->m_ptr = 0;
        return 0;
    }
    if (a1 == 2) {
        VTableBase* obj = a3->m_ptr;
        if (obj) {
            if (obj->field_8) {
                void* vtable = *(void**)obj->field_8;
                if (vtable) {
                    ((void (__cdecl*)(void*, int, void*))vtable)(obj + 2, 2, obj + 2);
                }
                obj->field_8 = 0;
            }
            operator_delete(obj);
        }
        a3->m_ptr = 0;
        return 0;
    }
    if (a1 == 3) {
        VTableBase* obj = a3->m_ptr;
        if (type_info_equal(obj, (void*)0xD807C0)) {
            VTableBase* src = a2->m_ptr;
            a3->m_ptr = src;
            return 0;
        }
        a3->m_ptr = 0;
        return 0;
    }
    a3->m_ptr = (VTableBase*)0xD807C0;
    return 0;
}
