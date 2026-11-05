// from server: 68% by atomic.potato
struct SoundChannel {
    char pad0[0x8c];
    void* m_a;
    void* m_b;
    void f_00699e20();
    void f_00699ea0(void* arg);
};

extern "C" void* __stdcall f_0082fcf0(void*, void*);

void SoundChannel::f_00699ea0(void* arg)
{
    void* local;
    f_0082fcf0(&m_a, &local);
    if (local != m_b)
        ((SoundChannel*)local)->f_00699e20();
}
