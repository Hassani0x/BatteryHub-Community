#pragma once
#include <algorithm>
#include <cstdint>

// Geometry in taskbar-local coordinates. Negative screen origins are valid on
// monitors to the left/above the primary display; clamp only after conversion.
namespace widget_geometry {
inline bool Vertical(int width, int height) { return height > width; }
inline int ClampStart(int start, int extent, int available) {
    return std::clamp(start, 0, std::max(0, available - extent));
}
inline int Offset(std::uint32_t stored) {
    // Registry values are unsigned. Never cast an arbitrary DWORD to signed
    // before bounding it, or a corrupt setting can wrap to the opposite edge.
    return static_cast<int>(std::min<std::uint32_t>(stored, 2000));
}
inline bool Fits(int start, int extent, int first, int last) {
    return extent > 0 && start >= first &&
           static_cast<std::int64_t>(start) + extent <= last;
}
}
