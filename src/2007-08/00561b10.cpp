// from server: 100% by tester
struct Instance {
    Instance* findFirstChild(const char* name);
};

struct Creator {
    void* create();
};

void* __cdecl findCreator(Instance* inst, int a, const char* name, const char* type, int b);

void* Creator_create(Instance* inst)
{
    while (inst != 0) {
        void* result = findCreator(inst, 0, (const char*)0x881f4c, (const char*)0x884e04, 0);
        if (result != 0) {
            return ((Creator*)result)->create();
        }
        inst = *(Instance**)((char*)inst + 0xbc);
    }
    return 0;
}
