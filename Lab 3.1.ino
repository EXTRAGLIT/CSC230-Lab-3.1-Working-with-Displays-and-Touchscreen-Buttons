/*
  Name: Dominick Warner

  Part 1
  Flash red, white, and blue screens for 1 second each.
  Set background to black.
  Display name at (20,20) with text size 2.

  Part 2
  White background.
  Favorite color text.
  Center full name on the screen.

  Part 3
  Right button: change to a different color combination.
  Middle button: choose a random color combination.
  Left button: return to the original color combination.
*/

#include <M5Core2.h>

// ---------- User Information ----------
String fullName = "Dominick Warner";

// ---------- Original Color Combination ----------
uint16_t originalBG = WHITE;
uint16_t originalText = BLUE;

// ---------- Alternate Color Combination ----------
uint16_t alternateBG = BLACK;
uint16_t alternateText = GREEN;

// ---------- Function to display centered text ----------
void displayCenteredName(uint16_t bgColor, uint16_t textColor)
{
  // Fill screen with background color
  M5.Lcd.fillScreen(bgColor);

  // Set text color
  M5.Lcd.setTextColor(textColor);

  // Set text size (adjust if needed)
  int textSize = 2;
  M5.Lcd.setTextSize(textSize);

  // Determine width and height of text
  int textWidth = fullName.length() * 12 * textSize;
  int textHeight = 16 * textSize;

  // Calculate centered position
  int x = (320 - textWidth) / 2;
  int y = (240 - textHeight) / 2;

  // Position cursor and print name
  M5.Lcd.setCursor(x, y);
  M5.Lcd.print(fullName);
}

void setup()
{
  // Initialize M5Core2
  M5.begin();

  // ---------------- Part 1 ----------------

  // Flash red screen
  M5.Lcd.fillScreen(RED);
  delay(1000);

  // Flash white screen
  M5.Lcd.fillScreen(WHITE);
  delay(1000);

  // Flash blue screen
  M5.Lcd.fillScreen(BLUE);
  delay(1000);

  // Set black background
  M5.Lcd.fillScreen(BLACK);

  // Display name at position (20,20)
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(20, 20);
  M5.Lcd.print(fullName);

  delay(3000);

  // ---------------- Part 2 ----------------

  // Show centered name with original colors
  displayCenteredName(originalBG, originalText);

  // Initialize random number generator
  randomSeed(millis());
}

void loop()
{
  // Update button status
  M5.update();

  // ---------------- Left Button ----------------
  // Return to original colors
  if (M5.BtnA.wasPressed())
  {
    displayCenteredName(originalBG, originalText);
  }

  // ---------------- Middle Button ----------------
  // Random color combinations (4 choices)
  if (M5.BtnB.wasPressed())
  {
    int choice = random(4);

    switch (choice)
    {
      case 0:
        displayCenteredName(BLACK, YELLOW);
        break;

      case 1:
        displayCenteredName(BLUE, WHITE);
        break;

      case 2:
        displayCenteredName(RED, CYAN);
        break;

      case 3:
        displayCenteredName(GREEN, MAGENTA);
        break;
    }
  }

  // ---------------- Right Button ----------------
  // Use alternate color combination
  if (M5.BtnC.wasPressed())
  {
    displayCenteredName(alternateBG, alternateText);
  }
}