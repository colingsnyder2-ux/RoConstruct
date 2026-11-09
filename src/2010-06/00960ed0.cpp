// from server: 100% by atomic.potato
struct SphereBuilder
{
    int IsSet();
};

int SphereBuilder::IsSet()
{
    return *(int*)((char*)this + 0x360) != 0;
}
