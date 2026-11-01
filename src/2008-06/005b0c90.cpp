// from server: 100% by king_originala
struct GetSetImpl
{
    char padding[8];
    int (__thiscall *function)(void *);
    int adjustment;
    int index;

    int Invoke(void *argument);
};

int GetSetImpl::Invoke(void *argument)
{
    char *object = argument ? (char *)argument - 0x14 : 0;
    return function(
        object + 0x150 +
        (*(int *)(*(char **)(object + 0x150) + index) + adjustment));
}
