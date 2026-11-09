// from server: 100% by colin
struct Part {
    char pad[0x20];
    int field20;
};

struct JointInstance {
    char pad[8];
    Part* part0;
    Part* part1;
    int getJointType(Part* p);
};

int JointInstance::getJointType(Part* p)
{
    Part* a = *(Part**)((char*)p + 8);
    int r = a->field20;
    if (r == (int)this)
    {
        Part* b = *(Part**)((char*)p + 0xc);
        r = b->field20;
    }
    return r;
}
