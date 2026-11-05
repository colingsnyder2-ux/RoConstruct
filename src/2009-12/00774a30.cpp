// from server: 51% by atomic.potato
struct VerbWidget
{
    int IsValid();
};

int VerbWidget::IsValid()
{
    struct VTable
    {
        int (__thiscall *IsEnabled)(void *);
        int (__thiscall *GetVerb)(void *);
    };

    struct Object
    {
        VTable *vtable;
    };

    Object *object = (Object *)this;
    if (!object->vtable->IsEnabled(this))
        return 0;
    if (*(int *)((char *)this + 0xac) == 0)
        return 0;

    Object *verb = *(Object **)((char *)this + 0xac);
    if (!verb->vtable->GetVerb(verb))
        return 0;
    return 1;
}
