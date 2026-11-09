// from server: 100% by king_originala
struct GetSetImpl
{
    char padding[24];
    void (__thiscall *function)(void *, int);
    int adjustment;
    int index;

    void Invoke(void *argument, const int &value);
};

void GetSetImpl::Invoke(void *argument, const int &value)
{
    char *object = argument ? (char *)argument - 0x14 : 0;
    function(
        object + 0x150 +
        (*(int *)(*(char **)(object + 0x150) + index) + adjustment),
        value);
}
