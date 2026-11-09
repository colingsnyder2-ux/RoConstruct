// from server: 100% by EspClaude
// roc 2009-06 00657850  unit: RBX::Stats::TypedMemItem  size: 193 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00657850
//
// 00657850  6aff                 push -1
// 00657852  68d1898600           push 0x8689d1
// 00657857  64a100000000         mov eax, dword ptr fs:[0]
// 0065785d  50                   push eax
// 0065785e  64892500000000       mov dword ptr fs:[0], esp
// 00657865  83ec24               sub esp, 0x24
// 00657868  56                   push esi
// 00657869  8d442404             lea eax, [esp + 4]
// 0065786d  57                   push edi
// 0065786e  50                   push eax
// 0065786f  8bf1                 mov esi, ecx
// 00657871  e88afeffff           call 0x657700
// 00657876  83c404               add esp, 4
// 00657879  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0065787d  51                   push ecx
// 0065787e  8d4c2414             lea ecx, [esp + 0x14]
// 00657882  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0065788a  ff15b4e48900         call dword ptr [0x89e4b4]
// 00657890  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00657894  8b11                 mov edx, dword ptr [ecx]
// 00657896  8b5204               mov edx, dword ptr [edx + 4]
// 00657899  8d442410             lea eax, [esp + 0x10]
// 0065789d  50                   push eax
// 0065789e  c644243801           mov byte ptr [esp + 0x38], 1
// 006578a3  ffd2                 call edx
// 006578a5  8d4c2410             lea ecx, [esp + 0x10]
// 006578a9  c644243400           mov byte ptr [esp + 0x34], 0
// 006578ae  ff15c4e48900         call dword ptr [0x89e4c4]
// 006578b4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006578b8  56                   push esi
// 006578b9  e892a5f7ff           call 0x5d1e50
// 006578be  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006578c2  8b7c2408             mov edi, dword ptr [esp + 8]
// 006578c6  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 006578ce  85f6                 test esi, esi
// 006578d0  742a                 je 0x6578fc
// 006578d2  8d4604               lea eax, [esi + 4]
// 006578d5  83c9ff               or ecx, 0xffffffff
// 006578d8  f00fc108             lock xadd dword ptr [eax], ecx
// 006578dc  751e                 jne 0x6578fc
// 006578de  8b16                 mov edx, dword ptr [esi]
// 006578e0  8b4204               mov eax, dword ptr [edx + 4]
// 006578e3  8bce                 mov ecx, esi
// 006578e5  ffd0                 call eax
// 006578e7  8d4e08               lea ecx, [esi + 8]
// 006578ea  83caff               or edx, 0xffffffff
// 006578ed  f00fc111             lock xadd dword ptr [ecx], edx
// 006578f1  7509                 jne 0x6578fc
// 006578f3  8b06                 mov eax, dword ptr [esi]
// 006578f5  8b5008               mov edx, dword ptr [eax + 8]
// 006578f8  8bce                 mov ecx, esi
// 006578fa  ffd2                 call edx
// 006578fc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00657900  8bc7                 mov eax, edi
// 00657902  5f                   pop edi
// 00657903  5e                   pop esi
// 00657904  64890d00000000       mov dword ptr fs:[0], ecx
// 0065790b  83c430               add esp, 0x30
// 0065790e  c20400               ret 4
// copied from an identical function in another client (function ?create@Item@ns_ROCX00001a@@QAEPAUObject@2@PBD@Z)

namespace ns_ROCX00001a {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Text;
extern void (__thiscall *constructText)(Text*, const char*);
extern void (__thiscall *destroyText)(Text*);

struct Text {
    unsigned char storage[28];
    Text(const char*);
    ~Text();
};

inline Text::Text(const char* value)
{
    constructText(this, value);
}

inline Text::~Text()
{
    destroyText(this);
}

struct Item;

struct Object {
    virtual void reserved();
    virtual void setName(const Text&);
    void attach(Item*);
};

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared {
    Object* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    if (control)
        control->release();
}

extern Shared __cdecl createObject();

struct Item {
    Object* create(const char*);
};

Object* Item::create(const char* name)
{
    Shared result = createObject();
    {
        Text text(name);
        result.object->setName(text);
    }
    result.object->attach(this);
    return result.object;
}
}
