// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Destructor analog for 005489b0: releases each element of the array member at
// +0xc (size 00442cd0, operator[] 0047f7e0, release 00548640), calls cleanup
// 005486e0, bumps counter 009738a8 and queries the shared mesh 009738b8.
namespace Ogre {
class Mesh {
public:
    __declspec(dllimport) unsigned short getNumSubMeshes() const;
};
template<class T>
class SharedPtr {
public:
    __declspec(dllimport) bool isNull() const;
    __declspec(dllimport) T* operator->() const;
    T* pointer;
};
}

class Item;

template<class T>
class Array {
public:
    ~Array();
    int size() const;
    T& operator[](int n);
    T* data;
    int num;
    int numAllocated;
};

class Base {
public:
    virtual ~Base();
    char data[8];
};

extern int meshUsers;
extern Ogre::SharedPtr<Ogre::Mesh> sharedMesh;

class Owner : public Base {
public:
    virtual ~Owner();
    static void release(Item* item);
    void cleanup();
    Array<Item*> items;
};

Owner::~Owner()
{
    for (int i = 0; i < items.size(); ++i)
        release(items[i]);
    cleanup();
    ++meshUsers;
    if (!sharedMesh.isNull())
        sharedMesh->getNumSubMeshes();
}
