// from server: 43% by atomic.potato
struct EventDesc
{
    int Dispatch(int value);
};

extern "C" void __stdcall Call_87E530(void*);

int EventDesc::Dispatch(int value)
{
    char* p = *(char**)((char*)this + 0x2c);
    if (value != 0)
        p += value - 0x1c;
    Call_87E530(p);
    return 0;
}
