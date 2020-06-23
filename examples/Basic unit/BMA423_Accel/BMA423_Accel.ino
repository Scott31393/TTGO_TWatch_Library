// => Hardware select
// #define LILYGO_WATCH_2019_WITH_TOUCH        // To use T-Watch2019 with touchscreen, please uncomment this line
// #define LILYGO_WATCH_2019_NO_TOUCH       // To use T-Watch2019 Not touchscreen , please uncomment this line
//#define LILYGO_WATCH_2020_V1              // To use T-Watch2020 , please uncomment this line


// Hardware NOT SUPPORT
//// #define LILYGO_WATCH_BLOCK
// Hardware NOT SUPPORT

#include <LilyGoWatch.h>

TTGOClass *ttgo;

void setup()
{
    Serial.begin(115200);
    ttgo = TTGOClass::getWatch();
    ttgo->begin();
    ttgo->openBL();
    ttgo->tft->fillScreen(TFT_BLACK);
    ttgo->tft->setTextColor(random(0xFFFF));
    if (!ttgo->bma->begin()) {
        ttgo->tft->drawString("BMA423 Init FAIL",  25, 50, 4);
        while (1);
    }
    ttgo->bma->enableAccel();
    ttgo->tft->fillScreen(TFT_BLACK);
    ttgo->tft->drawString("T-Watch BMA423",  25, 50, 4);
    ttgo->tft->setTextFont(4);
    ttgo->tft->setTextColor(TFT_WHITE, TFT_BLACK);
}

void loop()
{
    Accel acc;
    bool res = ttgo->bma->getAccel(acc);
    if (res == false) {
        Serial.println("getAccel FAIL");
    } else {
        ttgo->tft->fillRect(98, 100, 70, 85, TFT_BLACK);
        ttgo->tft->setCursor(80, 100);
        ttgo->tft->print("X:"); ttgo->tft->println(acc.x);
        ttgo->tft->setCursor(80, 130);
        ttgo->tft->print("Y:"); ttgo->tft->println(acc.y);
        ttgo->tft->setCursor(80, 160);
        ttgo->tft->print("Z:"); ttgo->tft->println(acc.z);
    }
    delay(100);
}
