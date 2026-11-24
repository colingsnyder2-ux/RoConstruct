// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace Ogre {
class Vector3 {
public:
    float x, y, z;
};

class Camera {
public:
    __declspec(dllimport) const Vector3& getDerivedPosition() const;
};

class RenderQueueGroup {
public:
    char pad[0x28];
    bool mShadowsEnabled;
};

class RenderQueue {
public:
    __declspec(dllimport) RenderQueueGroup* getQueueGroup(unsigned char group);
};
}

// INFERRED: polymorphic bases used only so dynamic_cast emits RTDynamicCast.
class NodeBase {
public:
    virtual ~NodeBase() {}
};
class RenderableObj : public NodeBase {
public:
};

// INFERRED: std::list node of a hash_map<string, Node*> (next, prev, key[0x1c], value)
struct ChildListNode {
    ChildListNode* next;
    ChildListNode* prev;
    char key[0x1c];
    NodeBase* value;
};

// INFERRED: checked iterator pair returned by the child-iterator virtual.
struct ChildIterRange {
    void* proxyBegin;
    ChildListNode* cur;
    void* proxyEnd;
    ChildListNode* end;
};

struct CamAttachObj {
    char pad0[0x34];
    void* obj34;
    void* obj38;
    void* obj3c;
    void* obj40;
    void* obj44;
    void* obj48;
    char pad4c[0x84 - 0x4c];
    bool flag84;
    bool flag85;
    char pad86[0xbc - 0x86];
    Ogre::Vector3 off40;
    Ogre::Vector3 off44;
};

typedef void (__thiscall *PFn1)(void*, void*);
typedef void (__thiscall *PFnI)(void*, int);

static inline void* vslot(void* obj, int off)
{
    return *(void**)(*(char**)obj + off);
}

extern "C" void __fastcall fn_0067f850(CamAttachObj* self, int unusedEdx,
                                       Ogre::Camera* cam, Ogre::RenderQueue* queue, int arg3)
{
    const Ogre::Vector3& p = cam->getDerivedPosition();
    Ogre::Vector3 pos = p;

    Ogre::Vector3 v44;
    v44.x = pos.x + self->off44.x;
    v44.y = pos.y + self->off44.y;
    v44.z = pos.z + self->off44.z;
    ((PFn1)vslot(self->obj44, 0x6c))(self->obj44, &v44);

    Ogre::Vector3 v40;
    v40.x = self->off40.x + pos.x;
    v40.y = self->off40.y + pos.y;
    v40.z = self->off40.z + pos.z;
    ((PFn1)vslot(self->obj40, 0x6c))(self->obj40, &v40);

    ((PFn1)vslot(self->obj48, 0x6c))(self->obj48, &pos);

    queue->getQueueGroup(0xa)->mShadowsEnabled = false;
    queue->getQueueGroup(0x14)->mShadowsEnabled = false;

    ((PFnI)vslot(self->obj38, 0x98))(self->obj38, 0xa);
    ((PFn1)vslot(self->obj38, 0x60))(self->obj38, cam);
    ((PFn1)vslot(self->obj38, 0x70))(self->obj38, queue);

    ((PFnI)vslot(self->obj34, 0x98))(self->obj34, 0x14);
    ((PFn1)vslot(self->obj34, 0x60))(self->obj34, cam);
    ((PFn1)vslot(self->obj34, 0x70))(self->obj34, queue);

    if (self->flag84) {
        ((PFnI)vslot(self->obj3c, 0x98))(self->obj3c, 0x14);
        ((PFn1)vslot(self->obj3c, 0x60))(self->obj3c, cam);
        ((PFn1)vslot(self->obj3c, 0x70))(self->obj3c, queue);
    }

    if (self->flag85) {
        void* node = self->obj48;
        ChildIterRange it;
        ((PFn1)vslot(node, 0x168))(node, &it);
        while (it.cur != it.end) {
            NodeBase* child = it.cur->value;
            it.cur = it.cur->next;
            // INFERRED: child is dynamically cast to a movable-object type
            RenderableObj* r = dynamic_cast<RenderableObj*>(child);
            ((PFnI)vslot(r, 0x98))(r, 0xa);
            ((PFn1)vslot(r, 0x60))(r, cam);
            ((PFn1)vslot(r, 0x70))(r, queue);
        }
    }
}
