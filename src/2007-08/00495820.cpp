// from server: 100% by colin
// roc 2007-08 00495820  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00495820

struct DescribedBase;

struct ClassDescriptor
{
    char pad[0x138];
    int value;
};

extern "C" ClassDescriptor* __cdecl getClassDescriptor(DescribedBase* object);

int getValue(DescribedBase* object)
{
    ClassDescriptor* cd = getClassDescriptor(object);
    if (cd)
        return cd->value;
    return 0;
}
