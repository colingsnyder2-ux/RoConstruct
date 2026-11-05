// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

#include <vector>
#include <algorithm>
struct Vector {int x,y,z;Vector(int a,int b,int c):x(a),y(b),z(c){}};
struct Primitive;struct TreeNode;
struct SpatialNode {Primitive* primitive;SpatialNode* next;SpatialNode* nextPrimitive;SpatialNode* prevPrimitive;unsigned hash;Vector grid;unsigned short level;unsigned short pad;};
struct LargeNode:SpatialNode {TreeNode* owner;};
struct TreeNode {unsigned short children[8];unsigned short level;unsigned char mask;char padding;unsigned references;unsigned hash;Vector grid;TreeNode* next; unsigned char hasChild(int i){return mask & (1<<i);} void setChild(int i,unsigned child){mask |= (1<<i);children[i]=child;} TreeNode():grid(0,0,0){reset();} void reset(){references=0;level=65535;hash=~0u;next=0;mask=0;for(int i=0;i<8;++i)children[i]=65535;}};
struct Primitive {char prefix[0x64];SpatialNode* nodes;};
struct Bucket {SpatialNode* head;TreeNode* tree;};
struct Manager {void onNewPair(Primitive*,Primitive*);};
void* __cdecl findContact(Primitive*,Primitive*);
extern int levelLimit;
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();
typedef std::vector<Bucket> Buckets;
typedef char buckets_extent[sizeof(Buckets)==24?1:-1];
struct SpatialHash {
 unsigned treeCount;void* world;Manager* manager;Buckets levels[4];SpatialNode* freeSmall;SpatialNode* freeLarge;TreeNode* freeTree;int nodeCount,maxBucket;
 SpatialNode* allocate(int,unsigned,const Vector&);
 TreeNode* find(int,unsigned,const Vector&);
 TreeNode* create(int,unsigned,const Vector&);
 void collide(TreeNode*,Primitive*);
 void addNode(int,Primitive*,const Vector&);
};



extern "C" void* __cdecl allocateBytes(unsigned);
__declspec(noinline) TreeNode* SpatialHash::find(int level,unsigned hash,const Vector& grid) {
 TreeNode* p=levels[level][hash].tree;
 while(p){if(p->grid.x==grid.x&&p->grid.y==grid.y&&p->grid.z==grid.z)return p;p=p->next;}
 return 0;
}
__declspec(noinline) TreeNode* SpatialHash::create(int level,unsigned hash,const Vector& grid) {
 TreeNode* p=freeTree;
 if(p){freeTree=p->next;p->reset();}else{p=new TreeNode;++treeCount;}
 p->references=0;p->level=(unsigned short)level;p->hash=hash;p->grid=grid;
 Buckets& group=levels[level];p->next=group[hash].tree;group[hash].tree=p;return p;
}
__declspec(noinline) SpatialNode* SpatialHash::allocate(int level,unsigned hash,const Vector& grid) {
 if(level==0){
  SpatialNode* p=freeSmall;
  if(p){freeSmall=p->next;p->hash=hash;p->grid=grid;return p;}
  p=static_cast<SpatialNode*>(allocateBytes(36));
  if(p){p->grid.x=0;p->grid.y=0;p->grid.z=0;p->level=0;return p;}
  return 0;
 }
 LargeNode* p=static_cast<LargeNode*>(freeLarge);
 if(p){freeLarge=p->next;p->level=(unsigned short)level;}
 else{LargeNode* fresh=static_cast<LargeNode*>(allocateBytes(40));if(fresh){fresh->grid.x=0;fresh->grid.y=0;fresh->grid.z=0;fresh->level=(unsigned short)level;}else fresh=0;p=fresh;}
 p->hash=hash;p->grid=grid;p->owner=find(level,hash,grid);if(!p->owner)p->owner=create(level,hash,grid);++p->owner->references;return p;
}

__declspec(noinline) void SpatialHash::collide(TreeNode* node,Primitive* primitive){
 Vector origin(node->grid.x*2,node->grid.y*2,node->grid.z*2);
 for(int child=0;child<8;++child){
  if(node->mask & (unsigned char)(1<<child)){
   unsigned short index=node->children[child];
   int x=origin.x+(child&1);
   int y=origin.y+((child>>1)&1);
   int z=origin.z+((child>>2)&1);
   Vector grid(x,y,z);
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

void SpatialHash::addNode(int level,Primitive* primitive,const Vector& grid){

 unsigned hash=(grid.z*0x04f9ffb7u ^grid.y*0x0127409fu ^grid.x*0x0466f45du)&(0xffff>>level);
 ++nodeCount;
 SpatialNode* node=allocate(level,hash,grid);
 node->primitive=primitive;node->grid=grid;node->hash=hash;
 SpatialNode* old=primitive->nodes;primitive->nodes=node;node->nextPrimitive=old;node->prevPrimitive=0;if(old)old->prevPrimitive=node;
 node->next=levels[level][hash].head;
 SpatialNode* current=node->next;
 levels[level][hash].head=node;
 int count=1;
 Vector parent=grid;
 unsigned previousHash=~0u;
 bool buildParent=true;
 for(int currentLevel=level;currentLevel<levelLimit;++currentLevel){
  if(currentLevel>level){
   parent.x>>=1;parent.y>>=1;parent.z>>=1;
   hash=(parent.z*0x04f9ffb7u ^parent.x*0x0466f45du ^parent.y*0x0127409fu)&(0xffff>>currentLevel);
   current=levels[currentLevel][hash].head;
  }
  while(current){
   Primitive* candidate=current->primitive;
   ++count;
   if(candidate!=primitive && current->grid.x==parent.x&&current->grid.y==parent.y&&current->grid.z==parent.z&&!findContact(primitive,candidate))manager->onNewPair(primitive,candidate);
   current=current->next;
  }
  if(currentLevel>level && buildParent){
   TreeNode* tree=find(currentLevel,hash,parent);
   if(!tree)tree=create(currentLevel,hash,parent);
   int shift=currentLevel-level-1;
   int index=((grid.x>>shift)&1)+2*(((grid.y>>shift)&1)+2*((grid.z>>shift)&1));
   if(tree->hasChild(index))buildParent=false;
   else tree->setChild(index,previousHash);
  }
  previousHash=hash;

 }
 if(node->level>0)collide(static_cast<LargeNode*>(node)->owner,primitive);
 maxBucket=std::max(maxBucket,count);
}
