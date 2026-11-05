// from server: 51% by atomic.potato
struct VHingeTool;

struct TToolVerb
{
    void *vfptr0;
    void *vfptr1;
    void *ctor(int);
};

extern "C" void *__cdecl sub_80a05e(unsigned int);

struct VHingeTool
{
    char pad[12];
    void *field_c;
    void *createVerb();
};

void *VHingeTool::createVerb()
{
    void *mem = sub_80a05e(0x4c);
    void *result = 0;
    if (mem)
    {
        void *p = *(void **)((char *)field_c + 0xacc);
        ((TToolVerb *)mem)->ctor((int)p);
        *(void **)mem = (void *)0xab918c;
        *(void **)((char *)mem + 4) = (void *)0xab9164;
        result = mem;
    }
    return result;
}
