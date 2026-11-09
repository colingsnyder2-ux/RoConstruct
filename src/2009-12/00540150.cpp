// from server: 88% by atomic.potato
extern "C" void* __cdecl sub_53F650(int);

struct Item
{
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
};

struct Replicator
{
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    Item* __cdecl NewInstanceItem(int);
};

Item* __stdcall NewInstanceItemHelper(Replicator* self, int a)
{
    Item* src = (Item*)sub_53F650(a);
    ((void (__thiscall*)(void*, const void*))0x5F3900)(self, src);
    self->f24 = src->f24;
    self->f28 = src->f28;
    self->f2c = src->f2c;
    return (Item*)self;
}

Item* Replicator::NewInstanceItem(int a)
{
    return NewInstanceItemHelper(this, a);
}
