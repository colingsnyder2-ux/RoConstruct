// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_arrowpathemptyaf768ad69331fbe5.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <vector>
typedef std::string String;
extern unsigned int __cdecl parseIndex(const String*);
struct Node { std::vector<Node*> children; String text; };
struct ArrowButton { Node* root; String resolve(std::vector<String> path); };
String ArrowButton::resolve(std::vector<String> path) {
 Node* node=root;
 for(unsigned int i=1;i<path.size();++i) {
  unsigned int index=parseIndex(&path[i]);
  if(index>=node->children.size()) return String("");
  node=node->children[index];
 }
 return String(node->text);
}
