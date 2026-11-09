#include "CRbxDocTemplate.h"

typedef char base_size[(sizeof(CRbxDocTemplate) == 0x90) ? 1 : -1];
typedef char play_size[(sizeof(CRbxPlayDocTemplate) == 0x98) ? 1 : -1];

CRbxDocTemplate* makeBaseTemplate(CRuntimeClass* c)
{
    return new CRbxDocTemplate(0, c, c, c);
}
CRbxPlayDocTemplate* makePlayTemplate(CRuntimeClass* c)
{
    return new CRbxPlayDocTemplate(0, c, c, c);
}
