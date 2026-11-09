// from server: 58% by atomic.potato
typedef unsigned int DWORD;

struct String
{
    String(const char *);
};

extern "C" void call_base_constructor(void *, void *);

struct UngroupSelectionVerb
{
    int method(void *);
};

int UngroupSelectionVerb::method(void *arg)
{
    String buffer("Gui:RotateAxis");
    call_base_constructor(this, &buffer);
    *(DWORD *)this = 0x00b9c920;
    return (int)this;
}
