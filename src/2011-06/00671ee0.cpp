// from server: 57% by atomic.potato
struct RBX_Instance;

extern "C" void* __stdcall sub_80B2EA(void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_411F60(void*, void*);
extern "C" unsigned int __stdcall sub_4A6220(void*);

struct RBX_Instance
{
    void* __cdecl ActionStation(void* arg, char flag);
    char pad[0x44];
    void* field_48;
};

void* RBX_Instance::ActionStation(void* arg, char flag)
{
    void* result = sub_80B2EA(this, 0, (void*)0xC071F8, (void*)0xC0BEEC, 0);
    if (result != 0)
    {
        if (*(char*)((char*)result + 0x180) != flag)
        {
            *(char*)((char*)result + 0x180) = flag;
            sub_411F60(result, (void*)0xCCE088);
        }
        return result;
    }
    unsigned int count = sub_4A6220(this);
    unsigned int i = 0;
    if (count > 0)
    {
        do
        {
            void* p = *(void**)((char*)field_48 + 4);
            void* item = *(void**)((char*)p + i * 8);
            ((RBX_Instance*)item)->ActionStation(arg, flag);
            i++;
        } while (i < sub_4A6220(this));
    }
    return 0;
}
