// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct WeakRef { void* px; void* pn; };
struct RequestTarget {
    std::string name;
    WeakRef a;
    WeakRef b;
    ~RequestTarget();
};
struct Request {
    int kind;
    RequestTarget target;
    Request(const Request&);
};
struct Flag { bool value; Flag(bool v) : value(v) {} };
class Dispatcher {
public:
    bool process(Request r, int x, Flag f);
    bool process(Request r, int x);
};
bool Dispatcher::process(Request r, int x)
{
    return process(r, x, Flag(false));
}
