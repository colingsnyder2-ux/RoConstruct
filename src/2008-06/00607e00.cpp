// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_contactpruningloop7f3f4eec9b143acb.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Array.h>

struct Object {
    virtual ~Object();
    bool active();
};

typedef G3D::Array<Object*> ObjectArray;
typedef G3D::Array<unsigned char> ByteArray;

struct Node {
    int field0;
    int index;
    int* f();
};

struct Contact {
    unsigned char padding[0x34];
    ObjectArray objects;
    ByteArray flags;

    Node* find(Object* object);
    void update();
};

void Contact::update(){
 for(int i=objects.size()-1;i>=0;--i){
  if(!flags[i]||!objects[i]->active()){
   Object*object=objects[i];
   objects.fastRemove(i);flags.fastRemove(i);
   find(object)->f();delete object;
  }
 }
}
