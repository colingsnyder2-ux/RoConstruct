// from server: 100% by atomic.potato
extern "C" void __cdecl sub_007a799a(int);

struct NetworkOwnerJob
{
    void __thiscall IsEmpty();
};

void __thiscall NetworkOwnerJob::IsEmpty()
{
    if (*(int*)((char*)this + 0x10) != 0)
        sub_007a799a(*(int*)((char*)this + 0x14));
}
