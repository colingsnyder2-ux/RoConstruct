// from server: 90% by Intel
// from server: 79% by colin
// roc 2007-08 0076c820  unit: seg_00760000  size: 58 bytes
// 2007-08 hand variant, take 2: the target pushes the ADDRESS of extern functions/tables
// (relocated symbols), not the value loaded out of extern pointers.

extern "C" int __stdcall sub_630D23(void*);

struct Registrar {
    int registerItem(void*, int, void*, void*, int, void*, int, int);
};

extern void callback();          // 0x41af30
extern char tableA[];             // 0x787958
extern char tableB[];             // 0x787964
extern char tableC[];             // 0x78796c
extern Registrar theRegistrar;   // 0x8bafd0 (this for the call)
extern char cleanupTarget[];     // 0x777530

int sub_76C820()
{
    int zero = 0;
    theRegistrar.registerItem(callback, zero, tableA, tableB, 0x1F4, tableC, 0x12C, 1);
    sub_630D23(cleanupTarget);
    return 0;
}
