// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_joinpermissionda0cc9a207d655eb.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <exception>
namespace RBX {
class Instance;
bool checkA(Instance* instance, int role);
bool checkB(Instance* instance, int role);
class runtime_error : public std::exception
{
    std::string message;
public:
    runtime_error(const std::string& m);
};
static __declspec(noinline) void checkPermissions(Instance* instance)
{
    if (checkA(instance, 1) && !checkB(instance, 1))
    {
        std::string msg("Insufficinet permissions");
        throw runtime_error(msg);
    }
}
void verify(Instance* instance)
{
    checkPermissions(instance);
}
}

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Pair;
struct Collection {
    unsigned char padding[12];
    Pair* begin;
    Pair* end;
};

struct Node {
    unsigned char padding[0x154];
    Collection* collection;
    Node* resolve();
    Pair first();
    Pair second();
};

void __cdecl combine(void*, void*);

struct JoinCommand {
    unsigned char padding[12];
    Node* node;
    void prepare();
    void execute(int);
};

void JoinCommand::execute(int)
{
    RBX::checkPermissions(reinterpret_cast<RBX::Instance*>(node));
    Node* p;
    Node* current = node;
    if (current)
        p = current->resolve();
    else
        p = 0;

    if (static_cast<unsigned>(p->collection->end -
                              p->collection->begin) == 2) {
        Pair a = p->first();
        Pair b = p->second();
        combine(a.get(), b.get());
    }
}
