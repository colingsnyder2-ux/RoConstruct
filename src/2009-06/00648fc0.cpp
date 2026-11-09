// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005bd6d0  unit: RBX::VNetworkSettings::?$BoundPropGetSet  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bd6d0
//
// 005bd6d0  6aff                 push -1
// 005bd6d2  68423e7d00           push 0x7d3e42
// 005bd6d7  64a100000000         mov eax, dword ptr fs:[0]
// 005bd6dd  50                   push eax
// 005bd6de  64892500000000       mov dword ptr fs:[0], esp
// 005bd6e5  83ec2c               sub esp, 0x2c
// 005bd6e8  55                   push ebp
// 005bd6e9  56                   push esi
// 005bd6ea  57                   push edi
// 005bd6eb  8bf1                 mov esi, ecx
// 005bd6ed  8d442410             lea eax, [esp + 0x10]
// 005bd6f1  50                   push eax
// 005bd6f2  c744244400000000     mov dword ptr [esp + 0x44], 0
// 005bd6fa  e801ffffff           call 0x5bd600
// 005bd6ff  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005bd703  6824759700           push 0x977524
// 005bd708  6820b35b00           push 0x5bb320
// 005bd70d  c644244c01           mov byte ptr [esp + 0x4c], 1
// 005bd712  e8199cf9ff           call 0x557330
// 005bd717  83c40c               add esp, 0xc
// 005bd71a  e8a1dbffff           call 0x5bb2c0
// 005bd71f  8d4c2448             lea ecx, [esp + 0x48]
// 005bd723  51                   push ecx
// 005bd724  8d54241c             lea edx, [esp + 0x1c]
// 005bd728  52                   push edx
// 005bd729  8bc8                 mov ecx, eax
// 005bd72b  e830ace8ff           call 0x448360
// 005bd730  8b17                 mov edx, dword ptr [edi]
// 005bd732  50                   push eax
// 005bd733  8b4204               mov eax, dword ptr [edx + 4]
// 005bd736  8bcf                 mov ecx, edi
// 005bd738  c644244402           mov byte ptr [esp + 0x44], 2
// 005bd73d  ffd0                 call eax
// 005bd73f  8d4c2418             lea ecx, [esp + 0x18]
// 005bd743  c644244001           mov byte ptr [esp + 0x40], 1
// 005bd748  ff1568248000         call dword ptr [0x802468]
// 005bd74e  8d4c244c             lea ecx, [esp + 0x4c]
// 005bd752  51                   push ecx
// 005bd753  8d54241c             lea edx, [esp + 0x1c]
// 005bd757  52                   push edx
// 005bd758  e8a3edf9ff           call 0x55c500
// 005bd75d  8bf8                 mov edi, eax
// 005bd75f  83ec18               sub esp, 0x18
// 005bd762  8bec                 mov ebp, esp
// 005bd764  8964242c             mov dword ptr [esp + 0x2c], esp
// 005bd768  57                   push edi
// 005bd769  8bcd                 mov ecx, ebp
// 005bd76b  c644246403           mov byte ptr [esp + 0x64], 3
// 005bd770  ff155c248000         call dword ptr [0x80245c]
// 005bd776  8b471c               mov eax, dword ptr [edi + 0x1c]
// 005bd779  89451c               mov dword ptr [ebp + 0x1c], eax
// 005bd77c  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 005bd780  e8dbfbffff           call 0x5bd360
// 005bd785  8d4c2418             lea ecx, [esp + 0x18]
// 005bd789  c644244001           mov byte ptr [esp + 0x40], 1
// 005bd78e  ff1568248000         call dword ptr [0x802468]
// 005bd794  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005bd798  56                   push esi
// 005bd799  e852d1f9ff           call 0x55a8f0
// 005bd79e  8d4c2448             lea ecx, [esp + 0x48]
// 005bd7a2  51                   push ecx
// 005bd7a3  8d8e3c010000         lea ecx, [esi + 0x13c]
// 005bd7a9  e8c2d2ffff           call 0x5baa70
// 005bd7ae  8b542410             mov edx, dword ptr [esp + 0x10]
// 005bd7b2  8d4c2414             lea ecx, [esp + 0x14]
// 005bd7b6  51                   push ecx
// 005bd7b7  8d4804               lea ecx, [eax + 4]
// 005bd7ba  8910                 mov dword ptr [eax], edx
// 005bd7bc  e8ef4de4ff           call 0x4025b0
// 005bd7c1  8b442414             mov eax, dword ptr [esp + 0x14]
// 005bd7c5  c644244000           mov byte ptr [esp + 0x40], 0
// 005bd7ca  85c0                 test eax, eax
// 005bd7cc  742c                 je 0x5bd7fa
// 005bd7ce  8bf0                 mov esi, eax
// 005bd7d0  83c004               add eax, 4
// 005bd7d3  83caff               or edx, 0xffffffff
// 005bd7d6  f00fc110             lock xadd dword ptr [eax], edx
// 005bd7da  751e                 jne 0x5bd7fa
// 005bd7dc  8b06                 mov eax, dword ptr [esi]
// 005bd7de  8b5004               mov edx, dword ptr [eax + 4]
// 005bd7e1  8bce                 mov ecx, esi
// 005bd7e3  ffd2                 call edx
// 005bd7e5  8d4608               lea eax, [esi + 8]
// 005bd7e8  83c9ff               or ecx, 0xffffffff
// 005bd7eb  f00fc108             lock xadd dword ptr [eax], ecx
// 005bd7ef  7509                 jne 0x5bd7fa
// 005bd7f1  8b16                 mov edx, dword ptr [esi]
// 005bd7f3  8b4208               mov eax, dword ptr [edx + 8]
// 005bd7f6  8bce                 mov ecx, esi
// 005bd7f8  ffd0                 call eax
// 005bd7fa  8d4c244c             lea ecx, [esp + 0x4c]
// 005bd7fe  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 005bd806  ff1568248000         call dword ptr [0x802468]
// 005bd80c  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 005bd810  5f                   pop edi
// 005bd811  5e                   pop esi
// 005bd812  64890d00000000       mov dword ptr fs:[0], ecx
// 005bd819  5d                   pop ebp
// 005bd81a  83c438               add esp, 0x38
// 005bd81d  c22000               ret 0x20

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct String;
extern void (__thiscall *stringCopy)(String*, const String&);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char storage[28];
    String(const String&);
    ~String();
};

inline String::String(const String& source)
{
    stringCopy(this, source);
}

inline String::~String()
{
    stringDestroy(this);
}

struct Value {
    String text;
    int tag;
};

struct Argument {
    String text;
    int tag;
    Argument(const Value&);
};

inline Argument::Argument(const Value& source)
    : text(source.text), tag(source.tag)
{
}

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
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

struct Writer {
    virtual void unused() = 0;
    virtual void write(const String&) = 0;
};

struct S;

struct Object {
    void set(Argument);
    void attach(S*);
};

struct ControlPointer {
    Control* pointer;
    void assign(const ControlPointer&);
};

struct Pair {
    Object* object;
    ControlPointer control;
    ~Pair();
};

inline Pair::~Pair()
{
    if (control.pointer)
        control.pointer->release();
}

struct Manager {
    String lookup(const int*);
};

struct Table {
    Pair* lookup(const int*);
};

extern Pair makePair();
extern void registerType(void (__cdecl*)(), const char*);
extern void registeredFunction();
extern const char registeredName[];
extern Manager* getManager();
extern Value makeValue(const String*);

struct S {
    char padding[0x94];
    Table table;
    void f(int key, String value);
};

void S::f(int key, String value)
{
    Pair p = makePair();
    Writer* writer = reinterpret_cast<Writer*>(p.object);
    registerType(registeredFunction, registeredName);
    Manager* manager = getManager();
    writer->write(manager->lookup(&key));
    p.object->set(makeValue(&value));
    p.object->attach(this);
    Pair* destination = table.lookup(&key);
    destination->object = p.object;
    destination->control.assign(p.control);
}
