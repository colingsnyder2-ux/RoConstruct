// from server: 87% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0059de20  unit: VCRenderSettings::?$EnumPropDescriptor  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059de20
//
// 0059de20  53                   push ebx
// 0059de21  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0059de25  6a00                 push 0
// 0059de27  6850dd9200           push 0x92dd50
// 0059de2c  687c909200           push 0x92907c
// 0059de31  6a00                 push 0
// 0059de33  53                   push ebx
// 0059de34  e88d391000           call 0x6a17c6
// 0059de39  83c414               add esp, 0x14
// 0059de3c  85c0                 test eax, eax
// 0059de3e  7420                 je 0x59de60
// 0059de40  8a4c240c             mov cl, byte ptr [esp + 0xc]
// 0059de44  3a88f0010000         cmp cl, byte ptr [eax + 0x1f0]
// 0059de4a  7460                 je 0x59deac
// 0059de4c  8888f0010000         mov byte ptr [eax + 0x1f0], cl
// 0059de52  68cc609700           push 0x9760cc
// 0059de57  8bc8                 mov ecx, eax
// 0059de59  e8a2fce6ff           call 0x40db00
// 0059de5e  5b                   pop ebx
// 0059de5f  c3                   ret 
// 0059de60  56                   push esi
// 0059de61  8bcb                 mov ecx, ebx
// 0059de63  33f6                 xor esi, esi
// 0059de65  e8b6cfeeff           call 0x48ae20
// 0059de6a  85c0                 test eax, eax
// 0059de6c  763d                 jbe 0x59deab
// 0059de6e  55                   push ebp
// 0059de6f  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0059de73  57                   push edi
// 0059de74  8bbb08010000         mov edi, dword ptr [ebx + 0x108]
// 0059de7a  8b4710               mov eax, dword ptr [edi + 0x10]
// 0059de7d  2b470c               sub eax, dword ptr [edi + 0xc]
// 0059de80  c1f803               sar eax, 3
// 0059de83  3bf0                 cmp esi, eax
// 0059de85  7206                 jb 0x59de8d
// 0059de87  ff1590288000         call dword ptr [0x802890]
// 0059de8d  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0059de90  8b14f1               mov edx, dword ptr [ecx + esi*8]
// 0059de93  55                   push ebp
// 0059de94  52                   push edx
// 0059de95  e886ffffff           call 0x59de20
// 0059de9a  83c408               add esp, 8
// 0059de9d  8bcb                 mov ecx, ebx
// 0059de9f  46                   inc esi
// 0059dea0  e87bcfeeff           call 0x48ae20
// 0059dea5  3bf0                 cmp esi, eax
// 0059dea7  72cb                 jb 0x59de74
// 0059dea9  5f                   pop edi
// 0059deaa  5d                   pop ebp
// 0059deab  5e                   pop esi
// 0059deac  5b                   pop ebx
// 0059dead  c3                   ret 

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
