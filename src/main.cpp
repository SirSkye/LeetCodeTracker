#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>

#include "ui/tabs/LandingTab.hpp"
#include "ui/TabBar.hpp"
#include "models/AppState.hpp"

using namespace ftxui;

int main() {
  auto screen = ScreenInteractive::Fullscreen();
  auto state = AppState(0);
  
  auto tab1 = make_landing_tab();

  auto tabs = Container::Tab({tab1}, 0);

  auto root = Renderer(tabs, [&] {
    return vbox({
      render_tab_bar(state.active_tab),
      tabs->Render() | flex
    });
  });

  root = CatchEvent(root, [&](Event e) {
    if (e == Event::Character('1')) {
      state.active_tab = 0; 
      return true;
    } else if (e == Event::Character('2')) {
      state.active_tab = 1;
      return true;
    } else if (e == Event::Character('q')) {
      screen.ExitLoopClosure()();
      return true;
    }
    return true;
  });

  screen.Loop(root);
  
  return 0;
}