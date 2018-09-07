#include "English.h"
#include "Special.h"
#include "Hangul.h"

byte Buffer[32];

void Print(const wchar_t* s)
{
    while (*s) {
        if (*s >= 0x0020 && *s <= 0x007E) {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 8; j++) {
                    Serial.print(GetEnglishPixel(*s, j, i) ? "**" : "  ");
                }
                Serial.println();
            }
        } else if (*s >= 0xAC00 && *s <= 0xD7A3) {
            ConstructHangul(*s);
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    Serial.print(GetHangulPixel(j, i) ? "**" : "  ");
                }
                Serial.println();
            }
        } else {
            if (ConstructSpecial(*s)) {
                for (int i = 0; i < 16; i++) {
                    for (int j = 0; j < 16; j++) {
                        Serial.print(GetSpecialPixel(j, i) ? "**" : "  ");
                    }
                    Serial.println();
                }
            }
        }
        s++;
    }
}

void setup()
{
    Serial.begin(19200);
}

void loop()
{
    Print(L"한글Aㅏㅁㄴㅇㄹ쀍뛡☆");
}
