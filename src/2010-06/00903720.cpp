// from server: 53% by atomic.potato
struct S
{
    int f(int);
};

void sub_903610(void *, int, char *);

int S::f(int value)
{
    char buffer[8];
    sub_903610((char *)this + 4, value, buffer);
    return 0;
}
