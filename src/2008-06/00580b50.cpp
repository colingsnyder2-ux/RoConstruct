// from server: 100% by colin
// from server: 95% by colin
// roc 2008-06 00580b50  unit: RBX::ClearStarterpack  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00580b50
//
// 00580b50  6aff                 push -1
// 00580b52  6881107d00           push 0x7d1081
// 00580b57  64a100000000         mov eax, dword ptr fs:[0]
// 00580b5d  50                   push eax
// 00580b5e  64892500000000       mov dword ptr fs:[0], esp
// 00580b65  83ec08               sub esp, 8
// 00580b68  56                   push esi
// 00580b69  8bf1                 mov esi, ecx
// 00580b6b  57                   push edi
// 00580b6c  89742408             mov dword ptr [esp + 8], esi
// 00580b70  83ec1c               sub esp, 0x1c
// 00580b73  8d442440             lea eax, [esp + 0x40]
// 00580b77  8bcc                 mov ecx, esp
// 00580b79  89642428             mov dword ptr [esp + 0x28], esp
// 00580b7d  50                   push eax
// 00580b7e  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00580b86  ff155c248000         call dword ptr [0x80245c]
// 00580b8c  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00580b90  51                   push ecx
// 00580b91  8bce                 mov ecx, esi
// 00580b93  e848280000           call 0x5833e0
// 00580b98  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 00580b9c  c644241801           mov byte ptr [esp + 0x18], 1
// 00580ba1  c70664078300         mov dword ptr [esi], 0x830764
// 00580ba7  85ff                 test edi, edi
// 00580ba9  7409                 je 0x580bb4
// 00580bab  8bcf                 mov ecx, edi
// 00580bad  e83efff0ff           call 0x490af0
// 00580bb2  eb02                 jmp 0x580bb6
// 00580bb4  33c0                 xor eax, eax
// 00580bb6  50                   push eax
// 00580bb7  8d560c               lea edx, [esi + 0xc]
// 00580bba  52                   push edx
// 00580bbb  e8807e0900           call 0x618a40
// 00580bc0  897e14               mov dword ptr [esi + 0x14], edi
// 00580bc3  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00580bca  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00580bd1  83c408               add esp, 8
// 00580bd4  8d4c2424             lea ecx, [esp + 0x24]
// 00580bd8  897e20               mov dword ptr [esi + 0x20], edi
// 00580bdb  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00580be3  ff1568248000         call dword ptr [0x802468]
// 00580be9  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00580bed  5f                   pop edi
// 00580bee  8bc6                 mov eax, esi
// 00580bf0  64890d00000000       mov dword ptr fs:[0], ecx
// 00580bf7  5e                   pop esi
// 00580bf8  83c414               add esp, 0x14
// 00580bfb  c22400               ret 0x24
#include <intrin.h>

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char storage[28];
    public:
        __declspec(dllimport) basic_string(const basic_string&);
        __declspec(dllimport) ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct Product;

struct Source {
    Product* getProduct();
};

struct ProductRef { Product* p; void* o; };
extern "C" void __cdecl initializeProduct(ProductRef*, Product*);

struct Base {
    unsigned int data[2];

    Base(int, String);
    virtual ~Base();
};

struct ClearStarterpack : Base {
    ProductRef product;
    Source* source;
    unsigned int first;
    unsigned int second;
    Source* savedSource;

    ClearStarterpack(int, String, Source*);
    virtual ~ClearStarterpack();
};

ClearStarterpack::ClearStarterpack(int value, String name, Source* owner)
    : Base(value, name)
{
    initializeProduct(&product, owner ? owner->getProduct() : 0);
    source = owner;
    first = 0;
    second = 0;
    *(Source* volatile*)&savedSource = owner;
}
