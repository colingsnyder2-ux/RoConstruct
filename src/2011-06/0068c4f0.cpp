// from server: 100% by atomic.potato
extern "C" void __stdcall Function_00411f60(int);

struct KeyframeSequence_0068c4f0
{
    char pad0[220];
    unsigned char m_dc;

    void Function_0068c4f0(unsigned char value);
};

void KeyframeSequence_0068c4f0::Function_0068c4f0(unsigned char value)
{
    if (m_dc != value)
    {
        m_dc = value;
        Function_00411f60(0x00CCF2D0);
    }
}
