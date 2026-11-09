// from server: 100% by tester
#include <string>

namespace boost {
template<class T> class shared_ptr { T* px; void* pn; };
}

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
    template<typename Function, typename Arg2Default>
    BoundFuncDesc(Function function, const char* name, const char* arg1, const char* arg2, Arg2Default arg2Default, Security security);
    ~BoundFuncDesc();
};
}

class Object { public: virtual ~Object(); };
class Notifier { public: virtual ~Notifier(); };

class Instance : public Object, public Notifier
{
public:
    boost::shared_ptr<Instance> findFirstChildByName2(std::string name, bool recursive);
};
}

using namespace RBX;

static Reflection::BoundFuncDesc<Instance, boost::shared_ptr<Instance>(std::string, bool), 2> func_FindFirstChild(&Instance::findFirstChildByName2, "FindFirstChild", "name", "recursive", false, Reflection::FunctionDescriptor::AnyCaller);
