// from server: 34% by atomic.potato
struct P8SoundChannel {
    void* field0;
    char pad1[0x1c];
    void* field20;

    void GetSetImpl(void* arg0, void* arg1);
};

extern "C" void __stdcall sub_6932B0(void* a, void* b);
extern "C" void __stdcall sub_75A4E0(void* a, void* b, void* c);

void P8SoundChannel::GetSetImpl(void* arg0, void* arg1)
{
    void* p = arg0;
    field0 = arg0;
    sub_6932B0(&field0 + 1, arg1);
    void* q = 0;
    if (arg0 != 0)
        q = (char*)arg0 + 0x20;
    sub_75A4E0(&field0 + 1, q, arg0);
}
