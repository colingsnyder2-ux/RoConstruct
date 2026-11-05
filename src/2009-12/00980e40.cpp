// from server: 64% by atomic.potato
extern "C" int __stdcall CloseHandle(int);

extern int G_00b83104;
extern int G_00b83130;

void Function_00980e40()
{
    int value = G_00b83130;
    G_00b83130 = 0;
    if (value != 0)
        CloseHandle(value);
    G_00b83104;
}
