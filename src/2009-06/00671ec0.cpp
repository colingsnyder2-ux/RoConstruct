// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <list>
namespace RBX {
class B0 { public: virtual ~B0(); char p[0x10]; };
class B1 { public: virtual ~B1(); };
class B2 { public: virtual ~B2(); int d; };
class B3 { public: virtual ~B3(); char p[0x68]; };
class Instance : public B0, public B1, public B2, public B3 {
public:
	virtual ~Instance();
};
template<class T, class B> class FactoryProduct : public B {
public:
	virtual ~FactoryProduct() {}
};
template<class T, class B> class Described : public FactoryProduct<T, B> {};
template<class T, class B> class DescribedCreatable : public Described<T, B> {};
class Service {};
class Spawner;
class SpawnerService : public DescribedCreatable<SpawnerService, Instance>, public Service {
public:
	~SpawnerService();
	std::list<Spawner*> spawners;
};
SpawnerService::~SpawnerService() {}
}
