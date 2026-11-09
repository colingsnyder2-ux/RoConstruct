// from server: 100% by Intel
extern "C" void __stdcall someFunction();

struct S
{
    void Set(void*, void*);
};

void S::Set(void* a1, void* a2)
{
    *(void**)((char*)this + 0xb8) = a1;
    *(void**)((char*)this + 0xbc) = a2;
}
