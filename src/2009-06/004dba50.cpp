// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct SpinMutex { long v; };
class ScopedSpinLock {
    long* p;
public:
    ScopedSpinLock(SpinMutex& m);
    ~ScopedSpinLock();
};
struct ObjId { int a, b; };
struct ObjInfo { int a, b, c, d; };
class InfoMap { public: ObjInfo& operator[](const ObjId& k); };
struct InfoOwner { char pad[0x1d0]; SpinMutex mutex; InfoMap map; };
class InfoClient {
    char pad[0xc];
    InfoOwner* owner;
public:
    int get(ObjId id);
};
int InfoClient::get(ObjId id)
{
    SpinMutex& mx = owner->mutex;
    ScopedSpinLock lock(mx);
    InfoOwner* o = owner;
    return o->map[id].c;
}
