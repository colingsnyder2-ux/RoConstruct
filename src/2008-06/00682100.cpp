// from server: 100% by king_originala
struct RbxSceneNode {
    char pad[0x18];
    void* field_18;
};

struct Pair {
    void* first;
    void* second;
};

extern RbxSceneNode* g_sceneNode;
extern "C" void (__cdecl *_invalid_parameter_noinfo)();
extern "C" Pair* __fastcall sub_681F00(
    void* self, int edx, Pair* out, void** key);

bool __fastcall sub_682100(RbxSceneNode* self, int edx, void* arg)
{
    Pair result;
    Pair* p = sub_681F00(g_sceneNode, edx, &result, &arg);
    void* first = p->first;
    void* second = p->second;
    RbxSceneNode* node = g_sceneNode;
    void* f18 = node->field_18;
    void* f0 = *(void* volatile*)node;
    if (first == 0 || first != f0)
        _invalid_parameter_noinfo();
    return second != f18;
}
