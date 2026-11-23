// native-flags: /O1 /Oy- /GS- /MD /hotpatch /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/src/atl/atls /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// 2008-06 native AtlStrMgr2008 (inactive): upstream tools/libs/mfc-9.0-rtm/atlmfc/src/atl/atls/atlstr.cpp, verbatim (atls.lib member).
// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the	
// Active Template Library product.

#include "StdAfx.H"

#pragma warning( disable: 4073 )  // initializers put in library initialization area

namespace ATL
{

#pragma init_seg( lib )

CWin32Heap g_strheap( ::GetProcessHeap() );
CAtlStringMgr g_strmgr( &g_strheap );

};  // namespace ATL

