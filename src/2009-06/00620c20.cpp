// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00590440  unit: RBX::RootInstance  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00590440
//
// 00590440  83ec10               sub esp, 0x10
// 00590443  53                   push ebx
// 00590444  55                   push ebp
// 00590445  56                   push esi
// 00590446  8b742420             mov esi, dword ptr [esp + 0x20]
// 0059044a  57                   push edi
// 0059044b  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0059044e  33ed                 xor ebp, ebp
// 00590450  bbf0a85500           mov ebx, 0x55a8f0
// 00590455  397e0c               cmp dword ptr [esi + 0xc], edi
// 00590458  7606                 jbe 0x590460
// 0059045a  ff1590288000         call dword ptr [0x802890]
// 00590460  8b560c               mov edx, dword ptr [esi + 0xc]
// 00590463  8b06                 mov eax, dword ptr [esi]
// 00590465  89442410             mov dword ptr [esp + 0x10], eax
// 00590469  89542424             mov dword ptr [esp + 0x24], edx
// 0059046d  3b5610               cmp edx, dword ptr [esi + 0x10]
// 00590470  760a                 jbe 0x59047c
// 00590472  ff1590288000         call dword ptr [0x802890]
// 00590478  8b542424             mov edx, dword ptr [esp + 0x24]
// 0059047c  8b0e                 mov ecx, dword ptr [esi]
// 0059047e  83ec10               sub esp, 0x10
// 00590481  8bc4                 mov eax, esp
// 00590483  8918                 mov dword ptr [eax], ebx
// 00590485  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 00590489  896804               mov dword ptr [eax + 4], ebp
// 0059048c  895808               mov dword ptr [eax + 8], ebx
// 0059048f  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 00590493  57                   push edi
// 00590494  89580c               mov dword ptr [eax + 0xc], ebx
// 00590497  8b442424             mov eax, dword ptr [esp + 0x24]
// 0059049b  50                   push eax
// 0059049c  52                   push edx
// 0059049d  51                   push ecx
// 0059049e  8d4c2430             lea ecx, [esp + 0x30]
// 005904a2  51                   push ecx
// 005904a3  e848ffffff           call 0x5903f0
// 005904a8  8b4610               mov eax, dword ptr [esi + 0x10]
// 005904ab  2b460c               sub eax, dword ptr [esi + 0xc]
// 005904ae  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 005904b2  c1f803               sar eax, 3
// 005904b5  83c424               add esp, 0x24
// 005904b8  33ff                 xor edi, edi
// 005904ba  85c0                 test eax, eax
// 005904bc  7628                 jbe 0x5904e6
// 005904be  3bf8                 cmp edi, eax
// 005904c0  7206                 jb 0x5904c8
// 005904c2  ff1590288000         call dword ptr [0x802890]
// 005904c8  8b560c               mov edx, dword ptr [esi + 0xc]
// 005904cb  8b04fa               mov eax, dword ptr [edx + edi*8]
// 005904ce  53                   push ebx
// 005904cf  50                   push eax
// 005904d0  e86bc10000           call 0x59c640
// 005904d5  8b4610               mov eax, dword ptr [esi + 0x10]
// 005904d8  2b460c               sub eax, dword ptr [esi + 0xc]
// 005904db  47                   inc edi
// 005904dc  c1f803               sar eax, 3
// 005904df  83c408               add esp, 8
// 005904e2  3bf8                 cmp edi, eax
// 005904e4  72e2                 jb 0x5904c8
// 005904e6  53                   push ebx
// 005904e7  e854e80700           call 0x60ed40
// 005904ec  83c404               add esp, 4
// 005904ef  5f                   pop edi
// 005904f0  5e                   pop esi
// 005904f1  5d                   pop ebp
// 005904f2  5b                   pop ebx
// 005904f3  83c410               add esp, 0x10
// 005904f6  c20c00               ret 0xc

struct Base1 {};
struct Base2 {};

struct __multiple_inheritance Object : Base1, Base2
{
    void callback();
};

struct Entry
{
    Object* object;
    int unused;
};

struct Iterator
{
    int unused;
    Entry* position;
};

struct Functor
{
    void (Object::*function)();
    void* argument;
    int unused;
};

struct Container
{
    int owner;
    int unused1;
    int unused2;
    Entry* first;
    Entry* last;
};

extern "C" void (__cdecl* _invalid_parameter_noinfo)();
extern Functor __cdecl apply(Iterator, Iterator, Functor);
extern void __cdecl visit(Object*, void*);
extern void __cdecl finish(void*);

void __stdcall process(Container* container, void* argument, void* context)
{
    Entry* end = container->last;

    Functor operation;
    operation.function = &Object::callback;
    operation.argument = argument;

    if (container->first > end)
        _invalid_parameter_noinfo();

    Iterator last;
    last.unused = container->owner;
    last.position = end;

    Entry* begin = container->first;
    if (begin > container->last)
        _invalid_parameter_noinfo();

    Iterator first;
    first.unused = container->owner;
    first.position = begin;

    apply(first, last, operation);

    for (unsigned int i = 0;
         i < static_cast<unsigned int>(container->last - container->first);
         ++i)
    {
        if (i >= static_cast<unsigned int>(container->last - container->first))
            _invalid_parameter_noinfo();

        visit(container->first[i].object, context);
    }

    finish(context);
}
