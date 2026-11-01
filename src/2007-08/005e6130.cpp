// from server: 78% by colin
struct Flag {
    char pad[0x240];
    int value;
    bool canBePickedUpByPlayer(void* p) const;
};

bool Flag::canBePickedUpByPlayer(void* p) const
{
    char* other = (char*)p;
    if (other[0x124] != 0)
        return false;
    return value != *(int*)(other + 0x120);
}
