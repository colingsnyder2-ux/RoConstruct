// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
struct Interface
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void destroy(unsigned int);
    unsigned char padding[8];
};

struct Object
{
    unsigned char padding[0x1c];
    Interface interfacePart;
    unsigned long references;
};

unsigned long __stdcall release(Object* object)
{
    unsigned long& count = object->references;
    unsigned long result = --count;
    if (result == 0 && object != 0)
        object->interfacePart.destroy(1);
    return result;
}
