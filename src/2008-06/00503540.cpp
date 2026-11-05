// from server: 100% by colin
// from server: 97% by king_originala
// roc 2008-06 00503540  unit: RBX::Render::RenderScene  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00503540
//
// 00503540  51                   push ecx
// 00503541  55                   push ebp
// 00503542  57                   push edi
// 00503543  8bf9                 mov edi, ecx
// 00503545  33ed                 xor ebp, ebp
// 00503547  39af6c020000         cmp dword ptr [edi + 0x26c], ebp
// 0050354d  7e7f                 jle 0x5035ce
// 0050354f  53                   push ebx
// 00503550  56                   push esi
// 00503551  33db                 xor ebx, ebx
// 00503553  8bb768020000         mov esi, dword ptr [edi + 0x268]
// 00503559  03f3                 add esi, ebx
// 0050355b  837e3400             cmp dword ptr [esi + 0x34], 0
// 0050355f  89742410             mov dword ptr [esp + 0x10], esi
// 00503563  745b                 je 0x5035c0
// 00503565  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00503568  8b01                 mov eax, dword ptr [ecx]
// 0050356a  8b5028               mov edx, dword ptr [eax + 0x28]
// 0050356d  ffd2                 call edx
// 0050356f  d81dc4358100         fcomp dword ptr [0x8135c4]
// 00503575  dfe0                 fnstsw ax
// 00503577  f6c441               test ah, 0x41
// 0050357a  750d                 jne 0x503589
// 0050357c  8d442410             lea eax, [esp + 0x10]
// 00503580  50                   push eax
// 00503581  8d8f8c020000         lea ecx, [edi + 0x28c]
// 00503587  eb32                 jmp 0x5035bb
// 00503589  8d4c2410             lea ecx, [esp + 0x10]
// 0050358d  51                   push ecx
// 0050358e  8d8f74020000         lea ecx, [edi + 0x274]
// 00503594  e8f7faffff           call 0x503090
// 00503599  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0050359c  8b11                 mov edx, dword ptr [ecx]
// 0050359e  8b4224               mov eax, dword ptr [edx + 0x24]
// 005035a1  ffd0                 call eax
// 005035a3  d81dc4358100         fcomp dword ptr [0x8135c4]
// 005035a9  dfe0                 fnstsw ax
// 005035ab  f6c441               test ah, 0x41
// 005035ae  7510                 jne 0x5035c0
// 005035b0  8d4c2410             lea ecx, [esp + 0x10]
// 005035b4  51                   push ecx
// 005035b5  8d8f80020000         lea ecx, [edi + 0x280]
// 005035bb  e8d0faffff           call 0x503090
// 005035c0  45                   inc ebp
// 005035c1  83c344               add ebx, 0x44
// 005035c4  3baf6c020000         cmp ebp, dword ptr [edi + 0x26c]
// 005035ca  7c87                 jl 0x503553
// 005035cc  5e                   pop esi
// 005035cd  5b                   pop ebx
// 005035ce  5f                   pop edi
// 005035cf  5d                   pop ebp
// 005035d0  59                   pop ecx
// 005035d1  c3                   ret 

struct Material
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual float reflectance();
    virtual float transparency();
};

struct Entry
{
    char padding[0x34];
    Material* material;
    char tail[0x0c];
};

struct EntryList
{
    Entry** data;
    int count;
    int capacity;

    void append(Entry* const& entry);
};

struct Scene
{
    char padding[0x268];
    Entry* entries;
    int count;
    int capacity;
    EntryList opaque;
    EntryList reflective;
    EntryList transparent;

    void classify();
};

void Scene::classify()
{
    for (int i = 0; i < count; ++i)
    {
        Entry* current = entries + i;
        Entry* entry;
        if (current->material ? (entry = current, false) : (entry = current, true))
            continue;
        {
            if (current->material->transparency() > 0.0f)
                transparent.append(entry);
            else
            {
                opaque.append(entry);
                if (current->material->reflectance() > 0.0f)
                    reflective.append(entry);
            }
        }
    }
}
