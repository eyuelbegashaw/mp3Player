bool checkSD()
{
  if (!SD.begin(53)) 
  {
    sm.println("SD card not found");
    return false;
  }

   return true;
}
