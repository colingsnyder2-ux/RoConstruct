// from server: 100% by EspClaude
// roc 2007-08 0053a6c0  RBX::Stats::Item::Item(name) : base(name), value(0) {} (double value @0xe8, std::string @0xf0; RTTI .?AVItem@Stats@RBX@@)
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace RBX {
class V0 { public: virtual ~V0(); };
class V1 { public: virtual ~V1(); int a, b; };
class V2 { public: virtual ~V2(); };
template<int N> class Notifier { public: virtual ~Notifier(); int pad[5]; };
class V8 { public: virtual ~V8(); char pad[0xe8 - 0x90]; };
class StatsItemBase : public V0, public V1, public V2, public Notifier<1>, public Notifier<2>, public Notifier<3>,
                      public Notifier<4>, public Notifier<5>, public V8 {
public:
    StatsItemBase(const char* name);
};
namespace Stats {
class Item : public StatsItemBase {
    double value;
    std::string stringValue;
public:
    Item(const char* name);
};
Item::Item(const char* name)
    : StatsItemBase(name), value(0)
{
}
}
}
