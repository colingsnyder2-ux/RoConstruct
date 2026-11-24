// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided. The target is the compiler-generated
// adjustor thunk (this -= 16; jmp StatsService::`vector deleting destructor')
// for the secondary-base vtable slot of StatsService. To make the compiler emit
// it, StatsService is modelled locally as a class with a 16-byte primary base
// and a second polymorphic base placed at offset 16.

namespace RBX {
namespace Stats {

// INFERRED: primary base, 16 bytes (vptr + 3 ints)
struct StatsPrimaryBase {
    virtual ~StatsPrimaryBase() {}
    int a, b, c;
};

// INFERRED: secondary base at offset 16 with a virtual destructor
struct StatsSecondaryBase {
    virtual ~StatsSecondaryBase() {}
};

class StatsService : public StatsPrimaryBase, public StatsSecondaryBase {
public:
    StatsService();
    virtual ~StatsService();
private:
    int data;
};

StatsService::StatsService()
    : data(0)
{
}

StatsService::~StatsService()
{
}

} // namespace Stats
} // namespace RBX
