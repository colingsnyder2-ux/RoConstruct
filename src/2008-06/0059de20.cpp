// from server: 100% by king_originala
struct Instance;

struct ChildEntry
{
    Instance* object;
    void* control;
};

struct Children
{
    char padding[12];
    ChildEntry* first;
    ChildEntry* last;
};

struct Instance
{
    char padding[0x108];
    Children* children;

    unsigned int childCount();
    void raisePropertyChanged(const char& descriptor);
};

struct PartInstance
{
    char padding[0x1f0];
    bool value;

    void raisePropertyChanged(const char& descriptor);
};

extern char instanceType;
extern char partInstanceType;
extern char propertyDescriptor;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

void __cdecl setValue(Instance* object, bool value)
{
    PartInstance* part = static_cast<PartInstance*>(
        __RTDynamicCast(object, 0, &instanceType, &partInstanceType, 0));

    if (part) {
        if (value != part->value) {
            part->value = value;
            part->raisePropertyChanged(propertyDescriptor);
        }
    } else {
        for (unsigned int i = 0; i < object->childCount(); ++i) {
            Children* children = object->children;
            if (i >= static_cast<unsigned int>(children->last - children->first))
                _invalid_parameter_noinfo();
            setValue(children->first[i].object, value);
        }
    }
}
