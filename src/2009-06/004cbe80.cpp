// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <typeinfo>
#include <list>
#include <string>
namespace ns_holder {
typedef std::list<std::string> List;
struct Held {
    int a, b, c, d;
    List list;
};
class any {
public:
    class placeholder {
    public:
        virtual ~placeholder() {}
        virtual const std::type_info& type() const = 0;
        virtual placeholder* clone() const = 0;
    };
    class holder : public placeholder {
    public:
        holder(const Held& value) : held(value) {}
        virtual const std::type_info& type() const { return typeid(Held); }
        virtual placeholder* clone() const { return new holder(held); }
        Held held;
    };
};
any::placeholder* use(const Held& h) { return new any::holder(h); }
}