// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00574050  unit: RBX::TopMenuBar  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00574050
//
// 00574050  83ec10               sub esp, 0x10
// 00574053  53                   push ebx
// 00574054  8bd9                 mov ebx, ecx
// 00574056  8b03                 mov eax, dword ptr [ebx]
// 00574058  8b5054               mov edx, dword ptr [eax + 0x54]
// 0057405b  ffd2                 call edx
// 0057405d  84c0                 test al, al
// 0057405f  0f84c0000000         je 0x574125
// 00574065  55                   push ebp
// 00574066  56                   push esi
// 00574067  e8a46e2400           call 0x7baf10
// 0057406c  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00574070  8bd0                 mov edx, eax
// 00574072  d902                 fld dword ptr [edx]
// 00574074  8d8b44010000         lea ecx, [ebx + 0x144]
// 0057407a  d819                 fcomp dword ptr [ecx]
// 0057407c  dfe0                 fnstsw ax
// 0057407e  f6c444               test ah, 0x44
// 00574081  7a27                 jp 0x5740aa
// 00574083  d94204               fld dword ptr [edx + 4]
// 00574086  d85904               fcomp dword ptr [ecx + 4]
// 00574089  dfe0                 fnstsw ax
// 0057408b  f6c444               test ah, 0x44
// 0057408e  7a1a                 jp 0x5740aa
// 00574090  d94208               fld dword ptr [edx + 8]
// 00574093  d85908               fcomp dword ptr [ecx + 8]
// 00574096  dfe0                 fnstsw ax
// 00574098  f6c444               test ah, 0x44
// 0057409b  7a0d                 jp 0x5740aa
// 0057409d  d9420c               fld dword ptr [edx + 0xc]
// 005740a0  d8590c               fcomp dword ptr [ecx + 0xc]
// 005740a3  dfe0                 fnstsw ax
// 005740a5  f6c444               test ah, 0x44
// 005740a8  7b1a                 jnp 0x5740c4
// 005740aa  8b7500               mov esi, dword ptr [ebp]
// 005740ad  51                   push ecx
// 005740ae  8d442410             lea eax, [esp + 0x10]
// 005740b2  50                   push eax
// 005740b3  8bcb                 mov ecx, ebx
// 005740b5  83c62c               add esi, 0x2c
// 005740b8  e8a3f8ffff           call 0x573960
// 005740bd  8b16                 mov edx, dword ptr [esi]
// 005740bf  50                   push eax
// 005740c0  8bcd                 mov ecx, ebp
// 005740c2  ffd2                 call edx
// 005740c4  57                   push edi
// 005740c5  8bcb                 mov ecx, ebx
// 005740c7  33ff                 xor edi, edi
// 005740c9  e8526df1ff           call 0x48ae20
// 005740ce  85c0                 test eax, eax
// 005740d0  7650                 jbe 0x574122
// 005740d2  8bb308010000         mov esi, dword ptr [ebx + 0x108]
// 005740d8  8b4610               mov eax, dword ptr [esi + 0x10]
// 005740db  2b460c               sub eax, dword ptr [esi + 0xc]
// 005740de  c1f803               sar eax, 3
// 005740e1  3bf8                 cmp edi, eax
// 005740e3  7206                 jb 0x5740eb
// 005740e5  ff1590288000         call dword ptr [0x802890]
// 005740eb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005740ee  8b04f9               mov eax, dword ptr [ecx + edi*8]
// 005740f1  6a00                 push 0
// 005740f3  68d8b89200           push 0x92b8d8
// 005740f8  687c909200           push 0x92907c
// 005740fd  6a00                 push 0
// 005740ff  50                   push eax
// 00574100  e8c1d61200           call 0x6a17c6
// 00574105  83c414               add esp, 0x14
// 00574108  85c0                 test eax, eax
// 0057410a  740a                 je 0x574116
// 0057410c  8b10                 mov edx, dword ptr [eax]
// 0057410e  8bc8                 mov ecx, eax
// 00574110  8b4260               mov eax, dword ptr [edx + 0x60]
// 00574113  55                   push ebp
// 00574114  ffd0                 call eax
// 00574116  8bcb                 mov ecx, ebx
// 00574118  47                   inc edi
// 00574119  e8026df1ff           call 0x48ae20
// 0057411e  3bf8                 cmp edi, eax
// 00574120  72b0                 jb 0x5740d2
// 00574122  5f                   pop edi
// 00574123  5e                   pop esi
// 00574124  5d                   pop ebp
// 00574125  5b                   pop ebx
// 00574126  83c410               add esp, 0x10
// 00574129  c20400               ret 4

#pragma float_control(precise, off)

struct Rect {
    float x, y, z, w;
    bool operator!=(const Rect &) const;
};

__forceinline bool Rect::operator!=(const Rect &other) const
{
    return x != other.x || y != other.y ||
           z != other.z || w != other.w;
}

struct Context;
struct Item;
struct S;

struct ContextVTable {
    char padding[44];
    void (__thiscall *draw)(Context *, const Rect &);
};

struct Context {
    ContextVTable *vtable;
};

struct ItemVTable {
    char padding[100];
    void (__thiscall *render)(Item *, Context *);
};

struct Item {
    ItemVTable *vtable;
};

struct Entry {
    void *object;
    void *owner;
    void *get() const;
};

__forceinline void *Entry::get() const
{
    return object;
}

struct Children {
    char padding[12];
    Entry *begin;
    Entry *end;
};

struct SVTable {
    char padding[88];
    bool (__thiscall *enabled)(S *);
};

struct S {
    SVTable *vtable;
    char padding0[0x48];
    Children *children;
    char padding1[0x50];
    Rect rectangle;

    unsigned int count();
    Rect query(const Rect &);
    void f(Context *);
};

extern const Rect &__cdecl emptyRectangle();
extern "C" void (__cdecl *_invalid_parameter_noinfo)();
extern "C" void *__cdecl runtimeCast(
    void *, int, const void *, const void *, int);
extern char instanceDescriptor;
extern char itemDescriptor;

void S::f(Context *context)
{
    if (vtable->enabled(this)) {
        const Rect &empty = emptyRectangle();

        if (rectangle != empty)
            context->vtable->draw(context, query(rectangle));

        for (unsigned int i = 0; i < count(); ++i) {
            Children *list = children;
            if (i >= static_cast<unsigned int>(list->end - list->begin))
                _invalid_parameter_noinfo();

            Item *item = static_cast<Item *>(
                runtimeCast(list->begin[i].get(), 0,
                            &instanceDescriptor, &itemDescriptor, 0));
            if (item)
                item->vtable->render(item, context);
        }
    }
}
