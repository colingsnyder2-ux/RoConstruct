// from server: 100% by EspClaude
// roc 2009-06 0066a3d0  unit: RBX::VHumanoid::?$BoundFuncDesc  size: 282 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0066a3d0
//
// 0066a3d0  6aff                 push -1
// 0066a3d2  68c0a48500           push 0x85a4c0
// 0066a3d7  64a100000000         mov eax, dword ptr fs:[0]
// 0066a3dd  50                   push eax
// 0066a3de  64892500000000       mov dword ptr fs:[0], esp
// 0066a3e5  83ec1c               sub esp, 0x1c
// 0066a3e8  56                   push esi
// 0066a3e9  57                   push edi
// 0066a3ea  8bf9                 mov edi, ecx
// 0066a3ec  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 0066a3ef  8b4744               mov eax, dword ptr [edi + 0x44]
// 0066a3f2  89442410             mov dword ptr [esp + 0x10], eax
// 0066a3f6  85c9                 test ecx, ecx
// 0066a3f8  7409                 je 0x66a403
// 0066a3fa  8b11                 mov edx, dword ptr [ecx]
// 0066a3fc  8b4208               mov eax, dword ptr [edx + 8]
// 0066a3ff  ffd0                 call eax
// 0066a401  eb02                 jmp 0x66a405
// 0066a403  33c0                 xor eax, eax
// 0066a405  89442414             mov dword ptr [esp + 0x14], eax
// 0066a409  8b742438             mov esi, dword ptr [esp + 0x38]
// 0066a40d  8b16                 mov edx, dword ptr [esi]
// 0066a40f  8b5204               mov edx, dword ptr [edx + 4]
// 0066a412  8d442410             lea eax, [esp + 0x10]
// 0066a416  50                   push eax
// 0066a417  6a01                 push 1
// 0066a419  8bce                 mov ecx, esi
// 0066a41b  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0066a423  ffd2                 call edx
// 0066a425  8b4f50               mov ecx, dword ptr [edi + 0x50]
// 0066a428  8b474c               mov eax, dword ptr [edi + 0x4c]
// 0066a42b  89442408             mov dword ptr [esp + 8], eax
// 0066a42f  85c9                 test ecx, ecx
// 0066a431  7409                 je 0x66a43c
// 0066a433  8b11                 mov edx, dword ptr [ecx]
// 0066a435  8b4208               mov eax, dword ptr [edx + 8]
// 0066a438  ffd0                 call eax
// 0066a43a  eb02                 jmp 0x66a43e
// 0066a43c  33c0                 xor eax, eax
// 0066a43e  8944240c             mov dword ptr [esp + 0xc], eax
// 0066a442  8b16                 mov edx, dword ptr [esi]
// 0066a444  8b5204               mov edx, dword ptr [edx + 4]
// 0066a447  8d442408             lea eax, [esp + 8]
// 0066a44b  50                   push eax
// 0066a44c  6a02                 push 2
// 0066a44e  8bce                 mov ecx, esi
// 0066a450  c644243401           mov byte ptr [esp + 0x34], 1
// 0066a455  ffd2                 call edx
// 0066a457  8b442434             mov eax, dword ptr [esp + 0x34]
// 0066a45b  6a00                 push 0
// 0066a45d  68e4ca9e00           push 0x9ecae4
// 0066a462  68c4bf9d00           push 0x9dbfc4
// 0066a467  6a00                 push 0
// 0066a469  50                   push eax
// 0066a46a  e80bf80a00           call 0x719c7a
// 0066a46f  83c414               add esp, 0x14
// 0066a472  85c0                 test eax, eax
// 0066a474  751e                 jne 0x66a494
// 0066a476  6850d38a00           push 0x8ad350
// 0066a47b  8d4c241c             lea ecx, [esp + 0x1c]
// 0066a47f  ff1570e98900         call dword ptr [0x89e970]
// 0066a485  68b04b9800           push 0x984bb0
// 0066a48a  8d4c241c             lea ecx, [esp + 0x1c]
// 0066a48e  51                   push ecx
// 0066a48f  e8b6f50a00           call 0x719a4a
// 0066a494  8d542408             lea edx, [esp + 8]
// 0066a498  52                   push edx
// 0066a499  8d4c2414             lea ecx, [esp + 0x14]
// 0066a49d  51                   push ecx
// 0066a49e  83c604               add esi, 4
// 0066a4a1  56                   push esi
// 0066a4a2  50                   push eax
// 0066a4a3  8bcf                 mov ecx, edi
// 0066a4a5  e876feffff           call 0x66a320
// 0066a4aa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0066a4ae  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0066a4b3  85c9                 test ecx, ecx
// 0066a4b5  7408                 je 0x66a4bf
// 0066a4b7  8b11                 mov edx, dword ptr [ecx]
// 0066a4b9  8b02                 mov eax, dword ptr [edx]
// 0066a4bb  6a01                 push 1
// 0066a4bd  ffd0                 call eax
// 0066a4bf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0066a4c3  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0066a4cb  85c9                 test ecx, ecx
// 0066a4cd  7408                 je 0x66a4d7
// 0066a4cf  8b11                 mov edx, dword ptr [ecx]
// 0066a4d1  8b02                 mov eax, dword ptr [edx]
// 0066a4d3  6a01                 push 1
// 0066a4d5  ffd0                 call eax
// 0066a4d7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0066a4db  5f                   pop edi
// 0066a4dc  5e                   pop esi
// 0066a4dd  64890d00000000       mov dword ptr fs:[0], ecx
// 0066a4e4  83c428               add esp, 0x28
// 0066a4e7  c20800               ret 8
// copied from an identical function in another client (function ?invoke@S@@QAEXPAVDescribedBase@Reflection@RBX@@PAUArguments@@@Z)

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