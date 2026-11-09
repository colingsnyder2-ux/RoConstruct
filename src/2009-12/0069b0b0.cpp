// from server: 100% by atomic.potato
struct S
{
    char padding[0x140];
    void* field_140;
    char padding2[0x8B];
    char field_1DC;
    void reset();
};

void S::reset()
{
    *(char*)((char*)this + 0x1DC) = 0;
    reset();
    *(int*)((char*)field_140 + 0x54) = 0;
}
