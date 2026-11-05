// from server: 88% by atomic.potato
struct S
{
    void f(int);
};

void S::f(int)
{
    int* p = (int*)((char*)this + 4);
    int* q = (int*)*p;

    if (q != p)
    {
        do
        {
            int* next = (int*)*q;
            q[0] = 0;
            q[1] = 0;
            q = next;
        } while (q != p);
    }

    p[0] = (int)p;
    p[1] = (int)p;
    *(int*)this = 0;
}
