// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_formfactorargument672deaf8874d4b90.cpp

// Candidate translation unit (score above; library headers required).
// from server: 92% by king_originala
// roc 2008-06 0059dfa0  unit: VCRenderSettings::?$EnumPropDescriptor  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059dfa0
//
// 0059dfa0  83ec1c               sub esp, 0x1c
// 0059dfa3  56                   push esi
// 0059dfa4  8bf1                 mov esi, ecx
// 0059dfa6  83bedc01000001       cmp dword ptr [esi + 0x1dc], 1
// 0059dfad  57                   push edi
// 0059dfae  7404                 je 0x59dfb4
// 0059dfb0  33ff                 xor edi, edi
// 0059dfb2  eb04                 jmp 0x59dfb8
// 0059dfb4  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0059dfb8  3bbee0010000         cmp edi, dword ptr [esi + 0x1e0]
// 0059dfbe  0f84bf000000         je 0x59e083
// 0059dfc4  56                   push esi
// 0059dfc5  e8c6530000           call 0x5a3390
// 0059dfca  83c404               add esp, 4
// 0059dfcd  85c0                 test eax, eax
// 0059dfcf  740e                 je 0x59dfdf
// 0059dfd1  8d8e28020000         lea ecx, [esi + 0x228]
// 0059dfd7  51                   push ecx
// 0059dfd8  8bc8                 mov ecx, eax
// 0059dfda  e8e1c40400           call 0x5ea4c0
// 0059dfdf  3bbee0010000         cmp edi, dword ptr [esi + 0x1e0]
// 0059dfe5  7412                 je 0x59dff9
// 0059dfe7  68ec629700           push 0x9762ec
// 0059dfec  8bce                 mov ecx, esi
// 0059dfee  89bee0010000         mov dword ptr [esi + 0x1e0], edi
// 0059dff4  e807fbe6ff           call 0x40db00
// 0059dff9  8b86c4020000         mov eax, dword ptr [esi + 0x2c4]
// 0059dfff  d94004               fld dword ptr [eax + 4]
// 0059e002  83c004               add eax, 4
// 0059e005  d95c240c             fstp dword ptr [esp + 0xc]
// 0059e009  d94004               fld dword ptr [eax + 4]
// 0059e00c  d95c2410             fstp dword ptr [esp + 0x10]
// 0059e010  d94008               fld dword ptr [eax + 8]
// 0059e013  d95c2414             fstp dword ptr [esp + 0x14]
// 0059e017  d9442410             fld dword ptr [esp + 0x10]
// 0059e01b  db5c2428             fistp dword ptr [esp + 0x28]
// 0059e01f  db442428             fild dword ptr [esp + 0x28]
// 0059e023  d9542428             fst dword ptr [esp + 0x28]
// 0059e027  d9e8                 fld1 
// 0059e029  d9542408             fst dword ptr [esp + 8]
// 0059e02d  ded9                 fcompp 
// 0059e02f  dfe0                 fnstsw ax
// 0059e031  f6c405               test ah, 5
// 0059e034  8d442428             lea eax, [esp + 0x28]
// 0059e038  7b04                 jnp 0x59e03e
// 0059e03a  8d442408             lea eax, [esp + 8]
// 0059e03e  d900                 fld dword ptr [eax]
// 0059e040  8d54240c             lea edx, [esp + 0xc]
// 0059e044  52                   push edx
// 0059e045  d95c2414             fstp dword ptr [esp + 0x14]
// 0059e049  8d44241c             lea eax, [esp + 0x1c]
// 0059e04d  50                   push eax
// 0059e04e  8bce                 mov ecx, esi
// 0059e050  e85bbeffff           call 0x599eb0
// 0059e055  8d4c2418             lea ecx, [esp + 0x18]
// 0059e059  51                   push ecx
// 0059e05a  8bce                 mov ecx, esi
// 0059e05c  e82ffbffff           call 0x59db90
// 0059e061  8bce                 mov ecx, esi
// 0059e063  e888d4ffff           call 0x59b4f0
// 0059e068  56                   push esi
// 0059e069  e822530000           call 0x5a3390
// 0059e06e  83c404               add esp, 4
// 0059e071  85c0                 test eax, eax
// 0059e073  740e                 je 0x59e083
// 0059e075  81c628020000         add esi, 0x228
// 0059e07b  56                   push esi
// 0059e07c  8bc8                 mov ecx, eax
// 0059e07e  e84dc50400           call 0x5ea5d0
// 0059e083  5f                   pop edi
// 0059e084  5e                   pop esi
// 0059e085  83c41c               add esp, 0x1c
// 0059e088  c20400               ret 4

#pragma float_control(except, off)
#pragma float_control(precise, off)
#pragma fenv_access(off)

#include <G3D/Vector3.h>
typedef G3D::Vector3 Vector;
struct Data {
    int header;
    Vector size;
};

struct Manager {
    void begin(void* property);
    void end(void* property);
};

struct S;
extern Manager* __cdecl getManager(S* object);
extern char descriptor;

template<class T>
inline const T& maximum(const T& a, const T& b)
{
    return a < b ? b : a;
}

struct S {
    char padding0[0x1dc];
    int mode;
    int value;
    char padding1[0x44];
    char property[0x9c];
    Data* data;

    void notify(const void* descriptor);
    Vector transform(const Vector& size);
    void apply(const Vector& size);
    void update();
    void setValue(int newValue);
};

void S::setValue(int newValue)
{
    if(mode!=1)newValue=0;

    if (newValue == value)
        return;

    Manager* manager = getManager(this);
    if (manager)
        manager->begin(property);

    if (newValue != value) {
        value = newValue;
        notify(&descriptor);
    }

    Vector size(data->size);
    float rounded = (float)G3D::iRound(size.y);
    float minimum = 1.0f;
    size.y = maximum(minimum, rounded);

    Vector transformed = transform(size);
    apply(transformed);
    update();

    manager = getManager(this);
    if (manager)
        manager->end(property);
}
