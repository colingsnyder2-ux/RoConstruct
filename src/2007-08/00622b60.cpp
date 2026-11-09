// from server: 100% by colin
struct Instance {
    char pad[0xbc];
    Instance* next;
};

extern "C" int __cdecl sub_630d36(Instance*, int, const char*, const char*, int);
extern "C" int __fastcall sub_450b40(Instance*);

Instance* FindInstance(Instance* inst) {
    while (inst != 0) {
        int result = sub_630d36(inst, 0, (const char*)0x881f4c, (const char*)0x884e04, 0);
        if (result != 0) {
            return (Instance*)sub_450b40((Instance*)result);
        }
        inst = inst->next;
    }
    return 0;
}
