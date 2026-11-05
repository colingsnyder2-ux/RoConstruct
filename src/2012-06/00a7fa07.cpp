// from server: 39% by tajop

struct D3DXVECTOR3 { float x, y, z; };
struct D3DXMATRIX { float m[4][4]; };
struct __declspec(align(16)) D3DXMATRIXA16 : public D3DXMATRIX {};
struct D3DVIEWPORT9 { unsigned long X, Y, Width, Height; float MinZ, MaxZ; };
extern "C" D3DXMATRIX* __stdcall D3DXMatrixMultiply(D3DXMATRIX* pOut, const D3DXMATRIX* pM1, const D3DXMATRIX* pM2);
extern "C" D3DXVECTOR3* __stdcall D3DXVec3TransformCoord(D3DXVECTOR3* pOut, const D3DXVECTOR3* pV, const D3DXMATRIX* pM);
extern "C" D3DXVECTOR3* __stdcall D3DXVec3Project(D3DXVECTOR3* pOut, const D3DXVECTOR3* pV, const D3DVIEWPORT9* pViewport, const D3DXMATRIX* pProjection, const D3DXMATRIX* pView, const D3DXMATRIX* pWorld) {
    D3DXMATRIXA16 mat;
    const D3DXMATRIX* pM = &mat;
    switch ((((((pWorld != 0) << 1) | (pView != 0)) << 1) | (pProjection != 0))) {
    case 0:
        mat.m[0][1] = mat.m[0][2] = mat.m[0][3] =
        mat.m[1][0] = mat.m[1][2] = mat.m[1][3] =
        mat.m[2][0] = mat.m[2][1] = mat.m[2][3] =
        mat.m[3][0] = mat.m[3][1] = mat.m[3][2] = 0.0f;
        mat.m[0][0] = mat.m[1][1] = mat.m[2][2] = mat.m[3][3] = 1.0f;
        break;
    case 1:
        pM = pProjection;
        break;
    case 2:
        pM = pView;
        break;
    case 3:
        D3DXMatrixMultiply(&mat, pView, pProjection);
        break;
    case 4:
        pM = pWorld;
        break;
    case 5:
        D3DXMatrixMultiply(&mat, pWorld, pProjection);
        break;
    case 6:
        D3DXMatrixMultiply(&mat, pWorld, pView);
        break;
    case 7:
        D3DXMatrixMultiply(&mat, pWorld, pView);
        D3DXMatrixMultiply(&mat, &mat, pProjection);
        break;
    }
    D3DXVec3TransformCoord(pOut, pV, pM);
    if (pViewport) {
        pOut->x = (pOut->x + 1.0f) * (float)pViewport->Width * 0.5f + (float)pViewport->X;
        pOut->y = (1.0f - pOut->y) * (float)pViewport->Height * 0.5f + (float)pViewport->Y;
        pOut->z = (pViewport->MaxZ - pViewport->MinZ) * pOut->z + pViewport->MinZ;
    }
    return pOut;
}
