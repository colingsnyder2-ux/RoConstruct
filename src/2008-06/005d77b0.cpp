// from server: 100% by colin
struct Humanoid {
    char pad[0xd0];
    void* ptr;
    int getField();
};

int Humanoid::getField()
{
    if (ptr)
        return *(int*)((char*)ptr + 0x84);
    return 0;
}
