// from server: 100% by atomic.potato
struct NetworkOwnerJob
{
    int __cdecl IsEmpty();
};

int __cdecl NetworkOwnerJob::IsEmpty()
{
    return *(int*)((char*)this + 0x14) == 0;
}
