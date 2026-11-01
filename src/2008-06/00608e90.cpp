// from server: 100% by colin
extern "C" void* __cdecl allocate(unsigned int);
extern unsigned char table[];

struct Object {
    void* volatile vtable;
    unsigned char pad04[4];
    volatile unsigned int value08;
    volatile unsigned int value0C;
    volatile unsigned int value10;
    unsigned char pad14[4];
};

Object** __cdecl makeObject(Object** result, unsigned int,
                           volatile unsigned int a,
                           volatile unsigned int b,
                           volatile unsigned int c)
{
    volatile unsigned int state = 0;
    Object* p = static_cast<Object*>(allocate(24));
Object* q;
    if (p) {
        p->vtable = table;
        p->value08 = a;
        p->value0C = b;
        p->value10 = c;
        q = p;
    } else
        q = 0;
    *result = q;
    return result;
}
