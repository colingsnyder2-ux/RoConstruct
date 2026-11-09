// from server: 49% by atomic.potato
struct PartInstance_006cbc10
{
    char pad0[0xa0];
    int m_fieldA0;
    char pad1[0x168 - 0xa4];
    int m_field168;
    void method(int arg);
};

extern "C" void __stdcall sub_0047d8e0(int* out, int val);
extern "C" void __stdcall sub_006edeb0(int* out);

void PartInstance_006cbc10::method(int arg)
{
    int local;
    sub_0047d8e0(&local, m_fieldA0);
    sub_006edeb0(&local);
}
