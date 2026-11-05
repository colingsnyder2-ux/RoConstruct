// from server: 45% by atomic.potato
struct UserInputJob
{
    UserInputJob *Run(double, double);
};

extern "C" UserInputJob *__stdcall JobCall(UserInputJob *, double, double);

UserInputJob *UserInputJob::Run(double a, double b)
{
    return JobCall(this, a, b);
}
