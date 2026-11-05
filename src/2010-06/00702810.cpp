// from server: 17% by atomic.potato
extern "C" void* __stdcall sub_7A79A0(unsigned int size);
extern "C" void __stdcall sub_7A799A(void* p);
extern "C" void __stdcall sub_4EEEE0(void* p);

struct S_7954F0 {
    void* field0;
    void ctor(const char* name);
    void dtor();
};

struct S_6F5AC0 {
    void ctor();
};

struct S_702810 {
    void* field0;
    void f();
};

void S_702810::f()
{
    if (this->field0 == 0)
    {
        S_7954F0 local;
        local.ctor((const char*)0x00C22758);
        if (this->field0 == 0)
        {
            S_6F5AC0* p = (S_6F5AC0*)sub_7A79A0(0x34);
            if (p != 0)
            {
                p->ctor();
            }
            else
            {
                p = 0;
            }
            void* old = this->field0;
            this->field0 = p;
            if (old != 0)
            {
                sub_4EEEE0(old);
                sub_7A799A(old);
            }
        }
        local.dtor();
    }
}
