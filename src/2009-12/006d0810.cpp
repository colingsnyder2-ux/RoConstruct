// from server: 72% by atomic.potato
extern "C" void __stdcall sub_0040C080(void*);

struct S
{
    void set(float);
};

void S::set(float value)
{
    float* field = (float*)((char*)this + 0x17c);
    if (value != *field)
    {
        *field = value;
        sub_0040C080((void*)0x00B927A8);
    }
}
