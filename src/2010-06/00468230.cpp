// from server: 66% by atomic.potato
extern "C" void __cdecl CallJob(double, void *, void *);

struct UserInputJob
{
    UserInputJob *f(void *, void *);
};

UserInputJob *UserInputJob::f(void *a, void *b)
{
    CallJob(0.0, b, a);
    return this;
}
