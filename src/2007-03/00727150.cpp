// from server: 100% by tester
extern "C" int (__stdcall *CloseHandle)(void*);

struct S_func_00726890 {
    void* field0;
    void* field4;
    void* field8;
    void f();
};

void S_func_00726890::f()
{
    int (__stdcall *p)(void*) = CloseHandle;
    p(field0);
    p(field4);
    p(field8);
}
