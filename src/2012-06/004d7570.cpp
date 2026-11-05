// roc 2012-06 004d7570  unit: Ogre::RbxSceneManagerFactory  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004d7570
//
// 004d7570  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004d7574  8b442404             mov eax, dword ptr [esp + 4]
// 004d7578  d901                 fld dword ptr [ecx]
// 004d757a  d918                 fstp dword ptr [eax]
// 004d757c  d94104               fld dword ptr [ecx + 4]
// 004d757f  d95804               fstp dword ptr [eax + 4]
// 004d7582  d94108               fld dword ptr [ecx + 8]
// 004d7585  d95808               fstp dword ptr [eax + 8]
// 004d7588  d9410c               fld dword ptr [ecx + 0xc]
// 004d758b  d9580c               fstp dword ptr [eax + 0xc]
// 004d758e  c3                   ret 
// copied from an identical function in another client (function ?copy@@YA?AUS@@PBU1@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    float x, y, z, w;
};

S __cdecl copy(const S* source)
{
    S result;
    result.x = source->x;
    result.y = source->y;
    result.z = source->z;
    result.w = source->w;
    return result;
}