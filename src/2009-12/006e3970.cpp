// from server: 56% by atomic.potato
struct RotatePJoint
{
    char pad0[576];
    void *object;
    int isReady();
};

int RotatePJoint::isReady()
{
    if (object == 0)
        return 1;

    struct VTable
    {
        int (*functions[11])(void *);
    };

    VTable *table = *(VTable **)object;
    return table->functions[10](object) == 12;
}
