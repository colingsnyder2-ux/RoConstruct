// from server: 70% by EspClaude
// true extent: 0xb5 bytes (server extent 0x63)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <exception>
#include <vector>
struct lua_State;
namespace boost { class any; template<class T> class shared_ptr { public: T* px; void* pn; ~shared_ptr(); T* operator->() const { return px; } }; }
namespace RBX {
enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
class StandardOut { public: static boost::shared_ptr<StandardOut> singleton(); void print(MessageType, const char* fmt, ...); };
class ScriptContext { public: void resume(lua_State* L, int n); };
ScriptContext* getContext(lua_State* L);
void prepare(lua_State* L);
namespace Reflection {
typedef std::vector<boost::any> Arguments;
int pushArgs(lua_State* L, const Arguments& args);
class GenericSlotWrapper { public: virtual ~GenericSlotWrapper(); virtual void execute(const Arguments&) = 0; char pad[8]; };
}
class WaitScriptSlot {
public:
	void check();
	char pad[0x20];
	lua_State* thread;
	void operator()(const Reflection::Arguments& arguments) {
		check();
		lua_State* L = thread;
		if (L) {
			prepare(L);
			int n = Reflection::pushArgs(L, arguments);
			getContext(L)->resume(L, n);
		}
	}
};
namespace Reflection {
template<class T> class TGenericSlotWrapper : public GenericSlotWrapper {
public:
	T slot;
	virtual void execute(const Arguments& arguments)
	{
		try
		{
			slot(arguments);
		}
		catch (std::exception& e)
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Exception caught in TGenericSlotWrapper. %s", e.what());
		}
	}
};
template class TGenericSlotWrapper<WaitScriptSlot>;
}
}
