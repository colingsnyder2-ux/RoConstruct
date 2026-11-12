// from server: 100% by EspClaude
// from server: 55% by colin
// roc 2007-08 0056f210  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056f210
//
// 0056f210  83ec08               sub esp, 8
// 0056f213  53                   push ebx
// 0056f214  8b1d08e77700         mov ebx, dword ptr [0x77e708]
// 0056f21a  56                   push esi
// 0056f21b  8bf1                 mov esi, ecx
// 0056f21d  8b06                 mov eax, dword ptr [esi]
// 0056f21f  8b4008               mov eax, dword ptr [eax + 8]
// 0056f222  57                   push edi
// 0056f223  50                   push eax
// 0056f224  b9d4278800           mov ecx, 0x8827d4
// 0056f229  ffd3                 call ebx
// 0056f22b  84c0                 test al, al
// 0056f22d  744b                 je 0x56f27a
// 0056f22f  8d7e04               lea edi, [esi + 4]
// 0056f232  57                   push edi
// 0056f233  e8f8edffff           call 0x56e030
// 0056f238  89442410             mov dword ptr [esp + 0x10], eax
// 0056f23c  db442410             fild dword ptr [esp + 0x10]
// 0056f240  6a10                 push 0x10
// 0056f242  dd5c2414             fstp qword ptr [esp + 0x14]
// 0056f246  e8ab0c0c00           call 0x62fef6
// 0056f24b  83c408               add esp, 8
// 0056f24e  85c0                 test eax, eax
// 0056f250  740f                 je 0x56f261
// 0056f252  dd44240c             fld qword ptr [esp + 0xc]
// 0056f256  c700b49f7a00         mov dword ptr [eax], 0x7a9fb4
// 0056f25c  dd5808               fstp qword ptr [eax + 8]
// 0056f25f  eb02                 jmp 0x56f263
// 0056f261  33c0                 xor eax, eax
// 0056f263  8b0f                 mov ecx, dword ptr [edi]
// 0056f265  85c9                 test ecx, ecx
// 0056f267  8907                 mov dword ptr [edi], eax
// 0056f269  7408                 je 0x56f273
// 0056f26b  8b11                 mov edx, dword ptr [ecx]
// 0056f26d  8b02                 mov eax, dword ptr [edx]
// 0056f26f  6a01                 push 1
// 0056f271  ffd0                 call eax
// 0056f273  e8a8e6ffff           call 0x56d920
// 0056f278  8906                 mov dword ptr [esi], eax
// 0056f27a  8b06                 mov eax, dword ptr [esi]
// 0056f27c  8b4808               mov ecx, dword ptr [eax + 8]
// 0056f27f  51                   push ecx
// 0056f280  b9e0278800           mov ecx, 0x8827e0
// 0056f285  ffd3                 call ebx
// 0056f287  84c0                 test al, al
// 0056f289  7451                 je 0x56f2dc
// 0056f28b  8d7e04               lea edi, [esi + 4]
// 0056f28e  57                   push edi
// 0056f28f  e8ecebffff           call 0x56de80
// 0056f294  f6d8                 neg al
// 0056f296  6a10                 push 0x10
// 0056f298  1bc0                 sbb eax, eax
// 0056f29a  f7d8                 neg eax
// 0056f29c  89442414             mov dword ptr [esp + 0x14], eax
// 0056f2a0  db442414             fild dword ptr [esp + 0x14]
// 0056f2a4  dd5c2414             fstp qword ptr [esp + 0x14]
// 0056f2a8  e8490c0c00           call 0x62fef6
// 0056f2ad  83c408               add esp, 8
// 0056f2b0  85c0                 test eax, eax
// 0056f2b2  740f                 je 0x56f2c3
// 0056f2b4  dd44240c             fld qword ptr [esp + 0xc]
// 0056f2b8  c700b49f7a00         mov dword ptr [eax], 0x7a9fb4
// 0056f2be  dd5808               fstp qword ptr [eax + 8]
// 0056f2c1  eb02                 jmp 0x56f2c5
// 0056f2c3  33c0                 xor eax, eax
// 0056f2c5  8b0f                 mov ecx, dword ptr [edi]
// 0056f2c7  85c9                 test ecx, ecx
// 0056f2c9  8907                 mov dword ptr [edi], eax
// 0056f2cb  7408                 je 0x56f2d5
// 0056f2cd  8b11                 mov edx, dword ptr [ecx]
// 0056f2cf  8b02                 mov eax, dword ptr [edx]
// 0056f2d1  6a01                 push 1
// 0056f2d3  ffd0                 call eax
// 0056f2d5  e846e6ffff           call 0x56d920
// 0056f2da  8906                 mov dword ptr [esi], eax
// 0056f2dc  8b06                 mov eax, dword ptr [esi]
// 0056f2de  8b4808               mov ecx, dword ptr [eax + 8]
// 0056f2e1  51                   push ecx
// 0056f2e2  b9ec278800           mov ecx, 0x8827ec
// 0056f2e7  ffd3                 call ebx
// 0056f2e9  84c0                 test al, al
// 0056f2eb  7443                 je 0x56f330
// 0056f2ed  8d7e04               lea edi, [esi + 4]
// 0056f2f0  57                   push edi
// 0056f2f1  e8faeaffff           call 0x56ddf0
// 0056f2f6  dd5c2410             fstp qword ptr [esp + 0x10]
// 0056f2fa  6a10                 push 0x10
// 0056f2fc  e8f50b0c00           call 0x62fef6
// 0056f301  83c408               add esp, 8
// 0056f304  85c0                 test eax, eax
// 0056f306  740f                 je 0x56f317
// 0056f308  dd44240c             fld qword ptr [esp + 0xc]
// 0056f30c  c700b49f7a00         mov dword ptr [eax], 0x7a9fb4
// 0056f312  dd5808               fstp qword ptr [eax + 8]
// 0056f315  eb02                 jmp 0x56f319
// 0056f317  33c0                 xor eax, eax
// 0056f319  8b0f                 mov ecx, dword ptr [edi]
// 0056f31b  85c9                 test ecx, ecx
// 0056f31d  8907                 mov dword ptr [edi], eax
// 0056f31f  7408                 je 0x56f329
// 0056f321  8b11                 mov edx, dword ptr [ecx]
// 0056f323  8b02                 mov eax, dword ptr [edx]
// 0056f325  6a01                 push 1
// 0056f327  ffd0                 call eax
// 0056f329  e8f2e5ffff           call 0x56d920

#include <typeinfo>

struct Descriptor {
    int pad0;
    int pad4;
    const type_info* type;
    template<class T> bool isType() const { return typeid(T) == *type; }
};

struct Holder {
    virtual ~Holder() {}
};

struct DoubleHolder : Holder {
    double value;
    DoubleHolder(double v) : value(v) {}
};

int __cdecl getIntValue(Holder** h);
bool __cdecl getBoolValue(Holder** h);
double __cdecl getDoubleValue(Holder** h);
Descriptor* __cdecl doubleDescriptor();

struct TypedPropertyDescriptor {
    Descriptor* desc;
    Holder* holder;
    void finish();
    void update();
};

void TypedPropertyDescriptor::update()
{
    if (desc->isType<int>()) {
        double d = getIntValue(&holder);
        Holder* n = new DoubleHolder(d);
        Holder* old = holder;
        holder = n;
        delete old;
        desc = doubleDescriptor();
    }
    if (desc->isType<bool>()) {
        double d = getBoolValue(&holder) ? 1 : 0;
        Holder* n = new DoubleHolder(d);
        Holder* old = holder;
        holder = n;
        delete old;
        desc = doubleDescriptor();
    }
    if (desc->isType<float>()) {
        double d = getDoubleValue(&holder);
        Holder* n = new DoubleHolder(d);
        Holder* old = holder;
        holder = n;
        delete old;
        desc = doubleDescriptor();
    }
    finish();
}
