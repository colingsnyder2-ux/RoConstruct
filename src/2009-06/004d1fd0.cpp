// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase() {} const ClassDescriptor* descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
	char ipad[0x8c - 0x2c];
};
}
class PluginInterface { public: virtual void p0(); };
namespace RBX { namespace Network {
class Peer : public Instance, public PluginInterface {
public:
	Peer();
	virtual ~Peer();
};
class PeerMid2009 : public Peer {
public:
	PeerMid2009() {}
	virtual const char* getClassName() const;
};
extern int counter2009;
class __declspec(novtable) Client2009 : public PeerMid2009 {
public:
	Client2009();
	static ClassDescriptor& classDescriptor();
};
Client2009::Client2009() { this->descriptor = &classDescriptor(); ++counter2009; }
}}
