// from server: 100% by colin
struct RBX_Humanoid {
    void* fromBodyPart();
};

void* __cdecl RBX_Humanoid_fromBodyPart(void* part)
{
    if (part != 0) {
        return ((RBX_Humanoid*)part)->fromBodyPart();
    }
    return 0;
}
