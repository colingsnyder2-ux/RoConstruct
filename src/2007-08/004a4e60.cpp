// from server: 100% by colin
struct Instance {
    char pad[0x1e10];
    char flag;
};

struct Replicator {
    void method(int);
};

extern "C" Instance* __cdecl sub_630d36(Instance* inst, int a, const char* b, const char* c, int d);

void __cdecl sub_4a4e60(Instance* inst)
{
    Instance* result = sub_630d36(inst, 0, (const char*)0x881f4c, (const char*)0x88f84c, 0);
    if (result != 0 && result->flag != 0) {
        ((Replicator*)result)->method(0);
    }
}
