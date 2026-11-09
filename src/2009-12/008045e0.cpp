// from server: 90% by atomic.potato
extern "C" void __stdcall Function007F3DDC(void*);

struct S
{
    void Set(void*);
};

void S::Set(void* value)
{
    if (*(void**)((char*)this + 0x168) != 0)
        Function007F3DDC(*(void**)((char*)this + 0x168));
    *(void**)((char*)this + 0x168) = value;
}
