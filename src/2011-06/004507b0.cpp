// from server: 80% by atomic.potato
struct VAuthoringSettings_BoundPropGetSet
{
    int padding;
    int value;

    int get(int *p);
};

int VAuthoringSettings_BoundPropGetSet::get(int *p)
{
    if (p)
        return *(int *)((char *)p + value - 0x1c);
    return *(int *)value;
}
