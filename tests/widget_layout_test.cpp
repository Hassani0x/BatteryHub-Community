// Exercise the real font/layout code without creating windows, polling devices,
// or changing the user's taskbar/settings.
#include <initguid.h>
#include "../src/widget.cpp"
#include <cassert>
#include <cstdio>

int main() {
    int width = 0, height = 0;
    g_items = { WidgetItem{} };
    g_items[0].kind = DeviceKind::Mouse;
    g_items[0].percent = 75;
    // A horizontal primary must not force a vertical secondary into a row.
    g_vertical = false;
    auto column = Layout(48, 1080, width, height);
    assert(width == 48 && height > 0 && height < 200);
    assert(column.size() >= 2 && column[1].py > column[0].py);
    // Conversely, a vertical primary must not force horizontal mirrors into a column.
    g_vertical = true;
    auto row = Layout(1920, 48, width, height);
    assert(height == 48 && width > 0 && width < 300);
    assert(row[0].px == INT_MIN);
    g_items.clear();
    Layout(48, 1080, width, height);
    assert(width == 48 && height > 0 && height < 100);
    // An empty vertical taskbar gets a small placeholder, never a screen-height strip.
    std::puts("widget mixed-orientation layout tests passed");
}
