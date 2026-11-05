// from server: 100% by atomic.potato
struct CornerWedgePoly
{
    int IsType113();
};

int CornerWedgePoly::IsType113()
{
    return *(int*)((char*)this + 0x14) == 0x113;
}
