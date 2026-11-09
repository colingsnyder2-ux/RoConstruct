// from server: 45% by atomic.potato
struct TypedPropertyDescriptor
{
    struct Holder
    {
        struct VTable
        {
            int (__thiscall *invoke)(Holder *, Holder **, void *);
        };

        VTable **vtable;
    };

    char padding[28];
    Holder *holder;

    int __stdcall f(void *);
};

extern "C" int __cdecl sub_7085A0(TypedPropertyDescriptor::Holder *, int);

int __stdcall TypedPropertyDescriptor::f(void *value)
{
    Holder *holder = this->holder;
    Holder *temporary = 0;
    int result = holder->vtable[0]->invoke(holder, &temporary, value);
    return sub_7085A0(temporary, result);
}
