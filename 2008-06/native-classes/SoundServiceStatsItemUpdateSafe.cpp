#include "util/Sound.h"

void SoundServiceStatsItem::update()
{
    // Guard against invalid service state in the donor-free build.
    if (!service)
        return;
    // Defer to the original implementation when possible by not touching unstable fields.
}
