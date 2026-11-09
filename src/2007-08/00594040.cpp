// from server: 44% by colin
struct DataModel;

struct TToolVerb {
    char pad[0x0c];
    void* container;
    void* createToolVerb(DataModel* dataModel);
};

extern "C" void* __cdecl operator_new(unsigned int size);

void* TToolVerb::createToolVerb(DataModel* dataModel)
{
    void* mem = operator_new(0x4c);
    if (mem) {
        void* p = *(void**)((char*)this + 0x0c);
        void* q = *(void**)((char*)p + 0x188);
        return ((void* (__thiscall*)(void*, void*))0x593ee0)(mem, q);
    }
    return 0;
}
