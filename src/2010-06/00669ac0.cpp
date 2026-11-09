// from server: 57% by atomic.potato
struct VShirtGraphic_BoundPropGetSet {
    char pad_0[8];
    int f_8;
    char pad_c[0x10];
    int f_1c;
    VShirtGraphic_BoundPropGetSet* run(VShirtGraphic_BoundPropGetSet* arg1, VShirtGraphic_BoundPropGetSet* arg2);
};

extern "C" void* __stdcall sub_9EA40C();

VShirtGraphic_BoundPropGetSet* VShirtGraphic_BoundPropGetSet::run(
    VShirtGraphic_BoundPropGetSet* arg1,
    VShirtGraphic_BoundPropGetSet* arg2)
{
    VShirtGraphic_BoundPropGetSet* tmp = arg1;
    if (tmp != 0) {
        tmp = (VShirtGraphic_BoundPropGetSet*)((char*)tmp - 0x1c);
    } else {
        tmp = 0;
    }
    int esi = f_8 + (int)tmp;
    sub_9EA40C();
    arg2->f_1c = *(int*)(esi + 0x1c);
    return arg2;
}
