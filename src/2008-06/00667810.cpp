// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Value {
    float get();
    void set(float);
};

struct Owner {
    char padding[20];
    char identity;
    Value* first();
    Value* second();
};

struct Signal {
    void notify(const char&, int);
};

struct Entry {
    char padding[16];
    Signal signal;
};

struct Registry {
    Entry* find(void*);
};

extern Registry registry;


struct PrimaryBase {virtual ~PrimaryBase();};
struct Interface {virtual void interfaceMethod();};
struct Base:PrimaryBase,Interface {
 char padding[164];
 Base(Owner*,float,float);
 virtual ~Base();
 Owner* owner();
};
struct Vector3 {float x,y,z;Vector3():x(0),y(0),z(0){}};
struct Freefall:Base {
 float savedSecond,savedFirst;Vector3 lastVelocity;
 Freefall(Owner*);
 ~Freefall();
};

Freefall::Freefall(Owner* p):Base(p,300.f,50.f),savedSecond(0),savedFirst(0),lastVelocity()
{
 Entry* entry=registry.find(p?&p->identity:0);
 if(entry){char tag;entry->signal.notify(tag,1);}
 if(p->first()){
  savedFirst=p->first()->get();
  p->first()->set(0);
 }
 if(p->second()){
  savedSecond=p->second()->get();
  p->second()->set(0);
 }
}
