#include "../src/widget_geometry.h"
#include <cassert>
#include <climits>
#include <cstdio>

int main() {
    using namespace widget_geometry;
    assert(Vertical(48, 1080));
    assert(!Vertical(1920, 48));
    // A restyled tray can report an anchor before the beginning of the bar.
    assert(ClampStart(-61, 59, 2560) == 0);
    assert(ClampStart(2550, 59, 2560) == 2501);
    assert(ClampStart(400, 59, 2560) == 400);
    assert(ClampStart(20, 100, 48) == 0);
    assert(Offset(0xffffffffu) == 2000);
    assert(Offset(48) == 48);
    // Secondary displays may legitimately use negative screen coordinates.
    assert(Fits(-1700, 80, -1920, -100));
    assert(!Fits(-1950, 80, -1920, -100));
    assert(!Fits(-150, 80, -1920, -100));
    assert(!Fits(INT_MAX - 10, 40, 0, INT_MAX));
    assert(!Fits(0, 0, 0, 100));
    std::puts("widget geometry tests passed");
}
