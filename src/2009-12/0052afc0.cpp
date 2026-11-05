// from server: 19% by atomic.potato
struct Job
{
    int GetValue();
    int Send(int, int, double);
};

int Job::GetValue()
{
    return 0;
}

int Job::Send(int a, int b, double c)
{
    return b;
}
