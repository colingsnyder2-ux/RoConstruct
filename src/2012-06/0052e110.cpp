// from server: 100% by Xemicl
// roc 2012-06 0052e110  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0052e110
//
// 0052e110  64a100000000         mov eax, dword ptr fs:[0]
// 0052e116  6aff                 push -1
// 0052e118  68085fad00           push 0xad5f08
// 0052e11d  50                   push eax
// 0052e11e  64892500000000       mov dword ptr fs:[0], esp
// 0052e125  8b01                 mov eax, dword ptr [ecx]
// 0052e127  83ec28               sub esp, 0x28
// 0052e12a  85c0                 test eax, eax
// 0052e12c  7516                 jne 0x52e144
// 0052e12e  8d0c24               lea ecx, [esp]
// 0052e131  e8aae1edff           call 0x40c2e0
// 0052e136  50                   push eax
// 0052e137  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0052e13f  e87c13eeff           call 0x40f4c0
// 0052e144  dd442438             fld qword ptr [esp + 0x38]
// 0052e148  8b4004               mov eax, dword ptr [eax + 4]
// 0052e14b  83ec08               sub esp, 8
// 0052e14e  83c108               add ecx, 8
// 0052e151  dd1c24               fstp qword ptr [esp]
// 0052e154  51                   push ecx
// 0052e155  ffd0                 call eax
// 0052e157  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0052e15b  83c40c               add esp, 0xc
// 0052e15e  64890d00000000       mov dword ptr fs:[0], ecx
// 0052e165  83c434               add esp, 0x34
// 0052e168  c20800               ret 8
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