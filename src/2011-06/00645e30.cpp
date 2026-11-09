// from server: 57% by atomic.potato
struct StarterGuiService
{
    int f(int);
};

int StarterGuiService::f(int value)
{
    if (value)
        value = *(int*)((char*)this + 0xa4);
    return value;
}
