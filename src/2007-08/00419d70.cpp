// from server: 100% by EspClaude
// from server: 44% by colin
// roc 2007-08 00419d70  unit: RBX::VInstance::V?$shared_ptr::?$holder  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00419d70
//
// 00419d70  6aff                 push -1
// 00419d72  6858be7300           push 0x73be58
// 00419d77  64a100000000         mov eax, dword ptr fs:[0]
// 00419d7d  50                   push eax
// 00419d7e  83ec08               sub esp, 8
// 00419d81  56                   push esi
// 00419d82  57                   push edi
// 00419d83  a188518b00           mov eax, dword ptr [0x8b5188]
// 00419d88  33c4                 xor eax, esp
// 00419d8a  50                   push eax
// 00419d8b  8d442414             lea eax, [esp + 0x14]
// 00419d8f  64a300000000         mov dword ptr fs:[0], eax
// 00419d95  8bf1                 mov esi, ecx
// 00419d97  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00419d9b  e810521500           call 0x56efb0
// 00419da0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00419da4  8bf8                 mov edi, eax
// 00419da6  e805521500           call 0x56efb0
// 00419dab  8b0f                 mov ecx, dword ptr [edi]
// 00419dad  8b10                 mov edx, dword ptr [eax]
// 00419daf  51                   push ecx
// 00419db0  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 00419db3  034c2428             add ecx, dword ptr [esp + 0x28]
// 00419db7  52                   push edx
// 00419db8  8b5628               mov edx, dword ptr [esi + 0x28]
// 00419dbb  8d442414             lea eax, [esp + 0x14]
// 00419dbf  50                   push eax
// 00419dc0  ffd2                 call edx
// 00419dc2  8bf0                 mov esi, eax
// 00419dc4  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00419dcc  e81f391500           call 0x56d6f0
// 00419dd1  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00419dd5  8901                 mov dword ptr [ecx], eax
// 00419dd7  56                   push esi
// 00419dd8  83c104               add ecx, 4
// 00419ddb  e840ffffff           call 0x419d20
// 00419de0  8b442410             mov eax, dword ptr [esp + 0x10]
// 00419de4  85c0                 test eax, eax
// 00419de6  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00419dee  742c                 je 0x419e1c
// 00419df0  8bf0                 mov esi, eax
// 00419df2  83c004               add eax, 4
// 00419df5  83c9ff               or ecx, 0xffffffff
// 00419df8  f00fc108             lock xadd dword ptr [eax], ecx
// 00419dfc  751e                 jne 0x419e1c
// 00419dfe  8b16                 mov edx, dword ptr [esi]
// 00419e00  8b4204               mov eax, dword ptr [edx + 4]
// 00419e03  8bce                 mov ecx, esi
// 00419e05  ffd0                 call eax
// 00419e07  8d4e08               lea ecx, [esi + 8]
// 00419e0a  83caff               or edx, 0xffffffff
// 00419e0d  f00fc111             lock xadd dword ptr [ecx], edx
// 00419e11  7509                 jne 0x419e1c
// 00419e13  8b06                 mov eax, dword ptr [esi]
// 00419e15  8b5008               mov edx, dword ptr [eax + 8]
// 00419e18  8bce                 mov ecx, esi
// 00419e1a  ffd2                 call edx
// 00419e1c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00419e20  64890d00000000       mov dword ptr fs:[0], ecx
// 00419e27  59                   pop ecx
// 00419e28  5f                   pop edi
// 00419e29  5e                   pop esi
// 00419e2a  83c414               add esp, 0x14
// 00419e2d  c21000               ret 0x10

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;

    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0) {
            destroy();
        }
    }
};

struct SharedPtr {
    void* px;
    sp_counted_base* pi;
    SharedPtr(const SharedPtr&);
    ~SharedPtr()
    {
        if (pi != 0) pi->release();
    }
};

struct Value {
    const int& get() const;
};

struct Type;
const Type* singletonType();

struct Holder {
    void set(const SharedPtr& p);
};

struct Variant {
    const Type* type;
    Holder holder;
    void assign(const SharedPtr& v)
    {
        type = singletonType();
        holder.set(v);
    }
};

struct Base1 { int a; };
struct Base2 { int b; };
struct Object : Base1, Base2 {};

struct Outer {
    char pad[0x28];
    SharedPtr (Object::*getter)(int, int);
    void method(Object* obj, Variant& out, const Value& a, const Value& b);
};

void Outer::method(Object* obj, Variant& out, const Value& a, const Value& b)
{
    out.assign((obj->*getter)(a.get(), b.get()));
}
