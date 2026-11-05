// from server: 100% by EspClaude
// roc 2009-06 004b9950  unit: RBX::Network::Player  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004b9950
//
// 004b9950  64a100000000         mov eax, dword ptr fs:[0]
// 004b9956  6aff                 push -1
// 004b9958  6848c38500           push 0x85c348
// 004b995d  50                   push eax
// 004b995e  64892500000000       mov dword ptr fs:[0], esp
// 004b9965  8b01                 mov eax, dword ptr [ecx]
// 004b9967  83ec28               sub esp, 0x28
// 004b996a  85c0                 test eax, eax
// 004b996c  7516                 jne 0x4b9984
// 004b996e  8d0c24               lea ecx, [esp]
// 004b9971  e86afbf4ff           call 0x4094e0
// 004b9976  50                   push eax
// 004b9977  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004b997f  e8dc08f5ff           call 0x40a260
// 004b9984  dd442438             fld qword ptr [esp + 0x38]
// 004b9988  8b4004               mov eax, dword ptr [eax + 4]
// 004b998b  83ec08               sub esp, 8
// 004b998e  83c108               add ecx, 8
// 004b9991  dd1c24               fstp qword ptr [esp]
// 004b9994  51                   push ecx
// 004b9995  ffd0                 call eax
// 004b9997  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004b999b  83c40c               add esp, 0xc
// 004b999e  64890d00000000       mov dword ptr fs:[0], ecx
// 004b99a5  83c434               add esp, 0x34
// 004b99a8  c20800               ret 8
// copied from an identical function in another client (function ??RCallable@ns_ROCX000013@@QAEXN@Z)

namespace ns_ROCX000013 {
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
