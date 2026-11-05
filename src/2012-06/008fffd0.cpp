// from server: 57% by atomic.potato
// roc 2012-06 008fffd0  unit: RBX::NormalBreakConnector  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008fffd0

struct RBX_NormalBreakConnector {
    static float* getFloorTouchInWorld();
};

float* RBX_NormalBreakConnector::getFloorTouchInWorld()
{
    static unsigned int initFlag = 0;
    static float floorTouchInWorld[3];
    if (!(initFlag & 1)) {
        initFlag |= 1;
        float v = *(float*)0x00bf1524;
        floorTouchInWorld[0] = v;
        floorTouchInWorld[1] = v;
        floorTouchInWorld[2] = v;
    }
    return floorTouchInWorld;
}
