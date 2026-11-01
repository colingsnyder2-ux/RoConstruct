// from server: 100% by EspClaude
// from server: 100% by tester
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct PartInstance;

struct GetSetImpl
{
    static PartInstance* get(PartInstance* p);
};

PartInstance* GetSetImpl::get(PartInstance* p)
{
    if (p != 0) {
        char* q = *(char**)((char*)p + 0xe8);
        if (q != 0)
            return (PartInstance*)(q - 0x9c);
    }
    return 0;
}
