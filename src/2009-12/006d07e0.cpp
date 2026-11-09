// from server: 72% by atomic.potato
extern "C" void __stdcall sub_0040C080(void*);

struct SeatImpl
{
    void setValue(float);
};

void SeatImpl::setValue(float value)
{
    float* field = (float*)((char*)this + 0x1bc);
    if (value == *field)
        return;

    *field = value;
    sub_0040C080((void*)0x00B92890);
}
