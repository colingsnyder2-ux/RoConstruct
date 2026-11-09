// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
inline double clamp(double val, double low, double hi) {
	if (val <= low) return low;
	else if (val >= hi) return hi;
	else return val;
}
}
namespace RBX {
class PropertyDescriptor;
class Instance {
public:
	void raisePropertyChanged(const PropertyDescriptor& d);
};
extern const PropertyDescriptor prop_value;
class Settings : public Instance {
	static double value;
public:
	void setValue(double v);
};
double Settings::value = 1.5;
void Settings::setValue(double v)
{
	v = G3D::clamp(v, 1.0, 10.0);
	if (v != value) {
		value = v;
		raisePropertyChanged(prop_value);
	}
}
}
