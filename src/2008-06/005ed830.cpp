// from server: 100% by colin
extern char descriptorData;
extern void __cdecl initializeDescriptor();
extern void __cdecl registerDescriptor(void (__cdecl *)(), void *);

struct EnumDescriptor {
    bool contains(int value);
};

extern EnumDescriptor * __cdecl getEnumDescriptor();

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void *object, const int *value);
};

struct S {
    char padding[28];
    Setter *setter;
    bool f(void *object, int value);
};

bool S::f(void *object, int value)
{
    registerDescriptor(initializeDescriptor, &descriptorData);
    EnumDescriptor *descriptor = getEnumDescriptor();
    if (descriptor->contains(value)) {
        int converted = value;
        setter->set(object, &converted);
        return true;
    }
    return false;
}
