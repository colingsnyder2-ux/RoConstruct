// from server: 100% by Intel
// roc 2007-08 0055e540  unit: RBX::RotateSelectionVerb  size: 21 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD

struct Subobject {
    virtual void first();
    virtual void second();
};

struct S {
    char padding[0xe8];
    Subobject subobject;
};

void f(S* object)
{
    object->subobject.second();
}
