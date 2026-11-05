// from server: 100% by atomic.potato
struct CEnumMediaTypes
{
    int f(void *);
};

int CEnumMediaTypes::f(void *p)
{
    struct VTable
    {
        void *entries[5];
    };

    struct Object
    {
        VTable *vtable;
    };

    struct State
    {
        int unused0;
        int result;
        Object *object;
        int unused1;
    };

    State *state = (State *)p;
    state->result = 0;
    state->unused1 = ((int (__thiscall *)(Object *))state->object->vtable->entries[4])(state->object);
    return 0;
}
