// from server: 61% by atomic.potato
extern "C" int sub_7a7f70(void *);
extern "C" void sub_41b2e0(void *);

struct CSelectionCaption
{
    int method();
    char data[0x190];
};

int CSelectionCaption::method()
{
    int result = sub_7a7f70(this);
    if (result != -1)
        return 0;
    sub_41b2e0((char *)this + 0x190);
    return 0;
}
