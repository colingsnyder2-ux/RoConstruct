// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace rbx { namespace signals {
class connection { public: ~connection(); void disconnect(); void* a; void* b; };
class scoped_connection : public connection { public: ~scoped_connection() { disconnect(); } };
} }
namespace RBX {
class HeartbeatInstance {
public:
	virtual ~HeartbeatInstance();
	rbx::signals::scoped_connection connection;
};
HeartbeatInstance::~HeartbeatInstance() {}
}
