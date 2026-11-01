// from server: 100% by king_originala
struct Holder
{
    virtual void __thiscall destroy(unsigned int);
};

extern "C" void __cdecl sub_557330(int, int);
extern "C" int* __cdecl sub_5ED630();
extern "C" int* __cdecl sub_6A0920(int);
extern int holderVtable[];

struct PointerSlot
{
    int* value;
    void assign(int*& source);
};

struct SurfaceDescriptor
{
    int* field0;
    PointerSlot field4;
    SurfaceDescriptor(int*);
};

__forceinline void PointerSlot::assign(int*& source)
{
    int* mem = sub_6A0920(8);
    if (mem)
    {
        mem[0] = (int)holderVtable;
        mem[1] = *source;
    }
    else
    {
        mem = 0;
    }

    int* old = mem;
    if (&source != &value)
    {
        old = value;
        value = mem;
    }

    if (old)
        ((Holder*)old)->destroy(1);
}

SurfaceDescriptor::SurfaceDescriptor(int* p)
{
    sub_557330(0x5ed690, 0x97b120);
    field0 = sub_5ED630();
    field4.assign(p);
}
