// from server: 100% by colin
struct Instance {
    virtual ~Instance();
    unsigned char padding[0x100];
    Instance *parent;
};
struct Workspace : Instance {};

bool __cdecl hasForceField(Instance *object);
extern char instanceType;
extern char workspaceType;
extern "C" void *__cdecl __RTDynamicCast(void *, long, void *, void *, int);

__declspec(dllexport) bool __cdecl protectedByForceField(Instance *object)
{
    if (hasForceField(object))
        goto yes;

    do {
        object = object->parent;
        if (!object)
            goto no;
        if (__RTDynamicCast(object, 0, &instanceType, &workspaceType, 0))
            goto no;
    } while (!hasForceField(object));
yes:
    return true;
no:
    return false;
}
