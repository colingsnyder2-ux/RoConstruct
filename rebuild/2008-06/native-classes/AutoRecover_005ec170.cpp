// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX
{
    // INFERRED: no NormalId header was shown, so the enum is declared locally. Values follow the 2007 donor usage (NORM_X_NEG, NORM_UNDEFINED).
    enum NormalId
    {
        NORM_X = 0,
        NORM_Y = 1,
        NORM_Z = 2,
        NORM_X_NEG = 3,
        NORM_Y_NEG = 4,
        NORM_Z_NEG = 5,
        NORM_UNDEFINED = 6
    };

    NormalId intToNormalId(int value)
    {
        return static_cast<NormalId>(value);
    }
}
