// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 00824270  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00824270
//
// 00824270  51                   push ecx
// 00824271  56                   push esi
// 00824272  6870057700           push 0x770570
// 00824277  68a485e400           push 0xe485a4
// 0082427c  8bf1                 mov esi, ecx
// 0082427e  e81dd3bdff           call 0x4015a0
// 00824283  83c408               add esp, 8
// 00824286  e885c2f4ff           call 0x770510
// 0082428b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0082428f  3b482c               cmp ecx, dword ptr [eax + 0x2c]
// 00824292  7328                 jae 0x8242bc
// 00824294  8b8090000000         mov eax, dword ptr [eax + 0x90]
// 0082429a  8b0c88               mov ecx, dword ptr [eax + ecx*4]
// 0082429d  894c2404             mov dword ptr [esp + 4], ecx
// 008242a1  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 008242a4  8b11                 mov edx, dword ptr [ecx]
// 008242a6  8b520c               mov edx, dword ptr [edx + 0xc]
// 008242a9  8d442404             lea eax, [esp + 4]
// 008242ad  50                   push eax
// 008242ae  8b442410             mov eax, dword ptr [esp + 0x10]
// 008242b2  50                   push eax
// 008242b3  ffd2                 call edx
// 008242b5  b001                 mov al, 1
// 008242b7  5e                   pop esi
// 008242b8  59                   pop ecx
// 008242b9  c20800               ret 8
// 008242bc  32c0                 xor al, al
// 008242be  5e                   pop esi
// 008242bf  59                   pop ecx
// 008242c0  c20800               ret 8

struct DescribedBase;

enum InputType { NO_INPUT = 0 };

struct GetSet
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void setValue(DescribedBase* instance, const InputType& value) const = 0;
};

struct EnumDescT
{
    char pad0[0x2c];
    unsigned int count;
    char pad1[0x60];
    InputType* values;
    bool convertToValue(unsigned int index, InputType& value) const
    {
        if (index < count)
        {
            value = values[index];
            return true;
        }
        return false;
    }
};

struct OnceFlag { int v; };
extern OnceFlag g_enumOnceFlag;
void enumInitFn();
void callOnce(OnceFlag& flag, void (*func)());
EnumDescT& enumSingleton();

struct SurfaceEnumPropDescriptor
{
    char pad0[0x2c];
    GetSet* getset;
    bool setIndex(DescribedBase* instance, unsigned int index) const;
};

bool SurfaceEnumPropDescriptor::setIndex(DescribedBase* instance, unsigned int index) const
{
    InputType value;
    callOnce(g_enumOnceFlag, enumInitFn);
    if (enumSingleton().convertToValue(index, value))
    {
        getset->setValue(instance, value);
        return true;
    }
    return false;
}
