// from server: 40% by colin
struct RbxSpatialHashedSceneNode {
    char pad[0x34];
    void* field34;
    char pad2[0x10];
    void* field48;
    void removeChild(void*);
    void update();
};

extern "C" void __stdcall _invalid_parameter_noinfo();

void RbxSpatialHashedSceneNode::update()
{
    void* p = field48;
    void* q = field34;
    void* node = *(void**)p;
    void* end = q;

    while (node != p) {
        if (q != 0 && q != end) {
            _invalid_parameter_noinfo();
        }
        if (node == p) break;
        if (q == 0) {
            _invalid_parameter_noinfo();
            void* t = 0;
            if (node == *(void**)((char*)t + 0x14)) {
                _invalid_parameter_noinfo();
            }
        } else {
            void* t = *(void**)q;
            if (node == *(void**)((char*)t + 0x14)) {
                _invalid_parameter_noinfo();
            }
        }
        removeChild(*(void**)((char*)node + 0x24));
        if (q == 0) {
            _invalid_parameter_noinfo();
            void* t = 0;
            if (node == *(void**)((char*)t + 0x14)) {
                _invalid_parameter_noinfo();
            }
        } else {
            void* t = *(void**)q;
            if (node == *(void**)((char*)t + 0x14)) {
                _invalid_parameter_noinfo();
            }
        }
        node = *(void**)node;
    }
}
