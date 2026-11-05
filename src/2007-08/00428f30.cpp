// from server: 100% by colin
// roc 2007-08 00428f30  unit: seg_00420000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00428f30

extern "C" void* __cdecl sub_62fef6(unsigned int size);

struct MainLogManager
{
    void* init();
};

void* MainLogManager::init()
{
    void* p = sub_62fef6(0x148);
    if (p)
        *(void**)p = p;
    void** q = (void**)((char*)p + 4);
    if (q)
        *q = p;
    return p;
}
