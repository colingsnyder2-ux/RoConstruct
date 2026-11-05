// from server: 91% by Intel
extern "C" void __stdcall sub_561950(void*, void*, void*);

struct VHintFactoryProductCreator
{
    void* create(void* a1, void* a2);
};

void* VHintFactoryProductCreator::create(void* a1, void* a2)
{
    static unsigned char counter;
    unsigned char index = counter++;
    unsigned int masked = index & 7;
    unsigned int offset = masked * 7;
    void* pool_entry = (void*)(0xE24240 + offset * 4);
    sub_561950(pool_entry, a1, a2);
    return pool_entry;
}
