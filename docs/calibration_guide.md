# Calibration Guide

## Soil Moisture Calibration
- Raw ADC Range: 0–4095
- Dry soil ≈ 0–1500
- Wet soil ≈ 2500–4095
- Converted to percentage using linear mapping.

## TDS Calibration
- Raw ADC mapped to 0–1000 ppm.
- Threshold set at 700 ppm.

## Turbidity Calibration
- Raw ADC mapped to 0–100%.
- Threshold set at 65%.

## Tank Level
- Ultrasonic distance measured in cm.
- Minimum required tank depth: 12 cm.
