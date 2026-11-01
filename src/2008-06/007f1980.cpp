// from server: 100% by tester
#include <string>

namespace RBX {
namespace Reflection {
class FunctionDescriptor
{
public:
    enum Security { AnyCaller, NeedTrustedCaller = 4 };
};

template<class Class, typename Signature, int ArgCount>
class BoundFuncDesc : public FunctionDescriptor
{
    char data[0x40];
public:
    template<typename Function>
    BoundFuncDesc(Function function, const char* name, const char* arg1, Security security);
    ~BoundFuncDesc();
};
}

class Instance { public: virtual ~Instance(); };
class Service { public: virtual ~Service(); };

namespace Network {
class Players : public Instance, public Service
{
public:
    void setAbuseReportUrl(std::string url);
};
}
}

using namespace RBX;

static Reflection::BoundFuncDesc<Network::Players, void(std::string), 1> func_setAbuseReportUrl(&Network::Players::setAbuseReportUrl, "SetAbuseReportUrl", "url", Reflection::FunctionDescriptor::NeedTrustedCaller);
