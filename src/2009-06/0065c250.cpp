// from server: 88% by EspClaude
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
        char* q = *(char**)((char*)p + 0xa4);
        if (q != 0)
            return (PartInstance*)(q - 0x1c0);
    }
    return 0;
}
