/*
 * Owner: Marco Caliendo (MCal88)
 * Contributors: Cameron Schwartzberg (BigBroccoli), and Andrew Barnes (abarnes6)
 */

#include "Encoders.h"
#include "PinDefinitions.h"

namespace encoders
{
#ifdef WROOM32
    void setupEncoder(uint8_t pin1, uint8_t pin2, ESP32Encoder &encoder)
    {
        encoder.attachFullQuad(pin1, pin2);
        encoder.setCount(0);
    }

    int32_t readEncoder(ESP32Encoder &encoder)
    {
        return encoder.getCount();
    }

    float getRPM(ESP32Encoder &encoder, volatile int32_t &lastCount, volatile uint32_t &lastReadTime, Direction &direction)
    {
        uint32_t currentTime = millis();
        int32_t currentCount = readEncoder(encoder);
        int32_t countChange = currentCount - lastCount;
        
        // Calculate time elapsed in seconds
        float timeElapsedSeconds = (currentTime - lastReadTime) / 1000.0f;
        
        // Only update if some time has passed
        if (timeElapsedSeconds > 0.01f) { // Minimum 10ms elapsed time
            // Calculate RPM: (count_change / PPR) * (60 seconds / time_elapsed) / gear_ratio
            float rpm = ((abs(static_cast<float>(countChange)) / PPR) * (60.0f / timeElapsedSeconds)) / CV;
            
            // Determine direction
            direction = getDirection(currentCount, lastCount);
            
            // Update stored values
            lastCount = currentCount;
            lastReadTime = currentTime;
            
            return rpm;
        }
        
        // If no significant time has passed, keep previous RPM value
        return 0.0f;
    }
#else
    void setupEncoder(uint8_t pin1, uint8_t pin2, Encoder &encoder)
    {
        // Constructor already sets up the pins
        encoder.write(0);
    }

    int32_t readEncoder(Encoder &encoder)
    {
        return encoder.read();
    }

    float getRPM(Encoder &encoder, volatile int32_t &lastCount, volatile uint32_t &lastReadTime, Direction &direction)
    {
        uint32_t currentTime = millis();
        int32_t currentCount = readEncoder(encoder);
        int32_t countChange = currentCount - lastCount;
        
        // Calculate time elapsed in seconds
        float timeElapsedSeconds = (currentTime - lastReadTime) / 1000.0f;
        
        // Only update if some time has passed
        if (timeElapsedSeconds > 0.01f) { // Minimum 10ms elapsed time
            // Calculate RPM: (count_change / PPR) * (60 seconds / time_elapsed) / gear_ratio
            float rpm = ((abs(static_cast<float>(countChange)) / PPR) * (60.0f / timeElapsedSeconds)) / CV;
            
            // Determine direction
            direction = getDirection(currentCount, lastCount);
            
            // Update stored values
            lastCount = currentCount;
            lastReadTime = currentTime;
            
            return rpm;
        }
        
        // If no significant time has passed, keep previous RPM value
        return 0.0f;
    }
#endif

    Direction getDirection(int32_t currentCount, int32_t lastCount)
    {
        int32_t difference = currentCount - lastCount;
        
        if (difference > 0) {
            return Direction::FORWARD;
        } else if (difference < 0) {
            return Direction::BACKWARD;
        } else {
            return Direction::STOPPED;
        }
    }
    
    uint8_t directionToUint8(Direction dir)
    {
        switch(dir) {
            case Direction::FORWARD:
                return 1;
            case Direction::BACKWARD:
                return 2;
            case Direction::STOPPED:
            default:
                return 0;
        }
    }
}
