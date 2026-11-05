// from server: 100% by colin
// from server: 99% by king_originala
// roc 2008-06 00424eb0  unit: CRobloxTreeCtrlNode  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00424eb0
//
// 00424eb0  83ec18               sub esp, 0x18
// 00424eb3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00424eb7  53                   push ebx
// 00424eb8  55                   push ebp
// 00424eb9  56                   push esi
// 00424eba  57                   push edi
// 00424ebb  8bf9                 mov edi, ecx
// 00424ebd  50                   push eax
// 00424ebe  8d4c241c             lea ecx, [esp + 0x1c]
// 00424ec2  51                   push ecx
// 00424ec3  e8783b1f00           call 0x618a40
// 00424ec8  8bb754010000         mov esi, dword ptr [edi + 0x154]
// 00424ece  8be8                 mov ebp, eax
// 00424ed0  8b4610               mov eax, dword ptr [esi + 0x10]
// 00424ed3  83c408               add esp, 8
// 00424ed6  8944242c             mov dword ptr [esp + 0x2c], eax
// 00424eda  39460c               cmp dword ptr [esi + 0xc], eax
// 00424edd  7606                 jbe 0x424ee5
// 00424edf  ff1590288000         call dword ptr [0x802890]
// 00424ee5  8b8754010000         mov eax, dword ptr [edi + 0x154]
// 00424eeb  8b5810               mov ebx, dword ptr [eax + 0x10]
// 00424eee  8b16                 mov edx, dword ptr [esi]
// 00424ef0  89542410             mov dword ptr [esp + 0x10], edx
// 00424ef4  39580c               cmp dword ptr [eax + 0xc], ebx
// 00424ef7  7606                 jbe 0x424eff
// 00424ef9  ff1590288000         call dword ptr [0x802890]
// 00424eff  8bbf54010000         mov edi, dword ptr [edi + 0x154]
// 00424f05  8b770c               mov esi, dword ptr [edi + 0xc]
// 00424f08  3b7710               cmp esi, dword ptr [edi + 0x10]
// 00424f0b  7606                 jbe 0x424f13
// 00424f0d  ff1590288000         call dword ptr [0x802890]
// 00424f13  8b3f                 mov edi, dword ptr [edi]
// 00424f15  89742424             mov dword ptr [esp + 0x24], esi
// 00424f19  3bf3                 cmp esi, ebx
// 00424f1b  740e                 je 0x424f2b
// 00424f1d  8b4500               mov eax, dword ptr [ebp]
// 00424f20  3906                 cmp dword ptr [esi], eax
// 00424f22  7407                 je 0x424f2b
// 00424f24  83c608               add esi, 8
// 00424f27  3bf3                 cmp esi, ebx
// 00424f29  75f5                 jne 0x424f20
// 00424f2b  85ff                 test edi, edi
// 00424f2d  7406                 je 0x424f35
// 00424f2f  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 00424f33  7406                 je 0x424f3b
// 00424f35  ff1590288000         call dword ptr [0x802890]
// 00424f3b  3b74242c             cmp esi, dword ptr [esp + 0x2c]
// 00424f3f  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00424f43  0f95c3               setne bl
// 00424f46  85f6                 test esi, esi
// 00424f48  742a                 je 0x424f74
// 00424f4a  8d4604               lea eax, [esi + 4]
// 00424f4d  83c9ff               or ecx, 0xffffffff
// 00424f50  f00fc108             lock xadd dword ptr [eax], ecx
// 00424f54  751e                 jne 0x424f74
// 00424f56  8b16                 mov edx, dword ptr [esi]
// 00424f58  8b4204               mov eax, dword ptr [edx + 4]
// 00424f5b  8bce                 mov ecx, esi
// 00424f5d  ffd0                 call eax
// 00424f5f  8d4e08               lea ecx, [esi + 8]
// 00424f62  83caff               or edx, 0xffffffff
// 00424f65  f00fc111             lock xadd dword ptr [ecx], edx
// 00424f69  7509                 jne 0x424f74
// 00424f6b  8b06                 mov eax, dword ptr [esi]
// 00424f6d  8b5008               mov edx, dword ptr [eax + 8]
// 00424f70  8bce                 mov ecx, esi
// 00424f72  ffd2                 call edx
// 00424f74  5f                   pop edi
// 00424f75  5e                   pop esi
// 00424f76  5d                   pop ebp
// 00424f77  8ac3                 mov al, bl
// 00424f79  5b                   pop ebx
// 00424f7a  83c418               add esp, 0x18
// 00424f7d  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__cdecl * const invalidParameter)();

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Product {
    unsigned int value;
    Control* control;
};

extern Product* __cdecl getProduct(Product*, void*);

struct Entry {
    unsigned int value;
    unsigned int data;
};

struct Container {
    void* owner;
    unsigned char padding[8];
    Entry* first;
    Entry* last;
};

struct Iterator {
    void* owner;
    Entry* position;
};

struct S {
    unsigned char padding[0x154];
    Container* container;
    bool f(void*);
};

bool S::f(void* argument)
{
    Iterator savedEnd;
    Product product;
    Product* key = getProduct(&product, argument);

    Container* original = container;
    Entry* savedEndPosition = original->last;
    if (original->first > savedEndPosition)
        invalidParameter();

    Container* c = container;
    Entry* end = c->last;
    savedEnd.owner = original->owner;
    if (c->first > end)
        invalidParameter();

    c = container;
    Entry* current = c->first;
    if (current > c->last)
        invalidParameter();

    Iterator begin;
    begin.owner = c->owner;
    *(Entry* volatile*)&begin.position = current;

    while (current != end) {
        if (current->value == key->value)
            break;
        ++current;
    }

    if (!begin.owner || begin.owner != savedEnd.owner)
        invalidParameter();

    bool result = current != savedEndPosition;
    Control* control = product.control;
    if (control) {
        if (_InterlockedDecrement(&control->strong) == 0) {
            control->dispose();
            if (_InterlockedDecrement(&control->weak) == 0)
                control->destroy();
        }
    }
    return result;
}
