// from server: 51% by atomic.potato
struct VPartDragTool
{
    int named(char *);
};

extern "C" void __stdcall construct_string(char *, const char *);

int VPartDragTool::named(char *value)
{
    char *text;
    if (*(char *)((char *)this + 0x38) != 0)
        text = (char *)0xAB63EC;
    else
        text = (char *)0xABEB50;
    construct_string(value, text);
    return (int)value;
}
