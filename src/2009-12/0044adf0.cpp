// from server: 95% by atomic.potato
struct S
{
    char pad[222];
    int fieldDE;
    char pad2[4];
    int fieldE6;

    void update(int);
    void notify(const char *);
    void f(int);
};

void S::f(int value)
{
    if (value != fieldE6)
    {
        fieldDE = value;
        update(0);
        notify("(SVW");
    }
}
