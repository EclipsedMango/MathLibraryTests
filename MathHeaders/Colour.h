#pragma once

namespace MathClasses
{
    using Byte = unsigned char;
    struct Colour
    {
        unsigned int colour;

        Colour() {
            Byte red = 0, green = 0, blue = 0, alpha = 255;
            colour = (red << 24) | (green << 16) | (blue << 8) | (alpha << 0);
        }

        Colour(Byte red, Byte green, Byte blue, Byte alpha) {
            colour = (red << 24) | (green << 16) | (blue << 8) | (alpha << 0);
        }

        Byte GetRed() const { return colour >> 24; }
        Byte GetGreen() const { return colour >> 16; }
        Byte GetBlue() const { return colour >> 8; }
        Byte GetAlpha() const { return colour; }

        void SetRed(const Byte red) {
	        colour = colour & ~(0b11111111 << 24);
            colour = colour | (red << 24);
        }

        void SetGreen(const Byte green) {
            colour = colour & ~(0b11111111 << 16);
            colour = colour | (green << 16);
        }

        void SetBlue(const Byte blue) {
            colour = colour & ~(0b11111111 << 8);
            colour = colour | (blue << 8);
        }

        void SetAlpha(const Byte alpha) {
            colour = colour & ~(0b11111111 << 0);
            colour = colour | alpha;
        }

        bool operator==(const Colour& o) const {
            return colour == o.colour;
        }
    };
}