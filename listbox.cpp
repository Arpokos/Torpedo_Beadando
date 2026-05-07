#include "listbox.hpp"

using namespace genv;

ListBox::ListBox(int x, int y, int sx, int sy, std::vector<std::string> initial_items)
    : Widget(x, y, sx, sy), items(initial_items), scroll_offset(0), selected_index(-1) {
    item_height = 20;
    visible_items = size_y / item_height;
}

void ListBox::draw() const {
    gout << move_to(x, y) << color(255, 255, 255) << box(size_x, size_y);
    gout << move_to(x + 2, y + 2) << color(20, 20, 20) << box(size_x - 4, size_y - 4);

    for (int i = 0; i < visible_items && i + scroll_offset < items.size(); ++i) {
        int idx = i + scroll_offset;

        if (idx == selected_index) {
            gout << move_to(x + 2, y + 2 + i * item_height) << color(100, 100, 200) << box(size_x - 4, item_height);
        }

        gout << move_to(x + 5, y + 2 + i * item_height + gout.cascent() + 2)
             << color(255, 255, 255) << genv::text(items[idx]);
    }
}

void ListBox::handle(genv::event ev) {
    if (is_selected(ev.pos_x, ev.pos_y)) {
        if (ev.type == ev_mouse) {
            if (ev.button == btn_wheelup && scroll_offset > 0) scroll_offset--;
            if (ev.button == btn_wheeldown && scroll_offset < (int)items.size() - visible_items) scroll_offset++;
            if (ev.button == btn_left) {
                int clicked_idx = scroll_offset + (ev.pos_y - y) / item_height;
                if (clicked_idx >= 0 && clicked_idx < items.size()) {
                    selected_index = clicked_idx;
                } else {
                    selected_index = -1;
                }
            }
        }
    }
}

void ListBox::add_item(std::string item) { items.push_back(item); }

void ListBox::remove_selected() {
    if (selected_index >= 0 && selected_index < items.size()) {
        items.erase(items.begin() + selected_index);
        selected_index = -1;
        if (scroll_offset > 0 && items.size() < visible_items) scroll_offset--;
    }
}

std::string ListBox::get_selected() const {
    if (selected_index >= 0 && selected_index < items.size()) return items[selected_index];
    return "";
}