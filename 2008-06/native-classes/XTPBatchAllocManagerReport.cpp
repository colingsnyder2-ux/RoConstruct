// native-flags: /O2 /GS /EHsc /MD /D_AFXDLL /D_XTP_STATICLINK /D_DLL /D_LIB /DNDEBUG /I{headers}/../../../tools/libs/xtp-11.2.2/Source /I{headers}/../../../tools/libs/mfc-9.0/atlmfc/include /FICommon/XTPDLLExports.h /FIXTToolkitPro.h
// 2008-06 native XTPBatchAllocManagerReport (inactive): CXTPBatchAllocManagerT instantiations for the
// report row / group row batch data (authentic XTP 11.2.2 Common/XTPCustomHeap.h template).
#include <XTToolkitPro.h>

template class CXTPBatchAllocManagerT<CXTPReportRowAllocator, CXTPReportRow_BatchData>;
template class CXTPBatchAllocManagerT<CXTPReportRowAllocator, CXTPReportGroupRow_BatchData>;
