// from server: 100% by colin
struct VNode {
    int v[2];

    VNode* init();
};

extern "C" int __cdecl helper();

VNode* VNode::init()
{
    this->v[0] = helper();
    this->v[1] = 0;
    return this;
}
