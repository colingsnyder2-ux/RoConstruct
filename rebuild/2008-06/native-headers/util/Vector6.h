#pragma once
// >>> native-status (generated) -- do not edit >>>
// Vector6 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src daea199c | roc native-status --write

template <typename T>
class Vector6
{
private:
	T data[6];
public:
	Vector6(const T& value)
	{
		for (int i = 5; i >= 0; i--)
			data[i] = value;
	}

	Vector6() {}

	T& operator[](int i) { return data[i]; }
	const T& operator[](int i) const { return data[i]; }
};
