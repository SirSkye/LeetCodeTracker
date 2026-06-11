#include "TabBar.hpp"
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

static const std::vector<std::string> TAB_NAMES = {
    "Problems", "Add Problem", "Attempt Problem", "Problem History"
};

Element render_tab_bar(const int& active_tab) {
    Elements tabs;
    for (int i = 0; i < TAB_NAMES.size(); i++) {
        auto tab = text(" " + TAB_NAMES[i] + " ");
        
        if (i == active_tab) {
            tab = tab | bold | inverted;
        } else {
            tab = tab | dim;
        }

        tabs.push_back(tab);
        tabs.push_back(text("|"));
    }

    return hbox(tabs) | border;
}