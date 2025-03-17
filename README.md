# ES45_ARM
### Tree till now

```.
├── APP
│   ├── MGPIO_TEST
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   ├── MNVIC_TEST
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   ├── MRCC_TEST
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   └── MSTK_TEST
│       ├── CMakeLists.txt
│       └── main.c
├── arm-gcc-toolchain.cmake
├── CMakeLists.txt
├── COMMON
│   ├── BIT_MATH.h
│   ├── startup_stm32f401xc.S
│   ├── STD_TYPES.h
│   └── STM32F401CCUX_FLASH.ld
├── Drivers.cmake
└── MCAL
    ├── MGPIO
    │   ├── inc
    │   │   ├── MGPIO.h
    │   │   └── MGPIO_private.h
    │   └── src
    │       └── MGPIO.c
    ├── MNVIC
    │   ├── inc
    │   │   ├── MNVIC_cfg.h
    │   │   ├── MNVIC.h
    │   │   └── MNVIC_private.h
    │   └── src
    │       └── MNVIC.c
    ├── MRCC
    │   ├── inc
    │   │   ├── MRCC.h
    │   │   └── MRCC_private.h
    │   └── src
    │       └── MRCC.c
    ├── MSTK
    │   ├── inc
    │   │   ├── MSTK.h
    │   │   └── MSTK_private.h
    │   └── src
    │       └── MSTK.c
    └── MUSART
        ├── inc
        │   ├── MUSART.h
        │   └── MUSART_private.h
        └── src
            └── MUSART.c

```

##
## How to build? 
```
cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=~/ES45_ARM/COTS-stm32f401cc/arm-gcc-toolchain.cmake
```
```
cmake --build build 
```
##
## How to flash? 
### "Check APP/MRCC_TEST and APP/MGPIO_TEST directories CMakeLists.txt files"
- Flashing APP/MRCC_TEST
```
cmake --build build --target flash_MRCC_TEST
   ```
- Flashing APP/MGPIO_TEST
```
cmake --build build --target flash_MGPIO_TEST
   ```

**Progress will be updated**
