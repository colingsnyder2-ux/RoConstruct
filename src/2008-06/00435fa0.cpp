// from server: 100% by king_originala
extern unsigned char descriptor_00928fe8;
extern unsigned char descriptor_0092f39c;
extern unsigned char descriptor_0092f3cc;

extern "C" void* __cdecl func_006a17c6(
    void*, int, const void*, const void*, int);

struct Handler
{
    void func_00435c80(void*);
    void func_00435180(void*);
    void func_00435860(void*);
};

struct Argument
{
    unsigned char padding[0x5c];
    void* descriptor;
};

struct CClassTreeView
{
    unsigned char padding[0xa8];
    Handler* primary;
    Handler* secondary;

    void func_00435fa0(Argument*, int*);
};

void CClassTreeView::func_00435fa0(Argument* argument, int* result)
{
    void* descriptor = argument->descriptor;

    if (primary)
    {
        void* converted = func_006a17c6(
            descriptor, 0, &descriptor_00928fe8, &descriptor_0092f39c, 0);

        if (converted)
        {
            primary->func_00435c80(converted);
        }
        else
        {
            converted = func_006a17c6(
                descriptor, 0, &descriptor_00928fe8, &descriptor_0092f3cc, 0);

            if (converted)
                primary->func_00435180(converted);
        }
    }

    if (secondary)
        secondary->func_00435860(descriptor);

    *result = 0;
}
