// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_servicefindnullname17d0646a46609007.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <vector>
struct OnceFlag { int value; };
extern OnceFlag registrationFlag;
void __cdecl registerTypes();
void __cdecl callOnce(void (__cdecl *)(), OnceFlag &);
unsigned int __cdecl typeIndex();
struct Base { virtual ~Base(); };
struct Derived : Base {};
struct S {
 char padding[0x190];
 std::vector<boost::shared_ptr<Base> > values;
 Derived* f();
};
Derived* S::f() {
 callOnce(registerTypes, registrationFlag);
 unsigned int index=typeIndex();
 if(index+1>values.size()) values.resize(index+1);
 else { Derived* service=static_cast<Derived*>(values[index].get()); if(service)return service; }
 if (true) return 0;
 boost::shared_ptr<Base> i;
 if(!i)return 0;
 values[index]=i;
 return static_cast<Derived*>(i.get());
}
