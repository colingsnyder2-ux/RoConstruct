// from server: 100% by Yeetserama
// roc 2011-06 004b3a70  unit: boost::any::N::?$holder  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004b3a70
//
// 004b3a70  64a100000000         mov eax, dword ptr fs:[0]
// 004b3a76  6aff                 push -1
// 004b3a78  6858d89c00           push 0x9cd858
// 004b3a7d  50                   push eax
// 004b3a7e  64892500000000       mov dword ptr fs:[0], esp
// 004b3a85  8b01                 mov eax, dword ptr [ecx]
// 004b3a87  83ec28               sub esp, 0x28
// 004b3a8a  85c0                 test eax, eax
// 004b3a8c  7516                 jne 0x4b3aa4
// 004b3a8e  8d0c24               lea ecx, [esp]
// 004b3a91  e8fa70f5ff           call 0x40ab90
// 004b3a96  50                   push eax
// 004b3a97  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004b3a9f  e8cc9ef5ff           call 0x40d970
// 004b3aa4  dd442438             fld qword ptr [esp + 0x38]
// 004b3aa8  8b4004               mov eax, dword ptr [eax + 4]
// 004b3aab  83ec08               sub esp, 8
// 004b3aae  83c108               add ecx, 8
// 004b3ab1  dd1c24               fstp qword ptr [esp]
// 004b3ab4  51                   push ecx
// 004b3ab5  ffd0                 call eax
// 004b3ab7  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004b3abb  83c40c               add esp, 0xc
// 004b3abe  64890d00000000       mov dword ptr fs:[0], ecx
// 004b3ac5  83c434               add esp, 0x34
// 004b3ac8  c20800               ret 8
// copied from an identical function in another client (function ??RCallable@ns_ROCX000009@@QAEXN@Z)

namespace ns_ROCX000009 {
// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct ExceptionObject
{
    unsigned long words[10];
    ExceptionObject();
    ~ExceptionObject();
};

extern __declspec(noreturn) void __cdecl raise_exception(const void *);

struct FunctionManager
{
    void *reserved;
    void (__cdecl *invoke)(void *, double);
};

struct Callable
{
    FunctionManager *manager;
    unsigned long unused;
    unsigned long storage[2];

    void operator()(double value);
};

inline void Callable::operator()(double value)
{
    if (!manager)
        (raise_exception(&ExceptionObject()), __assume(0));
    manager->invoke(storage, value);
}

struct FunctionObject
{
    unsigned long reserved[2];
    Callable callable;
};

struct Node
{
    unsigned long reserved[6];
    FunctionObject *function;
};

struct Owner
{
    unsigned long reserved[5];
    Node *end;
};

struct Iterator
{
    unsigned long reserved[4];
    Owner **owner;
    Node *node;
    unsigned long unused[8];
    double *value;
    bool *done;

    bool equal(const Iterator &other);
    void advance();
};

void *__stdcall process(void *result, Iterator first, Iterator last)
{
    if (!first.equal(last))
    {
        void (__cdecl *invalid)() = invalid_parameter_noinfo;
        do
        {
            if (!*first.done)
            {
                if (!first.owner)
                    invalid();

                Owner *owner = first.owner ? *first.owner : 0;
                if (first.node == owner->end)
                    invalid();

                Callable *callable = &first.node->function->callable;
                (*callable)(*first.value);

                if (!*first.done)
                    *first.done = true;
            }

            first.advance();
        } while (!first.equal(last));
    }

    return result;
}
}
