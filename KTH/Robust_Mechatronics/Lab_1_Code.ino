/*
  All-in-one setPWM with independent control of frequency and duty cycle.
  PWM is generated on `PB4` if available.
*/

/*
  Note: Please verify that 'pin' used for PWM has HardwareTimer capability for your board.
*/

#define pin  D12

// Initialize frequency and duty cycle with default values
uint32_t frequency = 500; // Default 5 kHz
uint32_t dutyCycle = 10;   // Default 50% duty cycle

HardwareTimer *MyTim;

TIM_TypeDef *Instance;
uint32_t channel;

void setup()
{
  Serial.begin(115200); // For communication input


  Instance = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(pin), PinMap_PWM);
  channel = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(pin), PinMap_PWM));

  MyTim = new HardwareTimer(Instance);

  // Configure and start PWM with default values
  MyTim->setPWM(channel, pin, frequency, dutyCycle);
}

void loop()
{
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');  // Read input until newline character
    input.trim();  // Remove any surrounding whitespace

    // Check if input starts with 'D:' for duty cycle or 'F:' for frequency
    if (input.startsWith("D:")) {
      // Extract and update duty cycle
      dutyCycle = input.substring(2).toInt();  // Convert the part after 'D:' to an integer
      MyTim->pause();
      MyTim->setPWM(channel, pin, frequency, dutyCycle); // Update PWM
      MyTim->resume();
      Serial.print("Duty Cycle set to: ");
      Serial.println(dutyCycle);

    } 
    else if (input.startsWith("F:")) {
      // Extract and update frequency
      frequency = input.substring(2).toInt();  // Convert the part after 'F:' to an integer
      MyTim->pause();
      MyTim->setPWM(channel, pin, frequency, dutyCycle); // Update PWM
      MyTim->resume();
      Serial.print("Frequency set to: ");
      Serial.println(frequency);
    }
  }
}
