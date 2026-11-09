// from server: 30% by atomic.potato
extern "C" void* __stdcall sub_7A79A0(unsigned int);
extern "C" void __stdcall sub_7A799A(void*);
extern "C" void __stdcall sub_7954F0(void*);
extern "C" void __stdcall sub_795540(void*);
extern "C" void __stdcall sub_6F5AC0(void*);
extern "C" void __stdcall sub_4EEEE0(void*);

struct S {
    void* field0;
    void f();
};

void S::f()
{
    if (field0 == 0) {
        sub_7954F0((char*)this + 4);
        if (field0 == 0) {
            void* p = sub_7A79A0(0x34);
            if (p != 0) {
                sub_6F5AC0(p);
            } else {
                p = 0;
            }
            void* old = field0;
            field0 = p;
            if (old != 0) {
                sub_4EEEE0(old);
                sub_7A799A(old);
            }
        }
        sub_795540((char*)this + 4);
    }
}
