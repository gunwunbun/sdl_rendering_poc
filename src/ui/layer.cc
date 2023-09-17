#include "layer.h"

Layer::Layer(const Color& color) : base_color_(color) {
  for (int i = 0; i < 5; i++) {
    Uint8 darkerRed = (base_color_.red >= i * 20) ? base_color_.red - i * 20 : 0;
    Uint8 darkerGreen = (base_color_.green >= i * 20) ? base_color_.green - i * 20 : 0;
    Uint8 darkerBlue = (base_color_.blue >= i * 20) ? base_color_.blue - i * 20 : 0;
    shades_.emplace_back(darkerRed, darkerGreen, darkerBlue);
  }
}

const Color& Layer::GetColor(int shade) const {
  return shades_.at(shade);
}
