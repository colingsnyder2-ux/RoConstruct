// from server: 83% by atomic.potato
struct NetworkOwnerJob
{
    int value;
    int next;
    int f(int);
};

int NetworkOwnerJob::f(int)
{
    int* sentinel = &next;
    int* p = (int*)next;

    while (p != sentinel)
    {
        int* n = (int*)p[0];
        p[0] = 0;
        p[1] = 0;
        p = n;
    }

    next = (int)sentinel;
    *(int*)this = 0;
    return 0;
}
