// from server: 80% by atomic.potato
extern "C" void __cdecl Function_00411f60();

struct KeyframeSequence_0068c520
{
    int pad0[56];
    int m_e0;

    void Function_0068c520(int);
};

void KeyframeSequence_0068c520::Function_0068c520(int value)
{
    if (m_e0 != value)
    {
        m_e0 = value;
        Function_00411f60();
    }
}
