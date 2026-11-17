// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005e6e90 (placeholder name for 005e6e90 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <algorithm>
#include <utility>
#include <GLG3D/PosedModel.h>
#include "util/Name.h"

typedef G3D::ReferenceCountedPointer<G3D::PosedModel2D> PosedModel2DRef_t;
typedef bool (__cdecl *PosedModel2DPred_t)(const PosedModel2DRef_t&, const PosedModel2DRef_t&);

void __cdecl sub_005e6e90(PosedModel2DRef_t* _First, PosedModel2DRef_t* _Last, int _Ideal, PosedModel2DPred_t _Pred)
{
	int _Count;
	for (; 32 < (_Count = (int)(_Last - _First)) && 0 < _Ideal; )
	{
		std::pair<PosedModel2DRef_t*, PosedModel2DRef_t*> _Mid = std::_Unguarded_partition(_First, _Last, _Pred);
		_Ideal /= 2, _Ideal += _Ideal / 2;

		if (_Mid.first - _First < _Last - _Mid.second)
		{
			sub_005e6e90(_First, _Mid.first, _Ideal, _Pred);
			_First = _Mid.second;
		}
		else
		{
			sub_005e6e90(_Mid.second, _Last, _Ideal, _Pred);
			_Last = _Mid.first;
		}
	}

	if (32 < _Count)
	{
		std::make_heap(_First, _Last, _Pred);
		std::sort_heap(_First, _Last, _Pred);
	}
	else if (1 < _Count)
	{
		std::_Insertion_sort(_First, _Last, _Pred);
	}
}
