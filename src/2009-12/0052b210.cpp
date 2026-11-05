// from server: 65% by atomic.potato
struct JobContext
{
    int (**vtable)(JobContext*, int);
};

struct PhysicsSender_Job
{
    char pad0[8];
    unsigned char active;
    char pad9[3];
    JobContext* context;
    int f(int);
};

int PhysicsSender_Job::f(int value)
{
    if (active != 0)
    {
        JobContext* p = context;
        if ((*p->vtable)(p, value) == 0)
            return 0;
    }
    return 1;
}
