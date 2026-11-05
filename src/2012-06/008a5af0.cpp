// from server: 100% by sophus
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base
{
    int field0;
    int field4;
    char padding[0x74];
    Base(void* arg);
};

struct ToolVerb : Base
{
    __forceinline ToolVerb(void* arg);
};

__forceinline ToolVerb::ToolVerb(void* arg) : Base(arg)
{
    field0 = 0xba3c6c;
    field4 = 0xba3c3c;
}

struct FieldC
{
    char padding[0xAC4];
    void* fieldAC4;
};

struct VAdvArrowTool
{
    char padding[0xC];
    FieldC* fieldC;
    ToolVerb* create();
};

ToolVerb* VAdvArrowTool::create()
{
    return new ToolVerb(fieldC->fieldAC4);
}
