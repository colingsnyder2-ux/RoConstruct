// from server: 100% by colin
struct EnumDescriptor {
    char padding0[0x28];
    unsigned int count;
    char padding1[0x98];
    int* begin;
    int* end;
};

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* object, const int& value);
};

struct S {
    char padding[0x1c];
    Setter* setter;
    bool f(void* object, unsigned int index);
};

extern char initializationState;
extern void __cdecl initializeDescriptor();
extern void __cdecl ensureInitialized(void (__cdecl *callback)(), void* state);
extern EnumDescriptor* __cdecl getDescriptor();
extern "C" void (__cdecl * const __imp__invalid_parameter_noinfo)();

bool S::f(void* object, unsigned int index)
{
    int value;
    ensureInitialized(initializeDescriptor, &initializationState);
    EnumDescriptor* descriptor = getDescriptor();
    if (index < descriptor->count) {
        if (index >= static_cast<unsigned int>(descriptor->end - descriptor->begin))
            __imp__invalid_parameter_noinfo();

        value = descriptor->begin[index];
        setter->set(object, value);
        return true;
    }
    return false;
}
