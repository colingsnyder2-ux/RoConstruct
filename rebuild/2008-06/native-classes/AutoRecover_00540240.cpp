// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <locale>

#pragma optimize("g", off)
#pragma strict_gs_check(on)

// INFERRED: Local layouts follow the supplied codegen analog.
struct Local_00540240_Node;

extern "C" int __fastcall fn_00540fb0(void* self, int unusedEdx, Local_00540240_Node* node);
extern "C" int __fastcall fn_00540b10(void* self, int unusedEdx, void* result, void* value);

struct Local_00540240_Ctype : std::ctype<char>
{
    static __forceinline void destroy(void* value)
    {
        static_cast<Local_00540240_Ctype*>(value)->std::ctype<char>::~ctype();
    }
};

struct Local_00540240_Handle
{
    Local_00540240_Node* pointer;
    void* control;

    __forceinline Local_00540240_Handle(Local_00540240_Node* node)
    {
        fn_00540fb0(this, 0, node);
    }

    __forceinline ~Local_00540240_Handle()
    {
        Local_00540240_Ctype::destroy(this);
    }
};

struct Local_00540240_Iterator
{
    Local_00540240_Node* node;
    void* owner;
};

struct Local_00540240_InsertResult
{
    Local_00540240_Iterator position;
    bool inserted;
};

struct Local_00540240_Bucket
{
    unsigned char storage[32];
};

struct Local_00540240
{
    unsigned char padding[40];
    Local_00540240_Bucket first;
    Local_00540240_Bucket second;
};

extern "C" void __fastcall fn_00540240(
    Local_00540240* self, int unusedEdx, Local_00540240_Node* node, bool flag)
{
    if (flag)
    {
        {
            Local_00540240_Handle value(node);
            Local_00540240_InsertResult result;
            fn_00540b10(&self->first, 0, &result, &value);
        }
        do {} while (0);
        do {} while (0);
    }
    else
    {
        {
            Local_00540240_Handle value(node);
            Local_00540240_InsertResult result;
            fn_00540b10(&self->second, 0, &result, &value);
        }
        do {} while (0);
        do {} while (0);
    }
}
