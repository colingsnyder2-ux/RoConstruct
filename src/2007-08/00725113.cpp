// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /Gy /GS- /MD
// roc-lib: atl-8.0 atls/atlstr.cpp

// Candidate translation unit (score above; library headers required).
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

