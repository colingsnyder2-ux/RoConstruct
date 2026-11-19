// native-flags: /O2 /GS- /EHsc /MD /fp:fast /D_AFXDLL /GS-
#include "../native-headers/v8world/Contact2008.h"

namespace RBX {
float Contact::contactFeatureHitRatio()
{
	int n = contactFeatureMatches + contactFeatureMisses;
	if (n == 0) return -1.0f;
	return (float)contactFeatureMatches / n;
}
}
