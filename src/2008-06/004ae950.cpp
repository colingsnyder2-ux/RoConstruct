// from server: 100% by king_originala
struct Object;
typedef void (__thiscall *Callback)(Object *, double, unsigned short, unsigned short);

struct Object {
    Callback *vtable;
};

struct Values {
    char padding0[0x154];
    int value;
    unsigned short first;
    char padding1[2];
    unsigned short second;
};

extern "C" Values *__cdecl getValues();

struct S {
    char padding[0x140];
    Object *object;

    void update();
};

void S::update()
{
    Object *target = object;
    Callback *slot = target->vtable + 64;
    (*slot)(target, (double)getValues()->value,
            getValues()->first, getValues()->second);
}
