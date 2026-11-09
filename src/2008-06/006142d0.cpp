// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_settransformownerd687038c93dd21b0.cpp

// Candidate translation unit (score above; library headers required).
// from server: 81% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
#include <G3D/CoordinateFrame.h>
typedef G3D::CoordinateFrame Transform;

struct Owner {
    unsigned char padding[0x90];
    int stamp;
};

struct UpdateTarget {
    void update();
};

struct DirtyFlag {
    unsigned char padding[4];
    unsigned char dirty;
};

struct PendingFlag {
    unsigned char padding[8];
    unsigned char pending;
};

struct Link {
    unsigned char padding[4];
    int value;
};

extern int updateCounter;

struct S {
    unsigned char padding0[0x10];
    Owner* owner;
    S* target;
    unsigned char padding1[0x10];
    DirtyFlag* dirtyFlag;
    PendingFlag* pendingFlag;
    unsigned char padding2[4];
    Link* link;
    Transform transform;

    void update();
    void setTransform(const Transform& value);
};

void S::update(){
 if(dirtyFlag && dirtyFlag->dirty)return;
 if(target)target->update();else if(pendingFlag)pendingFlag->pending=1;
 if(dirtyFlag)dirtyFlag->dirty=1;
}

void S::setTransform(const Transform& value)
{
    if (link) {
        link->value = 0;
        link = 0;
    }

    if (target) {
        transform=value;

        if (!dirtyFlag || !dirtyFlag->dirty) {
            if (target)
                target->update();
            else if (pendingFlag)
                pendingFlag->pending = 1;

            if (dirtyFlag)
                dirtyFlag->dirty = 1;
        }

        Owner* destinationOwner = owner;
        int stamp = ++updateCounter;
        if (stamp == 0x7fffffff) {
            stamp = 1;
            updateCounter = stamp;
        }
        destinationOwner->stamp = stamp;
    }
}
