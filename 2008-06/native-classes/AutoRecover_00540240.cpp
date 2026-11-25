// native-flags: /Od /Ob0 /GS /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: server-verified analog shape from packet_00540240.md; unknown
// callees use the required fn_<addr> naming convention.
#pragma optimize("g", off)

extern "C" int __fastcall fn_00540fb0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00540b10(void* self, int unusedEdx, void* a1, void* a2);
extern "C" void __fastcall fn_00541030(void* self);

struct Node;

struct Handle
{
    Node* pointer;
    void* control;

    explicit Handle(int n)
    {
        fn_00540fb0(this, 0, n);
    }
    ~Handle()
    {
        fn_00541030(this);
    }
};

struct Iterator
{
    Node* node;
    void* owner;
};

struct InsertResult
{
    Iterator position;
    bool inserted;
};

struct Bucket
{
    unsigned char storage[32];
};

struct Local_00540240_S
{
    unsigned char padding[40];
    Bucket first;
    Bucket second;
};

extern "C" void __fastcall fn_00540240(Local_00540240_S* self, int unusedEdx, int arg1, unsigned char flag)
{
    if (flag)
    {
        {
            Handle value(arg1);
            InsertResult result;
            fn_00540b10(&self->first, 0, &result, &value);
        }
        do {} while (0);
        do {} while (0);
    }
    else
    {
        {
            Handle value(arg1);
            InsertResult result;
            fn_00540b10(&self->second, 0, &result, &value);
        }
        do {} while (0);
        do {} while (0);
    }
}
