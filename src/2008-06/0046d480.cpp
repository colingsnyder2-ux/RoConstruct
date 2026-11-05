// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_lowerregistry_35c185b16f56c0c5.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
struct Object { char padding[0x3c];std::string value;std::string copy(); };
struct Disposable {virtual ~Disposable();};
struct S {char padding[0x5c];std::map<std::string,Object*> objects;Disposable* find(const std::string&);void update(Object*);};
void S::update(Object* object) {
 std::string text=object->copy();
 std::transform(text.begin(),text.end(),text.begin(),tolower);
 Disposable* previous=find(text);
 if(previous)delete previous;
 objects[text]=object;
}
