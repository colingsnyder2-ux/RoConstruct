// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 83% by king_originala
// roc 2008-06 0059dad0  unit: VCRenderSettings::?$EnumPropDescriptor  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059dad0
//
// 0059dad0  83ec18               sub esp, 0x18
// 0059dad3  56                   push esi
// 0059dad4  57                   push edi
// 0059dad5  8bf9                 mov edi, ecx
// 0059dad7  8bb7c8020000         mov esi, dword ptr [edi + 0x2c8]
// 0059dadd  8bce                 mov ecx, esi
// 0059dadf  e87cb8ffff           call 0x599360
// 0059dae4  d986c4000000         fld dword ptr [esi + 0xc4]
// 0059daea  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0059daee  d95c2408             fstp dword ptr [esp + 8]
// 0059daf2  d986c8000000         fld dword ptr [esi + 0xc8]
// 0059daf8  d95c240c             fstp dword ptr [esp + 0xc]
// 0059dafc  d986cc000000         fld dword ptr [esi + 0xcc]
// 0059db02  d95c2410             fstp dword ptr [esp + 0x10]
// 0059db06  d986d0000000         fld dword ptr [esi + 0xd0]
// 0059db0c  d9542414             fst dword ptr [esp + 0x14]
// 0059db10  d986d4000000         fld dword ptr [esi + 0xd4]
// 0059db16  d9542418             fst dword ptr [esp + 0x18]
// 0059db1a  d986d8000000         fld dword ptr [esi + 0xd8]
// 0059db20  d901                 fld dword ptr [ecx]
// 0059db22  ddeb                 fucomp st(3)
// 0059db24  dfe0                 fnstsw ax
// 0059db26  ddda                 fstp st(2)
// 0059db28  f6c444               test ah, 0x44
// 0059db2b  7a1a                 jp 0x59db47
// 0059db2d  d94104               fld dword ptr [ecx + 4]
// 0059db30  dae9                 fucompp 
// 0059db32  dfe0                 fnstsw ax
// 0059db34  f6c444               test ah, 0x44
// 0059db37  7a10                 jp 0x59db49
// 0059db39  d94108               fld dword ptr [ecx + 8]
// 0059db3c  dae9                 fucompp 
// 0059db3e  dfe0                 fnstsw ax
// 0059db40  f6c444               test ah, 0x44
// 0059db43  7b36                 jnp 0x59db7b
// 0059db45  eb04                 jmp 0x59db4b
// 0059db47  ddd8                 fstp st(0)
// 0059db49  ddd8                 fstp st(0)
// 0059db4b  d901                 fld dword ptr [ecx]
// 0059db4d  8d442408             lea eax, [esp + 8]
// 0059db51  d95c2414             fstp dword ptr [esp + 0x14]
// 0059db55  50                   push eax
// 0059db56  d94104               fld dword ptr [ecx + 4]
// 0059db59  d95c241c             fstp dword ptr [esp + 0x1c]
// 0059db5d  d94108               fld dword ptr [ecx + 8]
// 0059db60  8b8fc8020000         mov ecx, dword ptr [edi + 0x2c8]
// 0059db66  d95c2420             fstp dword ptr [esp + 0x20]
// 0059db6a  e8d1640700           call 0x614040
// 0059db6f  6810639700           push 0x976310
// 0059db74  8bcf                 mov ecx, edi
// 0059db76  e885ffe6ff           call 0x40db00
// 0059db7b  5f                   pop edi
// 0059db7c  5e                   pop esi
// 0059db7d  83c418               add esp, 0x18
// 0059db80  c20400               ret 4

struct Vector {
    float x, y, z;
};

struct Frame {
    Vector first;
    Vector second;
};

struct Source {
    char reserved[0xc4];
    Frame value;

    const void* get();
    void set(const Frame& value);
};

extern char property;

struct S {
    char reserved[0x2c8];
    Source* source;

    void changed(const void* property);
    void f(const Vector& value);
};

void S::f(const Vector& value)
{
    Source* p = source;
    p->get();

    Frame frame = {
        { p->value.first.x, p->value.first.y, p->value.first.z },
        { p->value.second.x, p->value.second.y, p->value.second.z }
    };

    if (frame.second.x != value.x ||
        frame.second.y != value.y ||
        frame.second.z != value.z) {
        frame.second.x = value.x;
        frame.second.y = value.y;
        frame.second.z = value.z;
        source->set(frame);
        changed(&property);
    }
}
