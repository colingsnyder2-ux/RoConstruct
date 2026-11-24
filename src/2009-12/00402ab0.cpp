// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp

// Candidate translation unit (score above; library headers required).
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"


// Note: in separate module so it can be replaced if needed

void AFXAPI AfxAbort()
{
	TRACE(traceAppMsg, 0, "AfxAbort called.\n");

	AfxWinTerm();
	abort();
}

/////////////////////////////////////////////////////////////////////////////
