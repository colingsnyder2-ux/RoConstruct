// from server: 30% by colin
struct Flag {
    char pad[0x21c];
    int field_21c;
    char pad2[0x228 - 0x220];
    int field_228;
    char pad3[0x23c - 0x22c];
    int field_23c;
    void onServiceProvider(void* oldProvider, void* newProvider);
};

extern "C" void __stdcall sub_57aa50(void*, void*);
extern "C" void __stdcall sub_48e1c0(void*);
extern "C" void __stdcall sub_5e49e0(void*, void*);
extern "C" void __stdcall sub_5e65f0(void*, void*);
extern "C" void __stdcall sub_5e6b70(void*);
extern "C" void __stdcall sub_5a4000(void*);
extern "C" void __stdcall sub_728350(void*);
extern "C" void __stdcall sub_450ec0(void*);
extern "C" void* __stdcall sub_630d36(void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_5d1df0(void*);
extern "C" void* __stdcall sub_5e70e0(void*);
extern "C" void* __stdcall sub_5e9f90(void*, void*);
extern "C" void* __stdcall sub_5ea2b0(void*, void*);
extern "C" void __stdcall sub_5e9ef0(void*, void*);

extern double dbl_795c08;
extern void* ptr_8a1bd0;
extern void* ptr_881f4c;
extern void* ptr_5e6df0;

void Flag::onServiceProvider(void* oldProvider, void* newProvider)
{
    sub_57aa50(newProvider, oldProvider);
    if (newProvider == 0) {
        int v;
        if (oldProvider != 0) {
            sub_48e1c0(oldProvider);
            v = 0;
        } else {
            v = 0;
        }
        double d = dbl_795c08;
        this->field_23c = v;
        sub_5e49e0(&d, this);
        sub_5e65f0(&d, &d);
        sub_5e6b70(&d);
        sub_5a4000((void*)this->field_23c);
    }
    if (oldProvider == 0) {
        sub_728350((char*)this + 0x228);
        int v;
        if (newProvider != 0) {
            sub_450ec0(newProvider);
            v = 0;
        } else {
            v = 0;
        }
        if (*(int*)(v + 0x14c) == 1) {
            void* p = (void*)this->field_21c;
            if (p != 0) {
                void* r = sub_630d36(p, 0, ptr_881f4c, ptr_8a1bd0, 0);
                sub_5d1df0(r);
                void* s = sub_5e70e0(this);
                void* t = sub_5e9f90(s, r);
                if (t == 0) {
                    void* u = sub_5ea2b0(s, r);
                    if (u != 0) {
                        sub_5e9ef0(u, r);
                    }
                }
            }
        }
    }
}
