// from server: 27% by colin
struct RBX_VBodyColors_FactoryProduct_Creator {
    void construct();
};

extern "C" void* __cdecl malloc(unsigned int size);

struct RBX_Name;

struct CreatorBase {
    void registerCreator(RBX_Name* name, RBX_VBodyColors_FactoryProduct_Creator* creator);
};

struct RBX_VBodyColors_FactoryProduct {
    void init(RBX_VBodyColors_FactoryProduct_Creator* creator);
};

void RBX_VBodyColors_FactoryProduct_Creator::construct()
{
    void* mem = malloc(0xec);
    RBX_VBodyColors_FactoryProduct_Creator* obj = 0;
    if (mem) {
        obj = (RBX_VBodyColors_FactoryProduct_Creator*)mem;
        ((void (__thiscall*)(void*))0x5a29f0)(obj);
    }
    RBX_VBodyColors_FactoryProduct* self = (RBX_VBodyColors_FactoryProduct*)((char*)this - 0);
    self->init(obj);
}
