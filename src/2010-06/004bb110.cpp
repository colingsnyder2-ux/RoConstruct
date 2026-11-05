// from server: 27% by atomic.potato
struct S {
    void* field0;
    void f();
};

extern "C" void* __stdcall sub_7a79a0(unsigned int size);
extern "C" void __stdcall sub_7a799a(void* p);
extern "C" void __stdcall sub_7954f0(void* p);
extern "C" void __stdcall sub_795540(void* p);
extern "C" void __stdcall sub_6f5ac0(void* p);
extern "C" void __stdcall sub_4eeee0(void* p);

void S::f()
{
    if (field0 == 0) {
        sub_7954f0(&field0);
        if (field0 == 0) {
            void* p = sub_7a79a0(0x34);
            if (p) {
                sub_6f5ac0(p);
            } else {
                p = 0;
            }
            void* old = field0;
            field0 = p;
            if (old) {
                sub_4eeee0(old);
                sub_7a799a(old);
            }
        }
        sub_795540(&field0);
    }
}
