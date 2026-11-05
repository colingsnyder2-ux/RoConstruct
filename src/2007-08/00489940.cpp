// from server: 51% by colin
struct VPlayerNotifier {
    void* field0;
    void* field4;
    int field8;
    void construct(void* arg);
};

extern "C" void* __cdecl sub_488160();

struct Other {
    void method(void* arg);
};

void VPlayerNotifier::construct(void* arg)
{
    void* p = sub_488160();
    field4 = p;
    *(unsigned char*)((char*)p + 0xe) = 1;
    void* q = field4;
    *(void**)((char*)q + 4) = q;
    void* r = field4;
    *(void**)r = r;
    void* s = field4;
    *(void**)((char*)s + 8) = s;
    field8 = 0;
    ((Other*)this)->method(arg);
}
