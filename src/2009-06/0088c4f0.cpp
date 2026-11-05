// from server: 100% by EspClaude
#include <string>

namespace RBX {
namespace Reflection {
class FunctionDescriptor
{
public:
    enum Security { AnyCaller, RobloxPlaceSecurity, NeedTrustedCaller = 4 };
};

template<class Class, typename Signature, int ArgCount>
class BoundFuncDesc : public FunctionDescriptor
{
    char data[0x40];
public:
    template<typename Function>
    BoundFuncDesc(Function function, const char* name, const char* arg1, const char* arg2, Security security);
    ~BoundFuncDesc();
};
}

class Instance { public: virtual ~Instance(); };
class Service { public: virtual ~Service(); };

class DataModel : public Instance, public Service
{
public:
    double getJobTimePeakFraction(std::string jobname, double greaterThan);
};
}

using namespace RBX;

static Reflection::BoundFuncDesc<DataModel, double(std::string, double), 2> func_GetJobTimePeakFraction(&DataModel::getJobTimePeakFraction, "GetJobTimePeakFraction", "jobname", "greaterThan", Reflection::FunctionDescriptor::RobloxPlaceSecurity);
