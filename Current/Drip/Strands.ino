
//---------------------------------------------------------------//
// STRANDS

// Loop Through Our Strands
void loopStrands() {
    // Iterate
    currentlyPlaying = true;
    // Serial.println("currentlyPlaying ON" );

    for(int i = 0; i < numStrands; i++) {
      // Set Random Speed
      speed[i] = random(blinkSpeed[miN],blinkSpeed[maX]);

      // Reset Current Millisecond
      currentMillis[i] = millis();
      
      for(int k = 0; k < strandLength; k++) {   
        // Check & Reset LED Strand
        resetStrand(k, i);
      }
  }
     currentlyPlaying = false; 
}

// Reset + Light Our Strands
void resetStrand(int k, int i) {

    // If We Reach The End Of The Strand, Reset
    if (k >= endLED[i]){       
      timer[i] = speed[i];
    } 
    
    // Is Our Timer Ready To Switch ?? 
    if(currentMillis[i] - stepTime[i] >= timer[i]) {
      
      // Turn The LEDs Black
      leds[LEDsections[i]].r = 0;
      leds[LEDsections[i]].g = 0;
      leds[LEDsections[i]].b = 0;
  
      // Increment
      LEDsections[i]++;
  
      // Go Back To The Beginning
      if(LEDsections[i] == endLED[i]) {
        // Are We Still Getting A Reading ?
        if(inRange) {
          LEDsections[i] = startLED[i];
          timer[i] = speed[i];
        }
        else {
          leds[LEDsections[i]].r = 0;
          leds[LEDsections[i]].g = 0;
          leds[LEDsections[i]].b = 0;
        }
      }
  
      // Turn The LEDs White
      leds[LEDsections[i]].r = 255;
      leds[LEDsections[i]].g = 255;
      leds[LEDsections[i]].b = 255;
  
      // Reset Our Timer
      stepTime[i] = currentMillis[i];
    }
  
}
