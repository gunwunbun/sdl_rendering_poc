#include "Layer.h"

Layer::Layer(const Color& color) : baseColor(color) {
    for (int i = 0; i < 5; i++) {
        Uint8 darkerRed = baseColor.red - i * 10;
        Uint8 darkerGreen = baseColor.green - i * 10;
        Uint8 darkerBlue = baseColor.blue - i * 10;
        shades.emplace_back(darkerRed, darkerGreen, darkerBlue);
    }
}