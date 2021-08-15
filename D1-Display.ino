#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESPRotary.h>
#include <Button2.h>

//Display
#define OLED_RESET 0
Adafruit_SSD1306 display(OLED_RESET); // 64x48 Pixel
//Rotary
ESPRotary r = ESPRotary(D5, D6, 5, 0, 255); //pin1, pin2, steps_per_click, min, max

//Pins
#define BUTTON_A_PIN D2
#define BUTTON_B_PIN D3

Button2 buttonA = Button2(BUTTON_A_PIN);
Button2 buttonB = Button2(BUTTON_B_PIN);

char *inputText[] = {"Main", "Alt", "Bluetooth"};
char *outputText[] = {"Main", "Dynaudio", "Alt"};
byte volume = 100;

byte currentInput = 0;
byte currentOutput = 1;
byte currentvolume = 1;

void setup()
{
    Serial.begin(115200);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.display();
    delay(2000);
    display.clearDisplay();
    display.setTextColor(WHITE);
    wDisplay();
    r.setChangedHandler(changeVolume);
    r.resetPosition(volume);

    buttonA.setClickHandler(click);
    buttonB.setClickHandler(click);

    Serial.println("");
    Serial.println("Ready!");
}

void loop()
{
    r.loop();
}

void drawCentreString(String buf, int y, int x = 32)
{
    int16_t x1, y1;
    uint16_t w, h;
    display.setTextWrap(false);
    display.getTextBounds(buf, x, y, &x1, &y1, &w, &h); //calc width of new string
    display.setCursor(x - w / 2, y);
    display.print(buf);
}

void changeVolume(ESPRotary &r)
{
    volume = r.getPosition();
    wDisplay();
}

void setVolume(byte value)
{
    volume = value;
    r.resetPosition(volume);
    wDisplay();
}

void setInput(byte nr)
{
    currentInput = nr;
    wDisplay();
}

void setOutput(byte nr)
{
    currentOutput = nr;
    wDisplay();
}

void wDisplay()
{
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    drawCentreString(inputText[currentInput], 0);
    display.setTextSize(2);
    drawCentreString(String(volume), 16);
    display.setTextSize(1);
    drawCentreString(outputText[currentOutput], 38);
    display.display();
}

void click(Button2 &btn)
{
    if (btn == buttonA)
    {
        setInput(currentInput + 1);
    }
    else if (btn == buttonB)
    {
        setVolume(60);
    }
    wDisplay();
}
