#ifndef LISTBOX_HPP_INCLUDED
#define LISTBOX_HPP_INCLUDED

#include "widget.hpp"
#include <vector>
#include <string>

class ListBox : public Widget {
protected:
    std::vector<std::string> items;
    int scroll_offset;
    int selected_index;
    int visible_items;
    int item_height;
public:
    ListBox(int x, int y, int sx, int sy, std::vector<std::string> initial_items = {});
    virtual void draw() const override;
    virtual void handle(genv::event ev) override;
    void add_item(std::string item);
    void remove_selected();
    std::string get_selected() const;
    int get_selected_index() const { return selected_index; }
};

#endif