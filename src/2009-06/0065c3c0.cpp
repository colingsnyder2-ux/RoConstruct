// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual bool isCylinder() const;
    char pad[0xa4];
};
class IRenderable {
public:
    virtual bool shouldRender3dAdorn() const = 0;
};
class PartInstance : public Base, public IRenderable {
public:
    static bool highlightSleepParts;
    static bool highlightAwakeParts;
    static bool showPartCoord;
    static bool showAnchoredParts;
    static bool showUnalignedParts;
    static bool showSpanningTree;
    static bool showReceiveAge;
    static bool showJoints;
    static bool showContacts;
    static bool showBodyTypes;
    static bool showMechanisms;
    bool computeSurfacesNeedAdorn() const;
    virtual bool shouldRender3dAdorn() const;
};
bool PartInstance::shouldRender3dAdorn() const
{
    return isCylinder() ||
           computeSurfacesNeedAdorn() ||
           highlightSleepParts ||
           highlightAwakeParts ||
           showPartCoord ||
           showAnchoredParts ||
           showUnalignedParts ||
           showSpanningTree ||
           showReceiveAge ||
           showJoints ||
           showContacts ||
           showBodyTypes ||
           showMechanisms;
}
}
