// from server: 45% by atomic.potato
extern "C" void __stdcall sub_409480(void*);
extern "C" void __stdcall sub_40A170(void*);

struct VAxesTypedPropertyDescriptor {
    void* field0;
    void* field4;
    void invoke(float a, float b, void* c);
};

void VAxesTypedPropertyDescriptor::invoke(float a, float b, void* c)
{
    if (field0 == 0) {
        char buf[0x28];
        sub_409480(buf);
        sub_40A170(buf);
    }
    void (*fn)(void*, float, float, void*) = (void (*)(void*, float, float, void*))((char*)field0 + 4);
    fn((char*)this + 8, a, b, c);
}
