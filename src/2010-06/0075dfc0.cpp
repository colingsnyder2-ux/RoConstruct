// from server: 49% by atomic.potato
struct MultiJoint
{
    void *get(int);
    void *update(int);
};

void *MultiJoint::update(int)
{
    int i = 0;
    void *p;
    do
    {
        p = get(i);
        if (p && *((MultiJoint **) ((char *)p + 0x24)) == this)
            break;
        ++i;
    } while (i < 2);

    return (void *)update(0);
}
