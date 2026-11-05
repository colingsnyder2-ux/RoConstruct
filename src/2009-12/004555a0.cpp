// from server: 41% by atomic.potato
struct ExitCommand;

struct ExitTarget
{
    bool CanExit();
    void (*next)(ExitCommand *);
};

struct ExitCommand
{
    int padding[31];
    ExitTarget *target;
    int Run();
};

int ExitCommand::Run()
{
    int result = 0;
    if (target && target->CanExit())
        result = 1;
    return result;
}
