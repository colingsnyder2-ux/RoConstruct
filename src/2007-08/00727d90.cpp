// from server: 48% by colin
struct type_info;

struct exception_base {
    void* vftable;
    int refcount;
    int refcount2;
    type_info* type;
};

struct thread_resource_error {
    exception_base* base;
    thread_resource_error(type_info* t);
};

extern "C" void* __cdecl operator_new(unsigned int size);

thread_resource_error::thread_resource_error(type_info* t)
{
    base = 0;
    exception_base* p = (exception_base*)operator_new(0x10);
    if (p != 0) {
        p->refcount = 1;
        p->refcount2 = 1;
        p->vftable = (void*)0x7e5190;
        p->type = t;
    } else {
        p = 0;
    }
    base = p;
}
