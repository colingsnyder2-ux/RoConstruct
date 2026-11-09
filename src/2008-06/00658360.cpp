// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_arrowboosttrim_b9f6a335cb2df56e.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/algorithm/string/trim.hpp>
#include <string>
#include <locale>
#include <vector>
typedef std::string String;
struct Value {char storage[12];bool get_string(String*);};
struct Node {char prefix[16];Value value;Node* find(void*);Node* next(Node*);};
extern void* node_key;
struct ArrowButton {std::vector<ArrowButton*> children;char remaining[28];ArrowButton(String);void build(ArrowButton*,Node*);};
void ArrowButton::build(ArrowButton* destination,Node* source){Node* node=source->find(node_key);while(node){{String text;node->value.get_string(&text);boost::trim(text);ArrowButton* child=new ArrowButton(text);destination->children.push_back(child);build(child,node);}node=source->next(node);}}
