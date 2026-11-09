// from server: 52% by colin
struct S_func_00464180 {
    char pad0[0x34];
    char m_lock[0x24];
    float m_f58;
    float m_f5c;
    float m_f60;
    float m_f64;
    float m_f70;
    float m_f74;
    float *f(float *out);
};

extern "C" void __stdcall LeaveCriticalSection(void *);

extern "C" void __stdcall sub_0041d870(void *);

float *S_func_00464180::f(float *out)
{
    struct Lock {
        void *cs;
        char locked;
    };
    Lock lock;
    lock.cs = m_lock;
    lock.locked = 0;
    sub_0041d870(&lock);

    float a = m_f58;
    float b = m_f5c;
    float c = m_f60;
    float d = m_f64;

    float x = (c + a) * *(double *)0x795b48;
    float y = (d + b) * *(double *)0x795b48;

    out[0] = x + m_f70;
    out[1] = y + m_f74;

    if (lock.locked) {
        LeaveCriticalSection(lock.cs);
    }
    return out;
}
