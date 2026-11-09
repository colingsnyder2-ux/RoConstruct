// from server: 100% by EspClaude
// from server: 98% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
struct Vector {int x,y,z;Vector(){} Vector(int a,int b,int c):x(a),y(b),z(c){} int& operator[](int i){return ((int*)this)[i];} const int& operator[](int i) const {return ((const int*)this)[i];}};
struct Primitive;
struct SpatialNode {Primitive* primitive;SpatialNode* next;char opaque[12];Vector grid;};
struct TreeNode {unsigned short children[8];unsigned short level;unsigned char mask;char opaque[9];Vector grid;TreeNode* next;};
struct Bucket {SpatialNode* head;TreeNode* tree;};
struct Manager {void onNewPair(Primitive*,Primitive*);};
void* __cdecl findContact(Primitive*,Primitive*);
struct SpatialHash {
 char prefix[8];Manager* manager;std::vector<Bucket> levels[];
 __declspec(noinline) TreeNode* find(unsigned level,unsigned index,const Vector& grid){TreeNode* p=levels[level][index].tree;while(p){if(p->grid.x==grid.x&&p->grid.y==grid.y&&p->grid.z==grid.z)return p;p=p->next;}return 0;}
 void collide(TreeNode*,Primitive*);
};
void SpatialHash::collide(TreeNode* node,Primitive* primitive){
 Vector origin(node->grid.x*2,node->grid.y*2,node->grid.z*2);
 for(int child=0;child<8;++child){
  if(node->mask & (unsigned char)(1<<child)){
   Vector grid;
   for(int i=0;i<3;++i)grid[i]=origin[i]+((child>>i)&1);
   unsigned index=node->children[child];
   SpatialNode* other=levels[node->level-1][index].head;
   while(other){
    Primitive* candidate=other->primitive;
    if(candidate!=primitive&&other->grid.x==grid.x&&other->grid.y==grid.y&&other->grid.z==grid.z&&!findContact(primitive,candidate))manager->onNewPair(primitive,candidate);
    other=other->next;
   }
   if(node->level>1){TreeNode* childNode=find(node->level-1,node->children[child],grid);collide(childNode,primitive);}
  }
 }
}
