// from server: 100% by atomic.potato
extern "C" void __cdecl sub_4b00a0(void*, void*, int);

struct VideoControl
{
    void __cdecl f(void*, int);
};

void VideoControl::f(void* a, int b)
{
    if (b != 4)
    {
        sub_4b00a0(this, a, b);
        return;
    }

    *(int*)a = 0x00d72318;
    *((unsigned char*)a + 4) = 0;
    *((unsigned char*)a + 5) = 0;
}
