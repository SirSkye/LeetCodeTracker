#include "LandingTab.hpp"

using namespace ftxui;

Component make_landing_tab() {
    auto renderer = Renderer([]() {
        return text("Hello");
    });

    return CatchEvent(renderer, [](Event e) {
        return false;
    });
}