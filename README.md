# SDL Rendering - proof of concept

![](preview.gif)

## Introduction
This proof of concept C++ project contains a small app that renders 
objects to a window.
The UI aspect is done by a little "framework", providing an interface with some basic UI tasks. 
The implementation can easily be swapped out for something else, in this case SDL2 is implemented.

## Additional information
- **Coding standards:** [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- **C++ version:** 20
- The only important files are the ones in `/ui_framework`, and `game.h` + `main.cc` in the root directory. The other files are just there for the visualisation/'city building simulation'.

## How it works

**Directory and file Structure**
- `/ui_framework`
  - `/ui.h`
    - Interface containing basic UI functionality such as creating a window, dealing with frames and drawing a rectangle.
  - `/sdl_ui.h`
    - SDL implementation of the UI framework.

**Instantiating the UI**
```c++
  std::unique_ptr<UI> ui = std::make_unique<SdlUi>(
    500, 300, "Rendering PoC", true, false);
```

**Using it to render things**
```c++
while (true) {
  ui_->StartFrame();
  // Draw stuff, update objects, handle input. For example:
  // ui_->DrawRectangle(/* args */)
  ui_->EndFrame();
}
```
