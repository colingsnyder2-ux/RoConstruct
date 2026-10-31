#include "util/NormalId.h"
#include <cstdio>
int main() {
    G3D::Vector3 v(2,3,5);
    G3D::Vector3 actual[6] = {
        RBX::uvwToObject<RBX::NORM_X>(v), RBX::uvwToObject<RBX::NORM_Y>(v),
        RBX::uvwToObject<RBX::NORM_Z>(v), RBX::uvwToObject<RBX::NORM_X_NEG>(v),
        RBX::uvwToObject<RBX::NORM_Y_NEG>(v), RBX::uvwToObject<RBX::NORM_Z_NEG>(v)
    };
    const float expected[6][3] = {{5,3,-2},{-2,5,3},{2,3,5},{-5,3,2},{2,-5,3},{-2,3,-5}};
    for(int i=0;i<6;++i)
        if(actual[i].x!=expected[i][0] || actual[i].y!=expected[i][1] || actual[i].z!=expected[i][2]) return i+1;
    std::puts("PASS: six recovered face orientations on asymmetric input");
    return 0;
}
