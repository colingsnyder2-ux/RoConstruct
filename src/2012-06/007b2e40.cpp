// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 00514db0  unit: Ogre::RbxMegaCluster  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00514db0
//
// 00514db0  56                   push esi
// 00514db1  8b7108               mov esi, dword ptr [ecx + 8]
// 00514db4  57                   push edi
// 00514db5  8b7904               mov edi, dword ptr [ecx + 4]
// 00514db8  8bd6                 mov edx, esi
// 00514dba  2bd7                 sub edx, edi
// 00514dbc  b867666666           mov eax, 0x66666667
// 00514dc1  f7ea                 imul edx
// 00514dc3  c1fa03               sar edx, 3
// 00514dc6  8bc2                 mov eax, edx
// 00514dc8  c1e81f               shr eax, 0x1f
// 00514dcb  03c2                 add eax, edx
// 00514dcd  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00514dd1  3bd0                 cmp edx, eax
// 00514dd3  7613                 jbe 0x514de8
// 00514dd5  8d7c2410             lea edi, [esp + 0x10]
// 00514dd9  57                   push edi
// 00514dda  2bd0                 sub edx, eax
// 00514ddc  52                   push edx
// 00514ddd  56                   push esi
// 00514dde  e85dae4300           call 0x94fc40
// 00514de3  5f                   pop edi
// 00514de4  5e                   pop esi
// 00514de5  c21800               ret 0x18
// 00514de8  7312                 jae 0x514dfc
// 00514dea  8d0492               lea eax, [edx + edx*4]
// 00514ded  56                   push esi
// 00514dee  8d0487               lea eax, [edi + eax*4]
// 00514df1  50                   push eax
// 00514df2  8d542414             lea edx, [esp + 0x14]
// 00514df6  52                   push edx
// 00514df7  e8a4feffff           call 0x514ca0
// 00514dfc  5f                   pop edi
// 00514dfd  5e                   pop esi
// 00514dfe  c21800               ret 0x18

struct Elem { int v[0x9]; };
struct It {
    Elem* p;
    It(Elem* q) : p(q) {}
};
struct Vec {
    int alloc;
    Elem* first;
    Elem* last;
    Elem* cap;
    unsigned size() const { return (unsigned)(last - first); }
    It erase(It f, It l);
    void insert_n(It where, unsigned count, const Elem& val);
    void resize(unsigned n, Elem val);
};
void Vec::resize(unsigned n, Elem val) {
    if (size() < n)
        insert_n(It(last), n - size(), val);
    else if (n < size())
        erase(It(first + n), It(last));
}
