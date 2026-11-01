// from server: 100% by colin
struct S;

struct S {
    S* findChild(const char* name, int recurse);
    int process();
};

extern "C" int __cdecl func_00630d36(S* self, int a, const char* b, const char* c, int d);

int __cdecl func_005e53c0(S* inst)
{
    while (inst != 0) {
        int r = func_00630d36(inst, 0, (const char*)0x881f4c, (const char*)0x884e04, 0);
        if (r != 0) {
            return ((S*)r)->process();
        }
        inst = *(S**)((char*)inst + 0xbc);
    }
    return 0;
}
