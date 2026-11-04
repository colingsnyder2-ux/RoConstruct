#include <afxwin.h>
#include <boost/scoped_ptr.hpp>
struct PaneOwner { boost::scoped_ptr<CWnd> ptr; void reset(CWnd* value); };
void PaneOwner::reset(CWnd* value) { ptr.reset(value); }
