#include <afxwin.h>
#include <cstddef>
#include "CContent.h"

typedef char ContentStreamOffset[offsetof(CContent, stream) == 0xc ? 1 : -1];
typedef char ContentObjectSize[sizeof(ATL::CComObject<CContent>) == 0x94 ? 1 : -1];
typedef HRESULT (WINAPI *ContentFactory)(ATL::CComObject<CContent>**);
ContentFactory nativeContentFactory = &ATL::CComObject<CContent>::CreateInstance;
