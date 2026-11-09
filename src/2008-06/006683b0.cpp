// from server: 100% by king_originala
struct JointStage;

struct Joint {
    char padding[4];
    int owner;
    void setOwner(int value);
};

struct NextStage {
    virtual void entry0();
    virtual void entry1();
    virtual void entry2();
    virtual void entry3();
    virtual void addJoint(Joint* joint);
};

struct JointStage {
    char padding[8];
    NextStage* next;

    bool acceptsJoint(Joint* joint);
    void addLocally(Joint* joint);
    void addJoint(Joint* joint);
};

void JointStage::addJoint(Joint* joint)
{
    joint->setOwner((int)this);
    if (acceptsJoint(joint))
        next->addJoint(joint);
    else
        addLocally(joint);
}
