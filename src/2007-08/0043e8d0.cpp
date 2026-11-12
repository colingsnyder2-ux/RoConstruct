// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 0043e8d0  unit: Vector3ComponentItem  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043e8d0
//
// 0043e8d0  6aff                 push -1
// 0043e8d2  68c8ec7300           push 0x73ecc8
// 0043e8d7  64a100000000         mov eax, dword ptr fs:[0]
// 0043e8dd  50                   push eax
// 0043e8de  83ec18               sub esp, 0x18
// 0043e8e1  56                   push esi
// 0043e8e2  57                   push edi
// 0043e8e3  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043e8e8  33c4                 xor eax, esp
// 0043e8ea  50                   push eax
// 0043e8eb  8d442424             lea eax, [esp + 0x24]
// 0043e8ef  64a300000000         mov dword ptr fs:[0], eax
// 0043e8f5  8bf1                 mov esi, ecx
// 0043e8f7  8b8614010000         mov eax, dword ptr [esi + 0x114]
// 0043e8fd  8b8888010000         mov ecx, dword ptr [eax + 0x188]
// 0043e903  51                   push ecx
// 0043e904  8d4c241c             lea ecx, [esp + 0x1c]
// 0043e908  e843afffff           call 0x439850
// 0043e90d  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0043e911  85ff                 test edi, edi
// 0043e913  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0043e91b  7405                 je 0x43e922
// 0043e91d  8d5704               lea edx, [edi + 4]
// 0043e920  eb02                 jmp 0x43e924
// 0043e922  33d2                 xor edx, edx
// 0043e924  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 0043e92a  8b4818               mov ecx, dword ptr [eax + 0x18]
// 0043e92d  8b01                 mov eax, dword ptr [ecx]
// 0043e92f  8b4004               mov eax, dword ptr [eax + 4]
// 0043e932  52                   push edx
// 0043e933  8d542410             lea edx, [esp + 0x10]
// 0043e937  52                   push edx
// 0043e938  ffd0                 call eax
// 0043e93a  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0043e940  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0043e944  03c0                 add eax, eax
// 0043e946  03c0                 add eax, eax
// 0043e948  85ff                 test edi, edi
// 0043e94a  d90408               fld dword ptr [eax + ecx]
// 0043e94d  d95c040c             fstp dword ptr [esp + eax + 0xc]
// 0043e951  7405                 je 0x43e958
// 0043e953  8d4704               lea eax, [edi + 4]
// 0043e956  eb02                 jmp 0x43e95a
// 0043e958  33c0                 xor eax, eax
// 0043e95a  8bb618010000         mov esi, dword ptr [esi + 0x118]
// 0043e960  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0043e963  8b11                 mov edx, dword ptr [ecx]
// 0043e965  8d74240c             lea esi, [esp + 0xc]
// 0043e969  56                   push esi
// 0043e96a  50                   push eax
// 0043e96b  8b4208               mov eax, dword ptr [edx + 8]
// 0043e96e  ffd0                 call eax
// 0043e970  8d4c2418             lea ecx, [esp + 0x18]
// 0043e974  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0043e97c  e81fac1100           call 0x5595a0
// 0043e981  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0043e985  64890d00000000       mov dword ptr fs:[0], ecx
// 0043e98c  59                   pop ecx
// 0043e98d  5f                   pop edi
// 0043e98e  5e                   pop esi
// 0043e98f  83c424               add esp, 0x24
// 0043e992  c20800               ret 8

struct Vector3 {
    float x, y, z;
    float &operator[](int i) { return (&x)[i]; }
    const float &operator[](int i) const { return (&x)[i]; }
};

struct Lock {
    void *a;
    void *b;
    void *c;
    explicit Lock(unsigned int);
    ~Lock();
};

struct Owner {
    char pad[0x188];
    unsigned int lockArg;
};

struct BaseA { void *p; };
struct BaseB { int q; };
struct Instance : BaseA, BaseB {};

struct Property {
    virtual void v0();
    virtual Vector3 getValue(const BaseB *obj) const;
    virtual void setValue(BaseB *obj, const Vector3 &value) const;
};

struct PropHolder {
    char pad[0x18];
    Property *prop;
    Vector3 getValue(const BaseB *obj) const { return prop->getValue(obj); }
    void setValue(BaseB *obj, const Vector3 &value) const { prop->setValue(obj, value); }
};

struct Vector3ComponentItem {
    char pad[0x114];
    Owner *owner;
    PropHolder *holder;
    int component;
    void setComponent(Instance *instance, const Vector3 &value);
};

void Vector3ComponentItem::setComponent(Instance *instance, const Vector3 &value)
{
    Lock lock(owner->lockArg);
    Vector3 v = holder->getValue(instance);
    v[component] = value[component];
    holder->setValue(instance, v);
}
