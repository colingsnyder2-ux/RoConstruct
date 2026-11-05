// from server: 22% by atomic.potato
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);
extern "C" int __cdecl type_info_equal(void*, void*);

struct Inner_007ea460 {
    char pad0[8];
    void* field8;
    char padC[4];
    void* field10;
};

struct Outer_007ea460 {
    void* field0;
};

struct Prop_007ea460 {
    void* field0;
    char field4;
    char field5;
    char pad6[2];
};

struct S_007ea460 {
    void* method_007ea040(void*);
    void method_007ea460(int, void*, void*);
};

void S_007ea460::method_007ea460(int op, void* a, void* b)
{
    if (op == 0) {
        Outer_007ea460* src = (Outer_007ea460*)a;
        void* v = src->field0;
        Prop_007ea460* p = (Prop_007ea460*)operator_new(0x30);
        if (p != 0) {
            p = (Prop_007ea460*)method_007ea040(v);
            *(void**)b = p;
        } else {
            *(void**)b = 0;
        }
        return;
    }
    if (op == 1) {
        Outer_007ea460* src = (Outer_007ea460*)a;
        void* v = src->field0;
        *(void**)b = v;
        src->field0 = 0;
        return;
    }
    if (op == 2) {
        Inner_007ea460* p = *(Inner_007ea460**)b;
        if (p != 0) {
            if (p->field8 != 0) {
                void* vt = *(void**)p->field8;
                void* arg = (char*)p + 0x10;
                if (vt != 0) {
                    ((void (__stdcall*)(int, void*, void*))vt)(2, arg, arg);
                }
                p->field8 = 0;
            }
            operator_delete(p);
        }
        *(void**)b = 0;
        return;
    }
    if (op == 3) {
        void** slot = (void**)b;
        void* cur = *slot;
        if (type_info_equal(cur, (void*)0xdd3e88)) {
            Outer_007ea460* src = (Outer_007ea460*)a;
            *slot = src->field0;
        } else {
            *slot = 0;
        }
        return;
    }
    Prop_007ea460* p = (Prop_007ea460*)b;
    p->field4 = 0;
    p->field5 = 0;
    p->field0 = (void*)0xdd3e88;
}
