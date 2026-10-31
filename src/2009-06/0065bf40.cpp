// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005991c0  unit: RBX::VPartInstance::?$FactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005991c0
//
// 005991c0  8b442408             mov eax, dword ptr [esp + 8]
// 005991c4  83ec18               sub esp, 0x18
// 005991c7  56                   push esi
// 005991c8  8b742428             mov esi, dword ptr [esp + 0x28]
// 005991cc  57                   push edi
// 005991cd  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005991d1  56                   push esi
// 005991d2  50                   push eax
// 005991d3  57                   push edi
// 005991d4  e8f7f7ffff           call 0x5989d0
// 005991d9  83c40c               add esp, 0xc
// 005991dc  8d4e24               lea ecx, [esi + 0x24]
// 005991df  51                   push ecx
// 005991e0  8d54240c             lea edx, [esp + 0xc]
// 005991e4  52                   push edx
// 005991e5  8bcf                 mov ecx, edi
// 005991e7  e874f8ffff           call 0x598a60
// 005991ec  d900                 fld dword ptr [eax]
// 005991ee  d95e30               fstp dword ptr [esi + 0x30]
// 005991f1  5f                   pop edi
// 005991f2  d94004               fld dword ptr [eax + 4]
// 005991f5  d95e34               fstp dword ptr [esi + 0x34]
// 005991f8  d94008               fld dword ptr [eax + 8]
// 005991fb  d95e38               fstp dword ptr [esi + 0x38]
// 005991fe  d9400c               fld dword ptr [eax + 0xc]
// 00599201  d95e3c               fstp dword ptr [esi + 0x3c]
// 00599204  d94010               fld dword ptr [eax + 0x10]
// 00599207  d95e40               fstp dword ptr [esi + 0x40]
// 0059920a  d94014               fld dword ptr [eax + 0x14]
// 0059920d  d95e44               fstp dword ptr [esi + 0x44]
// 00599210  5e                   pop esi
// 00599211  83c418               add esp, 0x18
// 00599214  c3                   ret 

struct Triple {
    float x, y, z;
};

struct Six {
    float a, b, c, d, e, f;
};

struct Data {
    char reserved[0x24];
    Triple input;
    Six output;
};

struct S {
    Six* compute(Six* result, const Triple* input);
};

extern void __cdecl prepare(S*, const void*, Data*);

void __cdecl update(S* object, const void* value, Data* data)
{
    Six temporary;
    prepare(object, value, data);
    Six* result = object->compute(&temporary, &data->input);
    data->output.a = result->a;
    data->output.b = result->b;
    data->output.c = result->c;
    data->output.d = result->d;
    data->output.e = result->e;
    data->output.f = result->f;
}
