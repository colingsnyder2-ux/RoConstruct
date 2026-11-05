// from server: 70% by atomic.potato
struct Primitive
{
    int f(int);
};

struct KernelJoint
{
    char pad0[0xb8];
    int m_count;
    int __cdecl find(int id);
};

int KernelJoint::find(int id)
{
    int count = m_count;
    int i = 0;
    if (count > 0)
    {
        do
        {
            Primitive* p = (Primitive*)((Primitive*)this)->f(i);
            if (p->f(0) == id)
                return (int)p;
            ++i;
        } while (i < count);
    }
    return 0;
}
