// from server: 100% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// from server: 45% by colin
// roc 2007-08 0056f350  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 187 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056f350
//
// 0056f350  64a100000000         mov eax, dword ptr fs:[0]
// 0056f356  6aff                 push -1
// 0056f358  68714b7500           push 0x754b71
// 0056f35d  50                   push eax
// 0056f35e  64892500000000       mov dword ptr fs:[0], esp
// 0056f365  83ec40               sub esp, 0x40
// 0056f368  57                   push edi
// 0056f369  8bf9                 mov edi, ecx
// 0056f36b  8b07                 mov eax, dword ptr [edi]
// 0056f36d  8b4008               mov eax, dword ptr [eax + 8]
// 0056f370  50                   push eax
// 0056f371  b9f8278800           mov ecx, 0x8827f8
// 0056f376  ff1508e77700         call dword ptr [0x77e708]
// 0056f37c  84c0                 test al, al
// 0056f37e  7474                 je 0x56f3f4
// 0056f380  56                   push esi
// 0056f381  8d7704               lea esi, [edi + 4]
// 0056f384  8d4c240c             lea ecx, [esp + 0xc]
// 0056f388  56                   push esi
// 0056f389  51                   push ecx
// 0056f38a  e8d1f0ffff           call 0x56e460
// 0056f38f  83c408               add esp, 8
// 0056f392  50                   push eax
// 0056f393  8d4c242c             lea ecx, [esp + 0x2c]
// 0056f397  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0056f39f  e86cdbedff           call 0x44cf10
// 0056f3a4  50                   push eax
// 0056f3a5  8d4c240c             lea ecx, [esp + 0xc]
// 0056f3a9  c644245401           mov byte ptr [esp + 0x54], 1
// 0056f3ae  e87de9ffff           call 0x56dd30
// 0056f3b3  8b16                 mov edx, dword ptr [esi]
// 0056f3b5  8b08                 mov ecx, dword ptr [eax]
// 0056f3b7  8910                 mov dword ptr [eax], edx
// 0056f3b9  890e                 mov dword ptr [esi], ecx
// 0056f3bb  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0056f3bf  85c9                 test ecx, ecx
// 0056f3c1  5e                   pop esi
// 0056f3c2  7408                 je 0x56f3cc
// 0056f3c4  8b01                 mov eax, dword ptr [ecx]
// 0056f3c6  8b10                 mov edx, dword ptr [eax]
// 0056f3c8  6a01                 push 1
// 0056f3ca  ffd2                 call edx
// 0056f3cc  8d4c2424             lea ecx, [esp + 0x24]
// 0056f3d0  c644244c00           mov byte ptr [esp + 0x4c], 0
// 0056f3d5  ff15ace67700         call dword ptr [0x77e6ac]
// 0056f3db  8d4c2408             lea ecx, [esp + 8]
// 0056f3df  c744244cffffffff     mov dword ptr [esp + 0x4c], 0xffffffff
// 0056f3e7  ff15ace67700         call dword ptr [0x77e6ac]
// 0056f3ed  e89ee5ffff           call 0x56d990
// 0056f3f2  8907                 mov dword ptr [edi], eax
// 0056f3f4  8bcf                 mov ecx, edi
// 0056f3f6  e835f1ffff           call 0x56e530
// 0056f3fb  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0056f3ff  5f                   pop edi
// 0056f400  64890d00000000       mov dword ptr fs:[0], ecx
// 0056f407  83c44c               add esp, 0x4c
// 0056f40a  c3                   ret 

#include <string>
#include <typeinfo>

namespace RBX {
class Name;

class ContentId {
    std::string id;
    const Name* mimeTypePtr;
public:
    ContentId(const std::string& id);   // 0x44cf10
};

namespace boost_ {
class any {
public:
    class placeholder {
    public:
        virtual ~placeholder() {}
    };
    any(const ContentId& value);        // 0x56dd30
    ~any() { delete content; }
    any& swap(any& rhs)
    {
        placeholder* tmp = content;
        content = rhs.content;
        rhs.content = tmp;
        return *this;
    }
    any& operator=(const ContentId& rhs)
    {
        any(rhs).swap(*this);
        return *this;
    }
    placeholder* content;
};
template<class T> T any_cast(any& operand);
template<> std::string any_cast<std::string>(any& operand);   // 0x56e460
}

namespace Reflection {
class Type {
public:
    int pad0[2];
    const type_info& type;   // +8
    template<class T> static const Type& singleton();
};

class Value {
    const Type* _type;
    boost_::any value;
public:
    const Type& type() const { return *_type; }
    template<typename T> bool isType() const { return typeid(T) == type().type; }
    template<typename T> T& genericConvert();
    template<typename T> T& convert();
};

template<> const Type& Type::singleton<ContentId>();   // 0x56d990
template<> ContentId& Value::genericConvert<ContentId>();   // 0x56e530

template<>
ContentId& Value::convert<ContentId>()
{
    if (isType<std::string>())
    {
        value = ContentId(boost_::any_cast<std::string>(value));
        _type = &Type::singleton<ContentId>();
    }
    return genericConvert<ContentId>();
}
}
}
