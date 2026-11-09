// from server: 100% by Yeetserama
// roc 2012-06 005d8720  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005d8720
//
// 005d8720  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005d8724  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005d8728  56                   push esi
// 005d8729  8b742408             mov esi, dword ptr [esp + 8]
// 005d872d  50                   push eax
// 005d872e  56                   push esi
// 005d872f  e8fcfeffff           call 0x5d8630
// 005d8734  8bc6                 mov eax, esi
// 005d8736  5e                   pop esi
// 005d8737  c3                   ret 
// copied from an identical function in another client (function ?insertLevel@@YA?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@UKey@@ULevel@@UKeyLess@@V?$allocator@U?$pair@$$CBUKey@@ULevel@@@std@@@std@@$0A@@std@@@std@@_N@std@@AAV?$map@UKey@@ULevel@@UKeyLess@@V?$allocator@U?$pair@$$CBUKey@@ULevel@@@std@@@std@@@2@ABU?$pair@$$CBUKey@@ULevel@@@2@@Z)

// from server: 100% by king_originala
// from server: 78% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lang: cpp
#include <map>
#include <intrin.h>

struct Vector3 { float x, y, z; };

static inline int __fastcall compareVec(const Vector3& p, const Vector3& q)
{
    if (q.x < p.x) return -1;
    if (q.x > p.x) return 1;
    if (q.y < p.y) return -1;
    if (q.y > p.y) return 1;
    if (q.z < p.z) return -1;
    if (q.z > p.z) return 1;
    return 0;
}

struct Key {
    Vector3 pos;
    unsigned int index;
    int value;
};

struct KeyLess {
 bool operator()(const Key&a,const Key&b)const {
    int c=compareVec(b.pos,a.pos);
    bool less;
    if(c<0)less=true;
    else if(c>0)less=false;
    else if(a.index<b.index)less=true;
    else if(a.index>b.index)less=false;
    else less=a.value<b.value;
    return less;
 }
};

struct Level {
    int data[5];
};

typedef std::map<Key, Level, KeyLess> LevelMap;

std::pair<LevelMap::iterator, bool> insertLevel(LevelMap& m, const LevelMap::value_type& v)
{
    return m.insert(v);
}