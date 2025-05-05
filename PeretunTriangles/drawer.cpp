#include "drawer.h"
#include <cairo/cairo.h>

void drawLine(const std::vector<Vidrizok>* va) {
    cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 400, 300);
    cairo_t* cr = cairo_create(surface);

    // Білий фон
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);

    // Чорні лінії
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_set_line_width(cr, 2);

    for (const auto& v : *va) {
        cairo_move_to(cr, v.startX * 10, v.startY * 10);
        cairo_line_to(cr, v.endX * 10, v.endY * 10);
        cairo_stroke(cr);
    }

    cairo_surface_write_to_png(surface, "lines.png");

    cairo_destroy(cr);
    cairo_surface_destroy(surface);
}
