#pragma once
// 2008-06 native G3D::ReferenceCountedObject minimal definition for Controller

#include "G3D/AtomicInt32.h"

namespace G3D
{
    class _WeakPtr;
    class _WeakPtrLinkedList;

    class ReferenceCountedObject
    {
    public:
        AtomicInt32 ReferenceCountedObject_refCount;

    protected:
        _WeakPtrLinkedList* ReferenceCountedObject_weakPointer;

    protected:
        ReferenceCountedObject();
        ReferenceCountedObject(const ReferenceCountedObject&);

    public:
        virtual ~ReferenceCountedObject();

        void ReferenceCountedObject_zeroWeakPointers();

        ReferenceCountedObject& operator=(const ReferenceCountedObject&);
    };
}