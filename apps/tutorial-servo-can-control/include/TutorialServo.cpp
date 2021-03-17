#include "TutorialServo.h"
#include "mbed.h"

TutorialServo::TutorialServo(PinName servoPin, float servoRangeInDegrees, float minPulsewidthInMs, float maxPulsewidthInMs)
  : m_servoPin(servoPin), m_servoRangeInDegrees(servoRangeInDegrees), m_minPulsewidthInMs(minPulsewidthInMs), m_maxPulsewidthInMs(maxPulsewidthInMs)
{
  PwmOut servoPwmOut(m_servoPin);
  servoPwmOut.period_ms(20);
}

void TutorialServo::setPositionInDegrees(const float degrees)
{
  if (degrees <= m_servoRangeInDegrees && degrees >= 0 && m_minPulsewidthInMs + degrees/m_servoRangeInDegrees <= m_maxPulsewidthInMs)
  {
    servoPwmOut.pulsewidth_ms(m_minPulsewidthInMs + degrees/m_servoRangeInDegrees)
  }
}

float TutorialServo::getServoRangeInDegrees() const
{
  return m_servoRangeInDegrees;
}

float TutorialServo::getMinPulsewidthInMs() const
{
  return m_minPulsewidthInMs;
}

float TutorialServo::getMaxPulsewidthInMs() const
{
  return m_maxPulsewidthInMs;
}
