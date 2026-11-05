// from server: 100% by king_originala
// from server: 95% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
}

namespace RBX {
struct Matrix3 {float data[9];Matrix3(const Matrix3&);};
struct Name {int id;std::string text;const char* c_str()const{return text.c_str();}};
struct Flag {bool value;Flag():value(false){}};
struct Changed {void notify(Flag);};
struct Workspace {char pad[0x344];Changed changed;};
struct History {void record(int);};
struct Selection;
// These getters are normal thiscall members on the context.
struct Context {
 Selection* selection();
 History* history();
};
struct IDataState {virtual void setDirty(bool)=0;};
void __cdecl trackVerb(const char*,Context*);
struct RotateAxisCommand {
 virtual ~RotateAxisCommand();
 virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();
 virtual Matrix3 axis();
 const Name* name;
 void* unused;
 Workspace* workspace;
 char pad[0x10];
 Context* context;
 void apply(const Matrix3&,void*);
 void doIt(IDataState*);
};
void RotateAxisCommand::doIt(IDataState* state){
 checkPermissions(reinterpret_cast<Instance*>(context));
 Selection* selected=context?context->selection():0;
 apply(axis(),reinterpret_cast<char*>(selected)+0x13c);
 History* history=context?context->history():0;
 history->record(4);
 workspace->changed.notify(Flag());
 trackVerb(name->c_str(),context);
 state->setDirty(true);
}
}
