// from server: 47% by atomic.potato
extern "C" void construct_string(void *, const char *);

struct S
{
    int f(void *);
};

int S::f(void *arg)
{
    char buffer[28];
    construct_string(buffer, "Duplicate");
    return 0;
}
