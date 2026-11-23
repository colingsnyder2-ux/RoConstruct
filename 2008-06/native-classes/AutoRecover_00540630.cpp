// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: callee is Ogre::Quaternion(const Radian&, const Vector3&); no native def, declared as fn_ extern.
// INFERRED: self+0xc holds a pointer to the Radian; self itself is the axis Vector3.
struct Fn540630Self {
    int pad[3];
    void* radian; // +0xc
};

extern "C" void* __fastcall fn_005426f0(void* out, int unusedEdx, void* radian, void* axis);

extern "C" void* __fastcall fn_00540630(Fn540630Self* self, int unusedEdx, void* out)
{
    fn_005426f0(out, 0, self->radian, self);
    return out;
}
