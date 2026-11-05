// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct SystemAddress { unsigned int binaryAddress; unsigned short port; };
struct spin_mutex { volatile long v; };
class scoped_lock {
    spin_mutex& m;
public:
    scoped_lock(spin_mutex& mm);
    ~scoped_lock();
};
struct Throughput { char pad[0x10]; double value; double get() const { return value; } };
struct PeerStats { char pad[0x120]; Throughput throughput; };
class StatsMap { public: PeerStats& operator[](const SystemAddress& a); };
struct StatsOwner { char pad[0x1d0]; spin_mutex mutex; StatsMap stats; };
static spin_mutex& idM(spin_mutex& m) { return m; }
class NetworkStats {
    char pad[0xc];
    StatsOwner* owner;
public:
    double getThroughput(SystemAddress addr);
};
double NetworkStats::getThroughput(SystemAddress addr)
{
    spin_mutex& m = owner->mutex;
    scoped_lock lock(m);
    StatsOwner* o = owner;
    return o->stats[addr].throughput.get();
}
