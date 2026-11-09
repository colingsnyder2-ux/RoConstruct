// from server: 100% by tajop
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
