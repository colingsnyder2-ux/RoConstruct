// from server: 100% by Yeetserama
// roc 2010-06 00671170  unit: RBX::VHumanoid::?$BoundFuncDesc  size: 282 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00671170
//
// 00671170  6aff                 push -1
// 00671172  6880409a00           push 0x9a4080
// 00671177  64a100000000         mov eax, dword ptr fs:[0]
// 0067117d  50                   push eax
// 0067117e  64892500000000       mov dword ptr fs:[0], esp
// 00671185  83ec1c               sub esp, 0x1c
// 00671188  56                   push esi
// 00671189  57                   push edi
// 0067118a  8bf9                 mov edi, ecx
// 0067118c  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 0067118f  8b4744               mov eax, dword ptr [edi + 0x44]
// 00671192  89442410             mov dword ptr [esp + 0x10], eax
// 00671196  85c9                 test ecx, ecx
// 00671198  7409                 je 0x6711a3
// 0067119a  8b11                 mov edx, dword ptr [ecx]
// 0067119c  8b4208               mov eax, dword ptr [edx + 8]
// 0067119f  ffd0                 call eax
// 006711a1  eb02                 jmp 0x6711a5
// 006711a3  33c0                 xor eax, eax
// 006711a5  89442414             mov dword ptr [esp + 0x14], eax
// 006711a9  8b742438             mov esi, dword ptr [esp + 0x38]
// 006711ad  8b16                 mov edx, dword ptr [esi]
// 006711af  8b5204               mov edx, dword ptr [edx + 4]
// 006711b2  8d442410             lea eax, [esp + 0x10]
// 006711b6  50                   push eax
// 006711b7  6a01                 push 1
// 006711b9  8bce                 mov ecx, esi
// 006711bb  c744243400000000     mov dword ptr [esp + 0x34], 0
// 006711c3  ffd2                 call edx
// 006711c5  8b4f50               mov ecx, dword ptr [edi + 0x50]
// 006711c8  8b474c               mov eax, dword ptr [edi + 0x4c]
// 006711cb  89442408             mov dword ptr [esp + 8], eax
// 006711cf  85c9                 test ecx, ecx
// 006711d1  7409                 je 0x6711dc
// 006711d3  8b11                 mov edx, dword ptr [ecx]
// 006711d5  8b4208               mov eax, dword ptr [edx + 8]
// 006711d8  ffd0                 call eax
// 006711da  eb02                 jmp 0x6711de
// 006711dc  33c0                 xor eax, eax
// 006711de  8944240c             mov dword ptr [esp + 0xc], eax
// 006711e2  8b16                 mov edx, dword ptr [esi]
// 006711e4  8b5204               mov edx, dword ptr [edx + 4]
// 006711e7  8d442408             lea eax, [esp + 8]
// 006711eb  50                   push eax
// 006711ec  6a02                 push 2
// 006711ee  8bce                 mov ecx, esi
// 006711f0  c644243401           mov byte ptr [esp + 0x34], 1
// 006711f5  ffd2                 call edx
// 006711f7  8b442434             mov eax, dword ptr [esp + 0x34]
// 006711fb  6a00                 push 0
// 006711fd  68347db800           push 0xb87d34
// 00671202  684090b700           push 0xb79040
// 00671207  6a00                 push 0
// 00671209  50                   push eax
// 0067120a  e8db791300           call 0x7a8bea
// 0067120f  83c414               add esp, 0x14
// 00671212  85c0                 test eax, eax
// 00671214  751e                 jne 0x671234
// 00671216  68540aa000           push 0xa00a54
// 0067121b  8d4c241c             lea ecx, [esp + 0x1c]
// 0067121f  ff159ca89e00         call dword ptr [0x9ea89c]
// 00671225  689022b100           push 0xb12290
// 0067122a  8d4c241c             lea ecx, [esp + 0x1c]
// 0067122e  51                   push ecx
// 0067122f  e87e771300           call 0x7a89b2
// 00671234  8d542408             lea edx, [esp + 8]
// 00671238  52                   push edx
// 00671239  8d4c2414             lea ecx, [esp + 0x14]
// 0067123d  51                   push ecx
// 0067123e  83c604               add esi, 4
// 00671241  56                   push esi
// 00671242  50                   push eax
// 00671243  8bcf                 mov ecx, edi
// 00671245  e876feffff           call 0x6710c0
// 0067124a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0067124e  c644242c00           mov byte ptr [esp + 0x2c], 0
// 00671253  85c9                 test ecx, ecx
// 00671255  7408                 je 0x67125f
// 00671257  8b11                 mov edx, dword ptr [ecx]
// 00671259  8b02                 mov eax, dword ptr [edx]
// 0067125b  6a01                 push 1
// 0067125d  ffd0                 call eax
// 0067125f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00671263  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0067126b  85c9                 test ecx, ecx
// 0067126d  7408                 je 0x671277
// 0067126f  8b11                 mov edx, dword ptr [ecx]
// 00671271  8b02                 mov eax, dword ptr [edx]
// 00671273  6a01                 push 1
// 00671275  ffd0                 call eax
// 00671277  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0067127b  5f                   pop edi
// 0067127c  5e                   pop esi
// 0067127d  64890d00000000       mov dword ptr fs:[0], ecx
// 00671284  83c428               add esp, 0x28
// 00671287  c20800               ret 8
// copied from an identical function in another client (function ?invoke@S@@QAEXPAVDescribedBase@Reflection@RBX@@PAUArguments@@@Z)

// from server: 100% by colin
#include <typeinfo>
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD


struct Resource {
    virtual ~Resource();
    virtual void reserved() = 0;
    virtual Resource* clone() = 0;
};

#pragma optimize("g", off)
__forceinline Resource* cloneResource(Resource* resource)
{
    if (resource)
        return resource->clone();
    return 0;
}
#pragma optimize("g", on)

struct Value {
    unsigned long value;
    Resource* resource;

    Value(const Value& other);
    ~Value();
};

__forceinline Value::Value(const Value& other)
    : value(other.value), resource(cloneResource(other.resource))
{
}

__forceinline Value::~Value()
{
    if (resource)
        delete resource;
}

struct Arguments {
    virtual void reserved() = 0;
    virtual void read(int index, Value* value) = 0;
};

namespace RBX { namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; } }
using RBX::Reflection::DescribedBase;

namespace RBX { class Humanoid : public DescribedBase {}; }
using RBX::Humanoid;

struct S {
    char padding[68];
    Value first;
    Value second;

    void invoke(DescribedBase* object, Arguments* arguments);
    void execute(Humanoid* object, void* context, Value* first, Value* second);
};

void S::invoke(DescribedBase* object, Arguments* arguments)
{
    Value a(first);
    arguments->read(1, &a);

    Value b(second);
    arguments->read(2, &b);

    Humanoid* humanoid = dynamic_cast<Humanoid*>(object);
    if (!humanoid)
        throw std::bad_cast("bad cast");

    execute(humanoid, reinterpret_cast<char*>(arguments) + 4, &a, &b);
}