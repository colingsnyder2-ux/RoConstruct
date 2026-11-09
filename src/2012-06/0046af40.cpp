// from server: 70% by atomic.potato
extern "C" void __fastcall G_00414500(void *, int);

struct S
{
    char padding[0x88];
    int value;
    void update(int);
};

void S::update(int v)
{
    if (value != v)
    {
        value = v;
        G_00414500((char *)this + 0x144, 0xe19bb8);
    }
}
