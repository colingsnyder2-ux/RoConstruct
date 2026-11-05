// from server: 100% by EspClaude
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

enum EnumValue { EnumZero = 0 };

struct Property {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const EnumValue&);
};

struct IntVector {
    unsigned int* first;
    unsigned int* last;
    unsigned int* end;
    unsigned int size() const { return first ? last - first : 0; }
    unsigned int operator[](unsigned int i) const {
        if (i >= (unsigned int)(last - first))
            _invalid_parameter_noinfo();
        return first[i];
    }
};

struct EnumMap {
    char padding0[0x28];
    unsigned int enumCount;
    char padding1[0x94];
    unsigned int proxy;
    IntVector indexToEnum;
    __forceinline bool convertToValue(unsigned int index, EnumValue& value) const {
        if (index < enumCount) {
            value = (EnumValue)indexToEnum[index];
            return true;
        }
        return false;
    }
};

struct Descriptor {
    char padding[0x1c];
    Property* property;
    EnumMap* enumMap;
    void setValue(void* o, EnumValue value) const { property->set(o, value); }
    bool set(void*, unsigned int);
};

bool Descriptor::set(void* instance, unsigned int index)
{
    EnumValue val;
    if (enumMap->convertToValue(index, val)) {
        setValue(instance, val);
        return true;
    }
    return false;
}
