// from server: 16% by atomic.potato
extern "C" int __cdecl Function_918fe0(int);

int Function_918cb0(int value)
{
    int selected;
    if (1)
        selected = value;
    else
        selected = *(int*)value;
    return Function_918fe0(selected);
}
