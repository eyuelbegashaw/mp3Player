const int rs = 47, en = 46, d4 = 45, d5 = 44, d6 = 43, d7 = 42;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void lcdMessage(String message)
{
  lcd.clear();
  lcd.begin(16, 4);
  lcd.print(message);
}