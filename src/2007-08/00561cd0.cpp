// from server: 100% by colin
struct Instance;

extern "C" void* __cdecl func_00630d36(Instance* self, int a, void* b, void* c, int d);
extern "C" void* __fastcall func_00450ec0(void* p);

struct FilteredSelection {
    static Instance* findFirstChildOfClass(Instance* inst, const char* className);
};

Instance* FilteredSelection::findFirstChildOfClass(Instance* inst, const char* className)
{
    while (inst != 0) {
        void* result = func_00630d36(inst, 0, (void*)0x881f4c, (void*)0x884e04, 0);
        if (result != 0)
            return (Instance*)func_00450ec0(result);
        inst = *(Instance**)((char*)inst + 0xbc);
    }
    return 0;
}
