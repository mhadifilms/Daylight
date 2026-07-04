/**
 * @file src/platform/macos/hid_gamepad.h
 * @brief Virtual HID gamepad via IOHIDUserDevice for macOS.
 */
#pragma once

#import <Foundation/Foundation.h>
#import <IOKit/hidsystem/IOHIDUserDevice.h>

typedef struct __attribute__((packed)) {
  uint8_t reportId;
  uint16_t buttons;
  uint8_t hatSwitch;
  uint8_t leftTrigger;
  uint8_t rightTrigger;
  int16_t leftStickX;
  int16_t leftStickY;
  int16_t rightStickX;
  int16_t rightStickY;
} HIDGamepadReport;

@interface HIDGamepad : NSObject

@property (nonatomic, assign) int gamepadIndex;
@property (nonatomic, assign) BOOL isConnected;
@property (nonatomic, assign) IOHIDUserDeviceRef hidDevice;
@property (nonatomic, strong) dispatch_queue_t hidQueue;

+ (BOOL)isAvailable;
- (instancetype)initWithIndex:(int)index;
- (BOOL)createDevice;
- (void)updateState:(uint32_t)buttons
         leftStickX:(int16_t)lsX
         leftStickY:(int16_t)lsY
        rightStickX:(int16_t)rsX
        rightStickY:(int16_t)rsY
        leftTrigger:(uint8_t)lt
       rightTrigger:(uint8_t)rt;
- (void)disconnect;

@end
