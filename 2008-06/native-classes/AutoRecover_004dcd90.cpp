// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::vector<Ogre::Vector3>::_Ufill(_Ptr, _Count, _Val); arg order from the push sequence.
struct Vector3 { float x, y, z; };

extern "C" void fn_004dca70(Vector3* first, unsigned count, const Vector3* val,
                            void* alloc, const Vector3* valTypePtr, char scalarTag);

extern "C" Vector3* __fastcall fn_004dcd90(char* self, int unusedEdx, Vector3* first,
                                           unsigned count, const Vector3* val)
{
    fn_004dca70(first, count, val, self + 8, val, 0);
    return first + count;
}
