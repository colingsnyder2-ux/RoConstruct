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

class DataModel : public Instance, public Service
{
public:
    void save(std::string url);
};
}

using namespace RBX;

static Reflection::BoundFuncDesc<DataModel, void(std::string), 1> func_save(&DataModel::save, "Save", "url", Reflection::FunctionDescriptor::NeedTrustedCaller);
