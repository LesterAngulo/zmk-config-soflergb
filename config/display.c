#include <zmk/display.h>
#include <zmk/keymap.h>

static int frame = 0;

void draw_status(struct zmk_display *display) {
    int layer = zmk_keymap_highest_layer_active();

    if (layer == 0) {
        if (frame == 0) {
            zmk_display_print(display, "(•‿•)");
        } else {
            zmk_display_print(display, "(-‿-)");
        }
    } else if (layer == 1) {
        zmk_display_print(display, "[DEV]");
    } else if (layer == 2) {
        zmk_display_print(display, "[NAV]");
    } else {
        zmk_display_print(display, "[CFG]");
    }

    frame = !frame;
}
