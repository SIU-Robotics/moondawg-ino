/*
 * Owner: Marco Caliendo (MCal88)
 * Contributors: Cameron Schwartzberg (BigBroccoli), and Andrew Barnes (abarnes6)
 */

#ifndef Encoders_h
#define Encoders_h

#ifdef WROOM32
#include <ESP32Encoder.h>
#else
#include <Encoder.h>
#endif
#include <Arduino.h>

namespace encoders
{
    constexpr uint8_t PPR = 20;
    constexpr uint8_t CV = 4;

    enum class Direction {
        FORWARD,
        BACKWARD,
        STOPPED
    };

    struct Container
    {
    #if defined(WROOM32)
        ESP32Encoder motor_encoder;
    #else
        Encoder motor_encoder;
    #endif
        volatile int32_t lastCount{0};
        volatile uint32_t lastReadTime{0};
        float rpm{0.0f};
        Direction direction{Direction::STOPPED};
    };

    #ifdef WROOM32
        void setupEncoder(uint8_t pin_1, uint8_t pin_2, ESP32Encoder &encoder);
        int32_t readEncoder(ESP32Encoder &encoder);
        float getRPM(ESP32Encoder &encoder, volatile int32_t &lastCount, volatile uint32_t &lastReadTime, Direction &direction);
        Direction getDirection(int32_t currentCount, int32_t lastCount);
    #else
        void setupEncoder(uint8_t pin_1, uint8_t pin_2, Encoder &encoder);
        int32_t readEncoder(Encoder &encoder);
        float getRPM(Encoder &encoder, volatile int32_t &lastCount, volatile uint32_t &lastReadTime, Direction &direction);
        Direction getDirection(int32_t currentCount, int32_t lastCount);
    #endif

    // Helper function to convert direction enum to uint8_t for I2C
    uint8_t directionToUint8(Direction dir);
}

#endif // Encoders_h
