// from server: 65% by atomic.potato
extern "C" void __stdcall sub_0079c260(int, int);

struct RBX_HUMAN_Dead {
    void* construct(int, int);
};

void* RBX_HUMAN_Dead::construct(int a, int b)
{
    sub_0079c260(a, b);
    *(int*)this = 0xabedc8;
    *(int*)((char*)this + 4) = 0xabedbc;
    *(float*)((char*)this + 0xc) = *(float*)0xa76e74;

    return this;
}
