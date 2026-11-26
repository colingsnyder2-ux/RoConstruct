// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 0076a470  unit: std::D::DU?$char_traits::$$A6A_NV?$basic_string::?$CallbackDescImpl  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0076a470
//
// 0076a470  b801000000           mov eax, 1
// 0076a475  56                   push esi
// 0076a476  8bf1                 mov esi, ecx
// 0076a478  8405e87ae300         test byte ptr [0xe37ae8], al
// 0076a47e  7531                 jne 0x76a4b1
// 0076a480  0905e87ae300         or dword ptr [0xe37ae8], eax
// 0076a486  6880a8b100           push 0xb1a880
// 0076a48b  c705dc7ae30068a7db00 mov dword ptr [0xe37adc], 0xdba768
// 0076a495  c705e47ae300d0085700 mov dword ptr [0xe37ae4], 0x5708d0
// 0076a49f  c705e07ae30090a75900 mov dword ptr [0xe37ae0], 0x59a790
// 0076a4a9  e8478d2100           call 0x9831f5
// 0076a4ae  83c404               add esp, 4
// 0076a4b1  8b06                 mov eax, dword ptr [esi]
// 0076a4b3  3ddc7ae300           cmp eax, 0xe37adc
// 0076a4b8  750f                 jne 0x76a4c9
// 0076a4ba  8b442408             mov eax, dword ptr [esp + 8]
// 0076a4be  8b08                 mov ecx, dword ptr [eax]
// 0076a4c0  894e04               mov dword ptr [esi + 4], ecx
// 0076a4c3  8bc6                 mov eax, esi
// 0076a4c5  5e                   pop esi
// 0076a4c6  c20400               ret 4
// 0076a4c9  85c0                 test eax, eax
// 0076a4cb  7412                 je 0x76a4df
// 0076a4cd  8b4004               mov eax, dword ptr [eax + 4]
// 0076a4d0  8d5604               lea edx, [esi + 4]
// 0076a4d3  52                   push edx
// 0076a4d4  ffd0                 call eax
// 0076a4d6  83c404               add esp, 4
// 0076a4d9  c70600000000         mov dword ptr [esi], 0
// 0076a4df  8d4604               lea eax, [esi + 4]
// 0076a4e2  85c0                 test eax, eax
// 0076a4e4  7408                 je 0x76a4ee
// 0076a4e6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0076a4ea  8b11                 mov edx, dword ptr [ecx]
// 0076a4ec  8910                 mov dword ptr [eax], edx
// 0076a4ee  c706dc7ae300         mov dword ptr [esi], 0xe37adc
// 0076a4f4  8bc6                 mov eax, esi
// 0076a4f6  5e                   pop esi
// 0076a4f7  c20400               ret 4

inline void* __cdecl operator new(unsigned int, void* p) throw() { return p; }

void destroy_fn(void*);
void other_fn(void*);

struct Desc {
    void (*destroy)(void*);
    void (*other)(void*);
    Desc(void (*a)(void*), void (*b)(void*)) { other = b; destroy = a; }
    virtual ~Desc();
};

struct S {
    Desc* vt;
    int storage;
    S& assign(const int& v);
};

S& S::assign(const int& v)
{
    static Desc desc(destroy_fn, other_fn);
    if (vt == &desc) {
        storage = v;
        return *this;
    }
    if (vt != 0) {
        vt->destroy(&storage);
        vt = 0;
    }
    new (&storage) int(v);
    vt = &desc;
    return *this;
}
