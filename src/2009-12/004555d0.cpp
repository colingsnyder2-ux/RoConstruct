// from server: 38% by atomic.potato
struct ExitCommand
{
    struct Interface
    {
        virtual int query() = 0;
    };

    Interface* member;
    int f();
};

int ExitCommand::f()
{
    int result = 0;
    if (member != 0 && member->query())
        result = 1;
    return result;
}
